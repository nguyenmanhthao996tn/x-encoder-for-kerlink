#include "app_version.h"
#include <stdio.h>

void print_version(void)
{
  char version_buffer[64] = { 0 };
  snprintf(version_buffer, 64, "%d.%d.%d", SOFTWARE_VERSION_MAJOR, SOFTWARE_VERSION_MINOR, SOFTWARE_VERSION_PATCH);
  
  printf("xen version %s\n", version_buffer);
  printf("\n");
  printf("Copyright (C) 2023 mtnguyen@leat\n");
  printf("This is free software: you are free to change and redistribute it.\n");
  printf("There is NO WARRANTY, to the extent permitted by law.\n");
}
