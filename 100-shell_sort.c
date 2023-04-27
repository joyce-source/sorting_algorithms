#include "sort.h"

/**
 * shell_sort - Sorts array of int in ascending order using the Shell sort
 * @array: The array to sort
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1, i, j, tmp;

	if (array == NULL || size < 2)
		return;

	while (gap < (int)size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < (int)size; i++)
		{
			tmp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = tmp;
		}

		gap = (gap - 1) / 3;

		print_array(array, size);
	}
}
