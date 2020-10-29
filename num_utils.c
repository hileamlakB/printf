#include "holberton.h"


/**
 *_pow - raises the number base to power power
 *@base : the base
 *@power : the power
 *Return: return the answer
 */
int _pow(unsigned int base, int power)
{
	int i, prod = 1;

	for (i = 0; i < power; i++)
	{
		prod = prod * base;
	}
	return (prod);
}

/**
 *_numLen - returns the lenth of string
 *@num : operand number
 *Return: number of digits
 */
int _numLen(unsigned int num)
{
	int length = 0;

	if (!num)
		return (1);

	while (num)
	{
		num = num / 10;
		length += 1;
	}

	return (length);
}

/**
 *max - returns max of two strings
 *@a : num 1
 *@b: num 2
 *Return: the great of a or b
 */
int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
