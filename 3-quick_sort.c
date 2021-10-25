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
	int t = *a;
	*a = *b;
	*b = t;
}
/**
 * partition - Function that sorts an array of
 * integers in ascending order using the Quick sort algorithm
 * @array: The Array to be sorted
 * @size: The Size of The Array
 * Return: Void
 */
int partition(int *array, int low, int high, int *array1, size_t size1)
{
	int pivot = array[high];
	int i = (low - 1);
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array1, size1);
	return (i + 1);
}
/**
 * quick_sort - Function that sorts an array of
 * integers in ascending order using the Quick sort algorithm
 * @array: The Array to be sorted
 * @size: The Size of The Array
 * Return: Void
 */
void real_quick_sort(int *array, int low, int high, int *array1, size_t size1)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, array1, size1);
		real_quick_sort(array, low, pi - 1, array1, size1);
		real_quick_sort(array, pi + 1, high, array1, size1);
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
	real_quick_sort(array, 0, size - 1, array, size);
}