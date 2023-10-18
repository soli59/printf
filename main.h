#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>

/* base numerals */
#define BIN 2
#define OCT 8
#define DEC 10
#define HEX 16

/* check foor non-printable characters */
#define is_non_print(c) ((c < 32 || c >= 127) ? 1 : 0)

/**
 * struct string_buffer - structure to hold a dynamically growing string
 * @data: the character array to store the string
 * @capacity: the capacity of the character array
 * @length: the current length of the string
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
 * struct format_specifier - structure to hold format specifier information
 * @specifier: format specifier character (e.g., 'd', 's', 'x', etc.)
 * @width: field width
 * @precision: field precision
 * @length: length modifier ('l' for long, 'h' for short, 0 for none)
 * @plus_flag: the '+' (plus) flag
 * @space_flag: the ' ' (space) flag
 * @sharp_flag: the '#' flag
 * @handler: pointer to the function that handles this format specifier
 */
typedef struct format_specifier
{
	char specifier;
	int width;
	int precision;
	char length;
	int plus_flag;
	int space_flag;
	int sharp_flag;
	int (*handler)(const struct format_specifier *, va_list,
			struct string_buffer *);
} format_specifier;

/* format selector */
int select_format_handler(const char specifier, format_specifier *spec,
		va_list args, string_buffer *buffer);
<<<<<<< HEAD

/* a helper function to the _printf() function */
int custom_printf(string_buffer *buffer, const char *format, va_list args);

/* string modifiers parser */
const char *parse_modifiers(const char *format, format_specifier *spec,
		string_buffer *buffer);

/* creates an array of format specifiers and used by the multiple functions */
=======
int custom_printf(string_buffer *buff, const char *format, va_list args);
const char *parse_modifiers(const char *format, format_specifier *spc,
		string_buffer *buff);
>>>>>>> ef788982b54a6348f3be5879099c2b7ba72ab08b
format_specifier *create_format_specifiers(void);

/* prints the resultant string buffer */
void print_str_buffer(const char *str, size_t len);
<<<<<<< HEAD

/* string handlers */
int handle_precision(const char *format, format_specifier *spec,
		string_buffer *buffer);
int handle_width(const char *format, format_specifier *spec,
		string_buffer *buffer);
int handle_string(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_custom_string(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_rot13(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_string_reversal(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_char(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_percent(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_float(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_unsigned(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_decimal(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_unsigned_int(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_binary(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_hex_lower(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_hex_upper(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_octal(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_pointer(const format_specifier *spec, va_list args,
		string_buffer *buffer);

/* prototype for the _printf function */
=======
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
>>>>>>> ef788982b54a6348f3be5879099c2b7ba72ab08b
int _printf(const char *format, ...);

/* handles number to string conversion */
void _itob(ssize_t number, char *buffer, int base);
void utob(size_t number, char *buffer, int base);

/* string manipulation functions */
void _reverse_str(char *buffer, size_t len);
char *_strchr(const char *s, int c);
char *rot13(char *s);
size_t _strlen(const char *str);
char *_strdup(const char *s);
<<<<<<< HEAD
void char_to_hex(char *buffer, unsigned char ch);

/* memory management functions */
void *_realloc(void *old_mem_blk, size_t old_size, size_t new_size);
void *_memcpy(void *dest, const void *src, size_t n);
/* a safer way to deallocate dynamic memory */
void _free(void **ptr);
=======
void char_to_hex(char *buff, unsigned char x);
void *_realloc(void *old_mem_blk, size_t old_size, size_t new_size);
void *_memcpy(void *dest, const void *src, size_t n);
void safely_free(void **ptr);
>>>>>>> ef788982b54a6348f3be5879099c2b7ba72ab08b
#define safe_free(p) _free((void **) &(p))

#endif /* MAIN_H */
