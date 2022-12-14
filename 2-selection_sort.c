#include "sort.h"

/**
 * selection_sort - selection sort algoerithms
 * https://en.wikipedia.org/wiki/Selection_sort
 * @array: array of integer to sort
 * @size: size of array
 *
 * Retrun: 
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, minIndex;
	int tmp;

	if (array == NULL || size < 1 )
		return;
	for (i = 0; i < size - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIndex])
				minIndex = j;
		}
		if (array[minIndex] != array[i])
		{
			tmp = array[minIndex];
			array[minIndex] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
