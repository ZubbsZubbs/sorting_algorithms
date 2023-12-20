#include "sort.h"
/**
* shell_sort -Sort an array using shell_sort algorithm
* @array: array
* @size: size of the array
* Return: NULL
**/
void shell_sort(int *array, size_t size)
{
unsigned int gap = 1, i, j;
int tmp;
if (array == NULL)
return;
if (size < 2)
return;
while (gap < size / 3)
gap = gap * 3 + 1;
while (gap > 0)
{
for (i = gap; i < size; i++)
{
tmp = array[i];
j = i;
while (j >= gap && array[j - gap] > tmp)
{
array[j] = array[j - gap];
j -= gap;
}
array[j] = tmp;
}
print_array(array, size);
gap /= 3;
}
}
