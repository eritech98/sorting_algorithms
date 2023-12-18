#include "sort.h"

void merge_subarr_ER(int *subarr_ER, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive_ER(int *subarr_ER,
	int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr_ER - Sort a subarray of integers.
 * @subarr_ER: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_subarr_ER(int *subarr_ER, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j_ER, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr_ER + front, mid - front);

	printf("[right]: ");
	print_array(subarr_ER + mid, back - mid);

	for (i = front, j_ER = mid; i < mid && j_ER < back; k++)
		buff[k] = (subarr_ER[i] < subarr_ER[j_ER]) ?
			subarr_ER[i++] : subarr_ER[j_ER++];
	for (; i < mid; i++)
		buff[k++] = subarr_ER[i];
	for (; j_ER < back; j_ER++)
		buff[k++] = subarr_ER[j_ER];
	for (i = front, k = 0; i < back; i++)
		subarr_ER[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr_ER + front, back - front);
}

/**
 * merge_sort_recursive_ER - Implement
 * the merge sort algorithm through recursion.
 * @subarr_ER: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_recursive_ER(int *subarr_ER,
	int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive_ER(subarr_ER, buff, front, mid);
		merge_sort_recursive_ER(subarr_ER, buff, mid, back);
		merge_subarr_ER(subarr_ER, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order  merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive_ER(array, buff, 0, size);

	free(buff);
}
