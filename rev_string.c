#include "main.h"

/**
 * print_rev - prints a string in reverse
 * @arguments: input
 * @buf: buffer
 * @buffx: index for buffer
 * Return: number of chars
 */

int print_rev(va_list arguments, char *buf, unsigned int buffx)
{
	char *str;
	unsigned int x;
	int j = 0;
	char nill[] = "(llun)";

	str = va_arg(arguments, char *);
	if (str == NULL)
	{
		for (x = 0; nill[x]; x++)
			buffx = handl_buf(buf, nill[x], buffx);
		return (6);
	}
	for (x = 0; str[x]; x++)
		;
	j = x - 1;
	for (; j >= 0; j--)
	{
		buffx = handl_buf(buf, str[j], buffx);
	}
	return (x);
}
