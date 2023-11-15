#include <stdio.h>
#include <stdint.h>
#include "app_types.h"
#include "app_help.h"
#include "app_version.h"
#include "app.h"

int main(int argc, char *argv[])
{
  switch (get_app_type(argc, argv))
  {
    case TYPE_UNKNOWN:
      printf("Execution ERROR: Check your params.\n");
      return 1;
    break;
    case TYPE_ENCRYPT:
      return encrypt(argv[2], argv[3]);
    break;
    case TYPE_DECRYPT:
      return decrypt(argv[2], argv[3]);
    break;
    case TYPE_PRINT_HELP:
      print_help();
      return 0;
    case TYPE_VERSION:
      print_version();
      return 0;
    break;
    break;
    default:
    break;
  }
  
  return 0;
}