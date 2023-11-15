#include "app_types.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

app_type_t get_app_type(int argc, char *argv[])
{
  switch (argc)
  {
    case 1:
      return TYPE_PRINT_HELP;
    break;
    case 2:
      if ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0))
      {
        return TYPE_PRINT_HELP;
      }
      else if ((strcmp(argv[1], "-v") == 0) || (strcmp(argv[1], "--version") == 0))
      {
        return TYPE_VERSION;
      }
      else
      {
        return TYPE_UNKNOWN;
      }
    break;
    case 4:
      if ((strcmp(argv[1], "-e") == 0) || (strcmp(argv[1], "--encrypt") == 0))
      {
        return TYPE_ENCRYPT;
      }
      else if ((strcmp(argv[1], "-d") == 0) || (strcmp(argv[1], "--decrypt") == 0))
      {
        return TYPE_DECRYPT;
      }
      else
      {
        return TYPE_UNKNOWN;
      }
    break;
    default:
      return TYPE_UNKNOWN;
    break;
  }
}