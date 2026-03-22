/*5. WAP to implement numerical differentiation techniques using
b) Central Difference Formula (for 1st derivative and 2nd Derivative) */

#include<stdio.h>
float f(float x){
    return x * x ; // Example function: f(x) = x^2
}
int main(){
    float central_1st, central_2nd, h, x;
    printf("Enter the point at which derivatives are to be calculated: ");
    scanf("%f", &x);

    printf("Enter the value of h (small increment): ");
    scanf("%f", &h);

    central_1st = (f(x + h) - f(x - h)) / (2 * h);
    central_2nd = (f(x + h) - 2 * f(x) + f(x - h)) / (h * h);

    printf("Central Difference Approximation of f' at x = %.4f is: %.4f\n", x, central_1st);
    printf("Central Difference Approximation of f'' at x = %.4f is: %.4f\n", x, central_2nd);
    printf("\nLab No.: 5(b) / Name:   / Roll No.:   / Section: C \n");

    return 0;
}