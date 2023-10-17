#include "main.h"

/**
 * _reverse_str - Reverses a string in place.
 * @buffer: Pointer to the string to reverse.
 * @len: Length of the string.
 */
void _reverse_str(char *buffer, size_t len)
{
	size_t i, mid;
	char c;

	if (!buffer)
		return; /* Invalid string, nothing to do */
	mid = len / 2;

	for (i = 0; i < mid; i++)
	{
		c = buffer[i];

		/* Swap values */
		buffer[i] = buffer[len - i - 1];
		buffer[len - i - 1] = c;
	}
}
