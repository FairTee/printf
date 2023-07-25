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
