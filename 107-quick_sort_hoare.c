#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partition - Sequence sudivision of array of integers
 *                   based on the hoare partition scheme.
 * @array: Array of integers.
 * @size: Size of an array.
 * @left: Initial index of subdvison to sequence.
 * @right: Final index of subdvison to sequence.
 *
 * Return: Final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 *              Outputs array after every single substitution.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - Use quicksort algorithm via recursion.
 * @array: Array of integers.
 * @size: Size of an array.
 * @left: Initial index of subdvison to sequence.
 * @right: Final index of subdvison to sequence.
 *
 * Description: Utilizies Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sorting the array of integers in increasing sequence
 *                    utilizing the quicksort algorithm.
 * @array: Array of integers.
 * @size: Size of an array.
 *
 * Description: Implements Hoare partition scheme.
 *              Outputs array after every single substitution.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
