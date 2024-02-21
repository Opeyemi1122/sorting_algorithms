#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @x: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *x, int *b)
{
	int temp;

	temp = *x;
	*x = *b;
	*b = temp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: array of integers.
 * @size: size of the array.
 * @left: a starting index of the subset to order.
 * @right: ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivt, abov, below;

	pivt = array + right;
	for (abov = below = left; below < right; below++)
	{
		if (array[below] < *pivt)
		{
			if (abov < below)
			{
				swap_ints(array + below, array + abov);
				print_array(array, size);
			}
			abov++;
		}
	}

	if (array[abov] > *pivt)
	{
		swap_ints(array + abov, pivt);
		print_array(array, size);
	}

	return (abov);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: array of integers to sort.
 * @size: size of the array.
 * @left: starting index of the array partition to order.
 * @right: ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int pat;

	if (right - left > 0)
	{
		pat = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, pat - 1);
		lomuto_sort(array, size, pat + 1, right);
	}
}

/**
 * quick_sort - sorts array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
