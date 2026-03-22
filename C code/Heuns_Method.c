#include <stdio.h>
#include<math.h>

float f(float x, float y)
{
    //return (2*x + y);   // dy/dx = 2x + y // input: 0 1 0.1 0.4  
    return 4*exp(0.8*x)-0.5*y;
}

int main()
{
    float x0, y0, h, xn;
    float x, y, y_next;

    printf("Enter initial values x0 and y0: ");
    scanf("%f %f", &x0, &y0);

    printf("Enter step size h: ");
    scanf("%f", &h);

    printf("Enter value of x at which y is required: ");
    scanf("%f", &xn);

    x = x0;
    y = y0;

    while (x < xn)
    {
        y_next = y + (h / 2.0) * ( f(x, y) + f(x + h, y + h * f(x, y)) );
        y = y_next;
        x = x + h;
    }

    printf("\nValue of y at x = %.3f is %.5f", x, y);
    printf("\nLab No.: 9(d) / Name:   / Roll No.:   / Section:C\n");

    return 0;
}
