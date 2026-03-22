#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, j, k;
    float A[10][10], L[10][10], sum;

    printf("Enter the order of matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of symmetric matrix row-wise:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%f", &A[i][j]);
        }
    }

    // Initialize L matrix to 0
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            L[i][j] = 0;
        }
    }

    // Cholesky Decomposition
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            sum = 0;

            if (j == i)
            { // Diagonal elements
                for (k = 0; k < j; k++)
                    sum += L[j][k] * L[j][k];

                L[j][j] = sqrt(A[j][j] - sum);
            }
            else
            { // Off-diagonal elements
                for (k = 0; k < j; k++)
                    sum += L[i][k] * L[j][k];

                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }

    printf("\nLower Triangular Matrix (L):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%.1f ", L[i][j]);
        printf("\n");
    }

    printf("\nTranspose Matrix (L^T):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j <= i)
                printf("%.1f ", L[i][j]);
            else
                printf("%.1f ", L[j][i]);
        }
        printf("\n");
    }
    printf("\nLab No.: 12(b) / Name:   / Roll No.:   / Section:C\n");

    return 0;
}


/*Enter the order of matrix: 3
Enter the elements of symmetric matrix row-wise:
1 2 3
2 8 22
3 22 82
x
Lower Triangular Matrix (L):
1.0 0.0 0.0 
2.0 2.0 0.0 
3.0 8.0 3.0 

Transpose Matrix (L^T):
1.0 2.0 3.0
2.0 2.0 8.0
3.0 8.0 3.0
 */