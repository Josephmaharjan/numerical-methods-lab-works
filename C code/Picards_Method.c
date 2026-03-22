/*9. WAP to solve ordinary differential equations using 
    b. Picard's Method
*/ 

#include <stdio.h>
#include <math.h>

/* Picard's successive approximations */
float picard1(float x, float x0, float y0)
{
    return y0 + (pow(x, 3) - pow(x0, 3)) / 3.0;
}

float picard2(float x, float x0, float y0)
{
    return y0 + (pow(x, 3) - pow(x0, 3)) / 3.0 + (pow(x, 7) - pow(x0, 7)) / 63.0;
}

int main()
{
    float x0, y0, x;

    printf("Enter x0, y0 and target x: ");
    scanf("%f %f %f", &x0, &y0, &x);

    printf("\n--- Picard's Successive Approximations ---");
    printf("\nFirst Approximation  y1 = %.6f", picard1(x, x0, y0));
    printf("\nSecond Approximation y2 = %.6f", picard2(x, x0, y0));

    printf("\nLab No.: 9(b) / Name:   / Roll No.:   / Section:C\n");
    return 0;
}
/// Input : 0 0 0.2

///Just to know: In this program we didn't use functions name as y1(...),y2(...) because y1(...),y2(...) are already defined in math.h header file as macros for the first and second roots of a quadratic equation. Using the same names for our functions would cause a conflict and lead to compilation errors. Therefore, we chose to name our functions picard1 and picard2 to avoid any naming conflicts and ensure that our code compiles successfully.///