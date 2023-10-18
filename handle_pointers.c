#include "main.h"

/**
*_pointer - adds a hexadecimal pointer
*
*@spc:format specifier
*@args:arguments list
*@buff:buffer to hold result
*
*Returns:num of chars added to buffer
*/
int _pointer(__attribute__((unused)) const format_specifier * spc,
		va_list args, string_buffer *buff)
{
	char hex_str[17];
	int printed_chars;
	size_t initial_length = buff->length;
	unsigned long int pointer = va_arg(args, unsigned long int);

	if (!pointer)
	{
		append_string(buff, "(nil)");
	}
	else
	{
		utob(pointer, hex_str, HEX);
		append_string(buff, "0x");
		append_string(buff, hex_str);
	}

	printed_chars = buff->length - initial_length;
	return (printed_chars);
}