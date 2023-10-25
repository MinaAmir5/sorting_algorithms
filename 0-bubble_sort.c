#include "sort.h"

/**
 * Bubble_ints_Swap - Swap two integers in an array.
 * @Copy_PU32_Int1: The first integer.
 * @Copy_PU32_Int2: The second integer.
 */
void Bubble_ints_Swap(int *Copy_PU32_Int1, int *Copy_PU32_Int2)
{
	int container;

	container = *Copy_PU32_Int2;
	*Copy_PU32_Int2 = *Copy_PU32_Int1;
	*Copy_PU32_Int1 = container;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @Copy_PU32_array: An array of integers.
 * @Copy_U32_size: The size of the array.
 */
void bubble_sort(int *Copy_PU32_array, unsigned int Copy_U32_size)
{
	bool Local_Bool_Sort = false;
	unsigned int Local_U32_Size = Copy_U32_size, Local_U32_Counter;

	if (Copy_U32_size < 2 || Copy_PU32_array == NULL)
		return;

	while (Local_Bool_Sort == false)
	{
		Local_Bool_Sort = true;
		for (Local_U32_Counter = 0; Local_U32_Counter < Local_U32_Size - 1;
			Local_U32_Counter++)
		{
			if (Copy_PU32_array[Local_U32_Counter] >
				Copy_PU32_array[Local_U32_Counter + 1])
			{
				Local_Bool_Sort = false;
				Bubble_ints_Swap(Copy_PU32_array + Local_U32_Counter,
					Copy_PU32_array + Local_U32_Counter + 1);
				print_array(Copy_PU32_array, Copy_U32_size);
			}
		}
		Local_U32_Size--;
	}
}
