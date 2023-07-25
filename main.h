#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct print - for functions
 * @type_arg: The identifier
 * @f: pointer that points to printer functions
 * Description: A type of struct soring pointers to printer funcs
 */
tpedef struct print
{
	char *type_arg;
	int (*f)(va_list, char *, unsigned int);
} print_t;

int _print(const char *format, ...);
int print_prg(va_list __attribute__((unused)), char *, unsigned int);
int print_chr(va_list arguments, char *buf, unsigned int buffx);
int print_str(va_list arguments, char *buf, unsigned int buffx);
int print_int(va_list arguments, char *buf, unsigned int buffx);
int print_bnr(va_list arguments, char *buf, unsigned int buffx);
int print_hex(va_list arguments, char *buf, unsigned int buffx);
int print_oct(va_list arguments, char *buf, unsigned int buffx);
int print_unt(va_list arguments, char *buf, unsigned int buffx);
int print_usr(va_list arguments, char *buf, unsigned int buffx);
int print_upx(va_list arguments, char *buf, unsigned int buffx);
int print_add(va_list arguments, char *buf, unsigned int buffx);
int print_rev(va_list arguments, char *buf, unsigned int buffx);
int print_rot(va_list arguments, char *buf, unsigned int buffx);
int prinlint(va_list arguments, char *buf, unsigned int buffx);
int prinlunt(va_list arguments, char *buf, unsigned int buffx);
int prinloct(va_list arguments, char *buf, unsigned int buffx);
int prinlhex(va_list arguments, char *buf, unsigned int buffx);
int prinlupx(va_list arguments, char *buf, unsigned int buffx);
int prinhint(va_list arguments, char *buf, unsigned int buffx);
int prinhunt(va_list arguments, char *buf, unsigned int buffx);
int prinhoct(va_list arguments, char *buf, unsigned int buffx);
int prinhhex(va_list arguments, char *buf, unsigned int buffx);
int prinhupx(va_list arguments, char *buf, unsigned int buffx);
int prinpint(va_list arguments, char *buf, unsigned int buffx);
int prinnoct(va_list arguments, char *buf, unsigned int buffx);
int prinnhex(va_list arguments, char *buf, unsigned int buffx);
int prinnupx(va_list arguments, char *buf, unsigned int buffx);
int prinsint(va_list arguments, char *buf, unsigned int buffx);
int (*get_print_func(const char *s, int index))(va_list, char *, unsigned int);
int ev_print_func(const char *s, int index);
unsigned int handl_buf(char *buf, char c, unsigned int nbuf);
char *fill_binary_array(char *binary, long int int_in, int isneg, int limit);
char *fill_oct_array(char *bnr, char *oct);
char *fill_long_oct_array(char *bnr, char *oct);
char *fill_short_oct_array(char *bnr, char *oct);
char *fill_hex_array(char *bnr, char *hex, int isupp, int limit);

#endif
