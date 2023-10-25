#include "sort.h"

/**
 * Quick_ints_Swap - Swap two integers in an array.
 * @Copy_PU32_Int1: The first integer.
 * @Copy_PU32_Int2: The second integer.
 */
void Quick_ints_Swap(int *Copy_PU32_Int1, int *Copy_PU32_Int2)
{
	int container;

	container = *Copy_PU32_Int2;
	*Copy_PU32_Int2 = *Copy_PU32_Int1;
	*Copy_PU32_Int1 = container;
}

/**
 * lomuto_partition - Order a subset of an array of integers
 * @Copy_PU32_Array: The array of integers.
 * @Copy_U32_Size: The size of the array.
 * @Copy_U32_Left: The starting index of the subset.
 * @Copy_U32_Right: The ending index of the subset.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *Copy_PU32_Array, unsigned int Copy_U32_Size,
	int Copy_U32_Left, int Copy_U32_Right)
{
	int *Local_U32_Pivot, Local_U32_Above, Local_U32_Below;

	Local_U32_Pivot = Copy_PU32_Array + Copy_U32_Right;
	for (Local_U32_Above = Local_U32_Below = Copy_U32_Left; Local_U32_Below <
		Copy_U32_Right; Local_U32_Below++)
	{
		if (Copy_PU32_Array[Local_U32_Below] < *Local_U32_Pivot)
		{
			if (Local_U32_Above < Local_U32_Below)
			{
				Quick_ints_Swap(Copy_PU32_Array + Local_U32_Below,
					Copy_PU32_Array + Local_U32_Above);
				print_array(Copy_PU32_Array, Copy_U32_Size);
			}
			Local_U32_Above++;
		}
	}
	if (Copy_PU32_Array[Local_U32_Above] > *Local_U32_Pivot)
	{
		Quick_ints_Swap(Copy_PU32_Array + Local_U32_Above, Local_U32_Pivot);
		print_array(Copy_PU32_Array, Copy_U32_Size);
	}
	return (Local_U32_Above);
}

/**
 * Void_lomuto_sort - Implement the quicksort algorithm through recursion.
 * @Copy_PU32_Array: The array of integers.
 * @Copy_U32_Size: The size of the array.
 * @Copy_U32_Left: The starting index of the subset.
 * @Copy_U32_Right: The ending index of the subset.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void Void_lomuto_sort(int *Copy_PU32_Array, unsigned int Copy_U32_Size,
	int Copy_U32_Left, int Copy_U32_Right)
{
	int Local_U32_part;

	if (Copy_U32_Right - Copy_U32_Left > 0)
	{
		Local_U32_part = lomuto_partition(Copy_PU32_Array, Copy_U32_Size,
			Copy_U32_Left, Copy_U32_Right);
		Void_lomuto_sort(Copy_PU32_Array, Copy_U32_Size, Copy_U32_Left,
			Local_U32_part - 1);
		Void_lomuto_sort(Copy_PU32_Array, Copy_U32_Size, Local_U32_part + 1,
			Copy_U32_Right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order
 * @Copy_PU32_Array: An array of integers.
 * @Copy_U32_Size: The size of the array.
 */
void quick_sort(int *Copy_PU32_Array, unsigned int Copy_U32_Size)
{
	if (Copy_U32_Size < 2 || Copy_PU32_Array == NULL)
		return;
	Void_lomuto_sort(Copy_PU32_Array, Copy_U32_Size, 0, Copy_U32_Size - 1);
}
