#include "sort.h"

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
 * selection_sort_ER - Sort an array f integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void selection_sort_ER(int *array, size_t size)
{
	int *min;
	size_t i, j_ER;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j_ER = i + 1; j_ER < size; j_ER++)
			min = (array[j_ER] < *min) ? (array + j_ER) : min;

		if ((array + i) != min)
		{
			swap_ints_ER(array + i, min);
			print_array(array, size);
		}
	}
}
