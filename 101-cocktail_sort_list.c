#include "sort.h"

void swap_node_ahead_ER(listint_t **list,
	listint_t **tail, listint_t **shaker_ER);
void swap_node_behind_ER(listint_t **list,
	listint_t **tail, listint_t **shaker_ER);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead_ER - Swap a node in a listint_t doubly-linked list
 *                   list of int with the node ahead f it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker_ER: A pointer to the current
 * swapping node of the cocktail shaker algo.
 */
void swap_node_ahead_ER(listint_t **list,
	listint_t **tail, listint_t **shaker_ER)
{
	listint_t *tmp = (*shaker_ER)->next;

	if ((*shaker_ER)->prev != NULL)
		(*shaker_ER)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker_ER)->prev;
	(*shaker_ER)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker_ER;
	else
		*tail = *shaker_ER;
	(*shaker_ER)->prev = tmp;
	tmp->next = *shaker_ER;
	*shaker_ER = tmp;
}

/**
 * swap_node_behind_ER - Swap a node in a listint_t doubly-linked
 *                    list of int with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker_ER: A pointer to the current
 * swapping node of the cocktail shaker algo.
 */
void swap_node_behind_ER(listint_t **list,
	listint_t **tail, listint_t **shaker_ER)
{
	listint_t *tmp = (*shaker_ER)->prev;

	if ((*shaker_ER)->next != NULL)
		(*shaker_ER)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker_ER)->next;
	(*shaker_ER)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker_ER;
	else
		*list = *shaker_ER;
	(*shaker_ER)->next = tmp;
	tmp->prev = *shaker_ER;
	*shaker_ER = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked lis
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker_ER;
	bool shaken_not_stirred_ER = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred_ER == false)
	{
		shaken_not_stirred_ER = true;
		for (shaker_ER = *list; shaker_ER != tail; shaker_ER = shaker_ER->next)
		{
			if (shaker_ER->n > shaker_ER->next->n)
			{
				swap_node_ahead_ER(list, &tail, &shaker_ER);
				print_list((const listint_t *)*list);
				shaken_not_stirred_ER = false;
			}
		}
		for (shaker_ER = shaker_ER->prev; shaker_ER != *list;
				shaker_ER = shaker_ER->prev)
		{
			if (shaker_ER->n < shaker_ER->prev->n)
			{
				swap_node_behind_ER(list, &tail, &shaker_ER);
				print_list((const listint_t *)*list);
				shaken_not_stirred_ER = false;
			}
		}
	}
}
