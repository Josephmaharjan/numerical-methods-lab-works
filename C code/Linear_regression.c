#include <stdio.h>

int main()
{
    int n, i;
    double x, y;
    double sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0;
    double a, b;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter data points (x y):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf %lf", &x, &y);
        sumx += x;
        sumy += y;
        sumxy += x * y;
        sumx2 += x * x;
    }

    b = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx);
    a = (sumy - b * sumx) / n;

    printf("\nEquation of best fit line is:\n");
    printf("y = %.4lf + %.4lf x\n", a, b);

    printf("\nLab No.: 4(a) / Name:   / Roll No.:   / Section: C \n");


    return 0; 
}
