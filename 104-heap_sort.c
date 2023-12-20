#include "sort.h"

/**
* stupify_funct - recurrssive heapfiy function
* @array: Array to sort
* @heap: size of heap data
* @i: index
* @size: size of array
*/

void stupify_funct(int *array, int heap, int i, int size)
{
	int lar = i, left = 2 * i + 1, right = 2 * i + 2, t;

	if (left < heap && array[left] > array[lar])
		lar = left;
	if (right < heap && array[right] > array[lar])
		lar = right;
	if (lar != i)
	{
		t = array[i], array[i] = array[lar], array[lar] = t;
		print_array(array, size);
		stupify_funct(array, heap, lar, size);
	}
}

/**
* heap_sort - Sorts array with heap sort algo
* @array: array to sort
* @size: Size of array to sort
*/

void heap_sort(int *array, size_t size)
{
	int i = size / 2 - 1, tmp;

	if (array == NULL || size < 2)
		return;
	for (; i >= 0; i--)
		stupify_funct(array, size, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		if (i > 0)
			print_array(array, size);
		stupify_funct(array, i, 0, size);
	}

}
