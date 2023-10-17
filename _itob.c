#include "main.h"

/**
 * _itoa_recursive - Helper function to convert integer to a specified base
 * using recursion.
 *
 * @number: the number to convert
 * @buffer: the string buffer to store the result
 * @base: the base to convert @number to
 * @len: the current length of the result string
 */
void _itoa_recursive(ssize_t number, char *buffer, int base, size_t *len)
{
	if (number == 0)
	{
		buffer[(*len)++] = '0';
		return;
	}

	ssize_t remainder = number % base;

	if (remainder < 0)
	{
		remainder = -remainder; /*Get the absolute value of the remainder*/

	}

	if (remainder > 9)
	{
		buffer[(*len)++] = 'a' + (remainder - 10);
	}
	else
	{
		buffer[(*len)++] = '0' + remainder;
	}

	if (number / base != 0)
	{
		_itoa_recursive(number / base, buffer, base, len);
	}
}

/**
 * _itob - convert integer to the specified base and stores the result
 * as a string.
 *
 * @number: the number to convert
 * @buffer: the string buffer to store the result
 * @base: the base to convert @number to
 */
void _itob(ssize_t number, char *buffer, int base)
{
	size_t len = 0;

	if (number < 0)
	{
		buffer[len++] = '-';
		number = -number; /* Get the absolute value of the number*/
	}

	if (base < 2 || base > 16)
	{
		return;
	}

	_itoa_recursive(number, buffer, base, &len);
	buffer[len] = '\0';
}
