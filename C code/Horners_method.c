
#include <stdio.h>

int main()
{
    int n, i;
    double x, result;

    printf("Enter degree of polynomial: ");
    scanf("%d", &n);

    double coeff[n + 1];

    printf("Enter coefficients (from highest degree to constant term):\n");
    for (i = 0; i <= n; i++)
    {
        scanf("%lf", &coeff[i]);
    }

    printf("Enter the value of x: ");
    scanf("%lf", &x);

    result = coeff[0];

    for (i = 1; i <= n; i++)
    {
        result = result * x + coeff[i];
    }

    printf("\nValue of polynomial at x = %.3lf is %.3lf\n", x, result);
    printf("\nLab No.: 2 / Name:   / Roll No.:   / Section: C \n");

    return 0;
}
