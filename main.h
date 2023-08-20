#ifndef main_h
#define main_h
#include <stdio.h>
#include <stdarg.h>
void _p_buffer(char buff[], int *buf_ind);
int h_print(const char *format, int *b, va_list ap, char buff[], int flags, int wdth, int p, int size);
int get_width(const char *format, int *b, va_list ap);
int get_flags(const char *format, int *b);
int get_precision(const char *format, int *b, va_list ap);
int get_size(const char *format, int *b);
int _printf(const char *format, ...);
int _putchar(char c);
#endif
