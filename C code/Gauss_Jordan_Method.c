#include <stdio.h>

int main() {
    int n, i, j, k;
    float a[10][10], ratio;

    printf("Enter number of variables: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix coefficients:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Gauss-Jordan Elimination
    for(i = 0; i < n; i++) {
        if(a[i][i] == 0.0) {
            printf("Mathematical Error!");
            return 0;
        }

        for(j = 0; j < n; j++) {
            if(i != j) {
                ratio = a[j][i] / a[i][i];
                for(k = 0; k <= n; k++) {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }

    printf("\nSolution:\n");
    for(i = 0; i < n; i++) {
        printf("x%d = %0.3f\n", i+1, a[i][n] / a[i][i]);
    }

    printf("\nLab No.: 10(c) / Name:  / Roll No.:  / Section:\n");


    return 0;
}

/*Enter number of variables: 3
Enter the augmented matrix coefficients:
2 4 -6 -8
1 3 1 10
2 -4 -2 -12

Solution:
x1 = 1.000
x2 = 2.000
x3 = 3.000*/