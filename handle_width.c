#include "main.h"

/**
*_width - handling width
*@format:formatted string being handled.
*@spc:format specifier to be processed.
*@buff: the string buffer for output.
*
*Return: the number of characters added to the buffer
*/
int handle_width(const char *format, format_specifier *spc,
		string_buffer *buff)
{
    int added_chars = 0;
	int w = 0;
	size_t initial_length = buff->length;

	format++;

	if (*format >= '0' && *format <= '9')
	{
		while (*format >= '0' && *format <= '9')
		{
			w = w * 10 + (*format - '0');
			format++;
		}

		spc->w = w;

		/* Append width to the output buffer */
		while (w > 0)
		{
			append_char(buffer, ' ');
			w--;
		}
	}

	added_chars = buff->length - initial_length;
	return (added_chars);
}