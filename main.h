#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_str(char *str);
int print_number(int n);
int print_conversion(char specifier, va_list args);

#endif /* MAIN_H */
