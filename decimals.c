#include "main.h"

/**
 * @c: char to be printed
 * print_char - prints a char
 * Return: number of chars printed
 **/

int print_char(char c)
{

        return (write(1, &c, 1));

}

/**
  * @str: string to be printed
  * print_str - prints string
  * Return: number of chars printed
  **/

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
 * print_number - prints number
 * @n: number to be printed
 * Return; number of chars printed
 **/

int print_number(int n)
{                n = -n;
        }

        if (n / 10)
        {
                count += print_number(n / 10);
                count += print_char(n % 10 + '0');
        }

        return (count);

}

/**
 * @c: char to be printed
 * @specifier: specifier
 * print_conversion - prints the conversion
 * @s: string to be printed
 * @%: %
 * @d: double to be printed
 * @i: integer to be printed
 * @str: string to be printed
 * print_string - prints string
 * Return: number of chars printed
 **/

int print_conversion(char specifier, va_list args)
{
        int print_str(char *str);

        int count;
        int int_arg;


        if (specifier == 'c')
        {
                count += print_char(va_arg(args, int));
        }

        else if (specifier == '%') {
                        count += write(1, str, 1);
                        str++;
                }
                return (count);
        }
        else if (specifier == 'd' || specifier == 'i')
        {
                int_arg = va_arg(args, int);
                count += print_number(int_arg);
        }

        return (count);

}

 /**
  * @format: format
  * handle_print - prints an argument based on its type
  * @_printf: printf function
  * @buffer:an array of chars
  * @ind:index
  * Return: chars printed
  **/

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	char *str_arg;

	va_start(args, format);

	if (*format == '%')
	{
		format++
			count += print_conversion(*format, args);
	}
	else
	{
		count += write(1, formart, 1);
	}
	format++;

	va_end(args);

	return (count);
}

