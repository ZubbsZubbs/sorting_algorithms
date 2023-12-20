#include "sort.h"
/**
 *bubble_sort - sorts an array of integers in ascending orde
 *@arr: the array to be sort
 *@size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
    size_t j, i;
    int k;
    if (size < 2)
        return;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                k = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = k;
                print_array(arr, size);
            }
        }
    }
}
