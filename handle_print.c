#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_val[] = {
		{'c', printf_char}, {'s', printf_string},
		{'%', printf_percent}, {'i', printf_int},
		{'d', printf_int}, {'b', printf_binary},
		{'u', printf_unsigned}, {'o', printf_octal},
		{'x', printf_hexadecimal}, {'X', printf_hexa_upper},
		{'p', printf_pointer}, {'S', printf_non_printable},
		{'r', printf_reverse}, {'R', printf_rot13string},
		{'\0', NULL}
	};
	for (i = 0; fmt_val[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_val[i].fmt)
			return (fmt_val[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_val[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
