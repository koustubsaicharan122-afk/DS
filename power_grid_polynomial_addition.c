#include <stdio.h>

int main() {
    int p1_coef[10], p1_exp[10];
    int p2_coef[10], p2_exp[10];
    int sum_coef[20], sum_exp[20];
    int n1, n2;
    int i = 0, j = 0, k = 0;

    /* Input first polynomial */
    printf("Enter number of terms in Polynomial 1:\n");
    scanf("%d", &n1);

    printf("Enter coefficient and exponent (in descending order of exponent):\n");
    for (i = 0; i < n1; i++) {
        scanf("%d %d", &p1_coef[i], &p1_exp[i]);
    }

    /* Input second polynomial */
    printf("Enter number of terms in Polynomial 2:\n");
    scanf("%d", &n2);

    printf("Enter coefficient and exponent (in descending order of exponent):\n");
    for (i = 0; i < n2; i++) {
        scanf("%d %d", &p2_coef[i], &p2_exp[i]);
    }

    i = j = k = 0;

    /* Add polynomials */
    while (i < n1 && j < n2) {
        if (p1_exp[i] == p2_exp[j]) {
            sum_coef[k] = p1_coef[i] + p2_coef[j];
            sum_exp[k] = p1_exp[i];
            i++;
            j++;
            k++;
        }
        else if (p1_exp[i] > p2_exp[j]) {
            sum_coef[k] = p1_coef[i];
            sum_exp[k] = p1_exp[i];
            i++;
            k++;
        }
        else {
            sum_coef[k] = p2_coef[j];
            sum_exp[k] = p2_exp[j];
            j++;
            k++;
        }
    }

    /* Copy remaining terms */
    while (i < n1) {
        sum_coef[k] = p1_coef[i];
        sum_exp[k] = p1_exp[i];
        i++;
        k++;
    }

    while (j < n2) {
        sum_coef[k] = p2_coef[j];
        sum_exp[k] = p2_exp[j];
        j++;
        k++;
    }

    /* Display result */
    printf("\nResultant Polynomial (Combined Power Consumption):\n");
    for (i = 0; i < k; i++) {
        if (i != 0 && sum_coef[i] > 0)
            printf(" + ");
        printf("%dx^%d", sum_coef[i], sum_exp[i]);
    }

    printf("\n");

    return 0;
}
