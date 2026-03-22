#include <stdio.h>
#include <math.h>

float f(float x) {
    return 1.0 / x ;
}

int main() {
    float a, b, h, r[10][10], sum;
    int n, i, j;

    printf("Enter a, b and iterations n: ");
    scanf("%f %f %d", &a, &b, &n);
    h = b - a;

    // --- FORMULA 1: Base Case R(0,0) ---
    // The very first trapezoid with width h
    r[0][0] = (h / 2.0) * (f(a) + f(b));

    for (i = 1; i < n; i++) {
        h = h / 2.0;
        sum = 0;

        // --- FORMULA 2: Finding R(i,0) (The First Column) ---
        // Uses the recursive trapezoidal rule
        for (j = 1; j <= pow(2, i) - 1; j += 2) {
            sum += f(a + j * h);
        }
        r[i][0] = 0.5 * r[i-1][0] + sum * h;

        // --- FORMULA 3: Finding R(i,j) (The Rest of the Row) ---
        // Richardson Extrapolation to improve accuracy
        for (j = 1; j <= i; j++) {
            r[i][j] = (pow(4, j) * r[i][j-1] - r[i-1][j-1]) / (pow(4, j) - 1);
        }
    }

    printf("Result R(%d,%d) = %.4f\n", n-1, n-1, r[n-1][n-1]);
    printf("\nLab No.: 7(h) / Name:   / Roll No.:   / Section:C\n");
    return 0;
}