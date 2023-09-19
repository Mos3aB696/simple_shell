#include "shell.h"

/**
 * _getHistory - gets history file
 * @info: struct
 *
 * Return: string containing history file
 */
char *_getHistory(info_t *info)
{
	char *buf, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

/**
 * _writeHistory - creates a file
 * @info: struct
 *
 * Return: 1 or -1
 */
int _writeHistory(info_t *info)
{
	ssize_t fd;
	char *filename = _getHistory(info);
	list_t *node;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->data, fd);
		_putcharfd('\n', fd);
	}
	_putcharfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * _readHistory - reads history from file
 * @info: struct
 *
 * Return: 0 or history count
 */
int _readHistory(info_t *info)
{
	int i, last = 0, lCount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = _getHistory(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			_listHistory(info, buf + last, lCount++);
			last = i + 1;
		}
	if (last != i)
		_listHistory(info, buf + last, lCount++);
	free(buf);
	info->history_count = lCount;
	while (info->history_count-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	_renumberHistory(info);
	return (info->history_count);
}

/**
 * _listHistory - add entry to history list
 * @info: struct
 * @buf: buffer
 * @lcount: history line count
 *
 * Return: 0
 */
int _listHistory(info_t *info, char *buf, int lcount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, lcount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * _renumberHistory - renumber histiry linked list
 * @info: struct
 *
 * Return: new history count
 */
int _renumberHistory(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->history_count = i);
}
