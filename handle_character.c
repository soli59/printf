#include "main.h"

/**
*handle_character - adds a character to buffer
*@args:arguments list
*@buff:buffer to hold result
*@spc:pointer to a format specifier
*
*Returns: 1
*/
int handle_character(__attribute__((unused))
		const format_specifier * spc, va_list args, string_buffer *buff)
{
	char x = va_arg(args, int);

	append_char(buffer, x);

	return (1);
}

/**
*handle_percentage - adds percentage to buffer
*@args:arguments list
*@buff:buffer to hold result
*@ptrspc:pointer to specifier
*
*Returns: 1
*/
int handle_percentage(__attribute__((unused)) const format_specifier * ptrspc,
		__attribute__((unused)) va_list args, string_buffer *buff)
{
	append_char(buff, '%');

	return (1);
}