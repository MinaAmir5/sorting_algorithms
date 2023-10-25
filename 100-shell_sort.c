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
 * shell_sort - Sort an array of integers in ascending
 * @Copy_PU32_Array: An array of integers.
 * @Copy_U32_Size: The size of the array.
 */
void shell_sort(int *Copy_PU32_Array, unsigned int Copy_U32_Size)
{
	unsigned int Local_U32_Gap, Local_U32_Counter1, Local_U32_Counter2;

	if (Copy_U32_Size < 2 || Copy_PU32_Array == NULL)
		return;
	Local_U32_Gap = 1;
	while (Local_U32_Gap < (Copy_U32_Size / 3))
		Local_U32_Gap = Local_U32_Gap * 3 + 1;

	while (Local_U32_Gap >= 1)
	{
		for (Local_U32_Counter1 = Local_U32_Gap; Local_U32_Counter1 < Copy_U32_Size;
			Local_U32_Counter1++)
		{
			Local_U32_Counter2 = Local_U32_Counter1;
			while (Local_U32_Counter2 >= Local_U32_Gap && Copy_PU32_Array
				[Local_U32_Counter2 - Local_U32_Gap] > Copy_PU32_Array[Local_U32_Counter2])
			{
				swap_ints(Copy_PU32_Array + Local_U32_Counter2, Copy_PU32_Array +
					(Local_U32_Counter2 - Local_U32_Gap));
				Local_U32_Counter2 -= Local_U32_Gap;
			}
		}
		print_array(Copy_PU32_Array, Copy_U32_Size);
		Local_U32_Gap /= 3;
	}
}
