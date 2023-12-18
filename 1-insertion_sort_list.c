#include "sort.h"

/**
 * swap_nodes_ER - Swap two nodes in  doubly-linked list.
 * @h_ER: A pointer to the linked list.
 * @n1_ER: A pointer to the first node to swap.
 * @n2_ER: The second node to swap.
 */
void swap_nodes_ER(listint_t **h_ER,
		listint_t **n1_ER, listint_t *n2_ER)
{
	(*n1_ER)->next = n2_ER->next;
	if (n2_ER->next != NULL)
		n2_ER->next->prev = *n1_ER;
	n2_ER->prev = (*n1_ER)->prev;
	n2_ER->next = *n1_ER;
	if ((*n1_ER)->prev != NULL)
		(*n1_ER)->prev->next = n2_ER;
	else
		*h_ER = n2_ER;
	(*n1_ER)->prev = n2_ER;
	*n1_ER = n2_ER->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using sort algorithm.
 * @list: A pointer to the head of a doubly-linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *iter_ER, *insert_ER, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter_ER = (*list)->next; iter_ER != NULL; iter_ER = tmp)
	{
		tmp = iter_ER->next;
		insert_ER = iter_ER->prev;
		while (insert_ER != NULL && iter_ER->n < insert_ER->n)
		{
			swap_nodes_ER(list, &insert_ER, iter_ER);
			print_list((const listint_t *)*list);
		}
	}
}
