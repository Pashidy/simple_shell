#include "shell.h"

/**
 * get_list_length - determines the length of the linked list
 * @head: pointer to the first node
 *
 * Return: size of the list
 */
size_t get_list_length(const list_t *head)
{
	size_t length = 0;

	while (head)
	{
	head = head->next;
	length++;
	}

	return (length);
}

/**
 * list_to_strings - returns an array of strings from the list->str
 * @head: pointer to the first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
	size_t length = get_list_length(head);
	char **strings;
	size_t i = 0;

	if (!head || !length)
	return (NULL);

	strings = malloc(sizeof(char *) * (length + 1));
	if (!strings)
	return (NULL);

	while (head)
	{
	strings[i] = _strdup(head->str);

	if (!strings[i])
	{
	for (size_t j = 0; j < i; j++)
	free(strings[j]);
	free(strings);
	return (NULL);
	}
	head = head->next;
	i++;
	}
	strings[i] = NULL;
	return (strings);
}

/**
 * print_list - prints all elements of a list_t linked list
 * @head: pointer to the first node
 *
 * Return: size of the list
 */
size_t print_list(const list_t *head)
{
	size_t i = 0;

	while (head)
	{
	_puts(convert_number(head->num, 10, 0));
	_putchar(':');
	_putchar(' ');
	_puts(head->str ? head->str : "(nil)");
	_puts("\n");
	head = head->next;
	i++;
	}

	return (i);
}

/**
 * find_node_starts_with - returns the node whose string
 * starts with the prefix
 * @head: pointer to the list head
 * @prefix: string to match
 * @c: the next character after the prefix to match
 *
 * Return: matching node or null
 */
list_t *find_node_starts_with(list_t *head, char *prefix, char c)
{
	char *p = NULL;

	while (head)
	{
	p = starts_with(head->str, prefix);

	if (p && ((c == -1) || (*p == c)))
		return (head);
	head = head->next;
	}

	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to the list head
 * @node: pointer to the node
 *
 * Return: index of the node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t index = 0;

	while (head)
	{
	if (head == node)
		return (index);
	head = head->next;
	index++;
	}

	return (-1);
}
