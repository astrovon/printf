#include "main.h"
#include "print_char.c"
#include "print_str.c"

/**
 * print_unsigned_number - prints a nummber to stdout
 * @n: the number to print
 * @base: the base of the conversion
 * Return: the number of tyhe characters printed
 */

int print_unsigned_number(unsigned int n, unsigned int base)
{
	int count = 0;
	char digit;

	if (n / base)
	{
		count += print_unsigned_number(n / base, base);
	}

	digit = (n % base < 10) ? (n % base + '0') : (n % base - 10 + 'a');

	count += print_char(digit);

	return (count);
}

/**
 * print_conversion - handles a conversion specifier
 * @specifier: handles the conversion specifier
 * @args: the va list of arguments
 * Return: the number of characters printed
 */

int print_conversion(char specifier, va_list args)
{
	int count = 0;

	if (specifier == 'c')
	{
		count += print_char(va_args(arg, int));
	}
	else if (specifier == 's')
	{
		char *str_arg = va_args(arg, char *);
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
		int int_arg = va_args(arg, int);
		count += print_unsigned number(int_arg, 10);
	}
	else if (specifier == 'b')
	{
		unsigned int binary_arg = va_args(arg, unsigned int);
		count += print_unsigned_number(args, 2);
	}

	return (count);
}

/**
 * _printf - a function that takes a format string and other variables
 * @format: the format of the string
 * Return: the number of characters printed
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
