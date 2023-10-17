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
