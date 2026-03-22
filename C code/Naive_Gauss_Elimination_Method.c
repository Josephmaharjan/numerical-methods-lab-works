#include <stdio.h>

int main() {
    int i, j, k, n;
    float a[10][10], x[10], factor;

    printf("Enter the number of unknowns: ");
    scanf("%d", &n);

    printf("Enter the elements of Augmented Matrix (Row-wise):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n + 1; j++) {
            // printf("a[%d][%d]: ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    // Forward Elimination
    for (i = 1; i <= n - 1; i++) {
        if (a[i][i] == 0.0) {
            printf("Error: Division by zero (Naive method failed).\n");
            return 0;
        }
        for (j = i + 1; j <= n; j++) {
            factor = a[j][i] / a[i][i];
            for (k = 1; k <= n + 1; k++) {
                a[j][k] = a[j][k] - factor * a[i][k];
            }
        }
    }

    // Back Substitution
    x[n] = a[n][n+1] / a[n][n];
    for (i = n - 1; i >= 1; i--) {
        float sum = 0;
        for (j = i + 1; j <= n; j++) {
            sum = sum + a[i][j] * x[j];
        }
        x[i] = (a[i][n+1] - sum) / a[i][i];
    }

    // Displaying Results
    printf("\nThe Solution is:\n");
    for (i = 1; i <= n; i++) {
        printf("x[%d] = %.3f\n", i, x[i]);
    }

    printf("\nLab No.: 10(a) / Name:   / Roll No.:   / Section:C\n");

    return 0;
}

/*Enter the number of unknowns: 3
Enter the elements of Augmented Matrix (Row-wise):
2 1 1 10
3 2 3 18
1 4 9 16
*/