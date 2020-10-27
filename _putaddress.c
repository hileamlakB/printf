#include "holberton.h"


/**
 * _putadress - prints the adress of a memory in hex form
 * @num: input integer (memory location as ui insided a va_list)
 * Return: length of hex
 */
int _putadress(va_list num)
{
	unsigned long int n = va_arg(num, unsigned long int);
	char *nums =  malloc(sizeof(char) * _numLen(n) + 1);
	int i = 0, tmp;

	write(1, &("0x"), 2);

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
	i = 2 + _printstr(nums);
	free(nums);
	return (i);
}

