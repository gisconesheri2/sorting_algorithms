#include "sort.h"
/**
 * selection_sort - sorts array via selectio sort
 * @array: array of ints
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t x, y, min_num, min_index, temp_num;

	x = 0;
	while (x < size - 1)
	{
		min_num = array[x];
		min_index = x;
		for (y = x; y < size; y++)
		{
			if (array[y] < (int)min_num)
			{
				min_num = array[y];
				min_index = y;
			}
		}
		if (min_index != x)
		{
			temp_num = array[x];
			array[x] = array[min_index];
			array[min_index] = temp_num;
			print_array(array, size);
		}
		x++;
	}
}
