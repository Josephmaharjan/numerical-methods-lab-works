#include <stdio.h>

int main()
{
    int n, i, j;
    double x, h, s, y;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    double xp[n], fd[n][n];

    printf("Enter data points (x y):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf %lf", &xp[i], &fd[i][0]);
    }

    /* Calculate forward difference table */
    for (j = 1; j < n; j++)
    {
        for (i = 0; i < n - j; i++)
        {
            fd[i][j] = fd[i + 1][j - 1] - fd[i][j - 1];
        }
    }

    printf("Enter the value of x for interpolation: ");
    scanf("%lf", &x);

    h = xp[1] - xp[0];
    s = (x - xp[0]) / h;

    y = fd[0][0];
    double term = 1.0;

    for (i = 1; i < n; i++)
    {
        term = term * (s - (i - 1)) / i;
        y = y + term * fd[0][i];
    }

    printf("\nInterpolated value at x = %.4lf is y = %.6lf\n", x, y);
    
    printf("\nLab No.: 3(c) / Name:   / Roll No.:   / Section: C \n");


    return 0;
}
