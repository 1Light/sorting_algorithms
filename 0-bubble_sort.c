#include "sort.h"

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
 * bubble_sort - Sorting the array of integers in increasing sequence.
 * @array: Array of integers to be sorted.
 * @size: Size of an array.
 *
 * Description: Outputs array after every single substitution.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
