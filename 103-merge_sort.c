#include "sort.h"

/**
 * merge_subarr - Sort a subarray of integers.
 * @Copy_PU32_SubArr: A subarray of an array of integers to sort.
 * @Copy_PU32_Temp: A buffer to store the sorted subarray.
 * @Copy_U32_Front: The front index of the array.
 * @Copy_U32_Mid: The middle index of the array.
 * @Copy_U32_Back: The back index of the array.
 */
void merge_subarr(int *Copy_PU32_SubArr, int *Copy_PU32_Temp, unsigned int
	Copy_U32_Front, unsigned int Copy_U32_Mid, unsigned int Copy_U32_Back)
{
	unsigned int Local_U32_Counter1, Local_U32_Counter2,
		Local_U32_Counter3 = 0;

	printf("Merging...\n[left]: ");
	print_array(Copy_PU32_SubArr + Copy_U32_Front,
		Copy_U32_Mid - Copy_U32_Front);
	printf("[right]: ");
	print_array(Copy_PU32_SubArr + Copy_U32_Mid, Copy_U32_Back - Copy_U32_Mid);

	for (Local_U32_Counter1 = Copy_U32_Front, Local_U32_Counter2 = Copy_U32_Mid;
		Local_U32_Counter1 < Copy_U32_Mid && Local_U32_Counter2 < Copy_U32_Back;
		Local_U32_Counter3++)
		if (Copy_PU32_SubArr[Local_U32_Counter1] <
			Copy_PU32_SubArr[Local_U32_Counter2])
			Copy_PU32_Temp[Local_U32_Counter3] = Copy_PU32_SubArr[Local_U32_Counter1++];
		else
			Copy_PU32_Temp[Local_U32_Counter3] = Copy_PU32_SubArr[Local_U32_Counter2++];
	while (Local_U32_Counter1 < Copy_U32_Mid)
	{
		Copy_PU32_Temp[Local_U32_Counter3++] = Copy_PU32_SubArr[Local_U32_Counter1];
		Local_U32_Counter1++;
	}
	while (Local_U32_Counter2 < Copy_U32_Back)
	{
		Copy_PU32_Temp[Local_U32_Counter3++] = Copy_PU32_SubArr[
			Local_U32_Counter2];
		Local_U32_Counter2++;
	}
	for (Local_U32_Counter1 = Copy_U32_Front, Local_U32_Counter3 = 0;
		Local_U32_Counter1 < Copy_U32_Back; Local_U32_Counter1++)
		Copy_PU32_SubArr[Local_U32_Counter1] = Copy_PU32_Temp[Local_U32_Counter3++];

	printf("[Done]: ");
	print_array(Copy_PU32_SubArr + Copy_U32_Front, Copy_U32_Back -
		Copy_U32_Front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @Copy_PU32_SubArr: A subarray of an array of integers to sort.
 * @Copy_PU32_Temp: A buffer to store the sorted result.
 * @Copy_U32_Front: The front index of the subarray.
 * @Copy_U32_Back: The back index of the subarray.
 */
void merge_sort_recursive(int *Copy_PU32_SubArr, int *Copy_PU32_Temp,
	unsigned int Copy_U32_Front, unsigned int Copy_U32_Back)
{
	unsigned int Local_U32_Mid;

	if (Copy_U32_Back - Copy_U32_Front > 1)
	{
		Local_U32_Mid = Copy_U32_Front + (Copy_U32_Back - Copy_U32_Front) / 2;
		merge_sort_recursive(Copy_PU32_SubArr, Copy_PU32_Temp, Copy_U32_Front,
			Local_U32_Mid);
		merge_sort_recursive(Copy_PU32_SubArr, Copy_PU32_Temp, Local_U32_Mid,
			Copy_U32_Back);
		merge_subarr(Copy_PU32_SubArr, Copy_PU32_Temp, Copy_U32_Front, Local_U32_Mid,
			Copy_U32_Back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 * @Copy_PU32_Array: An array of integers.
 * @Copy_U32_Size: The size of the array.
 */
void merge_sort(int *Copy_PU32_Array, unsigned int Copy_U32_Size)
{
	int *Local_U32_Temp;

	if (Copy_U32_Size < 2 || Copy_PU32_Array == NULL)
		return;
	Local_U32_Temp = malloc(sizeof(int) * Copy_U32_Size);
	if (Local_U32_Temp == NULL)
		return;
	merge_sort_recursive(Copy_PU32_Array, Local_U32_Temp, 0, Copy_U32_Size);
	free(Local_U32_Temp);
}
