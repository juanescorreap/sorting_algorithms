#include "sort.h"

/**
 * count_Sort - Sorts an array using the counting sort sort algorithm but
 * using the exp.
 * @array: Array to be sorted.
 * @size: size of the array.
 * @exp: base to use the counting sort (in this case base10)
 * @output: array to store the counting indexes.
 * Return: void.
 */
void count_Sort(int *array, int size, int exp, int *output)
{
	int i;
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 0; i < (int)size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = (int)size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - Sorts an array using the radix sort algorithm.
 * @array: Array to be sorted.
 * @size: size of the array.
 * Return: void.
 */
void radix_sort(int *array, size_t size)
{
	int max;
	int i, exp;
	int *output = NULL;

	if (array == NULL)
		return;
	if (size < 2)
	{
		return;
	}
	max = array[0];

	for (i = 1; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	output = malloc(sizeof(int) * max);
	if (!output)
		return;
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_Sort(array, (int)size, exp, output);
		print_array(array, size);
	}
	free(output);
}
