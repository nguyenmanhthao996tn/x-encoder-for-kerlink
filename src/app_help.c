#include "app_help.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

extern const char* app_help_text;

void print_help(void)
{
  printf("%s\n", app_help_text);
}
