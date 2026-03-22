#include <stdio.h>
#include <math.h>


// Original equation: 1 + 0.5*sin(x) - x = 0
// Rearranged to x = g(x) -> g(x) = 1 + 0.5*sin(x)
double g(double x)
{
    return 1 + 0.5 * sin(x);
}

int main()
{
    double x0, x1, error, tolerance;
    int iteration = 1;

    printf("Enter initial guess x0: ");
    scanf("%lf", &x0); // 1.25

    printf("Enter error tolerance (eg. 0.001): ");
    scanf("%lf", &tolerance);

    printf("\nIter |    x0     |    g(x0)     |   Error\n");
    printf("-----------------------------------------\n");

    do
    {
        x1 = g(x0);
        error = fabs((x1 - x0)/x1);

        printf("%4d | %9.6lf | %9.6lf | %9.6lf\n",
               iteration, x0, x1, error);

        x0 = x1;
        iteration++;

    } while (error > tolerance);

    printf("\nRoot = %.6lf\n", x1);

    printf("\nLab No.: 1(e) / Name:   / Roll No.:   / Section: C \n");

    return 0;
}
