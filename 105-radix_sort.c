#include "sort.h"

/**
* radix_sort - sorts an array following the Radix sort algorithm
* @array: array of ints to sort
* @size: size of the array
*/
void radix_sort(int *array, size_t size)
{
int max;
size_t k, lsd;

if (!array || size < 2)
return;

max = 0;
for (k = 0; k < size; k++)
if (array[k] > max)
max = array[k];

for (lsd = 1; max / lsd > 0; lsd *= 10)
{
my_count_sort_LSD(array, size, lsd);
print_array(array, size);
}
}

/**
* my_count_sort_LSD - count sort with LSD
* @array: array to sort
* @size: size of the array
* @lsd: least significant digit
*/
void my_count_sort_LSD(int *array, size_t size, size_t lsd)
{
int count_arr[10] = {0}, *out_arr, l, m;
size_t i, n;

out_arr = malloc(sizeof(int) * size);

for (i = 0; i < size; i++)
count_arr[(array[i] / lsd) % 10]++;
for (l = 1; l < 10; l++)
count_arr[l] += count_arr[l - 1];

for (m = size - 1; m >= 0; m--)
{
out_arr[count_arr[(array[m] / lsd) % 10] - 1] = array[m];
count_arr[(array[m] / lsd) % 10]--;
}

for (n = 0; n < size; n++)
array[n] = out_arr[n];

free(out_arr);
}
