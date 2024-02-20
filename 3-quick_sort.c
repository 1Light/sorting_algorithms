#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Substitute the two integers in the array.
 * @a: The first integer to be substituted.
 * @b: The second integer to be substituted.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Sequence a subdivision of the array of integers based on
 *                    lomuto partition scheme. Last item considered as pivot.
 * @array: Array of integers to be sorted.
 * @size: Size of an array.
 * @left: Initial index of the subdivision to sequence.
 * @right: Last index of the subdivison to sequence.
 *
 * Return: The last dividing index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Use quicksort algorithm via recursion.
 * @array: Array of integers to be sorted.
 * @size: Size of an array.
 * @left: Initial index of the subdivision to sequence.
 * @right: Last index of the subdivison to sequence.
 *
 * Description: Utilize Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort the array of integers in increasing sequence
 *              utilizing quicksort algorithm.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 *
 * Description: Utilizies Lomuto partition scheme. Outputs
 *              array after every single substitution.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
