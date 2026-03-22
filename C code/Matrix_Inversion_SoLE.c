#include <stdio.h>

int main() {
    int n, i, j, k;
    float matrix[10][20], ratio, x[10];

    printf("Enter the number of variables (n): ");
    scanf("%d", &n);

    printf("Enter the coefficients of matrix A and constants B (Augmented Matrix [A|B]):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    // Augmenting with Identity Matrix for Inversion (conceptually)
    // However, for solving AX=B directly, we can use Gauss-Jordan on [A|B]
    for (i = 0; i < n; i++) {
        if (matrix[i][i] == 0.0) {
            printf("Mathematical Error: Pivot element is zero!");
            return 0;
        }
        for (j = 0; j < n; j++) {
            if (i != j) {
                ratio = matrix[j][i] / matrix[i][i];
                for (k = 0; k < n + 1; k++) {
                    matrix[j][k] = matrix[j][k] - ratio * matrix[i][k];
                }
            }
        }
    }

    // Obtaining Solution
    printf("\nThe solution is:\n");
    for (i = 0; i < n; i++) {
        x[i] = matrix[i][n] / matrix[i][i];
        printf("x[%d] = %.2f\n", i + 1, x[i]);
    }
    printf("\nLab No.: 13(a) / Name:   / Roll No.:   / Section:C\n");

    return 0;
}

/*
For the system:
3x + 2y = 13
x - y = -1

Number of variables: 2
Row 1: 3 2 13
Row 2: 1 -1 -1*/