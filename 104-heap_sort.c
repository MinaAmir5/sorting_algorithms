#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @Copy_PU32_Int1: The first integer.
 * @Copy_PU32_Int2: The second integer.
 */
void swap_ints(int *Copy_PU32_Int1, int *Copy_PU32_Int2)
{
	int container;

	container = *Copy_PU32_Int2;
	*Copy_PU32_Int2 = *Copy_PU32_Int1;
	*Copy_PU32_Int1 = container;
}

/**
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @Copy_PU32_Array: An array of integers.
 * @Copy_U32_Size: The size of the array.
 * @Copy_U32_Base: The index of the base row of the tree.
 * @Copy_U32_Root: The root node of the binary tree.
 */
void max_heapify(int *Copy_PU32_Array, unsigned int Copy_U32_Size, unsigned int
	Copy_U32_Base, unsigned int Copy_U32_Root)
{
	unsigned int Local_U32_Large, Local_U32_Left, Local_U32_Right;

	Local_U32_Large = Copy_U32_Root;
	Local_U32_Right = 2 + 2 * Copy_U32_Root;
	Local_U32_Left = 1 + 2 * Copy_U32_Root;

	if (Copy_PU32_Array[Local_U32_Right] > Copy_PU32_Array[Local_U32_Large] &&
		Local_U32_Right < Copy_U32_Base)
		Local_U32_Large = Local_U32_Right;
	if (Copy_PU32_Array[Local_U32_Left] > Copy_PU32_Array[Local_U32_Large] &&
		Local_U32_Left < Copy_U32_Base)
		Local_U32_Large = Local_U32_Left;
	if (Local_U32_Large != Copy_U32_Root)
	{
		swap_ints(Copy_PU32_Array + Copy_U32_Root, Copy_PU32_Array +
			Local_U32_Large);
		print_array(Copy_PU32_Array, Copy_U32_Size);
		max_heapify(Copy_PU32_Array, Copy_U32_Size, Copy_U32_Base, Local_U32_Large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending order.
 * @Copy_PU32_Array: An array of integers.
 * @Copy_U32_Size: The size of the array.
 */
void heap_sort(int *Copy_PU32_Array, unsigned int Copy_U32_Size)
{
	int Local_U32_Counter;

	if (Copy_U32_Size < 2 || Copy_PU32_Array == NULL)
		return;
	for (Local_U32_Counter = (Copy_U32_Size / 2) - 1; Local_U32_Counter >= 0;
		Local_U32_Counter--)
		max_heapify(Copy_PU32_Array, Copy_U32_Size, Copy_U32_Size,
			Local_U32_Counter);
	for (Local_U32_Counter = Copy_U32_Size - 1; Local_U32_Counter > 0;
		Local_U32_Counter--)
	{
		swap_ints(Copy_PU32_Array, Copy_PU32_Array + Local_U32_Counter);
		print_array(Copy_PU32_Array, Copy_U32_Size);
		max_heapify(Copy_PU32_Array, Copy_U32_Size, Local_U32_Counter, 0);
	}
}
