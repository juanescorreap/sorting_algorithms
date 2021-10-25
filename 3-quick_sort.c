#include "sort.h"
/**
 * swap - Function swaps the values of two
 * positions in an array
 * @a: Position to be swapped
 * @b: Position to be swapped
 * Return: Void
 */
void swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}
/**
 * partition - Function that takes last element as pivot, places
 * the pivot element at its correct position in sorted
 * array, and places all smaller (smaller than pivot)
 * to left of pivot and all greater elements to right of pivot
 * @array: The Array to be sorted
 * @low: Starting index
 * @high: Ending index
 * @size: The size of the array (passed to be able to print)
 * Return: Void
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	return (i);
}
/**
 * real_quick_sort - Function that sorts an array of
 * integers in ascending order using the Quick sort algorithm
 * @array: The Array to be sorted
 * @low: Starting index
 * @high: Ending index
 * @size: The size of the array (passed to be able to print)
 * Return: Void
 */
void real_quick_sort(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		real_quick_sort(array, low, pi - 1, size);
		real_quick_sort(array, pi + 1, high, size);
	}
}
/**
 * quick_sort - Function that sorts an array of
 * integers in ascending order using the Quick sort algorithm
 * @array: The Array to be sorted
 * @size: The Size of The Array
 * Return: Void
 */
void quick_sort(int *array, size_t size)
{
	real_quick_sort(array, 0, size - 1, size);
}
