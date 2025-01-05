// lets sort an array using the bubble sort algorithm
// define an array
// sort the array
// print the array
#include<stdio.h>

void sorter(int size, int array[]);
void printer(int size, int array[]);

int main()
{
    int array[] = {9, 6, 7, 2, 8, 3, 5, 4, 1};
    int size = sizeof(array)/sizeof(array[0]);
    sorter(size, array);
    printer(size, array);
}

void sorter(int size, int array[])
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void printer(int size, int array[])
{
    printf("The array is now sorted in ascending order:\n");
    for (int i = 0; i < size; i++)
    {
        printf(" %i,", array[i]);
    }
    printf("\n");
}
