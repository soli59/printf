#include "main.h"

/**
 * parse_modifiers - handles string modifiers
 * @format: the string format
 * @spec: the format specifier
 * @buffer: the buffer to store the string
 *
 * Return: a pointer to the updated format
 */
const char *parse_modifiers(const char *format, format_specifier *spec,
							string_buffer *buffer)
{
	const char *fmt_marks = "%idcsSrRuxXop";

	spec->sharp_flag = 0;

	while (*format && !_strchr(fmt_marks, *format))
	{
		switch (*format)
		{
		case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			handle_width(format, spec, buffer);
			break;
		case '.':
			handle_precision(format, spec, buffer);
			break;

		case 'l':
			spec->length = 'l';
			break;
		case 'h':
			spec->length = 'h';
			break;
		case '#':
			spec->sharp_flag = 1;
			break;
		case '+':
			spec->plus_flag = 1;
			break;
		case ' ':
			spec->space_flag = 1;
			break;
		}
		format++;
	}
	return (format);
}
