#ifndef main_h
#define main_h

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define unused(x) (void)(x)
#define buff_size 1024

/* flags */
#define f_minus 1
#define f_plus 2
#define f_zero 4
#define f_hash 8
#define f_space 16

/* sizes */
#define s_long 2
#define s_short 1

/**
 * struct fmt - Represents a formatted object.
 *
 * This struct represents a formatted object that includes a format
 * character and a function pointer. The format character ('fmt') specifies
 * the format of the object, and the function pointer ('fn') points to
 * the function that applies the format to the object.
 *
 * @fmt: The format character.
 * @fn: The function that applies the format.
 */
typedef struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
} fmt_t;

int printf(const char *format, ...);

int handle_print(const char *fmt, int *i,
		va_list list, char buffer[], int flags, int width, int precision, int size);

/* Functions to print chars and strings */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
	char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* Function to print memory address */
int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/* Function to print string in reverse*/
int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* Function to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
		int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
		int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
		char buffer[],
		int flags, int width, int precision, int size);

/* Utils */
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* main_h */

