#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, k;
    float A[10][10], L[10][10], B[10], Y[10], X[10], sum;

    printf("Enter order of symmetric matrix (n): ");
    scanf("%d", &n);

    printf("Enter elements of symmetric matrix A:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%f", &A[i][j]);

    printf("Enter constants B:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &B[i]);

    // Initialize L matrix with zeros
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            L[i][j] = 0;

    // Step 1: Cholesky Decomposition (A = LL^T)
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            sum = 0;
            if (j == i) { // Diagonal elements
                for (k = 0; k < j; k++)
                    sum += pow(L[j][k], 2);
                L[j][j] = sqrt(A[j][j] - sum);
            } else { // Off-diagonal elements
                for (k = 0; k < j; k++)
                    sum += (L[i][k] * L[j][k]);
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }

    // Step 2: Forward Substitution (LY = B)
    for (i = 0; i < n; i++) {
        sum = 0;
        for (k = 0; k < i; k++)
            sum += L[i][k] * Y[k];
        Y[i] = (B[i] - sum) / L[i][i];
    }

    // Step 3: Back Substitution (L^T X = Y)
    for (i = n - 1; i >= 0; i--) {
        sum = 0;
        for (k = i + 1; k < n; k++)
            sum += L[k][i] * X[k]; // Using L[k][i] is equivalent to L^T[i][k]
        X[i] = (Y[i] - sum) / L[i][i];
    }

    printf("\nSolution using Cholesky:\n");
    for (i = 0; i < n; i++)
        printf("x[%d] = %.3f\n", i + 1, X[i]);

    printf("\nLab No.: 13(c) / Name:   / Roll No.:   / Section:C\n");
    return 0;
}