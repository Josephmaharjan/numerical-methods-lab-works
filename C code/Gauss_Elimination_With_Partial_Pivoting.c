#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, j, k, maxRow;
    float a[10][10], x[10], ratio, temp, max;

    printf("Enter number of unknowns: ");
    scanf("%d", &n);

    printf("Enter augmented matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    // Forward Elimination with Pivoting
    for (i = 1; i <= n - 1; i++)
    {
        max = fabs(a[i][i]);
        maxRow = i;

        for (k = i + 1; k <= n; k++)
        {
            if (fabs(a[k][i]) > max)
            {
                max = fabs(a[k][i]);
                maxRow = k;
            }
        }

        // Swap rows
        if (maxRow != i)
        {
            for (j = 1; j <= n + 1; j++)
            {
                temp = a[i][j];
                a[i][j] = a[maxRow][j];
                a[maxRow][j] = temp;
            }
        }

        for (j = i + 1; j <= n; j++)
        {
            ratio = a[j][i] / a[i][i];
            for (k = 1; k <= n + 1; k++)
            {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }

    // Back Substitution
    x[n] = a[n][n + 1] / a[n][n];
    for (i = n - 1; i >= 1; i--)
    {
        x[i] = a[i][n + 1];
        for (j = i + 1; j <= n; j++)
        {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }

    printf("\nSolution:\n");
    for (i = 1; i <= n; i++)
    {
        printf("x%d = %f\n", i, x[i]);
    }

    printf("\nLab No.: 10(b) / Name:   / Roll No.:   / Section:C\n");

    return 0;
}
