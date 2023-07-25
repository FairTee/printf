#include "main.h"

/**
 * print_buf - prints buffer
 * @buf: buffer
 * @nbuf: number of bytes
 * Return: number of bytes
 */

int print_buf(char *buf, unsigned int nbuf)
{
	return (write(1, buf, nbuf));
}

/**
 * handl_buf - concatenates the characters
 * @buf: buffer
 * @c: character
 * @buffx: index of buffer
 * Return: index of pointer
 */

unsigned int handl_buf(char *buf, char c, unsigned int buffx)
{
	if (buffx == 1024)
	{
		print_buf(buf, buffx);
		buffx = 0;
	}
	buf[buffx] = c;
	buffx++;
	return (buffx);
}
