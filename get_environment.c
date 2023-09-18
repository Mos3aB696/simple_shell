#include "shell.h"

/**
 * get_environ - returns the string array copy of our environ
 * @info: structure containing potential arguments
 *
 * Return: 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_change)
	{
		info->environ = list_to_str(info->env);
		info->env_change = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - remove an environment variable
 * @info: structure contain potential arguments
 * @var: string env var
 *
 * Return: 1 or 0
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = _startWith(node->data, var);
		if (p && *p == '=')
		{
			info->env_change = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_change);
}

/**
 * _setenv - initialize a new environment variables
 * @info: structure cntaining potential arguments
 * @var: the string env var property
 * @value: the string env var value
 *
 * Return: 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);

	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;

	while (node)
	{
		p = _startWith(node->data, var);
		if (p && *p == '=')
		{
			free(node->data);
			node->data = buf;
			info->env_change = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_change = 1;
	return (0);
}
