#include "sort.h"
/**
 * bubble_sort - sorts array in ascending order via bubble sort
 * @array: array of ints
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	int index, swapped, temp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		for (index = 0; index < (int)size - 1; index++)
		{
			if (array[index] > array[index + 1])
			{
				temp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = temp;
				print_array(array, size);
				swapped = 1;
			}
		}
	}
}
