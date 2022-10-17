#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * printf_char - Prints a char
 * @val: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int printf_char(va_list val, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(val, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * printf_string - Prints a string
 * @val: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: length of string printed
 */
int printf_string(va_list val, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(val, char *);

	UNSED(buffer);
	UNSED(flags);
	UNSED(width);
	UNSED(precision);
	UNSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * printf_percent - Prints a percent sign
 * @val: List of a arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: percent sign printed
 */
int printf_percent(va_list val, char buffer[],
	int flags, int width, int precision, int size)
{
	UNSED(val);
	UNSED(buffer);
	UNSED(flags);
	UNSED(width);
	UNSED(precision);
	UNSED(size);
	return (write(1, "%%", 1));
}
