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
 * hoare_partition - Order a subset of an array of integers
 * @Copy_PU32_Array: The array of integers.
 * @Copy_U32_Size: The size of the array.
 * @Copy_U32_Left: The starting index of the subset to order.
 * @Copy_U32_Right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int hoare_partition(int *Copy_PU32_Array, unsigned int Copy_U32_Size,
	int Copy_U32_Left, int Copy_U32_Right)
{
	int Local_U32_Pivot = Copy_PU32_Array[Copy_U32_Right], Local_U32_Above,
		Local_U32_Below;

	for (Local_U32_Above
		= Copy_U32_Left - 1, Local_U32_Below = Copy_U32_Right + 1;
		Local_U32_Above < Local_U32_Below;)
	{
		do {
			Local_U32_Below--;
		} while (Copy_PU32_Array[Local_U32_Below] > Local_U32_Pivot);
		do {
			Local_U32_Above++;
		} while (Copy_PU32_Array[Local_U32_Above] < Local_U32_Pivot);
		if (Local_U32_Above < Local_U32_Below)
		{
			swap_ints(Copy_PU32_Array + Local_U32_Above, Copy_PU32_Array +
				Local_U32_Below);
			print_array(Copy_PU32_Array, Copy_U32_Size);
		}
	}
	return (Local_U32_Above);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @Copy_PU32_Array: An array of integers to sort.
 * @Copy_U32_Size: The size of the array.
 * @Copy_U32_Left: The starting index of the array partition to order.
 * @Copy_U32_Right: The ending index of the array partition to order.
 */
void hoare_sort(int *Copy_PU32_Array, unsigned int Copy_U32_Size,
	int Copy_U32_Left, int Copy_U32_Right)
{
	int Local_U32_Part;

	if (Copy_U32_Right - Copy_U32_Left > 0)
	{
		Local_U32_Part = hoare_partition(Copy_PU32_Array, Copy_U32_Size,
			Copy_U32_Left, Copy_U32_Right);
		hoare_sort(Copy_PU32_Array, Copy_U32_Size, Copy_U32_Left,
			Local_U32_Part - 1);
		hoare_sort(Copy_PU32_Array, Copy_U32_Size, Local_U32_Part,
			Copy_U32_Right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 * @Copy_PU32_Array: An array of integers.
 * @Copy_U32_Size: The size of the array.
 */
void quick_sort_hoare(int *Copy_PU32_Array, unsigned int Copy_U32_Size)
{
	if (Copy_U32_Size < 2 || Copy_PU32_Array == NULL)
		return;
	hoare_sort(Copy_PU32_Array, Copy_U32_Size, 0, Copy_U32_Size - 1);
}
