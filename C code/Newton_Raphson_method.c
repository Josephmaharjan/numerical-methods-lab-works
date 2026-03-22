#include <stdio.h>
#include <math.h>

double f(double x)
{
    return cos(x) - x * exp(x); // f(x) = cos(x) - x e^x
}

double f_derivative(double x)
{
    return -sin(x) - exp(x) - x * exp(x); // f'(x) = -sin(x) - e^x - x e^x
}

int main()
{
    double x0, x1, error, tolerance;
    int iteration = 1;

    printf("Enter initial guess x0: ");
    scanf("%lf", &x0);

    printf("Enter error tolerance (eg. 0.001): ");
    scanf("%lf", &tolerance);

    printf("\nIter |    x0     |   f(x0)   |  f'(x0)  |   x1     |   Error\n");
    printf("---------------------------------------------------------------\n");

    do
    {
        x1 = x0 - f(x0) / f_derivative(x0);
        error = fabs((x1 - x0) / x1);

        printf("%4d | %9.6lf | %9.6lf | %9.6lf | %9.6lf | %9.6lf\n",
               iteration, x0, f(x0), f_derivative(x0), x1, error);

        x0 = x1;
        iteration++;

    } while (error > tolerance);

    printf("\nRoot = %.6lf\n", x1);

    printf("\nLab No.: 1(d) / Name:   / Roll No.:   / Section: C \n");

    return 0;
}
