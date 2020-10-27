#include "holberton.h"
/**
 * _putbin - prints the binary representation of a number
 * @num: input integer
 * Return: length of binary
 */
int _putbin(va_list num)
{
	unsigned int n = va_arg(num, unsigned int);
	unsigned int test = _pow(2, sizeof(unsigned int) * BIT_SIZE - 1);
	int start = 0, len = 0;

	if (n == 0)
	{
		len = write(1, &("0"), 1);
		if (len == -1)
			return (-1);
		return (len);
	}
	while (test)
	{
		if (!(test & n) && start)
		{
			if (write(1, &("0"), 1) == -1)
				return (-1);
			len++;
		}
		else if (test & n)
		{
			if (write(1, &("1"), 1) == -1)
				return (-1);
			start = 1;
			len++;
		}
		test = test >> 1;
	}
	return (len);

}

/**
 * _puthex - prints the lowercase hex representation of a number
 * @num: input integer
 * Return: length of hex
 */
int _puthex(va_list num)
{
	unsigned int n = va_arg(num, unsigned int);
	char *nums =  malloc(sizeof(char) * _numLen(n) + 1);
	int i = 0, tmp;

	while (n != 0)
	{
		tmp = n % 16;

		if (tmp < 10)
			nums[i] = tmp + 48;
		else
			nums[i] = tmp + 87;
		n = n / 16;
		i++;
	}
	nums[i] = '\0';
	rev_string(nums);
	i = _printstr(nums);
	free(nums);
	return (i);
}


/**
 * _putHex - prints the uppercase hex representation of a number
 * @num: input integer
 * Return: length of hex
 */
int _putHex(va_list num)
{
	unsigned int n = va_arg(num, unsigned int);
	char *nums =  malloc(sizeof(char) * _numLen(n) + 1);
	int i = 0, tmp;

	while (n != 0)
	{
		tmp = n % 16;

		if (tmp < 10)
			nums[i] = tmp + 48;
		else
			nums[i] = tmp + 55;
		n = n / 16;
		i++;
	}
	nums[i] = '\0';
	rev_string(nums);
	i = _printstr(nums);
	free(nums);
	return (i);
}

/**
 * _putoct - prints the octal representation of a number
 * @num: input integer
 * Return: length of octal
 */
int _putoct(va_list num)
{
	unsigned int n = va_arg(num, unsigned int);
	char *nums =  malloc(sizeof(char) * _numLen(n) * 2 + 1);
	int i = 0, tmp;

	while (n != 0)
	{
		tmp = n % 8;
		nums[i] = tmp + 48;
		n = n / 8;
		i++;
	}
	nums[i] = '\0';
	rev_string(nums);

	i = _printstr(nums);
	free(nums);
	return (i);
}
