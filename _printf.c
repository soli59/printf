#include "main.h"

void print_buff(char buff[], int *index_buff);

/**
 * my_printf - Printf function
 * @form: format.
 * Return: Printed chars.
 */
int my_printf(const char *form, ...)
{
	int idx, print_res = 0, total_printed_chars = 0;
	int flag_val, width_val, precision_val, size_val, index_buff = 0;
	va_list val_list;
	char buff[BUFF_SIZE];

	if (form == NULL)
		return (-1);

	va_start(val_list, form);

	for (idx = 0; form && form[idx] != '\0'; idx++)
	{
		if (form[idx] != '%')
		{
			buff[index_buff++] = form[idx];
			if (index_buff == BUFF_SIZE)
				print_buff(buff, &index_buff);
			total_printed_chars++;
		}
		else
		{
			print_buff(buff, &index_buff);
			flag_val = get_flags(form, &idx);
			width_val = get_width(form, &idx, val_list);
			precision_val = get_precision(form, &idx, val_list);
			size_val = get_size(form, &idx);
			++idx;
			print_res = handle_print(form, &idx, val_list, buff,
				flag_val, width_val, precision_val, size_val);
			if (print_res == -1)
				return (-1);
			total_printed_chars += print_res;
		}
	}

	print_buff(buff, &index_buff);

	va_end(val_list);

	return (total_printed_chars);
}

/**
 * print_buff - Prints the contents of the buffer if it exists
 * @buff: Array of chars
 * @index_buff: Index at which to add the next char, represents the length.
 */
void print_buff(char buff[], int *index_buff)
{
	if (*index_buff > 0)
		write(1, &buff[0], *index_buff);

	*index_buff = 0;
}
