#include "main.h"

/**
 * select_format_handler - Selects the appropriate handler 4 format specifier
 * @specifier: The specific format specifier to match
 * @spec: A pointer 2 the format specifier struc containing specifier info
 * @args: The va_list of arguments
 * @buffer: Pointer to the string_buffer structure for output
 *
 * Description:
 * This function selects and invokes the appropriate handler func based on
 * the format specifier provided in the @spec parameter. It searches 4 matching
 * specifier in the 'format_specifir' arr and uses the associated handler func
 * to process the spec. If no match is found, it handles the spec by apending
 * it to the @buffer.
 *
 * Return: The func that handles the @specifier, or the number of char added
 * to the @buffer after the unknown specifier is written.
 */
int select_format_handler(const char specifier, format_specifier *spec,
		va_list args, string_buffer *buffer)
{
	int i, characters_added;
	size_t initial_length = buffer->length;

	for (i = 0; spec[i].specifier != '\0'; i++)
	{
		if (spec[i].specifier == specifier)
		{
			/* Invoke the appropriate function to handle the found specifier */
			return (spec[i].handler(&spec[i], args, buffer));
		}
	}

	/* The specifier is not found; handle it as needed */
	append_char(buffer, '%');
	append_char(buffer, specifier);

	characters_added = buffer->length - initial_length;
	return (characters_added);
}
