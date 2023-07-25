#include "main.h"

/**
 * print_usr - prints a string
 * @arguments: input
 * @buf: buffer pointer
 * @buffx: index for buffer
 * Return: number of chars
 */

int print_usr(va_list arguments, char *buf, unsigned int buffx)
{
	unsigned char *str;
	char *hex, *bin;
	unsigned int x, sum, op;

	str = va_arg(arguments, unsigned char *);
	bin = malloc(sizeof(char) * (32 + 1));
	hex = malloc(sizeof(char) * (8 + 1));
	for (sum = x = 0; str[x]; x++)
	{
		if (str[x] < 32 || str[x] >= 127)
		{
			buffx = handl_buf(buf, '\\', buffx);
			buffx = handl_buf(buf, 'x', buffx);
			op = str[x];
			bin = fill_binary_array(bin, op, 0, 32);
			hex = fill_hex_array(bin, hex, 1, 8);
			buffx = handl_buf(buf, hex[6], buffx);
			buffx = handl_buf(buf, hex[7], buffx);
			sum += 3;
		}
		else
			buffx = handl_buf(buf, str[x], buffx);
	}
	free(bin);
	free(hex);
	return (x + sum);
}
