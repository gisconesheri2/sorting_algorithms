#include "sort.h"
/**
 * partition - divides array into two partitions
 * @array: list of ints
 * @lower_bound: lower index
 * @upper_bound: higher index
 * @size: size of the array
 *
 * Return: pivot index
 */
int partition(int *array, int lower_bound, int upper_bound, size_t size)
{
	int pivot, temp_num;
	int pivot_index, j;

	pivot = array[upper_bound];
	pivot_index = lower_bound - 1;

	for (j = lower_bound; j <= upper_bound - 1; j++)
	{
		if (array[j] <= pivot)
		{
			pivot_index++;
			temp_num = array[pivot_index];
			array[pivot_index] = array[j];
			array[j] = temp_num;
		}
	}
	pivot_index++;
	temp_num = array[pivot_index];
	array[pivot_index] = array[upper_bound];
	array[upper_bound] = temp_num;
	print_array(array, size);
	return (pivot_index);
}
/**
 * quick_sort_algo - sort an array
 * @array: list of ints
 * @lower_bound: lower index
 * @upper_bound: higher index
 * @size: size of the array
 */
void quick_sort_algo(int *array, int lower_bound, int upper_bound, size_t size)
{
	int pivot_index;

	if (lower_bound >= upper_bound || lower_bound < 0)
		return;

	pivot_index = partition(array, lower_bound, upper_bound, size);

	quick_sort_algo(array, lower_bound, pivot_index - 1, size);
	quick_sort_algo(array, pivot_index + 1, upper_bound, size);
}

/**
 * quick_sort - sort an array
 * @array: list of ints
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_algo(array, 0, size - 1, size);
}

