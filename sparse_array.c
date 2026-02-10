#include <stdio.h>

int main() {
    int a[20], b[20], result[40];
    int deg1, deg2;
    int i, j;

    // Input first polynomial
    printf("Enter degree of first polynomial: ");
    scanf("%d", &deg1);

    printf("Enter coefficients of first polynomial:\n");
    for (i = 0; i <= deg1; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &a[i]);
    }

    // Input second polynomial
    printf("\nEnter degree of second polynomial: ");
    scanf("%d", &deg2);

    printf("Enter coefficients of second polynomial:\n");
    for (i = 0; i <= deg2; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &b[i]);
    }

    // Initialize result polynomial
    for (i = 0; i <= deg1 + deg2; i++) {
        result[i] = 0;
    }

    // Multiply polynomials
    for (i = 0; i <= deg1; i++) {
        for (j = 0; j <= deg2; j++) {
            result[i + j] += a[i] * b[j];
        }
    }

    // Display result
    printf("\nResultant Polynomial:\n");
    for (i = deg1 + deg2; i >= 0; i--) {
        if (result[i] != 0) {
            if (i == 0)
                printf("%d", result[i]);
            else
                printf("%dx^%d + ", result[i], i);
        }
    }

    return 0;
}
