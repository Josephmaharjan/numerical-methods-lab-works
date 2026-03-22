#include <stdio.h>
#include <math.h>

double f(double x)
{
    return (x * x * x - 3 * x + 1);
}

int main()
{
    double a, b, c, prev_c, tolerance, error;
    int iteration = 1;

    printf("Enter the value of a and b: ");
    scanf("%lf %lf", &a, &b);

    printf("Enter the error tolerance (eg. 0.001): ");
    scanf("%lf", &tolerance);

    if (f(a) * f(b) >= 0)
    {
        printf("Invalid initial guesses.\n");
        return 0;
    }

    printf("\nIter |     a     |    f(a)   |     b     |    f(b)   |     c     |    f(c)   |   Error\n");
    printf("----------------------------------------------------------------------------------------------\n");

    prev_c = a; // initial previous value

    do
    {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        error = fabs(c - prev_c);

        printf("%4d | %9.6lf | %9.6lf | %9.6lf | %9.6lf | %9.6lf | %9.6lf | %9.6lf\n",
               iteration, a, f(a), b, f(b), c, f(c), error);

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        prev_c = c;
        iteration++;

    } while (error > tolerance);

    printf("\nRoot = %.6lf\n", c);
    printf("\nLab No.: 1(b) / Name:   / Roll No.:   / Section: C \n");

    return 0;
}
