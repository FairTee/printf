#include "main.h"
#include <stdio.h>

/**
 * print_add - prints an address
 * @arguments: input
 * @buf: buffer
 * @buffx: index of buffer
 * Return: number of chars
 */

int print_add(va_list arguments, char *buf, unsigned int buffx)
{
	void *add;
	long int int_input;
	int x, count, first_num, neg;
	char *hex, *bin;
	char nill[] = "(nil)";

	add = (va_arg(arguments, void *));
	if (add == NULL)
	{
		for (x = 0; nill[x]; x++)
			buffx = handl_buf(buf, nill[x], buffx);
		return (5);
	}
	int_input = (intptr_t)add;
	neg = 0;
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		neg = 1;
	}
	bin = malloc(sizeof(char) * (64 + 1));
	bin = fill_binary_array(bin, int_input, neg, 64);
	hex = malloc(sizeof(char) * (16 + 1));
	hex = fill_hex_array(bin, hex, 0, 16);
	buffx = handl_buf(buf, '0', buffx);
	buffx = handl_buf(buf, 'x', buffx);
	for (first_num = x = count = 0; hex[x]; x++)
	{
		if (hex[x] != '0' && first_num == 0)
			first_num = 1;
		if (first_num)
		{
			buffx = handl_buf(buf, hex[x], buffx);
			count++;
		}
	}
	free(bin);
	free(hex);
	return (count + 2);
}
