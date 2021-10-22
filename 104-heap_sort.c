#include "sort.h"

void heapify(int array[], int n, int i, int big_size)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int tmp = 0;

	if (l < n && array[l] > array[largest])
		largest = l;

	if (r < n && array[r] > array[largest])
		largest = r;

	if (largest != i)
	{
		tmp = array[i];
		array[i] = array[largest];
		array[largest] = tmp;
		print_array(array, big_size);
		heapify(array, n, largest, big_size);
	}
}

void heap_sort(int *array, size_t size)
{
	int tmp = 0;
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (int i = size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
