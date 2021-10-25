#include "sort.h"


void countSort(int *array, int size, int exp, int *output)
{
	int i;
	int count[10] = {0,0,0,0,0,0,0,0,0,0};

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


void radix_sort(int *array, size_t size)
{
	int max = array[0];
	int i, exp;
	int *output = NULL;

	for (i = 1; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	output = malloc(sizeof(int) * max);
	if (!output)
		return;
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(array, (int)size, exp, output);
		print_array(array, size);
	}
	free(output);
}
