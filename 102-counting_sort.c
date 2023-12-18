#include "sort.h"

/**
 * get_max_ER - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max_ER(int *array, int size)
{
	int max_ER, i;

	for (max_ER = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max_ER)
			max_ER = array[i];
	}

	return (max_ER);
}

/**
 * counting_sort - WILL Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max_ER, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max_ER = get_max_ER(array, size);
	count = malloc(sizeof(int) * (max_ER + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max_ER + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max_ER + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max_ER + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
