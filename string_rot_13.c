#include "main.h"

/**
 * print_rot - writes in ROT13
 * @arguments: input
 * @buf: buffer
 * @buffx: index for buffer
 * Return: number of chars
 */

int print_rot(va_list arguments, char *buf, unsigned int buffx)
{
	char alf[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str;
	unsigned int x, j, k;
	char nill[] = "(avyy)";

	str = va_arg(arguments, char *);
	if (str == NULL)
	{
		for (x = 0; nill[x]; x++)
			buffx = handl_buf(buf, nill[x], buffx);
		return (6);
	}
	for (x = 0; str[x]; x++)
	{
		for (k = j = 0; alf[j]; j++)
		{
			if (str[x] == alf[j])
			{
				k = 1;
				buffx = handl_buf(buf, rot[j], buffx);
				break;
			}
		}
		if (k == 0)
			buffx = handl_buf(buf, str[x], buffx);
	}
	return (x);
}
