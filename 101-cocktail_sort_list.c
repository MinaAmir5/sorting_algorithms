#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 * @Copy_PPU_Head: A pointer to the head of a doubly-linked list.
 * @Copy_PPU_Tail: A pointer to the tail of the doubly-linked list.
 * @Copy_PPU_Node: A pointer to the current swapping node of the cocktail shake
 */
void swap_node_ahead(listint_t **Copy_PPU_Head, listint_t **Copy_PPU_Tail,
	listint_t **Copy_PPU_Node)
{
	listint_t *Local_PU_Temp = (*Copy_PPU_Node)->next;

	if ((*Copy_PPU_Node)->prev != NULL)
		(*Copy_PPU_Node)->prev->next = Local_PU_Temp;
	else
		*Copy_PPU_Head = Local_PU_Temp;
	(*Copy_PPU_Node)->next = Local_PU_Temp->next;
	Local_PU_Temp->prev = (*Copy_PPU_Node)->prev;
	if (Local_PU_Temp->next != NULL)
		Local_PU_Temp->next->prev = *Copy_PPU_Node;
	else
		*Copy_PPU_Tail = *Copy_PPU_Node;
	Local_PU_Temp->next = *Copy_PPU_Node;
	(*Copy_PPU_Node)->prev = Local_PU_Temp;
	*Copy_PPU_Node = Local_PU_Temp;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 * @Copy_PPU_Head: A pointer to the head of a doubly-linked list.
 * @Copy_PPU_Tail: A pointer to the tail of the doubly-linked list.
 * @Copy_PPU_Node: A pointer to the current swapping node of the cocktail shake
 */
void swap_node_behind(listint_t **Copy_PPU_Head, listint_t **Copy_PPU_Tail,
	listint_t **Copy_PPU_Node)
{
	listint_t *Local_PU_Temp = (*Copy_PPU_Node)->prev;

	if ((*Copy_PPU_Node)->next != NULL)
		(*Copy_PPU_Node)->next->prev = Local_PU_Temp;
	else
		*Copy_PPU_Tail = Local_PU_Temp;
	Local_PU_Temp->next = (*Copy_PPU_Node)->next;
	(*Copy_PPU_Node)->prev = Local_PU_Temp->prev;
	if (Local_PU_Temp->prev != NULL)
		Local_PU_Temp->prev->next = *Copy_PPU_Node;
	else
		*Copy_PPU_Head = *Copy_PPU_Node;
	(*Copy_PPU_Node)->next = Local_PU_Temp;
	Local_PU_Temp->prev = *Copy_PPU_Node;
	*Copy_PPU_Node = Local_PU_Temp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers
 * @Copy_PPU_Head: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **Copy_PPU_Head)
{
	bool Local_Bool_Sorted = false;
	listint_t *Local_PPU_Tail, *Local_PPU_Node;

	if (Copy_PPU_Head == NULL || *Copy_PPU_Head == NULL ||
		(*Copy_PPU_Head)->next == NULL)
		return;
	Local_PPU_Tail = *Copy_PPU_Head;
	while (Local_PPU_Tail->next != NULL)
		Local_PPU_Tail = Local_PPU_Tail->next;

	while (Local_Bool_Sorted == false)
	{
		Local_Bool_Sorted = true;
		for (Local_PPU_Node = *Copy_PPU_Head; Local_PPU_Node != Local_PPU_Tail;
			Local_PPU_Node = Local_PPU_Node->next)
		{
			if (Local_PPU_Node->n > Local_PPU_Node->next->n)
			{
				swap_node_ahead(Copy_PPU_Head, &Local_PPU_Tail,
					&Local_PPU_Node);
				print_list((const listint_t *)*Copy_PPU_Head);
				Local_Bool_Sorted = false;
			}
		}
		for (Local_PPU_Node = Local_PPU_Node->prev; Local_PPU_Node != *Copy_PPU_Head;
			Local_PPU_Node = Local_PPU_Node->prev)
		{
			if (Local_PPU_Node->n < Local_PPU_Node->prev->n)
			{
				swap_node_behind(Copy_PPU_Head, &Local_PPU_Tail, &Local_PPU_Node);
				Local_Bool_Sorted = false;
				print_list((const listint_t *)*Copy_PPU_Head);
			}
		}
	}
}
