#ifndef __APP_H__
#define __APP_H__

#include <stdio.h>
#include <stdint.h>

int encrypt(char* input_file_path, char* output_file_path);
int decrypt(char* input_file_path, char* output_file_path);
char xor_r255(char a, char b);

#endif /* __APP_H__ */