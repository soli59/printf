#include "main.h"

/**
*_hex_lower - add a lowercase hexadeciaml to buffer
*
*@spc:format specifier
*@args:arguments list
*@buff:buffer to hold result
*Returns: the number of characters appended to the string buffer
*/
int _hex_lower(__attribute__((unused)) const format_specifier * spc,
		va_list args, string_buffer *buff)
{
	char hex_str[17];
	int added_chars;
	unsigned int x = va_arg(args, unsigned int);
	size_t initial_length = buff->length;

	utob(x, hex_str, HEX);
	append_string(buff, hex_str);

	added_chars = buff->length - initial_length;
	return (added_chars);
}

/**
*_hex_upper - add a uppercase hexadeciaml to buffer
*@spc:format specifier
*@args:arguments list
*@buff:buffer to hold result
*Returns:num of chars added to buffer
*/
int _hex_upper(__attribute__((unused)) const format_specifier * spc,
		va_list args, string_buffer *buff)
{
	int i;
	char hex_str[17];
	int added_chars;
	unsigned int x = va_arg(args, unsigned int);
	size_t initial_length = buffer->length;

	utob(x, hex_str, HEX);
	for (i = 0; hex_str[i] != '\0'; i++)
	{
		if (hex_str[i] >= 'a' && hex_str[i] <= 'f')
		{
			hex_str[i] = hex_str[i] - 'a' + 'A';
		}
	}
	append_string(buffer, hex_str);

	added_chars = buffer->length - initial_length;
	return (added_chars);
}