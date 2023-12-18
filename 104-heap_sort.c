#include "sort.h"

void swap_ints_ER(int *a_ER, int *b_ER);
void max_heapify_ER(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * max_heapify_ER - Turn a binary tree into a binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: dex of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapify_ER(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large_ER;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large_ER = root;

	if (left < base && array[left] > array[large_ER])
		large_ER = left;
	if (right < base && array[right] > array[large_ER])
		large_ER = right;

	if (large_ER != root)
	{
		swap_ints_ER(array + root, array + large_ER);
		print_array(array, size);
		max_heapify_ER(array, size, base, large_ER);
	}
}

/**
 * heap_sort - Sort an arrf integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of tharray.
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify_ER(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints_ER(array, array + i);
		print_array(array, size);
		max_heapify_ER(array, size, i, 0);
	}
}
