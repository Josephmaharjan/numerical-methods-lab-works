#include <stdio.h>

int main() {
    int n, i, j, k;
    float A[10][10], L[10][10], U[10][10], sum;

    printf("Enter the order of matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of matrix row-wise:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    // Initialize L and U matrices to 0
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            L[i][j] = 0;
            U[i][j] = 0;
        }
    }

    // Doolittle's Method
    for(i = 0; i < n; i++) {

        // Upper Triangular Matrix
        for(k = i; k < n; k++) {
            sum = 0;
            for(j = 0; j < i; j++)
                sum += L[i][j] * U[j][k];

            U[i][k] = A[i][k] - sum;
        }

        // Lower Triangular Matrix
        for(k = i; k < n; k++) {
            if(i == k)
                L[i][i] = 1;
            else {
                sum = 0;
                for(j = 0; j < i; j++)
                    sum += L[k][j] * U[j][i];

                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }

    printf("\nLower Triangular Matrix (L):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            printf("%.1f ", L[i][j]);
        printf("\n");
    }

    printf("\nUpper Triangular Matrix (U):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            printf("%.1f ", U[i][j]);
        printf("\n");
    }

    printf("\nLab No.: 12(a) / Name:   / Roll No.:   / Section:C\n");


    return 0;
}


/*Enter the order of matrix: 3
Enter the elements of matrix row-wise:
2 -1 -1
-4 6 1
-4 -2 6

Lower Triangular Matrix (L):
1.0 0.0 0.0 
-2.00 1.00 0.00 
-2.00 -1.00 1.00 

Upper Triangular Matrix (U):
2.00 -1.00 -1.00 
0.00 4.00 -1.00 
0.00 0.00 3.00 */