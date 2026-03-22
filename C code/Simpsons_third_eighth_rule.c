#include <stdio.h>
#include <math.h>

float f(float x) { return sqrt(x*x+1); }

int main() {
    float a, b, h, integration;

    printf("Enter a and b: ");
    scanf("%f %f", &a, &b);

    h = (b - a) / 3;
    integration = (3 * h / 8) * (f(a) + 3 * f(a + h) + 3 * f(a + 2 * h) + f(b));

    printf("Result: %.4f\n", integration);
    printf("\nLab No.: 7(e) / Name:   / Roll No.:   / Section:C\n");
    return 0;
}