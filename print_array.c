#include <stdio.h>
#include <stdlib.h>

/**
 * print_array - prints the array of the integers
 *
 * @array: array printed
 * @size: elements in @array
 */

void print_array(const int *array, size_t size)
{
	size_t j;

	j = 0;
	while (array && j < size)
	{
		if (j > 0)
			printf(", ");
		printf("%d", array[j]);
		++j;
	}
	printf("\n");
}
