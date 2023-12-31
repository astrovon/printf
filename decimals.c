#include "main.h"
#include "print_char.c"
#include "print_str.c"

/**
 * print_number - prints a number to standard output
 * @n: the number to print
 * Return: the number of characters printed
 */

int print_number(int n)
{
	int count = 0;

	if (n < 0)
	{
		count += print_char('-');
		n = -n;
	}
	if (n / 10)
	{
		count += print_number(n / 10);
		count += print_char(n % 10 + '0');
	}

	return (count);
}

/**
 * print_conversion - handles a conversion specifier
 * @specifier: the soecifier
 * @args: the va list of arguments
 * Return: the number of characters printed
 */

int print_conversion(char specifier, va_list args)
{
	int count = 0;

	if (specifier == 'c')
	{
		count += print_char(va_arg(args, int));
	}
	if (specifier == 's')
	{
		char *str_arg = va_arg(args, char *);

		if (str_arg == NULL)
			str_arg = "(null)";
		count += print_str(str_arg);
	}
	else if (specifier == '%')
	{
		count += print_char('%');
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		int int_arg = va_arg(args, int);

		count += print_number(int_arg);
	}

	return (count);
}

/**
 * _printf - prints to stdout according to format
 * @format: the format of what to be printed
 * Return: the number of printed item
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += print_conversion(*format, args);
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
