#include "sort.h"

void swap(int *x, int *y);
int partition(int *array, size_t size, int low, int high);
void quicksort_recursion(int *array, size_t size, int low, int high);
void quick_sort(int *array, size_t size);

/**
 * swap - Swaps the value of two integers in an array.
 * @x: Pointer to the first integer to swap.
 * @y: Pointer to the second integer to swap.
 */

void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * partition - Order a subset of an array of integers using the
 *             lomuto partition scheme with the last element as pivot.
 * @array: An array of integers given.
 * @size: Size of the given array.
 * @low: Starting index of the given array using the lomuto partition scheme.
 * @high: Ending index of the given array using the lomuto partition scheme.
 *
 * Return: The final partition index.
 */

int partition(int *array, size_t size, int low, int high)
{
	int *pivot_value, over, under;

	pivot_value = array + high;
	for (over = under = low; under < high; under++)
	{
		if (array[under] < *pivot_value)
		{
			if (over < under)
			{
				swap(array + under, array + over);
				print_array(array, size);
			}
			over++;
		}
	}

	if (array[over] > *pivot_value)
	{
		swap(array + over, pivot_value);
		print_array(array, size);
	}

	return (over);
}

/**
 * quicksort_recursion - Implements the quicksort algorithm through recursion.
 * @array: An array of integers given.
 * @size: Size of the given array.
 * @low: Starting index of given array using the lomuto partition scheme.
 * @high: Ending index of given array using the lomuto partition scheme.
 *
 * Description: Uses the lomuto scheme.
 */

void quicksort_recursion(int *array, size_t size, int low, int high)
{
	int part;

	if (high - low > 0)
	{
		part = partition(array, size, low, high);
		quicksort_recursion(array, size, low, part - 1);
		quicksort_recursion(array, size, part + 1, high);
	}
}
/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 * @array: Array of integers given.
 * @size: Size of the given array.
 *
 * Description: Uses the lomuto partition scheme to print the array
 * after the swaping of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursion(array, size, 0, size - 1);
}
