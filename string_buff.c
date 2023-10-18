#include "main.h"

/**
* init_string_buffer - initializing buffer to hold output
* @buff: dynamic storage placeholder
*/
void init_string_buffer(string_buffer *buff)
{
	buff->data = NULL;
	buff->capacity = 0;
	buff->length = 0;
}

/**
*append_char - adds a char to string buffer
*@buff: the string buffer to save the result
*@x: the char to be written
*/
void append_char(string_buffer *buff, char x)
{
	size_t previous_capacity = buff->capacity;
	char *new;
	if (buff->length + 1 >= buff->capacity)
	{
		buff->capacity = (previous_capacity == 0) ? 2 : previous_capacity * 2;
		new = _realloc(buff->data, previous_capacity, buff->capacity);

		if (new == NULL)
			return;

		buff->data = new;
	}
	buff->data[buff->length] = x;
	buff->length++;
	buff->data[buff->length] = '\0';
}

/**
*append_string - adds a string to buffer
*@buff:buffer to hold result
*@s:string to be added
*/
void append_string(string_buffer *buff, const char *s)
{
	while (*s)
	{
		append_char(buff, *s);
		s++;
	}
}