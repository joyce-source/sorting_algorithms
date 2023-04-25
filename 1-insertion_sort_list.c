#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of int in ascending order
 * @list: A pointer to a pointer to the first node of the list to be sorted
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *tmp;

	if (!list || !(*list) || !(*list)->next)
		return;

	curr = (*list)->next;

	while (curr)
	{
		tmp = curr->prev;

		while (tmp && tmp->n > curr->n)
		{
			tmp->next = curr->next;

			if (curr->next)
				curr->next->prev = tmp;
			curr->next = tmp;
			curr->prev = tmp->prev;
			tmp->prev = curr;

			if (curr->prev)
				curr->prev->next = curr;
			else
				*list = curr;

			tmp = curr->prev;
			print_list(*list);
		}
		curr = curr->next;
	}
}
