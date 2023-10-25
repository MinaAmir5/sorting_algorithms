#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @Copy_PU32_Array: An array of integers.
 * @Copy_U32_Size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *Copy_PU32_Array, int Copy_U32_Size)
{
	int Local_U32_Max, Local_U32_Counter;

	for (Local_U32_Max = Copy_PU32_Array[0], Local_U32_Counter = 1;
		Local_U32_Counter < Copy_U32_Size; Local_U32_Counter++)
	{
		if (Copy_PU32_Array[Local_U32_Counter] > Local_U32_Max)
			Local_U32_Max = Copy_PU32_Array[Local_U32_Counter];
	}
	return (Local_U32_Max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 * @Copy_PU32_Array: An array of integers.
 * @Copy_U32_Size: The size of the array.
 */
void counting_sort(int *Copy_PU32_Array, unsigned int Copy_U32_Size)
{
	int *Local_PU32_Num, *Local_PU32_Sorted, Local_U32_Max, Local_U32_Counter;

	if (Copy_PU32_Array == NULL || Copy_U32_Size < 2)
		return;
	Local_PU32_Sorted = malloc(sizeof(int) * Copy_U32_Size);
	if (Local_PU32_Sorted == NULL)
		return;
	Local_U32_Max = get_max(Copy_PU32_Array, Copy_U32_Size);
	Local_PU32_Num = malloc(sizeof(int) * (Local_U32_Max + 1));
	if (Local_PU32_Num == NULL)
	{
		free(Local_PU32_Sorted);
		return;
	}
	for (Local_U32_Counter = 0; Local_U32_Counter < (Local_U32_Max + 1);
		Local_U32_Counter++)
		Local_PU32_Num[Local_U32_Counter] = 0;
	for (Local_U32_Counter = 0; Local_U32_Counter < (int)Copy_U32_Size;
		Local_U32_Counter++)
		Local_PU32_Num[Copy_PU32_Array[Local_U32_Counter]] += 1;
	for (Local_U32_Counter = 0; Local_U32_Counter < (Local_U32_Max + 1);
		Local_U32_Counter++)
		Local_PU32_Num[Local_U32_Counter] += Local_PU32_Num[Local_U32_Counter - 1];
	print_array(Local_PU32_Num, Local_U32_Max + 1);
	for (Local_U32_Counter = 0; Local_U32_Counter < (int)Copy_U32_Size;
		Local_U32_Counter++)
	{
		Local_PU32_Sorted[Local_PU32_Num[Copy_PU32_Array[Local_U32_Counter]] - 1] =
		Copy_PU32_Array[Local_U32_Counter];
		Local_PU32_Num[Copy_PU32_Array[Local_U32_Counter]] -= 1;
	}
	for (Local_U32_Counter = 0; Local_U32_Counter < (int)Copy_U32_Size;
		Local_U32_Counter++)
		Copy_PU32_Array[Local_U32_Counter] = Local_PU32_Sorted[Local_U32_Counter];
	free(Local_PU32_Num);
	free(Local_PU32_Sorted);
}
