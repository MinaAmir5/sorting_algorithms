#include "sort.h"

/**
 * Insert_Nodes_Swap - Swap two nodes in a listint_t doubly-linked list.
 * @Copy_PPU_Head: Pointer to the head of the doubly-linked list.
 * @Copy_PPU_Node1: Pointer to the first node to swap.
 * @Copy_PPU_Node2: Pointer to the second node to swap.
 */
void Insert_Nodes_Swap(listint_t **Copy_PPU_Head, listint_t **Copy_PPU_Node1,
	listint_t *Copy_PPU_Node2)
{
	if (Copy_PPU_Node2->next != NULL)
		Copy_PPU_Node2->next->prev = *Copy_PPU_Node1;
	Copy_PPU_Node2->prev = (*Copy_PPU_Node1)->prev;
	(*Copy_PPU_Node1)->next = Copy_PPU_Node2->next;
	if ((*Copy_PPU_Node1)->prev != NULL)
		(*Copy_PPU_Node1)->prev->next = Copy_PPU_Node2;
	else
		*Copy_PPU_Head = Copy_PPU_Node2;
	(*Copy_PPU_Node1)->prev = Copy_PPU_Node2;
	Copy_PPU_Node2->next = *Copy_PPU_Node1;
	*Copy_PPU_Node1 = Copy_PPU_Node2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * @Copy_PPU_Head: A pointer to the head of a doubly-linked list of integers.
 */
void insertion_sort_list(listint_t **Copy_PPU_Head)
{
	listint_t *Local_PU_Loop, *Local_PU_Node, *Local_PU_Container;

	if (Copy_PPU_Head == NULL || (*Copy_PPU_Head)->next == NULL ||
		*Copy_PPU_Head == NULL)
		return;

	for (Local_PU_Loop = (*Copy_PPU_Head)->next; Local_PU_Loop != NULL;
		Local_PU_Loop = Local_PU_Container)
	{
		Local_PU_Node = Local_PU_Loop->prev;
		Local_PU_Container = Local_PU_Loop->next;
		while (Local_PU_Node != NULL && Local_PU_Loop->n < Local_PU_Node->n)
		{
			Insert_Nodes_Swap(Copy_PPU_Head, &Local_PU_Node, Local_PU_Loop);
			print_list((const listint_t *)*Copy_PPU_Head);
		}
	}
}
