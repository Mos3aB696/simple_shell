#include "shell.h"

/**
 * _strdup - make duplcation to string
 * @src: the string to make duplcation
 *
 * Return: str
 */

char *_strdup(const char *src)
{
	char *str, *new;
	int len = 0;

	while (src[len])
		len++;
	str = malloc(len + 1);
	new = str;
	while (*src)
		*new++ = *src++;
	*new = '\0';
	return (str);
}

/**
 * *_strcat - function that concatenates two strings
 * @dest: string one
 * @src: string two
 *
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	size_t i = 0, j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen - fucntion that return string length
 * @str: the string
 *
 * Return: i
 */

int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * _strcmp - function that compare two string
 * @s1: String One
 * @s2: String Two
 *
 * Return: 0
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 - *s2 != 0)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
/**
 * _strchr - locates char in a string
 * @str: stirng to be parsed
 * @c: character
 *
 * Return: pointer to
 */
char *_strchr(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}
