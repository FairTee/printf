#include "main.h"
/**
 * printsint - prints int starting with space
 * @arguments: input string
 * @buf: buffer ptr
 * @buffx: index for buffer ptr
 * Return: characters printed
 */
int printsint(va_list arguments, char *buf, unsigned int buffx)
{
	int int_input;
	unsigned int int_in, temp, x, over;

	int_input = va_arg(arguments, int);
	if (int_input < 0)
	{
		int_in = int_input * -1;
		buffx = handl_buf(buf, '-', buffx);
	}
	else
	{
		int_in = int_input;
		buffx = handl_buf(buf, ' ', buffx);
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
	return (x + 1);
}
