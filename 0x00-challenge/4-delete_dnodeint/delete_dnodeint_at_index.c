#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp, *prev_node, *next_node;
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}
	saved_head = *head;
	p = 0;
	while (p < index && saved_head != NULL)
	{
		saved_head = (saved_head)->next;
		p++;
	}
	if (p != index)
	{
		return (-1);
	}
	if (0 == index)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
		if (tmp != NULL)
		{
			tmp->prev = NULL;
		}
	}
	else
	{
		prev_node = (saved_head)->prev;
		next_node = (saved_head)->next;
		tmp = saved_head;
		free(tmp);
		prev_node->next = next_node;
		if (next_node)
			next_node->prev = prev_node;
	}
	return (1);
}
