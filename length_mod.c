#include "main.h"

/**
 * prinhunt - prints short unsigned integers
 * @arguments: numbers to print
 * @buf: buffer ptr
 * @buffx:index for buffer ptr
 * Return: characters printed
 */

int prinhunt(va_list arguments, char *buf, unsigned int buffx)
{
	unsigned short int int_in, temp, x, over;

	int_in = va_arg(arguments, unsigned int);

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
	return (x);
}

/**
 * prinlunt - prints a long unsigned number
 * @arguments: number to print
 * @buf: buffer ptr
 * @buffx: index for buffer ptr
 * Return: characters printed
 */
int prinlunt(va_list arguments, char *buf, unsigned int buffx)
{
	unsigned long int int_in, temp, x, over;

	int_in = va_arg(arguments, unsigned long int);
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
	return (x);
}
