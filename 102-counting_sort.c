#include "sort.h"
#include <stdio.h>
/**
 * _bigest - Give me the largest number in array of integers
 * @array: The Int array
 * @size: size of the array
 * Return: The largest number
 */
int _bigest(int *array, size_t size)
{
	size_t i;
	int k = 0;

	for (i = 0; i < size; i++)
	{
		if (k < array[i])
			k = array[i];
	}
	return (k);
}

/**
 * counting_sort - Counting sort
 * @array: array to evaluate
 * @size: size of array
 * Return: None
 * Note: Most of it works, except for the last count[10]
 */
void counting_sort(int *array, size_t size)
{
	size_t i, j;
	int k = 0;
	int *ptr = NULL, *sort_ar = NULL;

	if (size < 2)
		return;
	/*know the largest number in the array*/
	k = _bigest(array, size);
	/*Make the help array*/
	ptr = malloc(sizeof(size_t) * (k + 1));
	
	if (!ptr)
		return;
	/*Set the value for sorting*/
	for (i = 0; i< size; i++)
		for (j = 0; (int)j < k + 1; j++)
			if ((int)j == array[i])
				ptr[j] += 1;
	/*Modificate the count in the array*/
	for (i = 0;(int)i < k; i++)
		ptr[i + 1] = ptr[i] + ptr[i + 1];
	print_array(ptr, k + 1);
	/*Create the sort array*/
	sort_ar = malloc(size * sizeof(int));
	if (!sort_ar)
	{
		free(ptr);
		return;
	}
	for (i = 0; i < size; i++)
	{
		sort_ar[ptr[array[i]] - 1] = array[i];
		ptr[array[i]] -= 1;
	}
	for (j = 0; j < size; j++)
		array[j] = sort_ar[j];
	free(sort_ar);
	free(ptr);
}
