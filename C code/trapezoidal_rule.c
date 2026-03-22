#include <stdio.h>

float f(float x) {
    return x*x*x+2;
}

int main() {
    float a, b, h, integration;
    printf("Enter lower limit (a) and upper limit (b): ");
    scanf("%f %f", &a, &b);

    h = b - a;
    integration = (h / 2) * (f(a) + f(b));

    printf("Result: %.4f\n", integration);
    printf("\nLab No.: 7(a) / Name:   / Roll No.:   / Section:C\n");
    return 0;
}