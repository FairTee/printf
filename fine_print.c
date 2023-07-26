#include "main.h"

/**
 * print_int - prints an integer
 * @arguments: input
 * @buf: buffer pointer
 * @buffx: an index
 * Return: total of chars
 */

int print_int(va_list arguments, char *buf, unsigned int buffx)
{
	int int_input;
	unsigned int int_in, temp, x, over, isneg;

	int_input = va_arg(arguments, int);
	isneg = 0;
	if (int_input < 0)
	{
		int_in = int_input * -1;
		buffx = handl_buf(buf, '-', buffx);
		isneg = 1;
	}
	else
	{
		int_in = int_input;
	}

	temp = int_in;
	over = 1;

	while (temp > 9)
	{
		over *= 10;
		temp /= 10;
	}

	for (x = 0; over > 0; over /= 10, x++)
	{
		buffx = handl_buf(buf, ((int_in / over) % 10) + '0', buffx);
	}
	return (x + isneg);
}
