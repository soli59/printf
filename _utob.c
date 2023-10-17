#include "main.h"

/**
 * utob - Convert a positive integer to the specified base and store
 * the result as a string.
 *
 * @number: The number to convert.
 * @buffer: The string buffer to store the result.
 * @base: The base to convert @number to.
 */
void utob(size_t number, char *buffer, int base)
{
	size_t len = 0;

	switch (base) /* Check base number */
	{
		/* Accepted bases */
		case BIN:
		case OCT:
		case DEC:
		case HEX:
			do {
				buffer[len++] = (number % base > 9) ?
					('a' + (number % base - 10)) :
					(number % base + '0');
			} while ((number /= base) > 0);

			buffer[len] = '\0';
			_reverse_str(buffer, len); /* Get the correct representation */
			break;
		default:
			break;
	}
}
