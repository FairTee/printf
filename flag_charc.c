#include "main.h"
#include <stdio.h>

/**
 * print_prg - print the character to stdout
 * @c: input
 * @buf: buffer ptr
 * @n: index buffer ptr
 * Return: 1
 */
int print_prg(va_list c __attribute__((unused)), char *buf, unsigned int n)
{
	handl_buf(buf, '%', n);

	return (1);
}
/**
 * prinpint - print integer
 * @arguments: string
 * @buf: buffer ptr
 * @buffx: index for buffer ptr
 * Return: characters printed
 */
int prinpint(va_list arguments, char *buf, unsigned int buffx)
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
		buffx = handl_buf(buf, '+', buffx);
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
/**
 * prinnhex - print number in hex
 * @arguments: input
 * @buf: buffer ptr
 * @buffx: index for buffer ptr
 * Return: character printed
 */
int prinnhex(va_list arguments, char *buf, unsigned int buffx)
{
	int int_input, x, neg, count, first_num;
	char *bin, *hex;

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
	buffx = handl_buf(buf, '0', buffx);
	buffx = handl_buf(buf, 'x', buffx);
	bin = malloc(sizeof(char) * (32 + 1));
	bin = fill_binary_array(bin, int_input, neg, 32);
	hex = malloc(sizeof(char) * (8 + 1));
	hex = fill_hex_array(bin, hex[x], 0, 8);
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
/**
 * prinnoct - print the num in oct
 * @arguments: input string
 * @buf: buffer ptr
 * @buffx: index for buffer ptr
 * Return: characters printed
 */
int prinnoct(va_list arguments, char *buf, unsigned int buffx)
{
	int int_input, x, neg, count, first_num;
	char *oct, *bin;

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
	buffx = handl_buf(buf, '0', buffx);
	bin = malloc(sizeof(char) * (32 + 1));
	bin = fill_binary_array(bin, int_input, neg, 32);
	oct = malloc(sizeof(char) * (11 + 1));
	oct = fill_oct_array(bin, oct);
	for (first_num = x = count = 0; oct[x]; x++)
	{
		if (oct[x] != '0' && first_num == 0)
			first_num = 1;
		if (first_num)
		{
			buffx = handl_buf(buf, oct[x], buffx);
			count++;
		}
	}
	free(bin);
	free(oct);
	return (count + 1);
}
/**
 * prinnupx - prints in uppercase
 * @arguments: input string
 * @buf: buffer ptr
 * @buffx: index buffer ptr
 * Return: characters
 */
int prinnupx(va_list arguments, char *buf, unsigned int buffx)
{
	int int_input, x, neg, count, first_num;
	char *hex, *bin;

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
	buffx = handl_buf(buf, '0', buffx);
	buffx = handl_buf(buf, 'X', buffx);
	bin = malloc(sizeof(char) * (32 + 1));
	bin = fill_binary_array(bin, int_input, neg, 32);
	hex = malloc(sizeof(char) * (8 + 1));
	hex = fill_hex_array(bin, hex, 1, 8);
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
