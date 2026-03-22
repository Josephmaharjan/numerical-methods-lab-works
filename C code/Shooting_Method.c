// WAP for solving boundary value problem using shooting method.

#include <stdio.h>
#include <math.h>

#define f1(x, y, z) (z)
#define f2(x, y, z) 6 * (x)

int main()
{
    float xa, xb, ya, yb, x0, y0, z0, x, y, z;
    float xp, h, sol, ny, nz, error, E, g[3], v[3], gs;
    int i;
    printf("Enter Boundry Conditions:\n");
    scanf("%f%f%f%f", &xa, &ya, &xb, &yb);
    printf("Enter x at which value is required: ");
    scanf("%f", &xp);
    printf("Enter the step size: ");
    scanf("%f", &h);
    printf("Enter accuracy limit: ");
    scanf("%f", &E);

    x = xa;
    y = ya;
    g[1] = z = (yb - ya) / (xb - xa);
    printf("g=%.3f\n", g[1]);
    while (x < xb)
    { // using euler method
        ny = y + f1(x, y, z) * h;
        nz = z + f2(x, y, z) * h;
        y = ny;
        z = nz;
        x = x + h;

        if (x == xp)
            sol = y;
    }
    v[1] = y;
    if (y < yb)
        g[2] = z = 2 * g[1];
    else
        g[2] = z = g[1] / 2;
    printf("g=%.3f\n", g[2]);
    while (x < xb)
    { // using euler method
        ny = y + f1(x, y, z) * h;
        nz = z + f2(x, y, z) * h;
        y = ny;
        z = nz;
        x = x + h;

        if (x == xp)
            sol = y;
    }
    while (1)
    {
        x = xa;
        y = ya;
        gs = z = g[2] - (v[2] - yb) / (v[2] - v[1]) * (g[2] - g[1]);
        while (x < xb)
        { // using euler method
            ny = y + f1(x, y, z) * h;
            nz = z + f2(x, y, z) * h;
            y = ny;
            z = nz;
            x = x + h;

            if (x == xp)
                sol = y;
        }
        error = fabs(y - yb) / y;
        v[1] = v[2];
        g[1] = g[2];
        v[2] = y;
        g[2] = gs;
        if (error < E)
        {
            printf("y(%.3f)=%.3f\n", xp, sol);
            break;
        }
    }

    printf("\nLab No.: 16 / Name:   / Roll No.:   / Section:C\n");
    return 0;
}

/*Input :
Enter Boundry Conditions:
1 2 2 9
Enter x at which value is required: 1.5
Enter the step size: 0.5
Enter accuracy limit: 0.001
*/