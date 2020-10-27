#include "holberton.h"


/**
 *_putint - Print a number of any digit
 *@num: takes a varadic list containing the number to be printed
 *Return: the lenght of the integer printed
 */
int _putint(va_list num)
{
	char *nums, *_nums;
	int n = va_arg(num, int);
	int len = _numLen(n >= 0 ? n : -1 * n);

	if (n < 0)
		nums = malloc(sizeof(char) * len + 2);
	else
		nums = malloc(sizeof(char) * len + 1);

	if (!nums)
		return (-1);
	/*create a manipulating pointer*/
	_nums = nums;

	if (n < 0)
	{
		*_nums = '-';
		_nums++;
	}
	/*change the number to a reversed string and reverse it*/
	_toStr(n >= 0 ? n : -1 * n, _nums);
	*(_nums + len) = '\0';
	rev_string(_nums);

	len = _printstr(nums);
	free(nums);

	return (len);
}


/**
 *_putuint - Print a unsigned int of any digit
 *@num : a va_list containing the unsigned int to be printed as the first item
 *Return: the lenght of the unsigned integer printed
 */
int _putuint(va_list num)
{
	char *nums;
	int n = va_arg(num, unsigned int);
	int len = _numLen(n);

	nums = malloc(sizeof(char) * len + 1);
	if (!nums)
		return (-1);

	_toStr(n, nums);
	*(nums + len) = '\0';
	rev_string(nums);
	len = _printstr(nums);
	free(nums);
	return (len);
}
