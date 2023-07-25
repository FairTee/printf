#include "main.h"
/**
 * prinloct - long decimal num in oct
 * @arguments: for inputting num
 * @buf: buffer pointer
 * @buffx: index for buffer ptr
 * Return: characters printed
 */
int prinloct(va_list arguments, char *buf, unsigned int buffx)
{
	long int int_input, x, neg, count, first_num;
	char *oct, *bin;

	int_input = va_arg(arguments, long int);
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

	bin = malloc(sizeof(char) * (64 + 1));
	bin = fill_binary_array(bin, int_input, neg, 64);
	oct = malloc(sizeof(char) * (22 + 1));
	oct = fill_long_oct_array(bin, oct);
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
 * prinlhex - print a long hexadecimal num
 * @arguments: an input string
 * @buf: buffer ptr
 * @buffx: index for buffer ptr
 * Return: characters printed
 */

int prinlhex(va_list arguments, char *buf, unsigned int buffx)
{
	long int_input, x, neg, count, first_num;
	char *hex, *bin;

	int_input = va_arg(arguments, long int);
	neg = 0
		if (int_input == 0)
		{
			buffx = handl_buf(buf, '0', buffx);
			return (1);
		}
	if (int_input < 0)
	{
		int_input = (ont_input * -1) - 1;
		neg = 1;
	}

	bin = malloc(sizeof(char) * (64 + 1));
	bin = fill_binary_array(bin, int_input, neg, 64);
	hex = malloc(sizeof(char) * (16 + 1));
	hex = fill_hex_array(bin, hex, 0, 16);
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
 * prinlint - prints for long int
 * @arguments: input
 * @buf: buffer ptr
 * @buffx: index for buffer ptr
 * Return: characters printed
 */

int prinlint(va_list arguments, char *buf, unsigned int buffx)
{
	long int int_input;
	unsigned long int int_input, temp, x, over, neg;

	int_input = va_arg(arguments, long int);
	neg = 0;
	if (int_input < 0)
	{
		int_in = int_input * -1;
		buffx = handl_buf(buf, '-', buffx);
		neg = 1;
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
	return (x + neg);
}
/**
 * prinlupx - prints a long dec in hexa
 * @arguments: characters
 * @buf: buffer ptr
 * @buffx: index for buffer ptr
 * Return: characters printed
 */
int prinlupx(va_list arguments, char *buf, unsigned int buffx)
{
	long int int_input, x, neg, count, first_num;
	char *hex, *bin;

	int_input = va_arg(arguments, long int);
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

	bin = malloc(sizeof(char) * (64 + 1));
	bin = fill_binary_array(bin, int_input, neg, 64);
	hex = malloc(sizeof(char) * (16 + 1));
	hex = fill_hex_array(bin, hex, 1, 16);
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
