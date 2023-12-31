#include "sort.h"


/**
 * swap - function that swaps two numbers
 * @x: number to be swapped
 * @y: number to be swapped
 * Return: Nothing
 */
void swap(int *x, int *y)
{
	int tmp = *x;

	*x = *y;
	*y = tmp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array of elements to be swapped
 * @size: size of the array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped;

	if ((size <= 0) || !(array))
		return;
	for (i = 0; i < size - 1; i++)
	{
		swapped  = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				swapped = 1;
			}
		}
		if (swapped == 0)
		{
			break;
		}
	}
}
