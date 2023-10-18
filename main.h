#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>

#define BIN 2
#define OCT 8
#define DEC 10
#define HEX 16
#define is_non_print(c) ((c < 32 || c >= 127) ? 1 : 0)

/**
 * struct string_buffer - Holds a dynamically growing string
 * @data: Character array to store the string
 * @capacity: Capacity of the character array
 * @length: Current length of the string
 */
typedef struct string_buffer
{
	char *data;
	size_t capacity;
	size_t length;
} string_buffer;

void init_string_buffer(string_buffer *buff);
void append_char(string_buffer *buff, char x);
void append_string(string_buffer *buff, const char *s);

/**
 * struct format_specifier - Holds format specifier information
 * @specifier: Format specifier character (e.g., 'd', 's', 'x', etc.)
 * @width: Field width
 * @precision: Field precision
 * @length: Length modifier ('l' for long, 'h' for short, 0 for none)
 * @handler: Function that handles this format specifier
 * @format: The original format string
 */
typedef struct format_specifier
{
	char specifier;
	int width;
	int precision;
	char length;
	int (*handler)(const struct format_specifier *, va_list,
			struct string_buffer *);
	const char *format;
} format_specifier;

int select_format_handler(const char specifier, format_specifier *spec,
		va_list args, string_buffer *buffer);
int custom_printf(string_buffer *buff, const char *format, va_list args);
const char *parse_modifiers(const char *format, format_specifier *spc,
		string_buffer *buff);
format_specifier *create_format_specifiers(void);
void print_str_buffer(const char *str, size_t len);
int handle_precision(const char *format, format_specifier *spc,
		string_buffer *buff);
int handle_width(const char *format, format_specifier *spc,
		string_buffer *buff);
int handle_string(const format_specifier *spc, va_list args,
		string_buffer *buff);
int handle_custom_string(const format_specifier *spc, va_list args,
		string_buffer *buff);
int handle_rot13(const format_specifier *spc, va_list args,
		string_buffer *buff);
int handle_string_reversal(const format_specifier *spc, va_list args,
		string_buffer *buff);
int handle_char(const format_specifier *spc, va_list args,
		string_buffer *buff);
int handle_percent(const format_specifier *spc, va_list args,
		string_buffer *buff);
//int handle_float(const format_specifier *spc, va_list args,
//		string_buffer *buff);
int handle_unsigned(const format_specifier *spc, va_list args,
		string_buffer *buff);
int handle_decimal(const format_specifier *spc, va_list args,
		string_buffer *buff);
int handle_unsigned_int(const format_specifier *spc, va_list args,
		string_buffer *buff);
int handle_binary(const format_specifier *spc, va_list args,
		string_buffer *buff);
int handle_hex_lower(const format_specifier *spc, va_list args,
		string_buffer *buff);
int handle_hex_upper(const format_specifier *spc, va_list args,
		string_buffer *buff);
int handle_octal(const format_specifier *spc, va_list args,
		string_buffer *buff);
int handle_pointer(const format_specifier *spc, va_list args,
		string_buffer *buff);
int _printf(const char *format, ...);
void _itob(ssize_t number, char *buffer, int base);
void utob(size_t number, char *buffer, int base);
void _reverse_str(char *buffer, size_t len);
char *_strchr(const char *s, int c);
char *rot13(char *s);
size_t _strlen(const char *str);
char *_strdup(const char *s);
void char_to_hex(char *buff, unsigned char x);
void *_realloc(void *old_mem_blk, size_t old_size, size_t new_size);
void *_memcpy(void *dest, const void *src, size_t n);
void safely_free(void **ptr);
#define safe_free(p) _free((void **) &(p))

#endif /* MAIN_H */
