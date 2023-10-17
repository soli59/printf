#include "main.h"

/**
 * _realloc - Reallocates memory.
 * @old_mem_blk: Pointer to the old memory block.
 * @old_size: Size of the old memory block.
 * @new_size: Size of the new memory block.
 *
 * Description: Changes the size of the memory block pointed to by @old_mem_blk
 * to @new_size bytes. The contents are unchanged up to the minimum of the old
 * and new sizes. If @new_size is larger than @old_size, added memory is not
 * initialized. If @old_mem_blk is NULL, the call is equivalent to
 * @malloc(@new_size). If @new_size is zero and @old_mem_blk is not NULL, the
 * call is equivalent to free(@old_mem_blk).
 * Return: Pointer to the newly allocated memory, or NULL if  request failed.
 */
void *_realloc(void *old_mem_blk, size_t old_size, size_t new_size)
{
	void *new_mem_blk;
	size_t min_size;

	if (new_size == old_size)
		return (old_mem_blk);

	if (new_size == 0 && old_mem_blk != NULL)
	{
		free(old_mem_blk);
		return (NULL);
	}

	new_mem_blk = malloc(new_size);
	if (new_mem_blk == NULL)
		return (NULL);

	if (old_mem_blk != NULL)
	{
		min_size = (old_size < new_size) ? old_size : new_size;
		_memcpy(new_mem_blk, old_mem_blk, min_size);
		free(old_mem_blk);
	}

	return (new_mem_blk);
}
