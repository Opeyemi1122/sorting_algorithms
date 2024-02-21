#include "sort.h"

/**
 * swap_ints - swaps two integers in an array.
 * @x: first integer to swap.
 * @b: second integer to swap.
 */

void swap_ints(int *x, int *b)
{
	int tmp;

	tmp = *x;
	*x = *b;
	*b = tmp;
}

/**
 * selection_sort - sorts the array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: prints the array after each swap.
 */

void selection_sort(int *array, size_t size)
{
	int *mini;
	size_t i, c;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		mini = array + i;
		for (c = i + 1; c < size; c++)
			mini = (array[c] < *mini) ? (array + c) : mini;

		if ((array + i) != mini)
		{
			swap_ints(array + i, mini);
			print_array(array, size);
		}
	}
}
