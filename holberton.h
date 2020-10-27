#ifndef PRINTF
#define PRINTF

#define BIT_SIZE 8

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/*printer functions*/
int _putchar(va_list);
int _putstr(va_list);
int _putint(va_list);
int _putuint(va_list);
int _putbin(va_list);
int _puthex(va_list);
int _putoct(va_list);
int _putHex(va_list);
int _putadress(va_list);

/*printf and its helpers*/
int _printf(const char *format, ...);
int _printf_rec(const char *format, va_list list);
int *print(int (*)(va_list), va_list list, const char *);
int find(const char *, char);

/*printer identifier*/
int (*get_printer(char id))(va_list);

/*num_utils*/
int _pow(unsigned int, int);
int _numLen(unsigned int);

/*string utils*/
int _strlen(char *);
void rev_string(char *);
int _printstr(char *);
void _toStr(unsigned int, char *);




#endif /*PINTF*/

