#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to first element
 * @b: Pointer to second element
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - Partitions an array for quicksort
 * @array: Array to partition
 * @lo: Starting index of partition
 * @hi: Ending index of partition
 *
 * Return: Index of partition pivot
 */
int partition(int *array, int lo, int hi)
{
	int pivot, i, j;

	pivot = array[hi];
	i = lo - 1;

	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, hi - lo + 1);
			}
		}
	}
	if (i + 1 != hi)
	{
		swap(&array[i + 1], &array[hi]);
		print_array(array, hi - lo + 1);
	}
	return (i + 1);
}

/**
 * quick_sort_helper - Implements quicksort algorithm recursively
 * @array: Array to sort
 * @lo: Starting index of partition
 * @hi: Ending index of partition
 * @size: Size of each element of array
 */
void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi);
		quick_sort_helper(array, lo, p - 1, size);
		quick_sort_helper(array, p + 1, hi, size);
	}
}

/**
 * quick_sort - Sorts array of int in ascending order using the quicksort
 * @array: Array to sort
 * @size: Size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
