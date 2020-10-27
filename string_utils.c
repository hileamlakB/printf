#include "holberton.h"



/**
 * _strlen - returns the length of a string
 * @s: string s
 * Return: length of string
 */
int _strlen(char *s)
{

	int length = 0;

	while (*s)
	{
		s++;
		length++;
	}
	return (length);
}

/**
 * rev_string - reverses a string
 * @s: string to be reversed
 */
void rev_string(char *s)
{
	int length = _strlen(s);
	int counter = 0;
	char tmp;

	while (counter < length / 2)
	{
		tmp = *(s + counter);
		*(s + counter) = *(s + length - 1 - counter);
		*(s + length - 1 - counter) = tmp;
		counter++;
	}

}


/**
 * _toStr - changes an int to a a string and saves it in nums
 * @n:num
* @nums:pointer to store the number
*/
void _toStr(unsigned int n, char *nums)
{
	if (n < 10)
	{
		*nums = (char)(n % 10 + 48);
		return;
	}
	*nums = (char)(n % 10 + 48);
	nums++;
	_toStr(n / 10, nums);
}


/**
 * _printstr - prints a string
 * @c:string to be printed
* Return:return the length of the string in succes
* -1 in fauiler
*/
int _printstr(char *c)
{

	return (write(1, c, _strlen(c)));
}
