#include "sort.h"
/**
 * Sorts an array of integers in ascending order using the Bubble sort algorithm
 *
 * @param array: Pointer to the array of integers to be sorted
 * @param size: Size of the array
 *
 * @return None
 */
void bubble_sort(int *array, size_t size)
{
  int i, j, temp;
  for (i = 0; i < size - 1; i++)
  {
    for (j = 0; j < size - i - 1; j++)
    {
      if (array[j] > array[j + 1])
      {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
    /*print the array after each iteration*/ 
       for (int k = 0; k < size; k++)
    {
      printf("%d ", array[k]);
    }
    printf("\n");
  }
}
