#include "main.h"
#include <stdio.h>

/**
 * print_chr - prints character c to stdout
 * @arguments: input character
 * @buf: buffer
 * @buffx: index for buffer ptr
 * Return: 1
 */
int print_chr(va_list arguments, char *buf, unsigned int buffx)
{
	char c;

	c = va_arg(arguments, int);
	handl_buf(buf, c, buffx);
	return (1);
}
/**
 * print_str - prints string to stdout
 * @arguments: inout string
 * @buf: buffer ptr
 * @buffx: index for buffer ptr
 * Return: 1
 */
int print_str(va_list arguments, char *buf, unsigned int buffx)
{
	char *str;
	unsigned int x;
	char y[] = "(null)";

	str = va_arg(arguments, char *);
	if (str == NULL)
	{
		for (x = 0; y[x]; x++)
			buffx = handl_buf(buf, y[x], buffx);
		return (6);
	}
	for (x = 0; str[x]; x++)
		buffx = handl_buf(buf, str[x], buffx);
	return (x);
}
