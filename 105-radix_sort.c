#include "sort.h"

int get_max_ER(int *array, int size);
void radix_counting_sort_ER(int *array, size_t size, int sig_ER, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max_ER - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The of the array.
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
 * radix_counting_sort_ER - Sort the significant digits of an array of integers
 *                       in ascen rder using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig_ER: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort_ER(int *array, size_t size, int sig_ER, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig_ER) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig_ER) % 10] - 1] = array[i];
		count[(array[i] / sig_ER) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max_ER, sig_ER, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max_ER = get_max_ER(array, size);
	for (sig_ER = 1; max_ER / sig_ER > 0; sig_ER *= 10)
	{
		radix_counting_sort_ER(array, size, sig_ER, buff);
		print_array(array, size);
	}

	free(buff);
}
