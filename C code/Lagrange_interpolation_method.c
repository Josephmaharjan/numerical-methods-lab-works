#include <stdio.h>

int main()
{
    int n, i, j;
    double x, y = 0.0;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    double xp[n], yp[n];

    printf("Enter data points (x y):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf %lf", &xp[i], &yp[i]);
    }

    printf("Enter the value of x for interpolation: ");
    scanf("%lf", &x);

    for (i = 0; i < n; i++)
    {
        double term = yp[i];
        for (j = 0; j < n; j++)
        {
            if (j != i)
            {
                term = term * (x - xp[j]) / (xp[i] - xp[j]);
            }
        }
        y += term;
    }

    printf("\nInterpolated value at x = %.4lf is y = %.6lf\n", x, y);

    printf("\nLab No.: 3(a) / Name:   / Roll No.:   / Section: C \n");


    return 0;
}
