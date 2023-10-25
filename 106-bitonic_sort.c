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
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @Copy_PU32_Array: An array of integers.
 * @Copy_U32_Size: The size of the array.
 * @Copy_U32_Start: The starting index of the sequence in array to sort.
 * @Copy_U32_Seq: The size of the sequence to sort.
 * @Copy_U8_Flow: The direction to sort in.
 */
void bitonic_merge(int *Copy_PU32_Array, unsigned int Copy_U32_Size,
	unsigned int Copy_U32_Start, unsigned int Copy_U32_Seq, char Copy_U8_Flow)
{
	unsigned int Local_U32_Counter, Local_U32_Jump;

	Local_U32_Jump = Copy_U32_Seq / 2;
	if (Copy_U32_Seq > 1)
	{
		for (Local_U32_Counter = Copy_U32_Start; Local_U32_Counter <
			Copy_U32_Start + Local_U32_Jump; Local_U32_Counter++)
		{
			if ((Copy_U8_Flow == UP && Copy_PU32_Array[Local_U32_Counter] >
				Copy_PU32_Array[Local_U32_Counter + Local_U32_Jump]) ||
			    (Copy_U8_Flow == DOWN && Copy_PU32_Array[Local_U32_Counter] <
					Copy_PU32_Array[Local_U32_Counter + Local_U32_Jump]))
				swap_ints(Copy_PU32_Array + Local_U32_Counter, Copy_PU32_Array +
					Local_U32_Counter + Local_U32_Jump);
		}
		bitonic_merge(Copy_PU32_Array, Copy_U32_Size, Copy_U32_Start,
			Local_U32_Jump, Copy_U8_Flow);
		bitonic_merge(Copy_PU32_Array, Copy_U32_Size, Copy_U32_Start + Local_U32_Jump
			, Local_U32_Jump, Copy_U8_Flow);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @Copy_PU32_Array: An array of integers.
 * @Copy_U32_Size: The size of the array.
 * @Copy_U32_Start: The starting index of a block of the building bitonic seque
 * @Copy_U32_Seq: The size of a block of the building bitonic sequence.
 * @Copy_U8_Flow: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *Copy_PU32_Array, unsigned long int Copy_U32_Size,
	unsigned int Copy_U32_Start, unsigned long int Copy_U32_Seq,
	char Copy_U8_Flow)
{
	unsigned int Local_U32_Cut = Copy_U32_Seq / 2;
	char *Local_PU8_Str = (Copy_U8_Flow == UP) ? "UP" : "DOWN";

	if (Copy_U32_Seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", Copy_U32_Seq, Copy_U32_Size,
			Local_PU8_Str);
		print_array(Copy_PU32_Array + Copy_U32_Start, Copy_U32_Seq);

		bitonic_seq(Copy_PU32_Array, Copy_U32_Size, Copy_U32_Start, Local_U32_Cut,
			UP);
		bitonic_seq(Copy_PU32_Array, Copy_U32_Size, Copy_U32_Start + Local_U32_Cut,
			Local_U32_Cut, DOWN);
		bitonic_merge(Copy_PU32_Array, Copy_U32_Size, Copy_U32_Start, Copy_U32_Seq,
			Copy_U8_Flow);

		printf("Result [%lu/%lu] (%s):\n", Copy_U32_Seq, Copy_U32_Size,
			Local_PU8_Str);
		print_array(Copy_PU32_Array + Copy_U32_Start, Copy_U32_Seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 * @Copy_PU32_Array: An array of integers.
 * @Copy_U32_Size: The size of the array.
 */
void bitonic_sort(int *Copy_PU32_Array, unsigned int Copy_U32_Size)
{
	if (Copy_U32_Size < 2 || Copy_PU32_Array == NULL)
		return;
	bitonic_seq(Copy_PU32_Array, Copy_U32_Size, 0, Copy_U32_Size, UP);
}
