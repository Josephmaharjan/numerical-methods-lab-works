#include <stdio.h>
#include <math.h>

float f(float x) { return sqrt(x*x+1); }

int main() {
    float a, b, h, sum, integration;
    int n, i;
    printf("Enter a, b and n (multiple of 3): ");
    scanf("%f %f %d", &a, &b, &n);

    h = (b - a) / n;
    sum = f(a) + f(b);

    for (i = 1; i < n; i++) {
        if (i % 3 == 0) sum += 2 * f(a + i * h);
        else sum += 3 * f(a + i * h);
    }
    integration = (3 * h / 8) * sum;

    printf("Result: %.4f\n", integration);
    printf("\nLab No.: 7(f) / Name:   / Roll No.:   / Section:C\n");
    return 0;
}