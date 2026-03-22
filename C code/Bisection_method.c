#include <stdio.h>
#include <math.h>

double f(double x)
{
    // return x * x - 4 * cos(x); //x^2 - 4cos(x)
    return x*x*x-x-11;
}

int main()
{
    double a, b, c;
    double f_a, f_b, f_c, rel_error;
    double tolerance;
    const int Max_Iter = 1000;

    printf("Enter initial interval a and b: ");
    scanf("%lf %lf", &a, &b);

    printf("Enter error tolerance(eg. 0.001):");
    scanf("%lf", &tolerance);
    f_a = f(a);
    f_b = f(b);

    if (f_a * f_b >= 0)
    {
        printf("\nError: Invalid interval. f(a) = %.6lf, f(b) = %.6lf\n", f_a, f_b);
        return 1;
    }

    printf("\nIter |     a     |    f(a)   |     b     |    f(b)   |     c     |    f(c)   |  Error\n");
    printf("---------------------------------------------------------------------------------------------\n");

    for (int i = 1; i <= Max_Iter; i++)
    {
        c = (a + b) / 2.0;
        f_c = f(c);

        // Relative Error
        rel_error = fabs((a - b) / b); // fabs : return absolute value of number

        printf("%4d | %9.6lf | %9.6lf | %9.6lf | %9.6lf | %9.6lf | %9.6lf | %9.6lf \n",
               i, a, f_a, b, f_b, c, f_c, rel_error);
        //%9.6lf total width of 9 characters (including digits before/after decimal and decimal point) & 6 digits after the decimal point

        // Stopping Criterion 1: Guaranteed Error Bound
        if (rel_error < tolerance)
        {
            printf("\nRoot found after %d iterations: %.6lf", i, c);
            printf("\nLab No.: 1(a) / Name:   / Roll No.:   / Section: C \n");
            return 0;
        }

        if (f_a * f_c < 0)
        {
            b = c;
            f_b = f_c;
        }
        else
        {
            a = c;
            f_a = f_c;
        }
    }
    printf("\n Max iteration %d: %.6lf", Max_Iter, c);

    return 0;
}
