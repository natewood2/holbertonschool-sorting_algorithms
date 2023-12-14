#include "sort.h"


void swap_(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
void selection_sort(int *array, size_t size)
{
    size_t i, j, index;

    for (i = 0; i < size - 1; i++)
    {
        index = i;

        for(j = i + 1; j < size; j++)
        {
            if(array[j] < array[index])
            {
                index = j;
            }
        }
        if (index != i) 
        {
            swap_(&array[index], &array[i]);
        }
        print_array(array, size);
    }
}
