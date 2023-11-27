#include "sort.h"

/**
 * swap_list - function interchanges two successive nodes
 * @pre: node before the key
 * @key: node inserted at its right position
 * Return: Nothing
 */

void swap_list(listint_t **pre, listint_t **key)
{
	listint_t *tmp;
	listint_t *new;

	tmp = (*key)->next;
	new = (*pre)->prev;

	if (tmp != NULL)
		tmp->prev = (*pre);
	if (new != NULL)
		new->next = (*key);
	(*key)->next = (*pre);
	(*pre)->next = tmp;
	(*key)->prev = new;
	(*pre)->prev = (*key);
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the list
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key, *pre;

	if ((*list) == NULL || (*list)->next == NULL || list == NULL
			|| (*list)->prev != NULL)
		return;

	current = (*list);
	current = current->next;

	while (current != NULL)
	{
		key = current;
		pre = current->prev;
		while (pre != NULL && ((pre->n) > (key->n)))
		{
			swap_list(&pre, &key);
			pre = key->prev;
			if (pre == NULL)
				(*list) = key;
			print_list(*list);
		}
		current = current->next;
	}
}
