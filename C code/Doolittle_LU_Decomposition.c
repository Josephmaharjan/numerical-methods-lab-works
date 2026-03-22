#include <stdio.h>

int main()
{
    int n, i, j, k;
    float A[10][10], L[10][10], U[10][10], B[10], Y[10], X[10], sum;

    printf("Enter the number of variables (n): ");
    scanf("%d", &n);

    printf("Enter the elements of coefficient matrix A:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%f", &A[i][j]);

    printf("Enter the constants B:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &B[i]);

    // Step 1: LU Decomposition (Doolittle)
    for (i = 0; i < n; i++)
    {
        for (k = i; k < n; k++)
        {
            sum = 0;
            for (j = 0; j < i; j++)
                sum += (L[i][j] * U[j][k]);
            U[i][k] = A[i][k] - sum;
        }
        for (k = i; k < n; k++)
        {
            if (i == k)
                L[i][i] = 1;
            else
            {
                sum = 0;
                for (j = 0; j < i; j++)
                    sum += (L[k][j] * U[j][i]);
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }

    // Step 2: Forward Substitution (LY = B)
    for (i = 0; i < n; i++)
    {
        sum = 0;
        for (j = 0; j < i; j++)
            sum += L[i][j] * Y[j];
        Y[i] = B[i] - sum;
    }

    // Step 3: Back Substitution (UX = Y)
    for (i = n - 1; i >= 0; i--)
    {
        sum = 0;
        for (j = i + 1; j < n; j++)
            sum += U[i][j] * X[j];
        X[i] = (Y[i] - sum) / U[i][i];
    }

    printf("\nThe solution is:\n");
    for (i = 0; i < n; i++)
        printf("x[%d] = %.3f\n", i + 1, X[i]);

    printf("\nLab No.: 13(b) / Name:   / Roll No.:   / Section:C\n");

    return 0;
}


/**Enter the number of variables (n): 3
Enter the elements of coefficient matrix A:
2 3 1
1 2 3
3 1 2
Enter the constants B:
9 6 8
 */