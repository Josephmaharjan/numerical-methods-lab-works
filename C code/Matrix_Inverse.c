#include <stdio.h>

int main() {
    int n, i, j, k;
    float a[10][20], ratio;

    printf("Enter order of matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Augmenting with Identity Matrix
    for(i = 0; i < n; i++) {
        for(j = n; j < 2*n; j++) {
            if(i == (j - n))
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }

    // Gauss-Jordan Elimination
    for(i = 0; i < n; i++) {
        if(a[i][i] == 0.0) {
            printf("Mathematical Error! Inverse does not exist.");
            return 0;
        }

        for(j = 0; j < n; j++) {
            if(i != j) {
                ratio = a[j][i] / a[i][i];
                for(k = 0; k < 2*n; k++) {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }

    // Making diagonal elements 1
    for(i = 0; i < n; i++) {
        ratio = a[i][i];
        for(j = 0; j < 2*n; j++) {
            a[i][j] = a[i][j] / ratio;
        }
    }

    printf("\nInverse Matrix is:\n");
    for(i = 0; i < n; i++) {
        for(j = n; j < 2*n; j++) {
            printf("%.2f\t", a[i][j]);
        }
        printf("\n");
    }

    // Required printing statements
    printf("\nLab No.: 11 / Name:   / Roll No.:   / Section:C\n");

    return 0;
}


/*Enter order of matrix: 2
Enter matrix elements:
7 3
5 2

Inverse Matrix is:
-2.000  3.000
5.000   -7.000*/