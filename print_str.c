#include "main.h"

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
