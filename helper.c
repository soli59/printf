#include "main.h"

/**
 * helper_printf - customized printf
 * @buff: the string buffer
 * @format: the format string
 * @args: the variable argument
 *
 * Returns: num of printed chars
 */
int custom_printf(string_buffer *buff, const char *format, va_list args);{
	int printed_chars, n_chars;
	format_specifier *spc;

	spc = create_format_specifiers();
	if (spc == NULL)
		return (0);

	printed_chars = n_chars = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			format = parse_modifiers(format, spc, buff);
			n_chars = select_format_handler(*format, spc, args, buff);
			printed_chars += n_chars;
		}
		else
		{
			append_char(buff, *format);
			printed_chars++;
		}
		format++;
	}
	print_string_buffer(buff->data, printed_chars);
	safely_free(buff->data);
	safely_free(spc);
	return (printed_chars);
}