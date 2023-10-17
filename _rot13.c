#include "main.h"

/**
 * rot13 - Encodes a string using ROT13
 * @s: String to encode
 * Return: Pointer to the encoded string
 */
char *rot13(char *s)
{
	char *input = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *output = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (int i = 0; s[i] != '\0'; i++)
	{
		char *pos = strchr(input, s[i]);

		if (pos != NULL)
		{
			s[i] = output[pos - input];
		}
	}

	return (s);
}
