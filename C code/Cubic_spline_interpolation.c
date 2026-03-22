#include <stdio.h>

int main() {
    int n, i, j;
    
    printf("Enter number of data points (n): ");
    scanf("%d", &n);

    float x[n], f[n], h[n], a[n], l[n], u[n], z[n], c[n], b[n], d[n];
    float val, result;

    printf("Enter data points (x  y):\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &f[i]);
    }

    printf("Enter the value of x to interpolate: ");
    scanf("%f", &val);

    for (i = 0; i < n - 1; i++) {
        h[i] = x[i+1] - x[i];
    }

    for (i = 1; i < n - 1; i++) {
        a[i] = (3.0/h[i])*(f[i+1]-f[i]) - (3.0/h[i-1])*(f[i]-f[i-1]);
    }

    // Step 3: Solve Tridiagonal System (Thomas Algorithm/Gauss Method)
    l[0] = 1; u[0] = 0; z[0] = 0;
    for (i = 1; i < n - 1; i++) {
        l[i] = 2*(x[i+1]-x[i-1]) - h[i-1]*u[i-1];
        u[i] = h[i]/l[i];
        z[i] = (a[i] - h[i-1]*z[i-1])/l[i];
    }
    l[n-1] = 1; z[n-1] = 0; c[n-1] = 0;

    for (j = n - 2; j >= 0; j--) {
        c[j] = z[j] - u[j]*c[j+1];
        b[j] = (f[j+1]-f[j])/h[j] - h[j]*(c[j+1] + 2*c[j])/3;
        d[j] = (c[j+1] - c[j])/(3*h[j]);
    }

    // Step 4: Evaluate the spline at point of interest
    for (i = 0; i < n - 1; i++) {
        if (val >= x[i] && val <= x[i+1]) {
            float dx = val - x[i];
            result = f[i] + b[i]*dx + c[i]*dx*dx + d[i]*dx*dx*dx;
            break;
        }
    }

    // Output Results
    printf("\nInterpolated value at x = %.2f is: %.4f\n", val, result);
    
    printf("\nLab No.: 3(e) / Name:   / Roll No.:   / Section: C \n");
 

    return 0;
}