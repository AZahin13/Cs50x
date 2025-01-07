// function to check if it's a triangle
#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>

void valid_triangle(float a, float b, float c);

int main()
{
    printf("This program checks if you have a triangle\n");
    float a = get_float("Please input your first side: \n");
    float b = get_float("Please input your second side: \n");
    float c = get_float("Please input your third side: \n");
    valid_triangle(a, b, c);
    return 0;
}

void valid_triangle(float a, float b, float c)
{
    if ((a <= 0) || (b <= 0) || (c <= 0))
    {
        printf("Your shape is NOT a triangle!\n");
    }
    else if ((a + b <= c) || (b + c <= a) || (c + a <= b))
    {
        printf("Your shape is NOT a triangle!\n");
    }
    else
    {
        printf("Your shape is a triangle!\n");
    }
}
