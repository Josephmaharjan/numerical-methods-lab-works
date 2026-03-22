#include<stdio.h>

int main() {
    float x[10], y[10], dy[10][10], h, xp, s, der;
    int n, i, j;

    printf("Enter number of points: ");
    scanf("%d", &n);
    printf("Enter values of x and y:\n");
    for(i=0; i<n; i++) scanf("%f %f", &x[i], &y[i]);

    printf("Enter the point x at which derivative is required: ");
    scanf("%f", &xp);

    h = x[1] - x[0];
    s = (xp - x[0]) / h;

    for(i=0; i<n; i++) dy[i][0] = y[i];

    // Forward Difference Table
    for(j=1; j<n; j++) {
        for(i=0; i<n-j; i++) {
            dy[i][j] = dy[i+1][j-1] - dy[i][j-1];
        }
    }

    // Derivative using the general formula with s
    float term1 = dy[0][1];
    float term2 = ((2 * s - 1) / 2.0) * dy[0][2];
    float term3 = ((3 * s * s - 6 * s + 2) / 6.0) * dy[0][3];
    
    der = (term1 + term2 + term3) / h;

    printf("\nDerivative at x = %.4f is: %.4f\n", xp, der);


   printf("Lab No.: 6 (b) / Name:   / Roll No.:   / Section: C\n");
    return 0;
}