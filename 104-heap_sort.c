#include "sort.h"

/**
 * sift_down - Sorts an array on a max heap recursively.
 * @array: Array to be sorted.
 * @n: size of the array to heap.
 * @i: index to star the heap from.
 * @big_size: size of the complete array to print.
 * Return: void.
 */
void sift_down(int array[], int n, int i, int big_size)
{
	int largest = 0;
	int l = (2 * (i + 1)) - 1;
	int r = l + 1;
	int tmp = 0;

	if (r < n && array[r] > array[l])
		largest = r;
	else if (l < n)
		largest = l;
	else
	{
		largest = i;
	}
	if(array[i] >= array[largest])
	{
		largest = i;
	}
	if (largest != i)
	{
		tmp = array[i];
		array[i] = array[largest];
		array[largest] = tmp;
		print_array(array, big_size);
		sift_down(array, n, largest, big_size);
	}
}

/**
 * heap_sort - Sorts an array using the heap sort algorithm.
 * @array: Array to be sorted.
 * @size: size of the array.
 * Return: void.
 */
void heap_sort(int *array, size_t size)
{
	int tmp = 0;

	for (int i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i, size);

	for (int i = size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		sift_down(array, i, 0, size);
	}
}
