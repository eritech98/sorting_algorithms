#include "sort.h"

void swap_ints_ER(int *a_ER, int *b_ER);
void bitonic_merge_ER(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq_ER(int *array, size_t size,
	size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints_ER - Swap two integers in an array.
 * @a_ER: The first integer to swap.
 * @b_ER: The second integer to swap.
 */
void swap_ints_ER(int *a_ER, int *b_ER)
{
	int tmp;

	tmp = *a_ER;
	*a_ER = *b_ER;
	*b_ER = tmp;
}

/**
 * bitonic_merge_ER - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The sie of the array.
 * @start: The tarting index of the sequence in array to sort.
 * @seq: The sze of the sequence to sort.
 * @flow: The direction to sort in.
 */
void bitonic_merge_ER(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, jump_ER = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump_ER; i++)
		{
			if ((flow == UP && array[i] > array[i + jump_ER]) ||
			    (flow == DOWN && array[i] < array[i + jump_ER]))
				swap_ints_ER(array + i, array + i + jump_ER);
		}
		bitonic_merge_ER(array, size, start, jump_ER, flow);
		bitonic_merge_ER(array, size, start + jump_ER, jump_ER, flow);
	}
}

/**
 * bitonic_seq_ER - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq_ER(int *array, size_t size,
	size_t start, size_t seq, char flow)
{
	size_t cut_ER = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq_ER(array, size, start, cut_ER, UP);
		bitonic_seq_ER(array, size, start + cut_ER, cut_ER, DOWN);
		bitonic_merge_ER(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq_ER(array, size, 0, size, UP);
}
