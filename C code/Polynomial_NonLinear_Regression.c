#include <stdio.h>

int main()
{
    int n, i, j, k;
    double x, y;

    double sumx = 0, sumx2 = 0, sumx3 = 0, sumx4 = 0;
    double sumy = 0, sumxy = 0, sumx2y = 0;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter data points (x y):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf %lf", &x, &y);

        sumx += x;
        sumx2 += x * x;
        sumx3 += x * x * x;
        sumx4 += x * x * x * x;

        sumy += y;
        sumxy += x * y;
        sumx2y += x * x * y;
    }

    /* Augmented matrix [A|B] */
    double A[3][4] = {
        {n,     sumx,   sumx2,  sumy},
        {sumx,  sumx2,  sumx3,  sumxy},
        {sumx2, sumx3,  sumx4,  sumx2y}
    };

    /* Gaussian Elimination */
    for (i = 0; i < 3; i++)
    {
        for (j = i + 1; j < 3; j++)
        {
            double ratio = A[j][i] / A[i][i];
            for (k = 0; k < 4; k++)
            {
                A[j][k] -= ratio * A[i][k];
            }
        }
    }

    /* Back Substitution */
    double c = A[2][3] / A[2][2];
    double b = (A[1][3] - A[1][2] * c) / A[1][1];
    double a = (A[0][3] - A[0][2] * c - A[0][1] * b) / A[0][0];

    printf("\nBest fit polynomial equation:\n");
    printf("y = %.4lf + %.4lf x + %.4lf x^2\n", a, b, c);

    printf("\nLab No.: 4(c) / Name:   / Roll No.:   / Section: C \n");

    return 0;
}
