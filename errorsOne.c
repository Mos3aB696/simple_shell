#include "shell.h"

/**
 * _errorPuts - prints an input string
 * @str: string to be printed
 *
 * Return: nothing
 */
void _errorPuts(char *str)
{
	int i = 0;

	if (!str)
		return;

	while (str[i] != '\0')
	{
		_errorPutchar(str[i]);
		i++;
	}
}


/**
 * _errorPutchar -write character to stderr
 * @c: character to be printed
 *
 * Return: 1 or -1
 */
int _errorPutchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
/**
 * _putcharfd - write character to fd
 * @c: character to be printed
 * @fd: filedescriptor
 *
 * Return: 1 or -1
 */
int _putcharfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - prints an input string
 * @str: string to be printed
 * @fd: filedescriptor
 *
 * Return: numper of chars put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);

	while (*str)
	{
		i += _putcharfd(*str++, fd);
	}
	return (i);
}
