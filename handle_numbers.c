#include "main.h"

/**
*handle_decimal - add a decimal int to buffer
*@spc:format specifier information
*@args:arguments list
*@buff:buffer to hold result
*
*Returns:num of chars added to buffer
*/
int _decimal(__attribute__((unused)) const format_specifier * spc,
		va_list args, string_buffer *buff)
{
	int n = va_arg(args, int);
	char res[21];
	size_t initial_length = buff->length;
	int added_chars;

	_itob(n, res, DEC);
	append_string(buff, res);

	added_chars = buff->length - initial_length;
	return (added_chars);
}

/**
*_unsigned_int - add unsigned decimal int to buffer 
*@spc:format specifier
*@args:arguments list
*@buff:buffer to hold result
*Returns:num of chars added to buffer
*/
int _unsigned_int(__attribute__((unused)) const format_specifier * spc,
		va_list args, string_buffer *buff)
{
	unsigned int n = va_arg(args, unsigned int);
	char res[21];
	size_t initial_length = buff->length;
	int added_chars;

	utob(n, res, DEC);
	append_string(buff, res);

	added_chars = buff->length - initial_length;
	return (added_chars);
}

/**
*handle_binary - convert and append an integer in binary format to the string
*buffer
*@spc:format specifier
*@args:arguments list
*@buff:buffer to hold result
*Returns:num of chars added to buffer
*/
int _binary(__attribute__((unused)) const format_specifier * spc,
		va_list args, string_buffer *buff)
{
	char res[65];
	int added_chars;
	unsigned int n = va_arg(args, unsigned int);
	size_t initial_length = buff->length;

	utob(n, res, BIN);
	append_string(buff, res);

	added_chars = buff->length - initial_length;
	return (added_chars);
}

/**
*_octal - adds octal int to buffer
*@spec:format specifier
*@args:arguments list
*@buffer:buffer to hold result
*Returns:num of chars added to buffer
*/
int _octal(__attribute__((unused)) const format_specifier * spc,
		va_list args, string_buffer *buff)
{
	unsigned int n = va_arg(args, unsigned int);
	char res[23];
	size_t initial_length = buff->length;
	int added_chars;

	utob(n, res, OCT);
	append_string(buff, res);

	added_chars = buff->length - initial_length;
	return (added_chars);
}