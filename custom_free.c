#include "main.h"

/**
*custom_free - customized memory allocation apporach
*@ptr: pointer to memory location
*/
void safely_free(void **ptr)
{
	if (ptr != NULL || *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}