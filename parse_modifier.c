#include "main.h"

/**
*parse_mods - handling string modifiers
*@format:string format
*@spc:format specifier
*@buff:placeholder to hold string
*
*Returns:pointer to new format
*/
const char *parse_mods(const char *format, format_specifier *spc,
		string_buffer *buff)
{
	const char *format_tokens = "idfFcsSrRuxXop";
	char *temporary_format = (char *) format;

	while (*temporary_format && !_strchr(format_tokens, *temporary_format))
	{

		switch (*temporary_format)
		{
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				handle_width(temporary_format, spc, buff);
				break;
			case '.':
				handle_precision(temporary_format, spc, buff);
				break;
			case 'l':
				spc->length = 'l';
				break;
			case 'h':
				spc->length = 'h';
				break;
		}
		temporary_format++;
	}
	return (format);
}