#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, j;
    float A[10][10], X[10], Y[10];
    float eigenvalue = 0, oldEigenvalue = 0;
    float tolerance;

    printf("Enter order of matrix: ");
    scanf("%d", &n);

    printf("Enter matrix A:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%f", &A[i][j]);
        }
    }

    printf("Enter initial guess vector:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &X[i]);
    }

    printf("Enter tolerance: ");
    scanf("%f", &tolerance);

    while (1)
    {

        // Multiply A * X
        for (i = 0; i < n; i++)
        {
            Y[i] = 0;
            for (j = 0; j < n; j++)
            {
                Y[i] += A[i][j] * X[j];
            }
        }

        // Find maximum absolute value
        eigenvalue = fabs(Y[0]);
        for (i = 1; i < n; i++)
        {
            if (fabs(Y[i]) > eigenvalue)
                eigenvalue = fabs(Y[i]);
        }

        // Normalize vector
        for (i = 0; i < n; i++)
        {
            X[i] = Y[i] / eigenvalue;
        }

        // Check convergence
        if (fabs(eigenvalue - oldEigenvalue) < tolerance)
            break;

        oldEigenvalue = eigenvalue;
    }

    printf("\nDominant Eigenvalue = %.4f\n", eigenvalue);

    printf("Corresponding Eigenvector:\n");
    for (i = 0; i < n; i++)
    {
        printf("%.4f\n", X[i]);
    }

    printf("\nLab No.: 15 / Name:   / Roll No.:   / Section:C\n");
    return 0;
}

/*Input:
Enter order of matrix: 3
Enter matrix A:
5 4 2
4 5 2
2 2 2
Enter initial guess vector:
0 1 0
Enter tolerance: 0.0001
*/