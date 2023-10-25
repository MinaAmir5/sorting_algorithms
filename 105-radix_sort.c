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
 * radix_counting_sort - Sort the significant digits of an array of integers
 * @Copy_PU32_Array: An array of integers.
 * @Copy_U32_Size: The size of the array.
 * @Copy_U32_Digit: The significant digit to sort.
 * @Copy_PU32_Temp: A buffer to store the sorted array.
 */
void radix_counting_sort(int *Copy_PU32_Array, unsigned int Copy_U32_Size,
	int Copy_U32_Digit, int *Copy_PU32_Temp)
{
	size_t Local_U32_Counter;
	int Local_PU32_Count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (Local_U32_Counter = 0; Local_U32_Counter < Copy_U32_Size;
		Local_U32_Counter++)
		Local_PU32_Count[(Copy_PU32_Array[Local_U32_Counter] / Copy_U32_Digit)
		% 10] += 1;
	for (Local_U32_Counter = 0; Local_U32_Counter < 10; Local_U32_Counter++)
		Local_PU32_Count[Local_U32_Counter] +=
		Local_PU32_Count[Local_U32_Counter - 1];
	for (Local_U32_Counter = Copy_U32_Size - 1; (int)Local_U32_Counter >= 0;
		Local_U32_Counter--)
	{
		Copy_PU32_Temp[Local_PU32_Count[(Copy_PU32_Array[Local_U32_Counter] /
			Copy_U32_Digit) % 10] - 1] = Copy_PU32_Array[Local_U32_Counter];
		Local_PU32_Count[(Copy_PU32_Array[Local_U32_Counter] / Copy_U32_Digit) % 10]
			-= 1;
	}
	for (Local_U32_Counter = 0; Local_U32_Counter < Copy_U32_Size;
		Local_U32_Counter++)
		Copy_PU32_Array[Local_U32_Counter] = Copy_PU32_Temp[Local_U32_Counter];
}

/**
 * radix_sort - Sort an array of integers in ascending
 * @Copy_PU32_Array: An array of integers.
 * @Copy_U32_Size: The size of the array.
 */
void radix_sort(int *Copy_PU32_Array, unsigned int Copy_U32_Size)
{
	int Local_U32_Max, Local_U32_Digit, *Local_PU32_Temp;

	if (Copy_U32_Size < 2 || Copy_PU32_Array == NULL)
		return;
	Local_U32_Max = get_max(Copy_PU32_Array, Copy_U32_Size);
	Local_PU32_Temp = malloc(sizeof(int) * Copy_U32_Size);
	if (Local_PU32_Temp == NULL)
		return;
	for (Local_U32_Digit = 1; Local_U32_Max / Local_U32_Digit > 0;
		Local_U32_Digit *= 10)
	{
		radix_counting_sort(Copy_PU32_Array, Copy_U32_Size, Local_U32_Digit,
			Local_PU32_Temp);
		print_array(Copy_PU32_Array, Copy_U32_Size);
	}
	free(Local_PU32_Temp);
}
