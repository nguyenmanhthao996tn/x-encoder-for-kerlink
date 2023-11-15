#include "app.h"
#include "key.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

extern const char* key;
static int key_size;

int encrypt(char* input_file_path, char* output_file_path)
{
  key_size = (sizeof(key)/sizeof(key[0])) - 1;

  FILE* input_ptr = fopen(input_file_path, "r");
  if (NULL == input_ptr) {
    printf("Execution ERROR: Cannot open SOURCE file\n");
    return 1;
  }

  FILE* output_ptr = fopen(output_file_path, "w");
  if (NULL == output_ptr) {
    printf("Execution ERROR: Cannot open DEST file\n");
    return 1;
  }

  int counter = 0; // Counter for overflow
  char ch;

  // Get file size
  for (;;)
  {
    ch = fgetc(input_ptr);
    if ((ch == -1) || (ch == 255)) // EOF, for cross compilation
    {
      break;
    }
    else
    {
      counter++;
    }

    if (counter > (2*1024*1024)) // Upper limit is 2Mb
    {
      fclose(input_ptr);
      fclose(output_ptr);

      printf("Execution ERROR: Input file larger than 2Mb.");
      return 1;
    }
  }

  // Re-open input file
  fclose(input_ptr);
  input_ptr = fopen(input_file_path, "r");
  if (NULL == input_ptr) {
    printf("Execution ERROR: Cannot re-open SOURCE file\n");
    return 1;
  }

  // Write file size to the top of output file to avoid unintentional EOF
  char buffer[255] = { 0 };
  snprintf(buffer, 255, "%d\n", counter);
  fwrite(buffer, 1, (strlen(buffer)), output_ptr);

  // Do the encoding
  for (int i = 0; i < counter; i++)
  {
    ch = fgetc(input_ptr);
    buffer[0] = xor_r255(ch, key[counter % key_size]);
    fwrite(buffer, 1, 1, output_ptr);
  }

  fclose(input_ptr);
  fclose(output_ptr);

  return 0;
}

int decrypt(char* input_file_path, char* output_file_path)
{
  key_size = (sizeof(key)/sizeof(key[0])) - 1;

  FILE* input_ptr = fopen(input_file_path, "r");
  if (NULL == input_ptr) {
    printf("Execution ERROR: Cannot open SOURCE file\n");
    return 1;
  }

  FILE* output_ptr = fopen(output_file_path, "w");
  if (NULL == output_ptr) {
    printf("Execution ERROR: Cannot open DEST file\n");
    return 1;
  }

  int counter = 0; // Counter for overflow
  char ch;

  // Get file size
  char filesize_buffer[32] = { 0 };
  int filesize = 0;
  for (;;)
  {
    ch = fgetc(input_ptr);
    if (ch != '\n')
    {
      filesize_buffer[counter] = ch;
    }
    else
    {
      filesize = atoi(filesize_buffer);
      break;
    }
    counter++;

    if (counter > (2*1024*1024)) // Upper limit is 2Mb
    {
      fclose(input_ptr);
      fclose(output_ptr);

      printf("Execution ERROR: Input file larger than 2Mb.");
      return 1;
    }
  }

  // Do the decoding
  for (int i = 0; i < filesize; i++)
  {
    ch = fgetc(input_ptr);
    char buffer[0];
    buffer[0] = xor_r255(ch, key[filesize % key_size]);
    fwrite(buffer, 1, 1, output_ptr);
  }

  fclose(input_ptr);
  fclose(output_ptr);

  return 0;
}

char xor_r255(char a, char b)
{
  return (a ^ b);
}