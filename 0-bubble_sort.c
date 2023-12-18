#include "sort.h"

/**
 * swap_ints_ER - Swap two integer
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
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len_ER = size;
	bool bubbly_ER = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly_ER == false)
	{
		bubbly_ER = true;
		for (i = 0; i < len_ER - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints_ER(array + i, array + i + 1);
				print_array(array, size);
				bubbly_ER = false;
			}
		}
		len_ER--;
	}
}
