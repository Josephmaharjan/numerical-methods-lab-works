#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, k, num_vars, iter = 0;
    float a[50][50], b[50], x[50];
    float tl, tr, tb, tu, error, max_err, old_x, sum;

    printf("Enter number of grid divisions (n): ");
    scanf("%d", &n);
    num_vars = (n - 1) * (n - 1);

    printf("Enter temperatures (Left, Right, Bottom, Up): ");
    scanf("%f %f %f %f", &tl, &tr, &tb, &tu);

    printf("Enter accuracy limit: ");
    scanf("%f", &error);

    // Initialize
    for (i = 0; i < num_vars; i++) {
        x[i] = 0;
        b[i] = 0;
        for (j = 0; j < num_vars; j++) a[i][j] = 0;
    }

    // Matrix Construction
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            k = (i - 1) * (n - 1) + (j - 1);
            a[k][k] = -4.0;

            // Boundary/Neighbor logic
            if (j - 1 == 0) b[k] -= tl; else a[k][k - 1] = 1;
            if (j + 1 == n) b[k] -= tr; else a[k][k + 1] = 1;
            if (i - 1 == 0) b[k] -= tu; else a[k][k - (n - 1)] = 1;
            if (i + 1 == n) b[k] -= tb; else a[k][k + (n - 1)] = 1;
        }
    }

    // Gauss-Seidel Solver
    do {
        max_err = 0;
        for (i = 0; i < num_vars; i++) {
            sum = b[i];
            for (j = 0; j < num_vars; j++) {
                if (i != j) sum -= a[i][j] * x[j];
            }
            old_x = x[i];
            x[i] = sum / a[i][i];
            if (fabs(x[i] - old_x) > max_err) max_err = fabs(x[i] - old_x);
        }
        iter++;
    } while (max_err > error && iter < 1000);

    // Final Output
    printf("\nConverged in %d iterations.\n", iter);
    printf("Final Interior Temperatures:\n");
    for (i = 0; i < num_vars; i++) {
        printf("u[%d] = %.4f\n", i + 1, x[i]);
    }

    printf("\nLab No.: 17(a) / Name:   / Roll No.:   / Section:C\n");
    return 0;
}


/*
Enter number of grid divisions (n): 3
Enter temperatures (Left, Right, Bottom, Up): 75 100 50 300
Enter accuracy limit: 0.0001

Converged in 12 iterations.
Final Interior Temperatures:
u[1] = 159.3750
u[2] = 165.6250
u[3] = 96.8750
u[4] = 103.1250
*/