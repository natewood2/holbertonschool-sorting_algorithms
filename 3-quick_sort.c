#include "sort.h"

void swap_(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition_and_sort(int *array, int l, int h, size_t size) 
{
    int pivot;
    int i, j;

    pivot = array[h];
    i = l;

    for (j = l; j < h; j++) 
    {
        if (array[j] <= pivot) 
        {
            swap_(&array[i], &array[j]);
            if (i != j)
            {
                print_array(array, size);
            }
            i++;
        }
    }

    swap_(&array[i], &array[h]);
    if (i != h)
    {
        print_array(array, size);
    }
    return i;
}

void quick_recursion(int *array, int l, int h, size_t size) 
{
    if (l < h) 
    {
        int pivot_index = partition_and_sort(array, l, h, size);

        quick_recursion(array, l, pivot_index - 1, size);
        quick_recursion(array, pivot_index + 1, h, size);
    }
}

void quick_sort(int *array, size_t size) 
{
    if (size < 2) 
    {
        return;
    }

    quick_recursion(array, 0, size - 1, size);
}
