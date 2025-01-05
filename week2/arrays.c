// array tutorial
#include <stdio.h>

int main(void)
{
    // An array needs a data type
    // it is then initialised by arrayname[]
    double prices[] = {1.0, 2.0, 3.0, 4.0};
    
    // you can individually call upon an array
    // using an index number array[]
    // arrays start from array[0]
    printf("The first price is RM %.2lf\n", prices[0]);

    // using a loop to display all
    // assigning n to the value of 1 index in prices
    // this calculates the number of values in the array
    printf("The full list of prices are:\n");
    int n = sizeof(prices)/sizeof(prices[0]);

    for (int i = 0; i < n; i++)
    {
        printf("RM %.2lf\t", prices[i]);
    }
    printf("\n");
}
