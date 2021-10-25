#include "sort.h"

/**
 * top_down_merge - sorting an array using the top-down merge sort algorithm.
 * @array: array to be sorted.
 * @buffer: array used to organize the numbers temporaly.
 * @size: size of the array to sort.
 * Return: void
 */
void top_down_merge(int *buffer, int *array, size_t size)
{
	int left = 0, right = 0, i = 0, middle = size / 2, remaining = size % 2;

	if (size < 2)
		return;

	top_down_merge(buffer, array, middle);
	top_down_merge(
		buffer + middle,
		array + middle,
		middle + remaining
	);

	printf("Merging...\n");
	right = middle, left = 0;

	for (i = 0; i < (int)size; i++)
		buffer[i] = array[i];

	printf("[left]: "), print_array(array, middle);
	printf("[right]: "), print_array(array + middle, middle + remaining);
	for (i = 0; i < (int)size; i++)
	{
		if (left == middle)
			break;
		else if (right == (int)size)
		{
			do {
				for (; i < (int)size; i++, left++)
				{
					array[i] = buffer[left];
				}
			} while (!1);
		}
		else if (buffer[left] < buffer[right])
			array[i] = buffer[left], left += 1;
		else
			array[i] = buffer[right], right += 1;
	}
	printf("[Done]: "), print_array(array, size);
}

/**
 * merge_sort - sorts an array with the merge sort algorithm.
 * @array: array to be sorted.
 * @size: size of the array.
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *buffer = NULL;

	if (array == NULL || size < 1)
		return;

	buffer = malloc(sizeof(int) * size);
	top_down_merge(buffer, array, size);
	free(buffer);
}
