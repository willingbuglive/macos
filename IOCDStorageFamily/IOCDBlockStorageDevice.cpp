/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.1 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 * 
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
#include <IOKit/storage/IOCDBlockStorageDevice.h>

#define	super	IOBlockStorageDevice
OSDefineMetaClassAndAbstractStructors(IOCDBlockStorageDevice,IOBlockStorageDevice)

bool
IOCDBlockStorageDevice::init(OSDictionary * properties)
{
    bool result;

    result = super::init(properties);
    if (result) {
        setProperty(kIOBlockStorageDeviceTypeKey,
                    kIOBlockStorageDeviceTypeCDROM);
    }

    return(result);
}

IOReturn
IOCDBlockStorageDevice::getSpeed(UInt16 * kilobytesPerSecond)
{
    return(kIOReturnUnsupported);
}

OSMetaClassDefineReservedUsed(IOCDBlockStorageDevice, 0);

IOReturn
IOCDBlockStorageDevice::setSpeed(UInt16 kilobytesPerSecond)
{
    return(kIOReturnUnsupported);
}

OSMetaClassDefineReservedUsed(IOCDBlockStorageDevice, 1);

IOReturn
IOCDBlockStorageDevice::readTOC(IOMemoryDescriptor *buffer,CDTOCFormat format,
                                UInt8 msf,UInt8 trackSessionNumber,
                                UInt16 *actualByteCount)
{
    if (actualByteCount) {
        *actualByteCount = 0;
    }
    return(kIOReturnUnsupported);
}

OSMetaClassDefineReservedUsed(IOCDBlockStorageDevice, 2);

IOReturn
IOCDBlockStorageDevice::readDiscInfo(IOMemoryDescriptor *buffer,
                                     UInt16 *actualByteCount)
{
    if (actualByteCount) {
        *actualByteCount = 0;
    }
    return(kIOReturnUnsupported);
}

OSMetaClassDefineReservedUsed(IOCDBlockStorageDevice, 3);

IOReturn
IOCDBlockStorageDevice::readTrackInfo(IOMemoryDescriptor *buffer,UInt32 address,
                                      CDTrackInfoAddressType addressType,
                                      UInt16 *actualByteCount)
{
    if (actualByteCount) {
        *actualByteCount = 0;
    }
    return(kIOReturnUnsupported);
}

OSMetaClassDefineReservedUsed(IOCDBlockStorageDevice, 4);

OSMetaClassDefineReservedUnused(IOCDBlockStorageDevice,  5);
OSMetaClassDefineReservedUnused(IOCDBlockStorageDevice,  6);
OSMetaClassDefineReservedUnused(IOCDBlockStorageDevice,  7);
OSMetaClassDefineReservedUnused(IOCDBlockStorageDevice,  8);
OSMetaClassDefineReservedUnused(IOCDBlockStorageDevice,  9);
OSMetaClassDefineReservedUnused(IOCDBlockStorageDevice, 10);
OSMetaClassDefineReservedUnused(IOCDBlockStorageDevice, 11);
OSMetaClassDefineReservedUnused(IOCDBlockStorageDevice, 12);
OSMetaClassDefineReservedUnused(IOCDBlockStorageDevice, 13);
OSMetaClassDefineReservedUnused(IOCDBlockStorageDevice, 14);
OSMetaClassDefineReservedUnused(IOCDBlockStorageDevice, 15);
