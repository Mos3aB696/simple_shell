#include "shell.h"

/**
 * _history - display the history list
 * @info: struct
 *
 * Return: 0
 */
int _history(info_t *info)
{
	_printList(info->history);
	return (0);
}

/**
 * _unsetalias - unset alias to string
 * @info: struct
 * @str: the string alias
 *
 * Return: 0 or 1
 */
int _unsetalias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
										get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * _setalias - sets alias to string
 * @info: struct
 * @str: the string
 *
 * Return: 0 or 1
 */
int _setalias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);

	if (!*++p)
		return (_unsetalias(info, str));

	_unsetalias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * _printalias - print an alias string
 * @node: the alias node
 *
 * Return: 0 or 1
 */
int _printalias(list_t *node)
{
	char *str = NULL, *p = NULL;

	if (node)
	{
		str = _strchr(node->data, '=');
		for (p = node->data; p <= str; p++)
			_putchar(*p);
		_putchar('\'');
		_puts(str + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _alias - the alias builtin
 * @info: struct
 *
 * Return: 0
 */
int _alias(info_t *info)
{
	int i = 0;
	char *str = NULL;
	list_t *node;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			_printalias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		str = _strchr(info->argv[i], '=');
		if (str)
			_setalias(info, info->argv[i]);
		else
			_printalias(node_starts_with(info->alias, info->argv[i], '='));
	}
	return (0);
}
