#include <stdio.h>
#include <math.h>

double f(double x)
{
    return exp(-x)-3*x;  
}

int main()
{
    double x0, x1, x2, error, tolerance;
    int iteration = 1;

    printf("Enter two initial guesses x0 and x1: ");
    scanf("%lf %lf", &x0, &x1);

    printf("Enter the error tolerance (eg. 0.001): ");
    scanf("%lf", &tolerance);

    printf("\nIter |    x0     |   f(x0)    |    x1     |   f(x1)    |   x2      |   Error\n");
    printf("----------------------------------------------------------------------------\n");

    do
    {
        x2 = x1 - f(x1)*(x1 - x0)/(f(x1) - f(x0));
        error = fabs((x2 - x1)/x2);  

        printf("%4d | %9.6lf | %10.6lf | %9.6lf | %10.6lf | %9.6lf | %9.6lf\n",
               iteration, x0, f(x0), x1, f(x1), x2, error);

        x0 = x1;
        x1 = x2;
        iteration++;

    } while(error > tolerance);

    printf("\nRoot = %.6lf\n", x2);

    printf("\nLab No.: 1(c) / Name:   / Roll No.:   / Section: C \n");


    return 0;
}
