#include "main.h"

/**
 * _memcpy - Copies memory area.
 * @dest: Destination buffer.
 * @src: Source buffer.
 * @n: Number of bytes to write.
 *
 * Description: Copies @n bytes from memory area @src to memory area @dest.
 * The memory areas must not overlap.
 * Return: A pointer to @dest.
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	size_t idx;
	char *dest_temp = (char *) dest;
	const char *src_temp = (const char *) src;

	for (idx = 0; idx < n; idx++)
		dest_temp[idx] = src_temp[idx];
	return (dest);
}
