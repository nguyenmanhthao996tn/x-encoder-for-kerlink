#include <stdio.h>
#include <stdint.h>
#include "app_types.h"
#include "app_help.h"
#include "app.h"

int main(int argc, char *argv[])
{
  // Debugging input params
  // printf("argc = %d\n", argc);
  // for (int i = 0; i < argc; i++)
  // {
  //   printf("argv[%d] = %s\n", i, argv[i]);
  // }

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
    break;
    default:
    break;
  }
  
  return 0;
}