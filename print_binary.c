#include "main.h"

/**
 * print_bnr - prints in binary
 * @arguments: input
 * @buf: buffer
 * @buffx: index for buffer
 * Return: number of chars
 */

int print_bnr(va_list arguments, char *buf, unsigned int buffx)
{
	int int_input, count, x, first_one, neg;
	char *bin;

	int_input = va_arg(arguments, int);
	neg = 0;
	if (int_input == 0)
	{
		buffx = handl_buf(buf, '0', buffx);
		return (1);
	}
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		neg = 1;
	}
	bin = malloc(sizeof(char) * (32 + 1));
	bin = fill_binary_array(bin, int_input, neg, 32);
	first_one = 0;
	for (count = x = 0; bin[x]; x++)
	{
		if (first_one == 0 && bin[x] == '1')
			first_one = 1;
		if (first_one == 1)
		{
			buffx = handl_buf(buf, bin[x], buffx);
			count++;
		}
	}
	free(bin);
	return (count);
}
