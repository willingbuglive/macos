/*
 * Copyright (c) 2012,2014 Apple Inc. All Rights Reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */


#ifndef __SSL_UTILS_H__
#define __SSL_UTILS_H__

#include <Security/SecureTransport.h>

CFArrayRef CF_RETURNS_RETAINED trusted_roots(void);
CFArrayRef CF_RETURNS_RETAINED server_chain(void);
CFArrayRef CF_RETURNS_RETAINED server_ec_chain(void);
CFArrayRef CF_RETURNS_RETAINED trusted_client_chain(void);
CFArrayRef CF_RETURNS_RETAINED trusted_ec_client_chain(void);
CFArrayRef CF_RETURNS_RETAINED untrusted_client_chain(void);

#define client_chain trusted_client_chain

const char *ciphersuite_name(SSLCipherSuite cs);

#endif
