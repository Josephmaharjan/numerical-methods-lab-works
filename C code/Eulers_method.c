#include <stdio.h>
#include <math.h>

float f(float x, float y)
{
    return 2 * x + y; // input: 0 1 0.4 0.1   //book page no.269,270

    // return 3*pow(x,2)+1; <<---WITHOUT X IN FUNCTION---->>  // input: 1 2 2 0.5
}

int main()
{
    float x0, y0, xn, h, y, x;
    int steps;

    printf("Enter Initial Conditions (x0, y0): ");
    scanf("%f %f", &x0, &y0);
    printf("Enter calculation point (xn): ");
    scanf("%f", &xn);
    printf("Enter step size: ");
    scanf("%f", &h);

    steps = (xn - x0) / h; // number of steps

    x = x0;
    y = y0;

    printf("\nIteration\t x\t\t y\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < steps; i++)
    {
        printf("%d\t\t %.4f\t\t %.4f\n", i, x, y);
        y = y + h * f(x, y); // Euler update
        x = x + h;
    }

    // Print final step
    printf("%d\t\t %.4f\t\t %.4f\n", steps, x, y);

    printf("\nValue of y at x = %.2f is %.4f\n", xn, y);
    printf("\nLab No.: 9(c) / Name:   / Roll No.:   / Section:C\n");

    return 0;
}
