#include <stdio.h>
#include <math.h>

#define MAX 10

int main()
{
    float a[MAX][MAX], b[MAX], x[MAX];
    int n, i, j, iter = 0;
    float sum, error, max_error, accuracy;
    int max_limit = 100; // Safety cap

    printf("Enter number of variables: ");
    scanf("%d", &n);

    // Row-wise Input
    printf("Enter the Augmented Matrix row-wise (A|B):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%f", &a[i][j]);
        }
        scanf("%f", &b[i]); // The last number in the row is the constant B
    }

    printf("\nEnter required accuracy (e.g., 0.001): ");
    scanf("%f", &accuracy);

    // Initialize variables to zero
    for (i = 0; i < n; i++)
        x[i] = 0;

    // Table Header
    printf("\n%-5s", "Iter");
    for (i = 0; i < n; i++)
        printf("x[%d]%-10s", i + 1, "");
    printf("\n---------------------------------------------------------------\n");

    do
    {
        iter++;
        max_error = 0;

        for (i = 0; i < n; i++)
        {
            float old_val = x[i];
            sum = b[i];

            for (j = 0; j < n; j++)
            {
                if (i != j)
                {
                    sum -= a[i][j] * x[j]; // Uses updated values immediately
                }
            }

            // Pivot check to avoid division by zero
            if (fabs(a[i][i]) < 0.000001)
            {
                printf("\nError: Diagonal element a[%d][%d] is zero. Method fails.\n", i + 1, i + 1);
                return 1;
            }

            x[i] = sum / a[i][i];

            // Track the highest error in this iteration
            error = fabs(x[i] - old_val);
            if (error > max_error)
            {
                max_error = error;
            }
        }

        // Print iteration data for the table
        printf("%-5d", iter);
        for (i = 0; i < n; i++)
        {
            printf("%-14.4f", x[i]);
        }
        printf("\n");

        if (iter > max_limit)
        {
            printf("---------------------------------------------------------------\n");
            printf("Warning: Did not reach accuracy after %d iterations.\n", max_limit);
            break;
        }

    } while (max_error > accuracy);

    if (iter <= max_limit)
    {
        printf("---------------------------------------------------------------\n");
        printf("Convergence reached in %d iterations.\n", iter);
    }

    printf("\nFINAL SOLUTIONS:\n");
    for (i = 0; i < n; i++)
    {
        printf("x%d = %.4f\n", i + 1, x[i]);
    }

    printf("\nLab No.: 14(b) / Name:   / Roll No.:   / Section:C\n");
    return 0;
}
