/*
 * Copyright (c) 2000-2001 Apple Computer, Inc. All Rights Reserved.
 * 
 * The contents of this file constitute Original Code as defined in and are
 * subject to the Apple Public Source License Version 1.2 (the 'License').
 * You may not use this file except in compliance with the License. Please obtain
 * a copy of the License at http://www.apple.com/publicsource and read it before
 * using this file.
 * 
 * This Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS
 * OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES, INCLUDING WITHOUT
 * LIMITATION, ANY WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT. Please see the License for the
 * specific language governing rights and limitations under the License.
 */


/*
 * c_examples/simple/expbuf_ex.c - an example of how to call C ASN.1-BER
 *              encoders and decoders generated by snacc
 *              with the ExpBuf buffer.
 *
 * AUTHOR: Mike Sample
 * DATE:   Mar 92
 *
 * $Header: /cvs/Darwin/Security/SecuritySNACCRuntime/c-examples/simple/expbuf-ex.c,v 1.1.1.1 2001/05/18 23:14:07 mb Exp $
 * $Log: expbuf-ex.c,v $
 * Revision 1.1.1.1  2001/05/18 23:14:07  mb
 * Move from private repository to open source repository
 *
 * Revision 1.3  2001/05/05 00:59:20  rmurphy
 * Adding darwin license headers
 *
 * Revision 1.2  2000/06/08 20:06:59  dmitch
 * Mods for X port.
 *
 * Revision 1.1.1.1  1999/03/16 18:06:08  aram
 * Originals from SMIME Free Library.
 *
 * Revision 1.5  1995/07/24 20:44:58  rj
 * changed `_' to `-' in file names.
 *
 * Revision 1.4  1995/02/18  15:12:53  rj
 * cosmetic changes
 *
 * Revision 1.3  1994/08/31  23:48:29  rj
 * more portable .h file inclusion.
 *
 * Revision 1.2  1994/08/31  08:59:34  rj
 * first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.
 *
 */

#include "asn-incl.h"

#include <sys/file.h>
#include <sys/stat.h>
#if HAVE_FCNTL_H 
#include <fcntl.h>
#endif
#include <stdio.h>

#include "p-rec.h"
#include "exp-buf.h"

main PARAMS ((argc, argv),
    int argc _AND_
    char *argv[])
{
    int fd;
    ExpBuf *buf;
    ExpBuf  b;
    ExpBuf *tmpBuf;
    AsnLen encodedLen;
    AsnLen decodedLen;
    int     val;
    PersonnelRecord pr;
    int      size;
    char    *origData;
    struct stat sbuf;
    jmp_buf env;
    int  decodeErr;
    AsnTag tag;


    if (argc != 2)
    {
        fprintf (stderr, "Usage: %s <BER data file name>\n", argv[0]);
        fprintf (stderr, "   Decodes the given PersonnelRecord BER data file\n");
        fprintf (stderr, "   and re-encodes it to stdout\n");
        exit (1);
    }

    fd = open (argv[1], O_RDONLY, 0);
    if (fd < 0)
    {
        perror ("main: fopen");
        exit (1);
    }

    if (fstat (fd, &sbuf) < 0)
    {
        perror ("main: fstat");
        exit (1);
    }

    size = sbuf.st_size;
    origData = (char*)malloc (size);
    if (read (fd, origData, size) != size)
    {
        perror ("main: read");
        exit (1);
    }

    close (fd);

    /*
     * the "1024" is the size in bytes of the data
     * blk to allocate when writing to a buffer that
     * fills up.
     */
    ExpBufInit (1024);

    /*
     * the first argument (512) is the number of bytes to
     * initially allocate for the decoder to allocate from.
     * The second argument (512) is the size in bytes to
     * enlarge the nibble memory by when it fills up
     */
    InitNibbleMem (512, 512);

    /*
     * put the BER data read from the file
     * into buffer format, ready for reading from the
     * beginning
     */
    buf = &b;
    ExpBufInstallDataInBuf (buf, origData, size);

    decodedLen = 0;
    decodeErr = FALSE;
    if ((val = setjmp (env)) == 0)
    {
        BDecPersonnelRecord (&buf, &pr, &decodedLen, env);
    }
    else
    {
        decodeErr = TRUE;
        fprintf (stderr, "ERROR - Decode routines returned %d\n",val);
    }

    if (decodeErr)
        exit (1);

    fprintf (stderr, "decodedValue PersonnelRecord ::= ");
    PrintPersonnelRecord (stderr, &pr, 0);
    fprintf (stderr, "\n\n");

    /*
     * allocate a new buffer set up for writing to
     */
    buf = ExpBufAllocBufAndData();

    encodedLen =  BEncPersonnelRecord (&buf, &pr);

    /*
     * Alway check for a buffer write error after encoding
     */
    if (ExpBufWriteError (&buf))
    {
        fprintf (stderr, "ERROR - buffer write error during encoding\n");
        exit (1);
    }


    /*
     * free all of the decoded value since
     * it has been encoded into the buffer.
     * This is much more efficient than freeing
     * each compontent of the value individually
     */
    ResetNibbleMem();

    /*
     * go through buffer (s) and write encoded value
     * to stdout
     */
    buf->curr = buf->dataStart;
    for ( tmpBuf = buf; tmpBuf != NULL; tmpBuf = tmpBuf->next)
    {
        fwrite (tmpBuf->dataStart, tmpBuf->dataEnd - tmpBuf->dataStart, 1, stdout);
    }

    return 0;
}
