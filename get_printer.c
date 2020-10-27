#include "holberton.h"
/**
*get_printer - returns the correct type of printer function based on a delieter
*@id: a delimeter
*Return: a function pointer,
*
*/
int (*get_printer(char id))(va_list)
{

	int (*printer)(va_list);

	switch (id)
	{
		case 'c':
			printer = _putchar;
			break;

		case 's':
			printer = _putstr;
			break;

		case 'd':
			printer = _putint;
			break;

		case 'i':
			printer = _putint;
			break;

		case 'u':
			printer = _putuint;
			break;

		case 'b':
			printer = _putbin;
			break;
		case 'o':
			printer = _putoct;
			break;

		case 'x':
			printer = _puthex;
			break;

		case 'X':
			printer = _putHex;
			break;

		case 'p':
			printer = _putadress;
			break;

		default:
			printer = NULL;
			break;
	}

	return (printer);
}
