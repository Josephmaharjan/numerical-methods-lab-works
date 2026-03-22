/*5. WAP to implement numerical differentiation techniques using
a) Forward Difference Formula and Backward Difference Formula (for 1st Derivative) */

#include <stdio.h>

float f(float x)
{
    return x * x ; // Example function: f(x) = x^2
}

int main()
{
    float forward, backward, h, x;
    printf("Enter the point at which derivative is to be calculated: ");
    scanf("%f", &x);

    printf("Enter the value of h (small increment): ");
    scanf("%f", &h);

    forward = (f(x + h) - f(x)) / h;
    backward = (f(x) - f(x - h)) / h;

    printf("Forward Difference Approximation of f' at x = %.4f is: %.4f\n", x, forward);
    printf("Backward Difference Approximation of f' at x = %.4f is: %.4f\n", x, backward);
    printf("\nLab No.: 5(a) / Name:   / Roll No.:   / Section: C \n");

    return 0;
}