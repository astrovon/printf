#include "main.h"

/**
 * print_char - prints a character to stdout
 * @c: the character to be printed
 * Return: the number of characters printed
 */

int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - prints a string to stdout
 * @str: the string to be printed
 * Return: the number of characters printed
 */

int print_str(char *str)
{
	int count = 0;

	while (*str)
	{
		count += write(1, str, 1);
		str++;
	}
	return (count);
}

/**
 * _printf - produces output according to a format
 * @format: the format of the string
 * Return: the number of characters printed
 */

int _printf(char *format, ...)
{
	int count = 0;
	va_list args;
	char *str_arg;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				count += print_char(va_arg(args, int));
			}
			else if (*format == 's')
			{
				str_arg += va_arg(args, char *);
				if (str_arg == NULL)
				{
					str_arg = "(null)";
				}
				count += print_str(str_arg);
			}
			else if (*format == '%')
			{
				count += print_char('%');
			}
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}

	va_end(args);

	return (count);
}
