#include "holberton.h"
/**
 * _putrts - reverses string inside a va_list
 * @list: the variadic list to extract it from
 * @format: the format to use to prepare it
 * Return: a character pointer to the reversed string
 */
char *_putrts(va_list list, __attribute__((unused)) printing_format * format)
{
	char *s = va_arg(list, char *);
	char *s2 = malloc(sizeof(char) * _strlen(s) + 1);

	if (!s2)
		return (NULL);

	rev_string(s);
	_strcpy(s2, s);
	return (s2);

}
/**
 * _putrot13 - a rot13 encrypted string from the va_list
 *@list: the variadic list to extract it from
 *@format: the format to use to prepare it
 *Return: a character pointer to the the encrypted string
 */
char *_putrot13(va_list list, __attribute__((unused)) printing_format * format)
{

	char *s = va_arg(list, char *);
	char *s2 = malloc(sizeof(char) * _strlen(s) + 1);

	if (!s2)
		return (NULL);

	_strcpy(s2, rot13(s));
	return (s2);

}
/**
 * print_bigS - Non printable characters
 * (0 < ASCII value < 32 or >= 127) are
 * printed this way: \x, followed by the ASCII code
 * value in hexadecimal (upper case - always 2 characters)
 * @l: va_list arguments from _printf
 * @format: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
char *_putS(va_list l, __attribute__((unused)) printing_format * format)
{
	char *s1, *s2, *s = va_arg(l, char *);
	int n, tmp;

	if (!s)
		return (NULL);
	s2 = malloc(sizeof(char) * _strlen(s) * 4 + 1);
	if(!s2)
		return (NULL);
	s1 = s2;
	while(*s)
	{
		n = *s;
		if ((n > 0 && n < 32) || n >= 127)
		{
			*s1 = '\\';
			*(s1 + 1) = 'x';
			s1 += 2;
			if(n < 16)
			{
				*s1 = '0';
				s1++;
			}
			while (n != 0)
			{
				tmp = n % 16;

				if (tmp < 10)
					*s1 = tmp + 48;
				else
					*s1 = tmp + 55;
				n = n / 16;
				s1++;
			}

		}
		else
		{
			*s1 = *s;
			s1++;
		}
		s++;
	}
	s1 = '\0';
	return (s2);
}
