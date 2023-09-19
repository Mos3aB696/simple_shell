#include "shell.h"

/**
 * _strtok - splites a string into words, Repeat del are ign
 * @str: input string
 * @d: delimeter
 *
 * Return: ptr to an array of strings, or NULL on failure
 */
char **_strtok(char *str, char *d)
{
	int i, j, k, m, numwords = 0;
	char **ptr;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!_isdelim(str[i], d) && (_isdelim(str[i + 1], d) || !str[i + 1]))
			numwords++;
	if (numwords == 0)
		return (NULL);
	ptr = malloc((numwords + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (_isdelim(str[i], d))
			i++;
		k = 0;
		while (!_isdelim(str[i + k], d) && str[i + k])
			k++;
		ptr[j] = malloc((k + 1) * sizeof(char));
		if (!ptr[j])
		{
			for (k = 0; k < j; k++)
				free(ptr[k]);
			free(ptr);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			ptr[j][m] = str[i++];
		ptr[j][m] = 0;
	}
	ptr[j] = NULL;
	return (ptr);
}
