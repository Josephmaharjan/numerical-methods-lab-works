#include <stdio.h>

// Define the function f(x, y) = x^2 + y^2
float f(float x, float y) {
    return (x * x) + (y * y);
}

int main() {
    float a, b, c, d, h, k, sum = 0, term, integration;
    int n, m, i, j;
    int weight;

    // Limits for x
    printf("Enter limits of x (a, b): ");
    scanf("%f %f", &a, &b);
    // Limits for y
    printf("Enter limits of y (c, d): ");
    scanf("%f %f", &c, &d);
    // Segments
    printf("Enter number of segments for x and y (n, m): ");
    scanf("%d %d", &n, &m);

    h = (b - a) / n;
    k = (d - c) / m;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            // Determine weight based on position in the grid
            if ((i == 0 || i == n) && (j == 0 || j == m)) {
                weight = 1; // Corners
            } else if (i == 0 || i == n || j == 0 || j == m) {
                weight = 2; // Edges
            } else {
                weight = 4; // Interior points
            }

            sum += weight * f(a + i * h, c + j * k);
        }
    }

    integration = (h * k / 4.0) * sum;

    printf("\nResult of Double Integration: %.4f\n", integration);
printf("\nLab No.: 8 / Name:   / Roll No.:   / Section:C\n");

    return 0;
}