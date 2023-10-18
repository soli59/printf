#include "main.h"

/**
*_string - adds a string to buffer
*@spc:format specifier
*@args:the arguments list
*@buff:buffer holds result
*
*Returns:num of chars added to buffer
*/
int _string(
	__attribute__((unused)) const format_specifier *spc,
	va_list args, string_buffer *buff)
{
	char *s;
	int added_chars;
	size_t initial_length;

	s = va_arg(args, char *);
	initial_length = buff->length;

	if (s)
	{
		append_string(buff, s);
	}
	else
	{
		append_string(buff, "(null)");
	}

	added_chars = buff->length - initial_length;
	return (added_chars);
}

/**
*handle_string_reversal - appends a reversed string to the string buffer
*@spc: format specifier information (unused)
*@args: the arguments list
*@buffer: the string buffer to store the result
*Returns: the number of characters appended to the string @buffer
*/
int handle_string_reversal(
	__attribute__((unused)) const format_specifier * spc,
	va_list args, string_buffer *buff)
{
	char *str, *dup_str;
	int characters_added;
	size_t str_len, initial_length;

	str = va_arg(args, char *);
	initial_length = buff->length;

	if (str)
	{
		dup_str = _strdup(str);
		if (dup_str == NULL)
			return (0); /* memory allocation failed, nothing is written */

		str_len = _strlen(str);
		_reverse_str(dup_str, str_len);
		append_string(buff, dup_str);
		custom_free(dup_str);
	}
	else
	{
		append_string(buff, "(null)");
	}

	characters_added = buff->length - initial_length;
	return (characters_added);
}

/**
 * handle_rot13 - appends a ROT13 string to the string buffer
 * @spec: format specifier information (unused)
 * @args: the arguments list
 * @buffer: the string buffer to store the result
 *
 * Return: the number of characters appended to the string @buffer
 */
int handle_rot13(const format_specifier *spc, va_list args,
		string_buffer *buff);
{
	char *str, *dup_str;
	int characters_added;
	size_t initial_length;

	str = va_arg(args, char *);
	initial_length = buffer->length;

	if (str)
	{
		dup_str = _strdup(str);
		if (dup_str == NULL)
			return (0); /* memory allocation failed, nothing is written */

		rot13(dup_str);
		append_string(buffer, dup_str);
		custom_free(dup_str);
	}
	else
	{
		append_string(buffer, "(null)");
	}

	characters_added = buffer->length - initial_length;
	return (characters_added);
}

/**
*_custom_string - appends a custom string to the string buffer
*@spc:format specifier
*@args:the arguments list
*@buffer:buffer to hold result
*Returns:num of chars added to buffer
*/
int _custom_string(
	__attribute__((unused)) const format_specifier * spc,
	va_list args, string_buffer *buff)
{
	char hex_str[5];
	char *str, *dup_str;
	int added_chars;
	size_t initial_length, x;

	str = va_arg(args, char *);
	initial_length = buff->length;

	if (str)
	{
		dup_str = _strdup(str);
		if (dup_str == NULL)
			return (0); /* memory allocation failed, nothing is written */

		for (x = 0; dup_str[x] != '\0'; x++)
		{
			if (is_non_print(dup_str[x]))
			{
				char_to_hex(hex_str, dup_str[x]);
				append_string(buff, hex_str);
			}
			else
			{
				append_char(buff, dup_str[x]);
			}
		}
		custom_free(dup_str);
	}
	else
	{
		append_string(buff, "(null)");
	}

	added_chars = buff->length - initial_length;
	return (added_chars);
}

/**
*char_to_hex - converts a char to hexadecimal
*@buff:buffer to hold formatted char
*@x:char
*Return: Void
*/
void char_to_hex(char *buff, unsigned char x)
{
	const char *hex_chars = "0123456789ABCDEF";

	buff[0] = '\\';
	buff[1] = 'x';
	buff[2] = hex_chars[x >> 4]; /* first hex digit */
	buff[3] = hex_chars[x & 0x0F];  /* second hex digit */
}