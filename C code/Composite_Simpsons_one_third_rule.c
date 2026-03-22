#include <stdio.h>
#include <math.h>

float f(float x) { return sqrt(1 - x * x); }

int main() {
    float a, b, h, sum, integration;
    int n, i;
    printf("Enter limits a, b and even segments n: ");
    scanf("%f %f %d", &a, &b, &n);

    h = (b - a) / n;
    sum = f(a) + f(b);

    for (i = 1; i < n; i++) {
        if (i % 2 == 0) sum += 2 * f(a + i * h);
        else sum += 4 * f(a + i * h);
    }
    integration = (h / 3) * sum;

    printf("Result: %.4f\n", integration);
    printf("\nLab No.: 7(d) / Name:   / Roll No.:   / Section:C\n");
    return 0;
}