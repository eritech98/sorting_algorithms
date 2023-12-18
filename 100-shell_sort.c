#include "sort.h"

/**
 * swap_ints_ER - Swap two intege an array.
 * @a_ER: The first integer to swapI
 * @b_ER: The second integer to swapI
 */
void swap_ints_ER(int *a_ER, int *b_ER)
{
	int tmp;

	tmp = *a_ER;
	*a_ER = *b_ER;
	*b_ER = tmp;
}

/**
 * shell_sort - Sort an array of int in ascending
 *              order using shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap_ER, i, j_ER;

	if (array == NULL || size < 2)
		return;

	for (gap_ER = 1; gap_ER < (size / 3);)
		gap_ER = gap_ER * 3 + 1;

	for (; gap_ER >= 1; gap_ER /= 3)
	{
		for (i = gap_ER; i < size; i++)
		{
			j_ER = i;
			while (j_ER >= gap_ER && array[j_ER - gap_ER] > array[j_ER])
			{
				swap_ints_ER(array + j_ER, array + (j_ER - gap_ER));
				j_ER -= gap_ER;
			}
		}
		print_array(array, size);
	}
}
