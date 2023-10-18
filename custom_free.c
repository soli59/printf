#include "main.h"

/**
*custom_free - customized memory allocation apporach
*@ptr: pointer to memory location
*/
void custom_free(void **ptr)
{
	if (ptr != NULL || *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}