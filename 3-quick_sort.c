#include "sort.h"

void swap_ints_ER(int *a_ER, int *b_ER);
int lomuto_partition_ER(int *array, size_t size, int left, int right);
void lomuto_sort_ER(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition_ER - Order a subset of an array of integers according to
 *                    the lomuto pation scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting ineX of the subset to order.
 * @right: The ending indX of the subset to order.
 * Return: The final partion index.
 */
int lomuto_partition_ER(int *array, size_t size, int left, int right)
{
	int *pivot_ER, above, below;

	pivot_ER = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot_ER)
		{
			if (above < below)
			{
				swap_ints_ER(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot_ER)
	{
		swap_ints_ER(array + above, pivot_ER);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort_ER - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The eding index of the array partition to order.
 *
 */
void lomuto_sort_ER(int *array, size_t size, int left, int right)
{
	int part_ER;

	if (right - left > 0)
	{
		part_ER = lomuto_partition_ER(array, size, left, right);
		lomuto_sort_ER(array, size, left, part_ER - 1);
		lomuto_sort_ER(array, size, part_ER + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using e quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort_ER(array, size, 0, size - 1);
}
