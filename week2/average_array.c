// program to calculate the average of an array
#include <stdio.h>

int main()
{
    int array[] = {72, 77, 33};
    int size = sizeof(array) / sizeof(array[0]);

    float total = 0;
    for(int i = 0; i < size; i++)
    {
        total += array[i];
    }

    //calculate the average
    float average = total / size;
    printf("The average is %.2f percent \n", average);

    return 0;
}
