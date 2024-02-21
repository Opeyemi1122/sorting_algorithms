#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
* swap_ints - Swaps the two integers in the array.
* @a: first integer to swap.
* @x: second integer to swap.
*/
void swap_ints(int *a, int *x)
{
	if (a != x)
	{
		*a ^= *x;
		*x ^= *a;
		*a ^= *x;
	}
}

/**
* lomuto_partition - Order the subset of the array of integers according to
*                    lomuto partition scheme (last element as pivot).
* @array: array of integers.
* @size: size of the array.
* @right: ending index of the subset to order.
* @left: starting index of the subset to order.
*
* Return: The final partition index.
*/
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int pivt = array[right];
	int i = left - 1;

	for (int j = left; j <= right - 1; j++)
	{
		if (array[j] < pivt)
		{
			i++;
			swap_ints(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap_ints(&array[i + 1], &array[right]);
	print_array(array, size);
	return (i + 1);
}

/**
* lomuto_sort - Implement the quicksort algorithm through recursion.
* @array: An array of integers to sort.
* @left: The starting index of the array partition to order.
* @right: The ending index of the array partition to order.
* @size: The size of the array.
*
* Description: Uses the Lomuto partition scheme.
*/
void lomuto_sort(int *array, size_t size, int left, int right)
{
	if (left < right)
	{
		int part = lomuto_partition(array, size, left, right);

		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
* quick_sort - sorts an array of integers in ascending
*              order using the quicksort algorithm.
* @array: array of integers.
* @size: size of the array.
*
* Description: Uses Lomuto partition scheme. Prints
*              the array after each swap of two elements.
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;
	lomuto_sort(array, size, 0, size - 1);
}
