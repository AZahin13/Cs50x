// personal project to play around with sorting algorithms
// program to sort according to your choice of algos
// helps you measure time taken for each algo

#include <stdio.h>
#define MAX 10 

void sel_sort(int array[]);
void bub_sort(int array[]);

int main(void)
{
    // declare array of MAX
    int array[MAX];

    // get input from the user
    printf("Please input 10 numbers out of order. \n");

    // populate the array
    for(int i = 0; i < MAX; i++)
    {
        printf("Number %i: ", i + 1);
        scanf(" %i", &array[i]);
    }

    // Let user choose which sorting algo
    printf("Which algorithm would you like to use?\n");
    printf("1.Selection Sort\t2.Bubble Sort\n");

    int algo_choice = 0;
    do
    {
        printf("Number 1 or 2:\n");
        scanf(" %i", &algo_choice);
    }
    while(!(algo_choice == 1 || algo_choice == 2)); //repeat for correct input

    if (algo_choice == 1)
    {
        sel_sort(array);
    }
    else
    {
        bub_sort(array);
    }

    // output sorted array
    printf("Sorted in ascending:");
    for(int i = 0; i < MAX; i++)
    {
        printf(" %i,", array[i]);
    }
    printf("\n");

    return 0;
}

// selection sort algo
void sel_sort(int array[])
{
    // iterate over every element of the array
    for(int i = 0; i < MAX - 1; i++)
    {
        int indexMin = i; // initialise var index to location in array

        for(int j = i + 1; j < MAX; j++) // compare over every element after i + 1
        {
            if (array[j] < array[indexMin]) // compares values for smallest
            {
                indexMin = j; // bookmark index of small element
            }
        }

        if (indexMin != i) // swap values if swapped happened
        {
            int tempvalue = array[i];
            array[i] = array[indexMin];
            array[indexMin] = tempvalue;
        }
        // if not swapped, index and value stays the same
    }
}

// bubble sort algo (optimised with while loop)
void bub_sort(int array[])
{
    int swap = 1; // declare swap flag
    do // do while loop to ensure it runs atleast once, keeps running if swaps
    {
        swap = 0; // initialise swap flag to 0
        for(int j = 0; j < MAX - 1; j++) // inner for loop checks for swaps
        {
            if(array[j] > array[j+1])
            {
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
                swap ++; // if no swaps, swap = 0, then loop terminates
            }
        }
    }while (swap != 0);
}

