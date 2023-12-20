#include "sort.h"
/**
 * my_swap - swap two int
 * @a: int
 * @b: int
 * Return: (void) Swaped int
 */
void my_swap(int *x, int *y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}
/**
 * my_partition - Partition an array and using pivot
 * @arr: Array
 * @low: int
 * @high: int
 * @size: size of array (size_t)
 * Return: index of pivote (int)
 */
int my_partition(int *arr, int low, int high, size_t size)
{
    int pivot = arr[high];
    int i = low - 1, j;
    for (j = low; j <= high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                my_swap(&arr[i], &arr[j]);
                print_array(arr, size);
            }
        }
    }
    return (i);
}
/**
 * my_lomuto_qsort - Sorting Recursively an Array
 * @array: Array to be sorted
 * @low: The lowest value of the array
 * @high: highest value of the array
 * @size: Size of The Array
 * Return: void
 */
void my_lomuto_qsort(int *array, int low, int high, size_t size)
{
    int x;
    if (low < high)
    {
        x = my_partition(array, low, high, size);
        my_lomuto_qsort(array, low, x - 1, size);
        my_lomuto_qsort(array, x + 1, high, size);
    }
}
/**
 * quick_sort - Quick Sort Algorithme using lomuto partition
 * @array: Array to sort
 * @size: Size of The Array
 * Return: Sorted Array (void)
 */
void quick_sort(int *array, size_t size)
{
    my_lomuto_qsort(array, 0, size - 1, size);
}
