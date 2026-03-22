#include <stdio.h>

int main()
{
    int n, i, j;
    double x, h, s, y;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    double xp[n], bd[n][n];

    printf("Enter data points (x y):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf %lf", &xp[i], &bd[i][0]);
    }

    /* Construct backward difference table */
    for (j = 1; j < n; j++)
    {
        for (i = n - 1; i >= j; i--)
        {
            bd[i][j] = bd[i][j - 1] - bd[i - 1][j - 1];
        }
    }

    printf("Enter the value of x for interpolation: ");
    scanf("%lf", &x);

    h = xp[1] - xp[0];
    s = (x - xp[n - 1]) / h;

    y = bd[n - 1][0];
    double term = 1.0;

    for (i = 1; i < n; i++)
    {
        term = term * (s + (i - 1)) / i;
        y = y + term * bd[n - 1][i];
    }

    printf("\nInterpolated value at x = %.4lf is y = %.6lf\n", x, y);

    printf("\nLab No.: 3(d) / Name:   / Roll No.:   / Section: C \n");


    return 0;
}
