#include "main.h"

/**
*print_string_buff - prints a string to stdout
*@s:string to be printed
*@len:string length
*/
void print_string_buff(const char *str, size_t len)
{
	write(1, str, len);
}