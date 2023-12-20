#include "sort.h"


/**
* my_swapint - swaps index's of array
* @l: left or low index to swap
* @r: right or high index
*/

void my_swapint(int *l, int *r)
{
	int tmp;

	tmp = *l;
	*l = *r;
	*r = tmp;
}

/**
* b_merge - bitonic merge
* @array: Array slice being merged
* @low: lowest index
* @count: Count of slice
* @dir: Direction, ascending 1 descending 0
* @size: size of total array for printing
*/

void t_merge(int *array, int low, int count, int dir, size_t size)
{
	int k, n;

	if (count > 1)
	{
		n = count / 2;
		for (k = low; k < low + n; k++)
		{
			if (((array[k] > array[k + n]) && dir == 1) ||
			(dir == 0 && (array[k] < array[k + n])))
				my_swapint(&array[k], &array[k + n]);
		}
		t_merge(array, low, n, dir, size);
		t_merge(array, low + n, n, dir, size);
	}
}

/**
* b_sort - bitonic recursive sort
* @array: array to sort
* @low: lowest index
* @count: Count of slice
* @dir: Direction, ascending 1 descending 0
* @size: size of total array for printing
*/

void the_b_sort(int *array, int low, int count, int dir, size_t size)
{
	int n;

	if (count > 1)
	{
		n = count / 2;
		printf("Merging [%d/%d] ", count, (int)size);
		if (dir == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + low, count);
		the_b_sort(array, low, n, 1, size);
		the_b_sort(array, low + n, n, 0, size);
		t_merge(array, low, count, dir, size);
		printf("Result [%d/%d] ", count, (int)size);
		if (dir == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + low, count);
	}
}

/**
* bitonic_sort - Sorts array using bitonic algo
* @array: Array to sort
* @size: Size of array
*/

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	the_b_sort(array, 0, size, 1, size);
}
