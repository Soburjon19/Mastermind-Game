#ifndef MY_HEADERS_H
#define MY_HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

#define COLOR_RED     "\x1b[31m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_RESET   "\x1b[37m"

char *check_c_opt(int argc, char *argv[], char* charSec);
int check_t_opt(int argc, char *argv[]);
bool my_guess_check(char *charSec, char *guess);
char *my_guess_reader(char *guess, char *my_buf);
bool my_strcmp(char* param_1, char* param_2);
int my_strlen(char* param_1);
char* my_strcpy(char* param_1, char* param_2);
bool my_strchr(char* param_1, char param_2);
bool my_duplchr(char* param_1, char param_2);
bool my_strint(int* param_1, int param_2);
int *my_secretcode(int* secret_code);
char* my_itoa(char* charSec, int *secret_code);
bool valid_length(char *charSec);
bool code_validator(char *charSec);
char *my_emptystr(char* param);

#endif