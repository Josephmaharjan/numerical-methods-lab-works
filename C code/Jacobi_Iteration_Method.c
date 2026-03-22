#include <stdio.h>
#include <math.h>

#define MAX 10
#define EPSILON 0.0001

int main()
{
    int n, i, j, iter, max_iter;
    float a[MAX][MAX], b[MAX], x[MAX], old_x[MAX], sum, error, max_error;

    printf("Enter number of variables: ");
    scanf("%d", &n);

    printf("Enter coefficients and constants (A | B):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%f", &a[i][j]);
        }
        scanf("%f", &b[i]);
    }

    printf("Enter maximum iterations: ");
    scanf("%d", &max_iter);

    // Initial guess: all zeros
    for (i = 0; i < n; i++)
        x[i] = 0;

    // Table Header
    printf("\nIteration Table:\n");
    printf("-----------------------------------------------------------\n");
    printf("Iter\t");
    for (i = 0; i < n; i++)
        printf("x[%d]\t\t", i + 1);
    printf("\n-----------------------------------------------------------\n");

    for (iter = 1; iter <= max_iter; iter++)
    {
        max_error = 0;

        // Step 1: Store current x into old_x (previous iteration values)
        for (i = 0; i < n; i++)
            old_x[i] = x[i];

        // Step 2: Calculate new x values using old_x
        for (i = 0; i < n; i++)
        {
            sum = b[i];
            for (j = 0; j < n; j++)
            {
                if (i != j)
                    sum -= a[i][j] * old_x[j];
            }
            x[i] = sum / a[i][i];

            // Calculate error for convergence check
            error = fabs(x[i] - old_x[i]);
            if (error > max_error)
                max_error = error;
        }

        // Step 3: Print row of the table
        printf("%d\t", iter);
        for (i = 0; i < n; i++)
            printf("%.4f\t\t", x[i]);
        printf("\n");

        // Step 4: Check if we are close enough to the answer
        if (max_error < EPSILON)
            break;
    }

    // Final Solutions Output
    if (iter <= max_iter)
    {
        printf("\nStatus: Converged in %d iterations.\n", iter);
        printf("FINAL SOLUTIONS:\n");
        for (i = 0; i < n; i++)
        {
            printf("x%d = %.4f\n", i + 1, x[i]);
        }
    }
    else
    {
        printf("\nStatus: Did not converge within %d iterations.\n", max_iter);
    }
    printf("\nLab No.: 14(a) / Name:   / Roll No.:   / Section:C\n");
    return 0;
}
