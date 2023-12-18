#include "deck.h"

int _strcmp_ER(const char *s1_ER, const char *s2_ER);
char get_value_ER(deck_node_t *card);
void insertion_sort_deck_kind_ER(deck_node_t **deck);
void insertion_sort_deck_value_ER(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp_ER - Compares two strs.
 * @s1_ER: The first string.
 * @s2_ER: The second string.
 *
 * Return: Positive byte difference if s1_ER > s2_ER
 *         0 if s1_ER == s2_ER
 *         Negative byte difference if s1_ER < s2_ER
 */
int _strcmp_ER(const char *s1_ER, const char *s2_ER)
{
	while (*s1_ER && *s2_ER && *s1_ER == *s2_ER)
	{
		s1_ER++;
		s2_ER++;
	}

	if (*s1_ER != *s2_ER)
		return (*s1_ER - *s2_ER);
	return (0);
}

/**
 * get_value_ER - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The num value of the card.
 */
char get_value_ER(deck_node_t *card)
{
	if (_strcmp_ER(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp_ER(card->card->value, "1") == 0)
		return (1);
	if (_strcmp_ER(card->card->value, "2") == 0)
		return (2);
	if (_strcmp_ER(card->card->value, "3") == 0)
		return (3);
	if (_strcmp_ER(card->card->value, "4") == 0)
		return (4);
	if (_strcmp_ER(card->card->value, "5") == 0)
		return (5);
	if (_strcmp_ER(card->card->value, "6") == 0)
		return (6);
	if (_strcmp_ER(card->card->value, "7") == 0)
		return (7);
	if (_strcmp_ER(card->card->value, "8") == 0)
		return (8);
	if (_strcmp_ER(card->card->value, "9") == 0)
		return (9);
	if (_strcmp_ER(card->card->value, "10") == 0)
		return (10);
	if (_strcmp_ER(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp_ER(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind_ER - Sort a deck of cards from spades to diamond.
 * @deck: A pointer to the head of a deck_node_t doubly-linke
 */
void insertion_sort_deck_kind_ER(deck_node_t **deck)
{
	deck_node_t *iter_ER, *insert_ER, *tmp;

	for (iter_ER = (*deck)->next; iter_ER != NULL; iter_ER = tmp)
	{
		tmp = iter_ER->next;
		insert_ER = iter_ER->prev;
		while (insert_ER != NULL && insert_ER->card->kind > iter_ER->card->kind)
		{
			insert_ER->next = iter_ER->next;
			if (iter_ER->next != NULL)
				iter_ER->next->prev = insert_ER;
			iter_ER->prev = insert_ER->prev;
			iter_ER->next = insert_ER;
			if (insert_ER->prev != NULL)
				insert_ER->prev->next = iter_ER;
			else
				*deck = iter_ER;
			insert_ER->prev = iter_ER;
			insert_ER = iter_ER->prev;
		}
	}
}

/**
 * insertion_sort_deck_value_ER - Sort a deck of cards sorted from
 *                             spades to diamonds from ace to king.
 * @deck: A pointer to the head oF a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_value_ER(deck_node_t **deck)
{
	deck_node_t *iter_ER, *insert_ER, *tmp;

	for (iter_ER = (*deck)->next; iter_ER != NULL; iter_ER = tmp)
	{
		tmp = iter_ER->next;
		insert_ER = iter_ER->prev;
		while (insert_ER != NULL &&
		       insert_ER->card->kind == iter_ER->card->kind &&
		       get_value_ER(insert_ER) > get_value_ER(iter_ER))
		{
			insert_ER->next = iter_ER->next;
			if (iter_ER->next != NULL)
				iter_ER->next->prev = insert_ER;
			iter_ER->prev = insert_ER->prev;
			iter_ER->next = insert_ER;
			if (insert_ER->prev != NULL)
				insert_ER->prev->next = iter_ER;
			else
				*deck = iter_ER;
			insert_ER->prev = iter_ER;
			insert_ER = iter_ER->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind_ER(deck);
	insertion_sort_deck_value_ER(deck);
}
