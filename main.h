#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define BUFF_SIZE 1024

int _printf(const char *format, ...);
int print_char(char c);
int print_str(char *str);
int print_int(va_list types, char buffer)
#endif /* MAIN_H */
