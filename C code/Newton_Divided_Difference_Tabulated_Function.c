/**6. WAP to find the derivative of a tabulated function using
a. Newton's Divided Difference Formula
*/

#include<stdio.h>

int main() {
    float x[10], y[10], d[10][10], val, sum, term;
    int n, i, j;

    printf("Enter number of data points: ");
    scanf("%d", &n);
    printf("Enter data points (x and y):\n");
    for(i = 0; i < n; i++) scanf("%f %f", &x[i], &y[i]);

    printf("Enter point to find derivative: ");
    scanf("%f", &val);

    // Initialize first column of table
    for(i = 0; i < n; i++) d[i][0] = y[i];

    // Build Divided Difference Table
    for(j = 1; j < n; j++) {
        for(i = 0; i < n - j; i++) {
            d[i][j] = (d[i+1][j-1] - d[i][j-1]) / (x[i+j] - x[i]);
        }
    }

    // Derivative Calculation (for first two terms as example)
    sum = d[0][1] + d[0][2] * (2 * val - x[0] - x[1]);

    printf("\nDerivative at x = %.4f is %.4f\n", val, sum);

    printf("Lab No.: 6 (a) /Name:   / Roll No.:   / Section: C\n");
    return 0;
}