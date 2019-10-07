/*
 * Copyright (C) 2016-2019 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "ResourceLoadObserver.h"

#include "DeprecatedGlobalSettings.h"
#include "Document.h"
#include "Frame.h"
#include "FrameLoader.h"
#include "FrameLoaderClient.h"
#include "HTMLFrameOwnerElement.h"
#include "Logging.h"
#include "Page.h"
#include "RegistrableDomain.h"
#include "ResourceLoadStatistics.h"
#include "ResourceRequest.h"
#include "ResourceResponse.h"
#include "RuntimeEnabledFeatures.h"
#include "ScriptExecutionContext.h"
#include "SecurityOrigin.h"
#include "Settings.h"
#include <wtf/URL.h>

namespace WebCore {

static const Seconds minimumNotificationInterval { 5_s };

ResourceLoadObserver& ResourceLoadObserver::shared()
{
    static NeverDestroyed<ResourceLoadObserver> resourceLoadObserver;
    return resourceLoadObserver;
}

void ResourceLoadObserver::setStatisticsUpdatedCallback(WTF::Function<void(Vector<ResourceLoadStatistics>&&)>&& notificationCallback)
{
    ASSERT(!m_notificationCallback);
    m_notificationCallback = WTFMove(notificationCallback);
}

void ResourceLoadObserver::setRequestStorageAccessUnderOpenerCallback(WTF::Function<void(PAL::SessionID sessionID, const RegistrableDomain& domainInNeedOfStorageAccess, PageIdentifier openerPageID, const RegistrableDomain& openerDomain)>&& callback)
{
    ASSERT(!m_requestStorageAccessUnderOpenerCallback);
    m_requestStorageAccessUnderOpenerCallback = WTFMove(callback);
}

void ResourceLoadObserver::setLogUserInteractionNotificationCallback(Function<void(PAL::SessionID, const RegistrableDomain&)>&& callback)
{
    ASSERT(!m_logUserInteractionNotificationCallback);
    m_logUserInteractionNotificationCallback = WTFMove(callback);
}

void ResourceLoadObserver::setLogWebSocketLoadingNotificationCallback(Function<void(PAL::SessionID, const RegistrableDomain&, const RegistrableDomain&, WallTime)>&& callback)
{
    ASSERT(!m_logWebSocketLoadingNotificationCallback);
    m_logWebSocketLoadingNotificationCallback = WTFMove(callback);
}

void ResourceLoadObserver::setLogSubresourceLoadingNotificationCallback(Function<void(PAL::SessionID, const RegistrableDomain&, const RegistrableDomain&, WallTime)>&& callback)
{
    ASSERT(!m_logSubresourceLoadingNotificationCallback);
    m_logSubresourceLoadingNotificationCallback = WTFMove(callback);
}

void ResourceLoadObserver::setLogSubresourceRedirectNotificationCallback(Function<void(PAL::SessionID, const RegistrableDomain&, const RegistrableDomain&)>&& callback)
{
    ASSERT(!m_logSubresourceRedirectNotificationCallback);
    m_logSubresourceRedirectNotificationCallback = WTFMove(callback);
}
    
static inline bool is3xxRedirect(const ResourceResponse& response)
{
    return response.httpStatusCode() >= 300 && response.httpStatusCode() <= 399;
}

bool ResourceLoadObserver::shouldLog(bool usesEphemeralSession) const
{
    return DeprecatedGlobalSettings::resourceLoadStatisticsEnabled() && !usesEphemeralSession && m_notificationCallback;
}

void ResourceLoadObserver::logSubresourceLoading(const Frame* frame, const ResourceRequest& newRequest, const ResourceResponse& redirectResponse)
{
    ASSERT(frame->page());

    if (!frame)
        return;

    auto* page = frame->page();
    if (!page || !shouldLog(page->usesEphemeralSession()))
        return;

    bool isRedirect = is3xxRedirect(redirectResponse);
    const URL& redirectedFromURL = redirectResponse.url();
    const URL& targetURL = newRequest.url();
    const URL& topFrameURL = frame ? frame->mainFrame().document()->url() : URL();
    
    auto targetHost = targetURL.host();
    auto topFrameHost = topFrameURL.host();

    if (targetHost.isEmpty() || topFrameHost.isEmpty() || targetHost == topFrameHost || (isRedirect && targetHost == redirectedFromURL.host()))
        return;

    RegistrableDomain targetDomain { targetURL };
    RegistrableDomain topFrameDomain { topFrameURL };
    RegistrableDomain redirectedFromDomain { redirectedFromURL };

    if (targetDomain == topFrameDomain || (isRedirect && targetDomain == redirectedFromDomain))
        return;

    {
        auto& targetStatistics = ensureResourceStatisticsForRegistrableDomain(targetDomain);
        auto lastSeen = ResourceLoadStatistics::reduceTimeResolution(WallTime::now());
        targetStatistics.lastSeen = lastSeen;
        targetStatistics.subresourceUnderTopFrameDomains.add(topFrameDomain);

        m_logSubresourceLoadingNotificationCallback(page->sessionID(), targetDomain, topFrameDomain, lastSeen);
    }

    if (isRedirect) {
        auto& redirectingOriginStatistics = ensureResourceStatisticsForRegistrableDomain(redirectedFromDomain);
        redirectingOriginStatistics.subresourceUniqueRedirectsTo.add(targetDomain);
        auto& targetStatistics = ensureResourceStatisticsForRegistrableDomain(targetDomain);
        targetStatistics.subresourceUniqueRedirectsFrom.add(redirectedFromDomain);

        m_logSubresourceRedirectNotificationCallback(page->sessionID(), redirectedFromDomain, targetDomain);
    }
}

void ResourceLoadObserver::logWebSocketLoading(const URL& targetURL, const URL& mainFrameURL, PAL::SessionID sessionID)
{
    if (!shouldLog(sessionID.isEphemeral()))
        return;

    auto targetHost = targetURL.host();
    auto mainFrameHost = mainFrameURL.host();
    
    if (targetHost.isEmpty() || mainFrameHost.isEmpty() || targetHost == mainFrameHost)
        return;
    
    RegistrableDomain targetDomain { targetURL };
    RegistrableDomain topFrameDomain { mainFrameURL };

    if (targetDomain == topFrameDomain)
        return;

    auto lastSeen = ResourceLoadStatistics::reduceTimeResolution(WallTime::now());

    auto& targetStatistics = ensureResourceStatisticsForRegistrableDomain(targetDomain);
    targetStatistics.lastSeen = lastSeen;
    targetStatistics.subresourceUnderTopFrameDomains.add(topFrameDomain);

    m_logWebSocketLoadingNotificationCallback(sessionID, targetDomain, topFrameDomain, lastSeen);
}

void ResourceLoadObserver::logUserInteractionWithReducedTimeResolution(const Document& document)
{
    if (!document.sessionID().isValid() || !shouldLog(document.sessionID().isEphemeral()))
        return;

    auto& url = document.url();
    if (url.protocolIsAbout() || url.isLocalFile() || url.isEmpty())
        return;

    RegistrableDomain topFrameDomain { url };
    auto newTime = ResourceLoadStatistics::reduceTimeResolution(WallTime::now());
    auto lastReportedUserInteraction = m_lastReportedUserInteractionMap.get(topFrameDomain);
    if (newTime == lastReportedUserInteraction)
        return;

    m_lastReportedUserInteractionMap.set(topFrameDomain, newTime);

    auto& statistics = ensureResourceStatisticsForRegistrableDomain(topFrameDomain);
    statistics.hadUserInteraction = true;
    statistics.lastSeen = newTime;
    statistics.mostRecentUserInteractionTime = newTime;

#if ENABLE(RESOURCE_LOAD_STATISTICS)
    if (auto* frame = document.frame()) {
        if (auto* opener = frame->loader().opener()) {
            if (auto* openerDocument = opener->document()) {
                if (auto* openerFrame = openerDocument->frame()) {
                    if (auto openerPageID = openerFrame->loader().client().pageID())
                        requestStorageAccessUnderOpener(document.sessionID(), topFrameDomain, openerPageID.value(), *openerDocument);
                }
            }
        }
    }

    m_logUserInteractionNotificationCallback(document.sessionID(), topFrameDomain);
#endif

#if ENABLE(RESOURCE_LOAD_STATISTICS) && !RELEASE_LOG_DISABLED
    if (shouldLogUserInteraction()) {
        auto counter = ++m_loggingCounter;
#define LOCAL_LOG(str, ...) \
        RELEASE_LOG(ResourceLoadStatistics, "ResourceLoadObserver::logUserInteraction: counter = %" PRIu64 ": " str, counter, ##__VA_ARGS__)

        auto escapeForJSON = [](String s) {
            s.replace('\\', "\\\\").replace('"', "\\\"");
            return s;
        };
        auto escapedURL = escapeForJSON(url.string());
        auto escapedDomain = escapeForJSON(topFrameDomain.string());

        LOCAL_LOG(R"({ "url": "%{public}s",)", escapedURL.utf8().data());
        LOCAL_LOG(R"(  "domain" : "%{public}s",)", escapedDomain.utf8().data());
        LOCAL_LOG(R"(  "until" : %f })", newTime.secondsSinceEpoch().seconds());

#undef LOCAL_LOG
    }
#endif
}

#if ENABLE(RESOURCE_LOAD_STATISTICS)
void ResourceLoadObserver::requestStorageAccessUnderOpener(PAL::SessionID sessionID, const RegistrableDomain& domainInNeedOfStorageAccess, PageIdentifier openerPageID, Document& openerDocument)
{
    auto openerUrl = openerDocument.url();
    RegistrableDomain openerDomain { openerUrl };
    if (domainInNeedOfStorageAccess != openerDomain
        && !openerDocument.hasRequestedPageSpecificStorageAccessWithUserInteraction(domainInNeedOfStorageAccess)
        && !equalIgnoringASCIICase(openerUrl.string(), WTF::blankURL())) {
        m_requestStorageAccessUnderOpenerCallback(sessionID, domainInNeedOfStorageAccess, openerPageID, openerDomain);
        // Remember user interaction-based requests since they don't need to be repeated.
        openerDocument.setHasRequestedPageSpecificStorageAccessWithUserInteraction(domainInNeedOfStorageAccess);
    }
}
#endif

void ResourceLoadObserver::logFontLoad(const Document& document, const String& familyName, bool loadStatus)
{
#if ENABLE(WEB_API_STATISTICS)
    if (!shouldLog(document.sessionID().isEphemeral()))
        return;
    RegistrableDomain registrableDomain { document.url() };
    auto& statistics = ensureResourceStatisticsForRegistrableDomain(registrableDomain);
    bool shouldCallNotificationCallback = false;
    if (!loadStatus) {
        if (statistics.fontsFailedToLoad.add(familyName).isNewEntry)
            shouldCallNotificationCallback = true;
    } else {
        if (statistics.fontsSuccessfullyLoaded.add(familyName).isNewEntry)
            shouldCallNotificationCallback = true;
    }
    RegistrableDomain mainFrameRegistrableDomain { document.topDocument().url() };
    if (statistics.topFrameRegistrableDomainsWhichAccessedWebAPIs.add(mainFrameRegistrableDomain.string()).isNewEntry)
        shouldCallNotificationCallback = true;
    if (shouldCallNotificationCallback)
        scheduleNotificationIfNeeded();
#else
    UNUSED_PARAM(document);
    UNUSED_PARAM(familyName);
    UNUSED_PARAM(loadStatus);
#endif
}
    
void ResourceLoadObserver::logCanvasRead(const Document& document)
{
#if ENABLE(WEB_API_STATISTICS)
    if (!shouldLog(document.sessionID().isEphemeral()))
        return;
    RegistrableDomain registrableDomain { document.url() };
    auto& statistics = ensureResourceStatisticsForRegistrableDomain(registrableDomain);
    RegistrableDomain mainFrameRegistrableDomain { document.topDocument().url() };
    statistics.canvasActivityRecord.wasDataRead = true;
    if (statistics.topFrameRegistrableDomainsWhichAccessedWebAPIs.add(mainFrameRegistrableDomain.string()).isNewEntry)
        scheduleNotificationIfNeeded();
#else
    UNUSED_PARAM(document);
#endif
}

void ResourceLoadObserver::logCanvasWriteOrMeasure(const Document& document, const String& textWritten)
{
#if ENABLE(WEB_API_STATISTICS)
    if (!shouldLog(document.sessionID().isEphemeral()))
        return;
    RegistrableDomain registrableDomain { document.url() };
    auto& statistics = ensureResourceStatisticsForRegistrableDomain(registrableDomain);
    bool shouldCallNotificationCallback = false;
    RegistrableDomain mainFrameRegistrableDomain { document.topDocument().url() };
    if (statistics.canvasActivityRecord.recordWrittenOrMeasuredText(textWritten))
        shouldCallNotificationCallback = true;
    if (statistics.topFrameRegistrableDomainsWhichAccessedWebAPIs.add(mainFrameRegistrableDomain.string()).isNewEntry)
        shouldCallNotificationCallback = true;
    if (shouldCallNotificationCallback)
        scheduleNotificationIfNeeded();
#else
    UNUSED_PARAM(document);
    UNUSED_PARAM(textWritten);
#endif
}
    
void ResourceLoadObserver::logNavigatorAPIAccessed(const Document& document, const ResourceLoadStatistics::NavigatorAPI functionName)
{
#if ENABLE(WEB_API_STATISTICS)
    if (!shouldLog(document.sessionID().isEphemeral()))
        return;
    RegistrableDomain registrableDomain { document.url() };
    auto& statistics = ensureResourceStatisticsForRegistrableDomain(registrableDomain);
    bool shouldCallNotificationCallback = false;
    if (!statistics.navigatorFunctionsAccessed.contains(functionName)) {
        statistics.navigatorFunctionsAccessed.add(functionName);
        shouldCallNotificationCallback = true;
    }
    RegistrableDomain mainFrameRegistrableDomain { document.topDocument().url() };
    if (statistics.topFrameRegistrableDomainsWhichAccessedWebAPIs.add(mainFrameRegistrableDomain.string()).isNewEntry)
        shouldCallNotificationCallback = true;
    if (shouldCallNotificationCallback)
        scheduleNotificationIfNeeded();
#else
    UNUSED_PARAM(document);
    UNUSED_PARAM(functionName);
#endif
}
    
void ResourceLoadObserver::logScreenAPIAccessed(const Document& document, const ResourceLoadStatistics::ScreenAPI functionName)
{
#if ENABLE(WEB_API_STATISTICS)
    if (!shouldLog(document.sessionID().isEphemeral()))
        return;
    RegistrableDomain registrableDomain { document.url() };
    auto& statistics = ensureResourceStatisticsForRegistrableDomain(registrableDomain);
    bool shouldCallNotificationCallback = false;
    if (!statistics.screenFunctionsAccessed.contains(functionName)) {
        statistics.screenFunctionsAccessed.add(functionName);
        shouldCallNotificationCallback = true;
    }
    RegistrableDomain mainFrameRegistrableDomain { document.topDocument().url() };
    if (statistics.topFrameRegistrableDomainsWhichAccessedWebAPIs.add(mainFrameRegistrableDomain.string()).isNewEntry)
        shouldCallNotificationCallback = true;
    if (shouldCallNotificationCallback)
        scheduleNotificationIfNeeded();
#else
    UNUSED_PARAM(document);
    UNUSED_PARAM(functionName);
#endif
}
    
ResourceLoadStatistics& ResourceLoadObserver::ensureResourceStatisticsForRegistrableDomain(const RegistrableDomain& domain)
{
    auto addResult = m_resourceStatisticsMap.ensure(domain, [&domain] {
        return ResourceLoadStatistics(domain);
    });
    return addResult.iterator->value;
}

void ResourceLoadObserver::updateCentralStatisticsStore()
{
    m_notificationCallback(takeStatistics());
}

String ResourceLoadObserver::statisticsForURL(const URL& url)
{
    auto iter = m_resourceStatisticsMap.find(RegistrableDomain { url });
    if (iter == m_resourceStatisticsMap.end())
        return emptyString();

    return makeString("Statistics for ", url.host().toString(), ":\n", iter->value.toString());
}

Vector<ResourceLoadStatistics> ResourceLoadObserver::takeStatistics()
{
    Vector<ResourceLoadStatistics> statistics;
    statistics.reserveInitialCapacity(m_resourceStatisticsMap.size());
    for (auto& statistic : m_resourceStatisticsMap.values())
        statistics.uncheckedAppend(WTFMove(statistic));

    m_resourceStatisticsMap.clear();

    return statistics;
}

void ResourceLoadObserver::clearState()
{
    m_resourceStatisticsMap.clear();
    m_lastReportedUserInteractionMap.clear();
}

URL ResourceLoadObserver::nonNullOwnerURL(const Document& document) const
{
    auto url = document.url();
    auto* frame = document.frame();
    auto host = document.url().host();

    while ((host.isNull() || host.isEmpty()) && frame && !frame->isMainFrame()) {
        auto* ownerElement = frame->ownerElement();

        ASSERT(ownerElement != nullptr);
        
        auto& doc = ownerElement->document();
        frame = doc.frame();
        url = doc.url();
        host = url.host();
    }

    return url;
}

} // namespace WebCore
