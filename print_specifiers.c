#include "main.h"
/**
 * print_unt - prints unsigned int
 * @arguments: number to be printed
 * @buf: buffer ptr
 * @buffx: index buffer ptr
 * Return: characters printed
 */
int print_unt(va_list arguments, char *buf, unsigned int buffx)
{
	unsigned int int_in, temp, x, over;

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
 * print_oct - prints decimal in oct
 * @arguments: input number
 * @buf: buffer ptr
 * @buffx: index buffer ptr
 * Return: characters printed
 */
int print_oct(va_list arguments, char *buf, unsigned int buffx)
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
	return (count);
}
/**
 * print_hex - prints a dec in hexa
 * @arguments: input string
 * @buf: buffer ptr
 * @buffx: index for ptr
 * Return: characters printed
 */
int print_hex(va_list arguments, char *buf, unsigned int buffx)
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
	bin = malloc(sizeof(char) * (32 + 1));
	bin = fill_binary_array(bin, int_input, neg, 32);
	hex = malloc(sizeof(char) * (8 + 1));
	hex = fill_hex_array(bin, hex, 0, 8);
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
	return (count);
}
/**
 * print_upx - prints a decimal in hex
 * @arguments: character
 * @buf: buffer ptr
 * @buffx: index to buffer ptr
 * Return: characters printed
 */
int print_upx(va_list arguments, char *buf, unsigned int buffx)
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
	return (count);
}
