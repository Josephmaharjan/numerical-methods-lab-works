#include <stdio.h>
#include <math.h>

float f(float x) { return sqrt(1 - x * x); }

int main()
{
    float a, b, h, integration;
    printf("Enter lower and upper limit: ");
    scanf("%f %f", &a, &b);

    h = (b - a) / 2;
    integration = (h / 3) * (f(a) + 4 * f(a + h) + f(b));

    printf("Result: %.4f\n", integration);
    printf("\nLab No.: 7(c) / Name:   / Roll No.:   / Section:C\n");
    return 0;
}