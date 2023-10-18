#include "main.h"

/**
 * _strdup - Duplicates a string.
 * @str: string to duplicate
 *
 * Description: The _strdup() function returns a pointer to a newly allocated
 * space in memory, which contains a copy of the string @str. Memory for the
 * new string is obtained with malloc() and can be freed with free()
 *
 * Return: A pointer to the duplicated string, NULL if it fails/
 */
char *_strdup(const char *s)
{
	char *dup_str;
	int i = 0;

	if (s == NULL)
		return (NULL);

	dup_str = malloc(_strlen(s) + 1);

	if (dup_str == NULL)
		return (NULL);

	while (s[i] != '\0')
	{
		dup_str[i] = s[i];
		i++;
	}
	dup_str[i] = '\0';

	return (dup_str);
}
