#include <stdio.h>
#include <math.h>

int main()
{
    int n, i;
    double x, y;
    double sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0;
    double a, A, B;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter data points (x y) (y > 0):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf %lf", &x, &y);
        y = log(y); // linearize by taking ln(y)
        sumx += x;
        sumy += y;
        sumxy += x * y;
        sumx2 += x * x;
        
    }

    B = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx);
    a = (sumy - B * sumx) / n;
    A = exp(a); // convert back from ln(A)

    printf("\nEquation of best fit exponential model is:\n");
    printf("y = %.4lf * e^(%.4lf * x)\n", A, B);

    printf("\nLab No.: 4(b) / Name:   / Roll No.:   / Section: C \n");


    return 0;
}
