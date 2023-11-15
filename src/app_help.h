#ifndef __APP_HELP_H__
#define __APP_HELP_H__

static const char* app_help_text = "\
Usage: xen [OPTION] SOURCE DEST\n\
\n\
Encode / Decode a text file from SOURCE to DEST.\n\
\n\
Mandatory arguments to long options are mandatory for short options too.\n\
  -e, --encrypt     Encrypt text file\n\
  -d, --decrypt     Decrypt text file\n\
  -h, --help        Print this help\n\
  -v, --version     Get version of this software\n\
\n\
Exit status:\n\
  0    if OK,\n\
  1    if error,\n\
";

void print_help(void);

#endif /* __APP_HELP_H__ */
