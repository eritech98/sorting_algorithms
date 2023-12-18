#include "sort.h"

void swap_ints_ER(int *a_ER, int *b_ER);
int hoare_partition_ER(int *array, size_t size, int left, int right);
void hoare_sort_ER(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints_ER - Swap two inTs in an array.
 * @a_ER: The fst integer to swap.
 * @b_ER: The snd integer to swap.
 */
void swap_ints_ER(int *a_ER, int *b_ER)
{
	int tmp;

	tmp = *a_ER;
	*a_ER = *b_ER;
	*b_ER = tmp;
}

/**
 * hoare_partition_ER - Order a subset of an array of integers
 *                   acrding to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The sze of the array.
 * @left: The tarting index of the subset to order.
 * @right: The nding index of the subset to order.
 *
 * Return: Thefinal partition index.
 *
 * Description: Usthe last element of the partition as the pivot.
 * Prints they after each swap of two elements.
 */

int hoare_partition_ER(int *array, size_t size, int left, int right)
{
	int pivot_ER, above, below;

	pivot_ER = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot_ER);
		do {
			below--;
		} while (array[below] > pivot_ER);

		if (above < below)
		{
			swap_ints_ER(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort_ER - Implement the ort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: ses the Hoare partition scheme.
 */
void hoare_sort_ER(int *array, size_t size, int left, int right)
{
	int part_ER;

	if (right - left > 0)
	{
		part_ER = hoare_partition_ER(array, size, left, right);
		hoare_sort_ER(array, size, left, part_ER - 1);
		hoare_sort_ER(array, size, part_ER, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    ordersing the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each sp of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort_ER(array, size, 0, size - 1);
}
