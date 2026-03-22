#include <stdio.h>

int main()
{
    int n, i, j;
    double x, result;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    double xp[n], dd[n][n];

    printf("Enter data points (x y):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf %lf", &xp[i], &dd[i][0]);
    }

    /* Construct divided difference table */
    for (j = 1; j < n; j++)
    {
        for (i = 0; i < n - j; i++)
        {
            dd[i][j] = (dd[i + 1][j - 1] - dd[i][j - 1]) /
                       (xp[i + j] - xp[i]);
        }
    }

    printf("Enter the value of x for interpolation: ");
    scanf("%lf", &x);

    result = dd[0][0];
    double term = 1.0;

    for (i = 1; i < n; i++)
    {
        term *= (x - xp[i - 1]);
        result += term * dd[0][i];
    }

    printf("\nInterpolated value at x = %.4lf is y = %.6lf\n", x, result);

    printf("\nLab No.: 3(b) / Name:   / Roll No.:   / Section: C \n");


    return 0;
}
