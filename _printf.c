#include "holberton.h"

/**
 * _printf - a function that prints anything using
 *           posix callex via the write function
 * @format: formated string to be printed
 * Return: the number of things printed
 */
int _printf(const char *format, ...)
{

	va_list items;
	int size;

	va_start(items, format);
	size = _printf_rec(format, items);
	va_end(items);
	if (size < 0)
		return (-1);
	return (size);

}
/**
 *find - returns the index of the first apearing patter in s
 *@s: string
 *@pattern: pattern to look for
 *Return: the index of pattern in s or the length of s if pattern not found
 */
int find(const char *s, char pattern)
{
	int i = 0;

	while (*(s + i))
	{
		if (*(s + i) == pattern)
			break;
		i++;
	}
	return (i);
}

/**
 *print - prints an element inside a va_list using
 *  a printer function that is passed as an argment based on a formated string
 *  the formated string will be used to identify what to print in case no print
 *  funciton is passed
 *@printer:  pointer to pritner functuion
 *@list: va_list containing the item to be printed
 *@format:  a formated string that starts with % followed by a possible
 *        identifier character
 *Return: an array containing the length of the string printed and the number
 *of items reolaced in the formated string in case of success and
 *an array containign -1 in case of failure
 */
int *print(int (*printer)(va_list), va_list list, const char *format)
{
	int buff;
	int *arr = malloc(sizeof(int) * 2);
	/*
	 *arr[0] -> the characters printed instead of the formated characters
	 *arr[1] ->  the characters replaced from the fromated string
	 */
	if (printer)
	{
		buff = printer(list);
		if (buff == -1)
			arr[0] = -1, arr[1] = -1;

		arr[0] = buff;
		/*if printer was successful '%(id)' is repaced*/
		arr[1] = 2;
	}
	else
	{
		/*one of the cases a printer might be null is if we are trying to print %%*/
		if (*(format + 1) == '%')
		{
			if (write(1, &("%"), 1) == -1)
				arr[0] = -1, arr[1] = -1;

			arr[0] = 1;
		}
		else
		{
			if (write(1, (format), 2) == -1)
				arr[0] = -1, arr[1] = -1;
			arr[0] = 2;
		}
		arr[1] = 2;
	}
	return (arr);

}
/**
 * _printf_rec - prints in a recursive manner calling
 *               itself when finding a format identifer
 * @format: format string
 * @list: a varadic list containing
 *        elements to be printed in place of the format identifers
 * Return: returns the number of characters that has been printed
 */
int _printf_rec(const char *format, va_list list)
{
	int i = 0, len = 0, (*printer)(va_list), *presult;

	if (!*format)
		return (0);

	i = find(format, '%');
	len = write(1, format, i);
	if (len == -1)
		return (-2147483648);
	if (*(format + i))
	{
		printer = get_printer(*(format + i + 1));
		presult = print(printer, list, format + i);

		if (presult[0] == -1 && presult[1] == -1)
			return (-2147483648);
		len += presult[0];
		i += presult[1];

		free(presult);

	}

	return (len + _printf_rec(format + i, list));
}
