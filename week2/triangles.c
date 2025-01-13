// function to check if it's a triangle
// a triangle may only have sides with positive length
// the length of two sides cannot be less than or equal to the third
// triangle inequality theorem
// why can't it be equal?
// if it's equal then the sum of the two sides would like flat
// along with the third

#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>

void valid_triangle(float a, float b, float c);

int main()
{
    printf("This program checks if you have a triangle\n");

    // obtain sides of the triangle
    float a = get_float("Please input your first side: \n");
    float b = get_float("Please input your second side: \n");
    float c = get_float("Please input your third side: \n");

    // check for positive int.
    // ideally during float entry
    if ((a <= 0) || (b <= 0) || (c <= 0))
    {
        printf("Please input a positive int\n");
        return 1;
    }

    // call the triangle function
    valid_triangle(a, b, c);

    // return 0 if the program functions correctly
    return 0;
}

void valid_triangle(float a, float b, float c)
{
    // check for the qualities that exclude a triangle
    if ((a + b <= c) || (b + c <= a) || (c + a <= b))
    {
        printf("Your shape is NOT a triangle!\n");
    }
    else
    {
        printf("Your shape is a triangle!\n");
    }
}
