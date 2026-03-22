#include <stdio.h>
#include <math.h>

float f(float x) { return 3*x*x+5; }

int main() {
    float a, b, c1, c2, x, res2, res3;
    printf("Enter limits a and b: ");
    scanf("%f %f", &a, &b);

    c1 = (b - a) / 2.0;
    c2 = (b + a) / 2.0;

    // 2-point
    res2 = c1 * (f(c1 * (-1/sqrt(3)) + c2) + f(c1 * (1/sqrt(3)) + c2));

    // 3-point
    res3 = c1 * ((5.0/9.0) * f(c1 * (-sqrt(0.6)) + c2) + 
                 (8.0/9.0) * f(c2) + 
                 (5.0/9.0) * f(c1 * (sqrt(0.6)) + c2));

    printf("2-Point: %.4f\n3-Point: %.4f\n", res2, res3);
    printf("\nLab No.: 7(g) / Name:   / Roll No.:   / Section:C\n");
    return 0;
}