#include "sort.h"

/**
 * Select_Ints_Swap - Swap two integers in an array.
 * @Copy_PU32_Int1: The first integer.
 * @Copy_PU32_Int2: The second integer.
 */
void Select_Ints_Swap(int *Copy_PU32_Int1, int *Copy_PU32_Int2)
{
	int container;

	container = *Copy_PU32_Int2;
	*Copy_PU32_Int2 = *Copy_PU32_Int1;
	*Copy_PU32_Int1 = container;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 * @Copy_PU32_array: An array of integers.
 * @Copy_U32_size: The size of the array.
 */
void selection_sort(int *Copy_PU32_array, unsigned int Copy_U32_size)
{
	unsigned int Local_U32_Counter1, Local_U32_Counter2;
	int *Local_U32_Container;

	if (Copy_U32_size < 2 || Copy_PU32_array == NULL)
		return;

	for (Local_U32_Counter1 = 0; Local_U32_Counter1 < Copy_U32_size - 1;
		Local_U32_Counter1++)
	{
		Local_U32_Container = Copy_PU32_array + Local_U32_Counter1;
		for (Local_U32_Counter2 = Local_U32_Counter1 + 1; Local_U32_Counter2 <
			Copy_U32_size; Local_U32_Counter2++)
		{
			if (Copy_PU32_array[Local_U32_Counter2] < *Local_U32_Container)
				Local_U32_Container = (Copy_PU32_array + Local_U32_Counter2);
		}

		if ((Copy_PU32_array + Local_U32_Counter1) != Local_U32_Container)
		{
			Select_Ints_Swap(Copy_PU32_array + Local_U32_Counter1,
				Local_U32_Container);
			print_array(Copy_PU32_array, Copy_U32_size);
		}
	}
}
