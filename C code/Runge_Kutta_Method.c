#include <stdio.h>

float f(float x, float y)
{
    //return (x*x + y*y);   // dy/dx = x^2 + y^2
    return (y-x)/(y+x);   // dy/dx = (y-x)/(y+x) 
}

int main()
{
    float x0, y0, h, xn;
    float x, y;
    float m1, m2, m3, m4;

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
        m1 =  f(x, y);
        m2 =  f(x + h / 2.0, y + m1*h / 2.0);
        m3 =  f(x + h / 2.0, y + m2*h / 2.0);
        m4 =  f(x + h, y + m3*h);

        y = y + h/6.0 *(m1 + 2 * m2 + 2 * m3 + m4);
        x = x + h;
    }

    printf("\nValue of y at x = %.3f is %.5f", x, y);
    printf("\nLab No.: 9(e) / Name:   / Roll No.:   / Section:C\n");


    return 0;
}
