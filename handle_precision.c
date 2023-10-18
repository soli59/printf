#include "main.h"

/**
*_precision - handles format specifiers precision level
*@format: the formatted string
*@spc:format specifier
*@buff:buffer to hold result
*
*Returns:num of chars added to buffer
*/
int _precision(const char *format, format_specifier *spc,
		string_buffer *buff)
{
	int plevel = 0;
	int added_chars = 0;
	size_t initial_length = buff->length;

	format++;
	while (*format >= '0' && *format <= '9')
	{
		plevel = plevel * 10 + (*format - '0');
		format++;
	}
	if (plevel > 0)
	{
		spc->precision = plevel;

		if (*format != '\0')
			append_char(buff, *format);

		while (plevel > 0)
		{
			format++;
			if (*format != '\0')
				append_char(buff, *format);
			plevel--;
		}
	}
	else if (*format == '*')
	{
		spc->precision = -1;
		append_char(buff, *format);
	}
	added_chars = buff->length - initial_length;
	return (added_chars);
}