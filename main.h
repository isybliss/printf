#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1



/**
 * struct format - match the conversion specifiers for printf
 * @format: the format
 * @f: type pointer to function for the conversion specifier
 *
 */

typedef struct format
{
	char format;
	int (*f)(va_list, char[], int, int, int, int);
} fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/***** FUNCTIONS ******/

int printf_char(va_list val, char buffer[],
	int flags, int width, int precision, int size);
int printf_string(va_list val, char buffer[],
	int flags, int width, int precision, int size);
int printf_percent(va_list val, char buffer[],
	int flags, int width, int precision, int size);
int printf_int(va_list val, char buffer[],
	int flags, int width, int precision, int size);
int printf_binary(va_list val, char buffer[],
	int flags, int width, int precision, int size);
int printf_unsigned(va_list val, char buffer[],
	int flags, int width, int precision, int size);
int printf_octal(va_list val, char buffer[],
	int flags, int width, int precision, int size);
int printf_hexadecimal(va_list val, char buffer[],
	int flags, int width, int precision, int size);
int printf_hexa_upper(va_list val, char buffer[],
	int flags, int width, int precision, int size);

int printf_hexa(va_list val, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

int printf_non_printable(va_list val, char buffer[],
	int flags, int width, int precision, int size);

int printf_pointer(va_list val, char buffer[],
		int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

int printf_reverse(va_list val, char buffer[],
	int flags, int width, int precision, int size);


int printf_rot13string(va_list val, char buffer[],
	int flags, int width, int precision, int size);
int printf_hex_aux(unsigned long int num);
int printf_HEX_aux(unsigned int num);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
