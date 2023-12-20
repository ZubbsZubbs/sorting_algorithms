#include "sort.h"
/**
* my_locate_min - Locatin the min From Current index in the array
* @arr: The Array to be Searched
* @index: Starting Index of The Search
* @size: The Size of The Array
* Return: (int) index of min if found or
* same given index if index is the min
*/
int my_locate_min(int *arr, int index, size_t size)
{
int min, idx_min;
int k;
min = arr[index];
idx_min = index;
for (k = index; k < (int)size; k++)
{
if (arr[k] < min)
{
min = arr[k];
idx_min = k;
}
}
if (idx_min == index)
return (-1);
return (idx_min);
}
/**
* selection_sort - Implementation of selection Sort Algrithm
* @array: Array to sort type int *
* @size: The Size of The Given Array
*
* Return: (Void) Sorted Array
*/
void selection_sort(int *array, size_t size)
{
int x;
int mini, tmp;
for (x = 0; x < (int)size; x++)
{
mini = my_locate_min(array, x, size);
if (mini != -1)
{
tmp = array[x];
array[x] = array[mini];
array[mini] = tmp;
print_array(array, size);
}
}
}
