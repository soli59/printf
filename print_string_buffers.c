#include "main.h"

/**
*print_string_buff - prints a string to stdout
*@s:string to be printed
*@len:string length
*/
void print_str_buffer(const char *str, size_t len)
{
	write(1, str, len);
}