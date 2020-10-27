#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
#include <unistd.h>

int putchar(va_list);
int putstr(va_list);
int (*get_printer(char ))(va_list);
int _printf(const char *format, ...);

#endif /*HOLBERTON_H*/
