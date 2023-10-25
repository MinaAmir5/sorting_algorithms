#include "deck.h"

/**
 * _strcmp - Compares two strings.
 * @Copy_PU8_Str1: The first string.
 * @Copy_PU8_Str2: The second string.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2
 */
int _strcmp(const char *Copy_PU8_Str1, const char *Copy_PU8_Str2)
{
	while (*Copy_PU8_Str1 && *Copy_PU8_Str2 && *Copy_PU8_Str1 ==
		*Copy_PU8_Str2)
	{
		Copy_PU8_Str1++;
		Copy_PU8_Str2++;
	}
	if (*Copy_PU8_Str1 != *Copy_PU8_Str2)
		return (*Copy_PU8_Str1 - *Copy_PU8_Str2);
	return (0);
}

/**
 * get_value - Get the numerical value of a card.
 * @Copy_Deck_Card: A pointer to a card.
 *
 * Return: The numerical value of the card.
 */
char get_value(deck_node_t *Copy_Deck_Card)
{
	if (_strcmp(Copy_Deck_Card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(Copy_Deck_Card->card->value, "1") == 0)
		return (1);
	if (_strcmp(Copy_Deck_Card->card->value, "2") == 0)
		return (2);
	if (_strcmp(Copy_Deck_Card->card->value, "3") == 0)
		return (3);
	if (_strcmp(Copy_Deck_Card->card->value, "4") == 0)
		return (4);
	if (_strcmp(Copy_Deck_Card->card->value, "5") == 0)
		return (5);
	if (_strcmp(Copy_Deck_Card->card->value, "6") == 0)
		return (6);
	if (_strcmp(Copy_Deck_Card->card->value, "7") == 0)
		return (7);
	if (_strcmp(Copy_Deck_Card->card->value, "8") == 0)
		return (8);
	if (_strcmp(Copy_Deck_Card->card->value, "9") == 0)
		return (9);
	if (_strcmp(Copy_Deck_Card->card->value, "10") == 0)
		return (10);
	if (_strcmp(Copy_Deck_Card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(Copy_Deck_Card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind - Sort a deck of cards from spades to diamonds.
 * @Copy_PPD_Deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_kind(deck_node_t **Copy_PPD_Deck)
{
	deck_node_t *Local_Deck_Loop, *Local_PDeck_Ins, *Local_PDeck_Temp;

	for (Local_Deck_Loop = (*Copy_PPD_Deck)->next; Local_Deck_Loop != NULL;
		Local_Deck_Loop = Local_PDeck_Temp)
	{
		Local_PDeck_Ins = Local_Deck_Loop->prev;
		Local_PDeck_Temp = Local_Deck_Loop->next;
		while (Local_PDeck_Ins != NULL && Local_PDeck_Ins->card->kind >
			Local_Deck_Loop->card->kind)
		{
			if (Local_Deck_Loop->next != NULL)
				Local_Deck_Loop->next->prev = Local_PDeck_Ins;
			Local_PDeck_Ins->next = Local_Deck_Loop->next;
			Local_Deck_Loop->next = Local_PDeck_Ins;
			Local_Deck_Loop->prev = Local_PDeck_Ins->prev;
			if (Local_PDeck_Ins->prev != NULL)
				Local_PDeck_Ins->prev->next = Local_Deck_Loop;
			else
				*Copy_PPD_Deck = Local_Deck_Loop;
			Local_PDeck_Ins->prev = Local_Deck_Loop;
			Local_PDeck_Ins = Local_Deck_Loop->prev;
		}
	}
}

/**
 * insertion_sort_deck_value - Sort a deck of cards
 * @Copy_PPD_Deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_value(deck_node_t **Copy_PPD_Deck)
{
	deck_node_t *Local_Deck_Loop, *Local_PDeck_Ins, *Local_PDeck_Temp;

	for (Local_Deck_Loop = (*Copy_PPD_Deck)->next; Local_Deck_Loop != NULL;
		Local_Deck_Loop = Local_PDeck_Temp)
	{
		Local_PDeck_Ins = Local_Deck_Loop->prev;
		Local_PDeck_Temp = Local_Deck_Loop->next;
		while (Local_PDeck_Ins != NULL &&
			Local_PDeck_Ins->card->kind == Local_Deck_Loop->card->kind &&
		       get_value(Local_PDeck_Ins) > get_value(Local_Deck_Loop))
		{
			if (Local_Deck_Loop->next != NULL)
				Local_Deck_Loop->next->prev = Local_PDeck_Ins;
			Local_PDeck_Ins->next = Local_Deck_Loop->next;

			Local_Deck_Loop->next = Local_PDeck_Ins;
			Local_Deck_Loop->prev = Local_PDeck_Ins->prev;
			if (Local_PDeck_Ins->prev != NULL)
				Local_PDeck_Ins->prev->next = Local_Deck_Loop;
			else
				*Copy_PPD_Deck = Local_Deck_Loop;
			Local_PDeck_Ins->prev = Local_Deck_Loop;
			Local_PDeck_Ins = Local_Deck_Loop->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 * @Copy_PPD_Deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **Copy_PPD_Deck)
{
	if ((*Copy_PPD_Deck)->next == NULL || Copy_PPD_Deck == NULL ||
		*Copy_PPD_Deck == NULL)
		return;
	insertion_sort_deck_kind(Copy_PPD_Deck);
	insertion_sort_deck_value(Copy_PPD_Deck);
}
