/* Automatically generated by po2tbl.sed from fetchmail.pot.  */

#if HAVE_CONFIG_H
# include <config.h>
#endif

#include "libgettext.h"

const struct _msg_ent _msg_tbl[] = {
  {"", 1},
  {"Checking if %s is really the same node as %s\n", 2},
  {"Yes, their IP addresses match\n", 3},
  {"No, their IP addresses don't match\n", 4},
  {"nameserver failure while looking for `%s' during poll of %s.\n", 5},
  {"could not decode BASE64 challenge\n", 6},
  {"decoded as %s\n", 7},
  {"kerberos error %s\n", 8},
  {"krb5_sendauth: %s [server says '%*s'] \n", 9},
  {"\
Subject: Fetchmail oversized-messages warning.\r\n\
\r\n\
The following oversized messages remain on the mail server %s:", 10},
  {"\t%d msg %d octets long skipped by fetchmail.\r\n", 11},
  {"skipping message %d (%d octets)", 12},
  {" (length -1)", 13},
  {" (oversized, %d octets)", 14},
  {"couldn't fetch headers, msg %d (%d octets)", 15},
  {"reading message %d of %d", 16},
  {" (%d %soctets)", 17},
  {"header ", 18},
  {" (%d body octets) ", 19},
  {"message %d was not the expected length (%d actual != %d expected)\n", 20},
  {" retained\n", 21},
  {" flushed\n", 22},
  {" not flushed\n", 23},
  {"fetchlimit %d reached; %d messages left on server\n", 24},
  {"SIGPIPE thrown from an MDA or a stream socket error\n", 25},
  {"timeout after %d seconds waiting to connect to server %s.\n", 26},
  {"timeout after %d seconds waiting for server %s.\n", 27},
  {"timeout after %d seconds waiting for %s.\n", 28},
  {"timeout after %d seconds waiting for listener to respond.\n", 29},
  {"timeout after %d seconds.\n", 30},
  {"Subject: fetchmail sees repeated timeouts\r\n", 31},
  {"\
Fetchmail saw more than %d timeouts while attempting to get mail from \
%s@%s.\r\n", 32},
  {"\
This could mean that your mailserver is stuck, or that your SMTP\r\n\
server is wedged, or that your mailbox file on the server has been\r\n\
corrupted by a server error.  You can run `fetchmail -v -v' to\r\n\
diagnose the problem.\r\n\
\r\n\
Fetchmail won't poll this mailbox again until you restart it.\r\n", 33},
  {"pre-connection command failed with status %d\n", 34},
  {"internal inconsistency\n", 35},
  {"%s connection to %s failed", 36},
  {"host is unknown.", 37},
  {"name is valid but has no IP address.", 38},
  {"unrecoverable name server error.", 39},
  {"temporary name server error.", 40},
  {"unknown DNS error %d.", 41},
  {"\
Subject: Fetchmail unreachable-server warning.\r\n\
\r\n\
Fetchmail could not reach the mail server %s:", 42},
  {"SSL connection failed.\n", 43},
  {"Lock-busy error on %s@%s\n", 44},
  {"Server busy error on %s@%s\n", 45},
  {"Authorization failure on %s@%s%s\n", 46},
  {" (previously authorized)", 47},
  {"Subject: fetchmail authentication failed on %s@%s\r\n", 48},
  {"Fetchmail could not get mail from %s@%s.\r\n", 49},
  {"\
The attempt to get authorization failed.\r\n\
Since we have already succeeded in getting authorization for this\r\n\
connection, this is probably another failure mode (such as busy server)\r\n\
that fetchmail cannot distinguish because the server didn't send a useful\r\n\
error message.\r\n\
\r\n\
However, if you HAVE changed you account details since starting the\r\n\
fetchmail daemon, you need to stop the daemon, change your configuration\r\n\
of fetchmail, and then restart the daemon.\r\n\
\r\n\
The fetchmail daemon will continue running and attempt to connect\r\n\
at each cycle.  No future notifications will be sent until service\r\n\
is restored.", 50},
  {"\
The attempt to get authorization failed.\r\n\
This probably means your password is invalid, but some servers have\r\n\
other failure modes that fetchmail cannot distinguish from this\r\n\
because they don't send useful error messages on login failure.\r\n\
\r\n\
The fetchmail daemon will continue running and attempt to connect\r\n\
at each cycle.  No future notifications will be sent until service\r\n\
is restored.", 51},
  {"Unknown login or authentication error on %s@%s\n", 52},
  {"Authorization OK on %s@%s\n", 53},
  {"Subject: fetchmail authentication OK on %s@%s\r\n", 54},
  {"Fetchmail was able to log into %s@%s.\r\n", 55},
  {"Service has been restored.\r\n", 56},
  {"selecting or re-polling folder %s\n", 57},
  {"selecting or re-polling default folder\n", 58},
  {"%s at %s (folder %s)", 59},
  {"%s at %s", 60},
  {"Polling %s\n", 61},
  {"%d %s (%d seen) for %s", 62},
  {"messages", 63},
  {"message", 64},
  {"%d %s for %s", 65},
  {" (%d octets).\n", 66},
  {"No mail for %s\n", 67},
  {"socket", 68},
  {"missing or bad RFC822 header", 69},
  {"MDA", 70},
  {"client/server synchronization", 71},
  {"client/server protocol", 72},
  {"lock busy on server", 73},
  {"SMTP transaction", 74},
  {"DNS lookup", 75},
  {"undefined error\n", 76},
  {"%s error while delivering to SMTP host %s\n", 77},
  {"%s error while fetching from %s\n", 78},
  {"post-connection command failed with status %d\n", 79},
  {"Kerberos V4 support not linked.\n", 80},
  {"Kerberos V5 support not linked.\n", 81},
  {"Option --flush is not supported with %s\n", 82},
  {"Option --all is not supported with %s\n", 83},
  {"Option --limit is not supported with %s\n", 84},
  {"%s: You don't exist.  Go away.\n", 85},
  {"%s: can't determine your host!", 86},
  {"gethostbyname failed for %s\n", 87},
  {"Unknown system error", 88},
  {"%s (log message incomplete)", 89},
  {"partial error message buffer overflow", 90},
  {"%s's SMTP listener does not support ESMTP\n", 91},
  {"%s's SMTP listener does not support ETRN\n", 92},
  {"Queuing for %s started\n", 93},
  {"No messages waiting for %s\n", 94},
  {"Pending messages for %s started\n", 95},
  {"Unable to queue messages for node %s\n", 96},
  {"Node %s not allowed: %s\n", 97},
  {"ETRN syntax error\n", 98},
  {"ETRN syntax error in parameters\n", 99},
  {"Unknown ETRN error %d\n", 100},
  {"Option --keep is not supported with ETRN\n", 101},
  {"Option --flush is not supported with ETRN\n", 102},
  {"Option --remote is not supported with ETRN\n", 103},
  {"Option --check is not supported with ETRN\n", 104},
  {"fetchmail: invoked with", 105},
  {"This is fetchmail release %s", 106},
  {"Taking options from command line%s%s\n", 107},
  {" and ", 108},
  {"No mailservers set up -- perhaps %s is missing?\n", 109},
  {"fetchmail: no mailservers have been specified.\n", 110},
  {"fetchmail: no other fetchmail is running\n", 111},
  {"fetchmail: error killing %s fetchmail at %d; bailing out.\n", 112},
  {"background", 113},
  {"foreground", 114},
  {"fetchmail: %s fetchmail at %d killed.\n", 115},
  {"\
fetchmail: can't check mail while another fetchmail to same host is \
running.\n", 116},
  {"\
fetchmail: can't poll specified hosts with another fetchmail running at %d.\n", 117},
  {"fetchmail: another foreground fetchmail is running at %d.\n", 118},
  {"\
fetchmail: can't accept options while a background fetchmail is running.\n", 119},
  {"fetchmail: background fetchmail at %d awakened.\n", 120},
  {"fetchmail: elder sibling at %d died mysteriously.\n", 121},
  {"fetchmail: can't find a password for %s@%s.\n", 122},
  {"Enter password for %s@%s: ", 123},
  {"starting fetchmail %s daemon \n", 124},
  {"couldn't time-check %s (error %d)\n", 125},
  {"restarting fetchmail (%s changed)\n", 126},
  {"attempt to re-exec fetchmail failed\n", 127},
  {"poll of %s skipped (failed authentication or too many timeouts)\n", 128},
  {"interval not reached, not querying %s\n", 129},
  {"Query status=0 (SUCCESS)\n", 130},
  {"Query status=1 (NOMAIL)\n", 131},
  {"Query status=2 (SOCKET)\n", 132},
  {"Query status=3 (AUTHFAIL)\n", 133},
  {"Query status=4 (PROTOCOL)\n", 134},
  {"Query status=5 (SYNTAX)\n", 135},
  {"Query status=6 (IOERR)\n", 136},
  {"Query status=7 (ERROR)\n", 137},
  {"Query status=8 (EXCLUDE)\n", 138},
  {"Query status=9 (LOCKBUSY)\n", 139},
  {"Query status=10 (SMTP)\n", 140},
  {"Query status=11 (DNS)\n", 141},
  {"Query status=12 (BSMTP)\n", 142},
  {"Query status=13 (MAXFETCH)\n", 143},
  {"Query status=%d\n", 144},
  {"All connections are wedged.  Exiting.\n", 145},
  {"fetchmail: sleeping at %s\n", 146},
  {"awakened by %s\n", 147},
  {"awakened by signal %d\n", 148},
  {"awakened at %s\n", 149},
  {"normal termination, status %d\n", 150},
  {"couldn't time-check the run-control file\n", 151},
  {"Warning: multiple mentions of host %s in config file\n", 152},
  {"\
fetchmail: warning: no DNS available to check multidrop fetches from %s\n", 153},
  {"couldn't find HESIOD pobox for %s\n", 154},
  {"Lead server has no name.\n", 155},
  {"couldn't find canonical DNS name of %s\n", 156},
  {"%s configuration invalid, port number cannot be negative\n", 157},
  {"%s configuration invalid, RPOP requires a privileged port\n", 158},
  {"%s configuration invalid, LMTP can't use default SMTP port\n", 159},
  {"Both fetchall and keep on in daemon mode is a mistake!\n", 160},
  {"all mailserver name lookups failed, exiting\n", 161},
  {"terminated with signal %d\n", 162},
  {"%s querying %s (protocol %s) at %s\n", 163},
  {"POP2 support is not configured.\n", 164},
  {"POP3 support is not configured.\n", 165},
  {"IMAP support is not configured.\n", 166},
  {"ETRN support is not configured.\n", 167},
  {"Cannot support ETRN without gethostbyname(2).\n", 168},
  {"ODMR support is not configured.\n", 169},
  {"Cannot support ODMR without gethostbyname(2).\n", 170},
  {"unsupported protocol selected.\n", 171},
  {"Poll interval is %d seconds\n", 172},
  {"Logfile is %s\n", 173},
  {"Idfile is %s\n", 174},
  {"Progress messages will be logged via syslog\n", 175},
  {"Fetchmail will masquerade and will not generate Received\n", 176},
  {"Fetchmail will show progress dots even in logfiles.\n", 177},
  {"Fetchmail will forward misaddressed multidrop messages to %s.\n", 178},
  {"Fetchmail will direct error mail to the postmaster.\n", 179},
  {"Fetchmail will direct error mail to the sender.\n", 180},
  {"Options for retrieving from %s@%s:\n", 181},
  {"  Mail will be retrieved via %s\n", 182},
  {"  Poll of this server will occur every %d intervals.\n", 183},
  {"  True name of server is %s.\n", 184},
  {"  This host %s be queried when no host is specified.\n", 185},
  {"will not", 186},
  {"will", 187},
  {"  Password will be prompted for.\n", 188},
  {"  APOP secret = \"%s\".\n", 189},
  {"  RPOP id = \"%s\".\n", 190},
  {"  Password = \"%s\".\n", 191},
  {"  Protocol is KPOP with Kerberos %s authentication", 192},
  {"  Protocol is %s", 193},
  {" (using service %s)", 194},
  {" (using network security options %s)", 195},
  {" (using port %d)", 196},
  {" (using default port)", 197},
  {" (forcing UIDL use)", 198},
  {"  All available authentication methods will be tried.\n", 199},
  {"  Password authentication will be forced.\n", 200},
  {"  NTLM authentication will be forced.\n", 201},
  {"  OTP authentication will be forced.\n", 202},
  {"  CRAM-Md5 authentication will be forced.\n", 203},
  {"  GSSAPI authentication will be forced.\n", 204},
  {"  Kerberos V4 authentication will be forced.\n", 205},
  {"  Kerberos V5 authentication will be forced.\n", 206},
  {"  End-to-end encryption assumed.\n", 207},
  {"  Mail service principal is: %s\n", 208},
  {"  SSL encrypted sessions enabled.\n", 209},
  {"  SSL server certificate checking enabled.\n", 210},
  {"  SSL trusted certificate directory: %s\n", 211},
  {"  SSL key fingerprint (checked against the server key): %s\n", 212},
  {"  Server nonresponse timeout is %d seconds", 213},
  {" (default).\n", 214},
  {"  Default mailbox selected.\n", 215},
  {"  Selected mailboxes are:", 216},
  {"  %s messages will be retrieved (--all %s).\n", 217},
  {"All", 218},
  {"Only new", 219},
  {"  Fetched messages %s be kept on the server (--keep %s).\n", 220},
  {"  Old messages %s be flushed before message retrieval (--flush %s).\n", 221},
  {"  Rewrite of server-local addresses is %s (--norewrite %s).\n", 222},
  {"enabled", 223},
  {"disabled", 224},
  {"  Carriage-return stripping is %s (stripcr %s).\n", 225},
  {"  Carriage-return forcing is %s (forcecr %s).\n", 226},
  {"  Interpretation of Content-Transfer-Encoding is %s (pass8bits %s).\n", 227},
  {"  MIME decoding is %s (mimedecode %s).\n", 228},
  {"  Idle after poll is %s (idle %s).\n", 229},
  {"  Nonempty Status lines will be %s (dropstatus %s)\n", 230},
  {"discarded", 231},
  {"kept", 232},
  {"  Delivered-To lines will be %s (dropdelivered %s)\n", 233},
  {"  Message size limit is %d octets (--limit %d).\n", 234},
  {"  No message size limit (--limit 0).\n", 235},
  {"  Message size warning interval is %d seconds (--warnings %d).\n", 236},
  {"  Size warnings on every poll (--warnings 0).\n", 237},
  {"  Received-message limit is %d (--fetchlimit %d).\n", 238},
  {"  No received-message limit (--fetchlimit 0).\n", 239},
  {"  SMTP message batch limit is %d.\n", 240},
  {"  No SMTP message batch limit (--batchlimit 0).\n", 241},
  {"  Deletion interval between expunges forced to %d (--expunge %d).\n", 242},
  {"  No forced expunges (--expunge 0).\n", 243},
  {"  Domains for which mail will be fetched are:", 244},
  {" (default)", 245},
  {"  Messages will be appended to %s as BSMTP\n", 246},
  {"  Messages will be delivered with \"%s\".\n", 247},
  {"  Messages will be %cMTP-forwarded to:", 248},
  {"  Host part of MAIL FROM line will be %s\n", 249},
  {"  Address to be put in RCPT TO lines shipped to SMTP will be %s\n", 250},
  {"  Recognized listener spam block responses are:", 251},
  {"  Spam-blocking disabled\n", 252},
  {"  Server connection will be brought up with \"%s\".\n", 253},
  {"  No pre-connection command.\n", 254},
  {"  Server connection will be taken down with \"%s\".\n", 255},
  {"  No post-connection command.\n", 256},
  {"  No localnames declared for this host.\n", 257},
  {"  Multi-drop mode: ", 258},
  {"  Single-drop mode: ", 259},
  {"%d local name(s) recognized.\n", 260},
  {"  DNS lookup for multidrop addresses is %s.\n", 261},
  {"  Server aliases will be compared with multidrop addresses by ", 262},
  {"IP address.\n", 263},
  {"name.\n", 264},
  {"  Envelope-address routing is disabled\n", 265},
  {"  Envelope header is assumed to be: %s\n", 266},
  {"Received", 267},
  {"  Number of envelope header to be parsed: %d\n", 268},
  {"  Prefix %s will be removed from user id\n", 269},
  {"  No prefix stripping\n", 270},
  {"  Predeclared mailserver aliases:", 271},
  {"  Local domains:", 272},
  {"  Connection must be through interface %s.\n", 273},
  {"  No interface requirement specified.\n", 274},
  {"  Polling loop will monitor %s.\n", 275},
  {"  No monitor interface specified.\n", 276},
  {"  Server connections will be made via plugin %s (--plugin %s).\n", 277},
  {"  No plugin command specified.\n", 278},
  {"  Listener connections will be made via plugout %s (--plugout %s).\n", 279},
  {"  No plugout command specified.\n", 280},
  {"  No UIDs saved from this host.\n", 281},
  {"  %d UIDs saved.\n", 282},
  {"  Poll trace information will be added to the Received header.\n", 283},
  {"\
  No poll trace information will be added to the Received header.\n\
.\n", 284},
  {"  Pass-through properties \"%s\".\n", 285},
  {"alloca failed", 286},
  {"ERROR: no support for getpassword() routine\n", 287},
  {"\
\n\
Caught SIGINT... bailing out.\n", 288},
  {"Couldn't get service name for [%s]\n", 289},
  {"Using service name [%s]\n", 290},
  {"Sending credentials\n", 291},
  {"Error exchanging credentials\n", 292},
  {"Couldn't unwrap security level data\n", 293},
  {"Credential exchange complete\n", 294},
  {"Server requires integrity and/or privacy\n", 295},
  {"Unwrapped security level flags: %s%s%s\n", 296},
  {"Maximum GSS token size is %ld\n", 297},
  {"Error creating security level request\n", 298},
  {"Releasing GSS credentials\n", 299},
  {"Error releasing credentials\n", 300},
  {"fetchmail: thread sleeping for %d sec.\n", 301},
  {"Protocol identified as IMAP4 rev 1\n", 302},
  {"Protocol identified as IMAP4 rev 0\n", 303},
  {"Protocol identified as IMAP2 or IMAP2BIS\n", 304},
  {"will idle after poll\n", 305},
  {"Required OTP capability not compiled into fetchmail\n", 306},
  {"Required NTLM capability not compiled into fetchmail\n", 307},
  {"Required LOGIN capability not supported by server\n", 308},
  {"re-poll failed\n", 309},
  {"%d messages waiting after re-poll\n", 310},
  {"mailbox selection failed\n", 311},
  {"%d messages waiting after first poll\n", 312},
  {"search for unseen messages failed\n", 313},
  {"%u is unseen\n", 314},
  {"Unable to open kvm interface. Make sure fetchmail is SGID kmem.", 315},
  {"Unable to parse interface name from %s", 316},
  {"get_ifinfo: sysctl (iflist estimate) failed", 317},
  {"get_ifinfo: malloc failed", 318},
  {"get_ifinfo: sysctl (iflist) failed", 319},
  {"Routing message version %d not understood.", 320},
  {"No interface found with name %s", 321},
  {"No IP address found for %s", 322},
  {"missing IP interface address\n", 323},
  {"invalid IP interface address\n", 324},
  {"invalid IP interface mask\n", 325},
  {"activity on %s -noted- as %d\n", 326},
  {"skipping poll of %s, %s down\n", 327},
  {"skipping poll of %s, %s IP address excluded\n", 328},
  {"activity on %s checked as %d\n", 329},
  {"skipping poll of %s, %s inactive\n", 330},
  {"activity on %s was %d, is %d\n", 331},
  {"could not decode initial BASE64 challenge\n", 332},
  {"principal %s in ticket does not match -u %s\n", 333},
  {"non-null instance (%s) might cause strange behavior\n", 334},
  {"could not decode BASE64 ready response\n", 335},
  {"challenge mismatch\n", 336},
  {"fetchmail: removing stale lockfile\n", 337},
  {"fetchmail: lock creation failed.\n", 338},
  {"warning: found \"%s\" before any host names", 339},
  {"%s:%d: warning: found \"%s\" before any host names\n", 340},
  {"%s:%d: warning: unknown token \"%s\"\n", 341},
  {"%s's SMTP listener does not support ATRN\n", 342},
  {"Turnaround now...\n", 343},
  {"ATRN request refused.\n", 344},
  {"Unable to process ATRN request now\n", 345},
  {"You have no mail.\n", 346},
  {"Command not implemented\n", 347},
  {"Authentication required.\n", 348},
  {"Unknown ODMR error %d\n", 349},
  {"Option --keep is not supported with ODMR\n", 350},
  {"Option --flush is not supported with ODMR\n", 351},
  {"Option --remote is not supported with ODMR\n", 352},
  {"Option --check is not supported with ODMR\n", 353},
  {"Could not decode initial BASE64 challenge\n", 354},
  {"Could not decode OTP challenge\n", 355},
  {"Secret pass phrase: ", 356},
  {"String '%s' is not a valid number string.\n", 357},
  {"Value of string '%s' is %s than %d.\n", 358},
  {"smaller", 359},
  {"larger", 360},
  {"Invalid protocol `%s' specified.\n", 361},
  {"Invalid authentication `%s' specified.\n", 362},
  {"fetchmail: network security support is disabled\n", 363},
  {"usage:  fetchmail [options] [server ...]\n", 364},
  {"  Options are as follows:\n", 365},
  {"  -?, --help        display this option help\n", 366},
  {"  -V, --version     display version info\n", 367},
  {"  -c, --check       check for messages without fetching\n", 368},
  {"  -s, --silent      work silently\n", 369},
  {"  -v, --verbose     work noisily (diagnostic output)\n", 370},
  {"  -d, --daemon      run as a daemon once per n seconds\n", 371},
  {"  -N, --nodetach    don't detach daemon process\n", 372},
  {"  -q, --quit        kill daemon process\n", 373},
  {"  -L, --logfile     specify logfile name\n", 374},
  {"\
      --syslog      use syslog(3) for most messages when running as a \
daemon\n", 375},
  {"      --invisible   don't write Received & enable host spoofing\n", 376},
  {"  -f, --fetchmailrc specify alternate run control file\n", 377},
  {"  -i, --idfile      specify alternate UIDs file\n", 378},
  {"      --postmaster  specify recipient of last resort\n", 379},
  {"      --nobounce    redirect bounces from user to postmaster.\n", 380},
  {"  -I, --interface   interface required specification\n", 381},
  {"  -M, --monitor     monitor interface for activity\n", 382},
  {"      --ssl         enable ssl encrypted session\n", 383},
  {"      --sslkey      ssl private key file\n", 384},
  {"      --sslcert     ssl client certificate\n", 385},
  {"      --sslproto    force ssl protocol (ssl2/ssl3/tls1)\n", 386},
  {"      --plugin      specify external command to open connection\n", 387},
  {"      --plugout     specify external command to open smtp connection\n", 388},
  {"  -p, --protocol    specify retrieval protocol (see man page)\n", 389},
  {"  -U, --uidl        force the use of UIDLs (pop3 only)\n", 390},
  {"  -P, --port        TCP/IP service port to connect to\n", 391},
  {"      --auth        authentication type (password/kerberos/ssh)\n", 392},
  {"  -t, --timeout     server nonresponse timeout\n", 393},
  {"  -E, --envelope    envelope address header\n", 394},
  {"  -Q, --qvirtual    prefix to remove from local user id\n", 395},
  {"      --principal   mail service principal\n", 396},
  {"      --tracepolls  add poll-tracing information to Received header\n", 397},
  {"  -u, --username    specify users's login on server\n", 398},
  {"  -a, --all         retrieve old and new messages\n", 399},
  {"  -K, --nokeep      delete new messages after retrieval\n", 400},
  {"  -k, --keep        save new messages after retrieval\n", 401},
  {"  -F, --flush       delete old messages from server\n", 402},
  {"  -n, --norewrite   don't rewrite header addresses\n", 403},
  {"  -l, --limit       don't fetch messages over given size\n", 404},
  {"  -w, --warnings    interval between warning mail notification\n", 405},
  {"  -T, --netsec      set IP security request\n", 406},
  {"  -S, --smtphost    set SMTP forwarding host\n", 407},
  {"      --fetchdomains fetch mail for specified domains\n", 408},
  {"  -D, --smtpaddress set SMTP delivery domain to use\n", 409},
  {"      --smtpname    set SMTP full name username@domain\n", 410},
  {"  -Z, --antispam,   set antispam response values\n", 411},
  {"  -b, --batchlimit  set batch limit for SMTP connections\n", 412},
  {"  -B, --fetchlimit  set fetch limit for server connections\n", 413},
  {"  -e, --expunge     set max deletions between expunges\n", 414},
  {"  -m, --mda         set MDA to use for forwarding\n", 415},
  {"      --bsmtp       set output BSMTP file\n", 416},
  {"      --lmtp        use LMTP (RFC2033) for delivery\n", 417},
  {"  -r, --folder      specify remote folder name\n", 418},
  {"      --showdots    show progress dots even in logfiles\n", 419},
  {"Required APOP timestamp not found in greeting\n", 420},
  {"Timestamp syntax error in greeting\n", 421},
  {"Undefined protocol request in POP3_auth\n", 422},
  {"lock busy!  Is another session active?\n", 423},
  {"Messages inserted into list on server. Cannot handle this.\n", 424},
  {"protocol error\n", 425},
  {"protocol error while fetching UIDLs\n", 426},
  {"Option --remote is not supported with POP3\n", 427},
  {"server option after user options", 428},
  {"SDPS not enabled.", 429},
  {"invalid security request", 430},
  {"network-security support disabled", 431},
  {"\
fetchmail: interface option is only supported under Linux (without IPv6) and \
FreeBSD\n", 432},
  {"\
fetchmail: monitor option is only supported under Linux (without IPv6) and \
FreeBSD\n", 433},
  {"end of input", 434},
  {"File %s must not be a symbolic link.\n", 435},
  {"File %s must have no more than -rwx--x--- (0710) permissions.\n", 436},
  {"File %s must be owned by you.\n", 437},
  {"About to rewrite %s", 438},
  {"Rewritten version is %s\n", 439},
  {"Success", 440},
  {"Restricted user (something wrong with account)", 441},
  {"Invalid userid or passphrase", 442},
  {"Deity error", 443},
  {"RPA token 2: Base64 decode error\n", 444},
  {"Service chose RPA version %d.%d\n", 445},
  {"Service challenge (l=%d):\n", 446},
  {"Service timestamp %s\n", 447},
  {"RPA token 2 length error\n", 448},
  {"Realm list: %s\n", 449},
  {"RPA error in service@realm string\n", 450},
  {"RPA token 4: Base64 decode error\n", 451},
  {"User authentication (l=%d):\n", 452},
  {"RPA status: %02X\n", 453},
  {"RPA token 4 length error\n", 454},
  {"RPA rejects you: %s\n", 455},
  {"RPA rejects you, reason unknown\n", 456},
  {"RPA User Authentication length error: %d\n", 457},
  {"RPA Session key length error: %d\n", 458},
  {"RPA _service_ auth fail. Spoof server?\n", 459},
  {"Session key established:\n", 460},
  {"RPA authorisation complete\n", 461},
  {"Get response\n", 462},
  {"Get response return %d [%s]\n", 463},
  {"Hdr not 60\n", 464},
  {"Token length error\n", 465},
  {"Token Length %d disagrees with rxlen %d\n", 466},
  {"Mechanism field incorrect\n", 467},
  {"dec64 error at char %d: %x\n", 468},
  {"Inbound binary data:\n", 469},
  {"Outbound data:\n", 470},
  {"RPA String too long\n", 471},
  {"Unicode:\n", 472},
  {"RPA Failed open of /dev/urandom. This shouldn't\n", 473},
  {"    prevent you logging in, but means you\n", 474},
  {"    cannot be sure you are talking to the\n", 475},
  {"    service that you think you are (replay\n", 476},
  {"    attacks by a dishonest service are possible.)\n", 477},
  {"User challenge:\n", 478},
  {"MD5 being applied to data block:\n", 479},
  {"MD5 result is: \n", 480},
  {"forwarding to %s\n", 481},
  {"SMTP: (bounce-message body)\n", 482},
  {"mail from %s bounced to %s\n", 483},
  {"Saved error is still %d\n", 484},
  {"%cMTP error: %s\n", 485},
  {"BSMTP file open or preamble write failed\n", 486},
  {"%cMTP listener doesn't like recipient address `%s'\n", 487},
  {"no address matches; no postmaster set.\n", 488},
  {"can't even send to %s!\n", 489},
  {"no address matches; forwarding to %s.\n", 490},
  {"%cMTP connect to %s failed\n", 491},
  {"can't raise the listener; falling back to %s", 492},
  {"about to deliver with: %s\n", 493},
  {"MDA open failed\n", 494},
  {"MDA returned nonzero status %d\n", 495},
  {"Message termination or close of BSMTP file failed\n", 496},
  {"SMTP listener refused delivery\n", 497},
  {"LMTP delivery error on EOM\n", 498},
  {"Unexpected non-503 response to LMTP EOM: %s\n", 499},
  {"\
--\r\n\
\t\t\t\tThe Fetchmail Daemon\r\n", 500},
  {"fetchmail: malloc failed\n", 501},
  {"fetchmail: socketpair failed\n", 502},
  {"fetchmail: fork failed\n", 503},
  {"dup2 failed\n", 504},
  {"running %s (host %s service %s)\n", 505},
  {"execvp(%s) failed\n", 506},
  {"fetchmail: getaddrinfo(%s.%s)\n", 507},
  {"fetchmail: illegal address length received for host %s\n", 508},
  {"Issuer Organization: %s\n", 509},
  {"Warning: Issuer Organization Name too long (possibly truncated).\n", 510},
  {"Unknown Organization\n", 511},
  {"Issuer CommonName: %s\n", 512},
  {"Warning: Issuer CommonName too long (possibly truncated).\n", 513},
  {"Unknown Issuer CommonName\n", 514},
  {"Server CommonName: %s\n", 515},
  {"Bad certificate: Subject CommonName too long!\n", 516},
  {"Server CommonName mismatch: %s != %s\n", 517},
  {"Server name not set, could not verify certificate!\n", 518},
  {"Unknown Server CommonName\n", 519},
  {"Server name not specified in certificate!\n", 520},
  {"EVP_md5() failed!\n", 521},
  {"Out of memory!\n", 522},
  {"Digest text buffer too small!\n", 523},
  {"%s key fingerprint: %s\n", 524},
  {"%s fingerprints match.\n", 525},
  {"%s fingerprints do not match!\n", 526},
  {"Warning: server certificate verification: %s\n", 527},
  {"unknown issuer (first %d characters): %s\n", 528},
  {"File descriptor out of range for SSL", 529},
  {"Invalid SSL protocol '%s' specified, using default (SSLv23).\n", 530},
  {"Certificate/fingerprint verification was somehow skipped!\n", 531},
  {"mapped %s to local %s\n", 532},
  {"passed through %s matching %s\n", 533},
  {"\
analyzing Received line:\n\
%s", 534},
  {"line accepted, %s is an alias of the mailserver\n", 535},
  {"line rejected, %s is not an alias of the mailserver\n", 536},
  {"no Received address found\n", 537},
  {"found Received address `%s'\n", 538},
  {"message delimiter found while scanning headers\n", 539},
  {"no local matches, forwarding to %s\n", 540},
  {"forwarding and deletion suppressed due to DNS errors\n", 541},
  {"writing RFC822 msgblk.headers\n", 542},
  {"no recipient addresses matched declared local names", 543},
  {"recipient address %s didn't match any local name", 544},
  {"message has embedded NULs", 545},
  {"SMTP listener rejected local recipient addresses: ", 546},
  {"writing message text\n", 547},
  {"lstat: %s: %s\n", 548},
  {"Old UID list from %s:", 549},
  {" <empty>", 550},
  {"Scratch list of UIDs:", 551},
  {"New UID list from %s:", 552},
  {"swapping UID lists\n", 553},
  {"not swapping UID lists, no UIDs seen this query\n", 554},
  {"Deleting fetchids file.\n", 555},
  {"Writing fetchids file.\n", 556},
  {"malloc failed\n", 557},
  {"realloc failed\n", 558},
};

int _msg_tbl_length = 558;
