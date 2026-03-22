#include <stdio.h>
#include <math.h>

int main()
{
    float x0, y0, x, h, yx;
    float y_prime, y_double_prime, y_triple_prime;

    printf("For y' = x - y^2 Enter initial x0 and y0: ");
    scanf("%f %f", &x0, &y0);
    printf("Enter x at which y is required: ");
    scanf("%f", &x);

    h = x - x0;

    // Derivatives for y' = x - y^2 at (x0, y0)
    y_prime = x0 - y0 * y0;
    y_double_prime = 1 - 2 * y0 * y_prime;
    y_triple_prime = -2 * (y_prime * y_prime + y0 * y_double_prime);

    // Taylor Series: y(x) = y0 + h*y' + (h^2/2)*y'' + (h^3/6)*y'''
    yx = y0 + (h * y_prime) + (pow(h, 2) / 2.0) * y_double_prime + (pow(h, 3) / 6.0) * y_triple_prime;

    printf("\nResult y(%.4f) = %.4f\n", x, yx);
    printf("\nLab No.: 9(a) / Name:   / Roll No.:   / Section:C\n");
    return 0;
}