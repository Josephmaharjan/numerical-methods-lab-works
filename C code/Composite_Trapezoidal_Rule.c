#include <stdio.h>
#include <math.h>

float f(float x) { return sqrt(1+x*x); }

int main() {
    float a, b, h, sum = 0, integration;
    int n, i;
    printf("Enter a, b and number of segments (n): ");
    scanf("%f %f %d", &a, &b, &n);

    h = (b - a) / n;
    sum = f(a) + f(b);

    for (i = 1; i < n; i++) {
        sum += 2 * f(a + i * h);
    }
    integration = (h / 2) * sum;

    printf("Result: %.4f\n", integration);
    printf("\nLab No.: 7(b) / Name:   / Roll No.:   / Section:C\n");
    return 0;
}