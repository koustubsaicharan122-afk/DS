#include <stdio.h>

int main() {
    int sp1[20][3], sp2[20][3], sum[40][3];
    int i = 1, j = 1, k = 1;

    /* Input first sparse matrix */
    printf("Enter Sparse Matrix 1 (rows cols non-zero):\n");
    scanf("%d %d %d", &sp1[0][0], &sp1[0][1], &sp1[0][2]);

    printf("Enter triplets (row col value):\n");
    for (i = 1; i <= sp1[0][2]; i++) {
        scanf("%d %d %d", &sp1[i][0], &sp1[i][1], &sp1[i][2]);
    }

    /* Input second sparse matrix */
    printf("Enter Sparse Matrix 2 (rows cols non-zero):\n");
    scanf("%d %d %d", &sp2[0][0], &sp2[0][1], &sp2[0][2]);

    printf("Enter triplets (row col value):\n");
    for (i = 1; i <= sp2[0][2]; i++) {
        scanf("%d %d %d", &sp2[i][0], &sp2[i][1], &sp2[i][2]);
    }

    /* Check compatibility */
    if (sp1[0][0] != sp2[0][0] || sp1[0][1] != sp2[0][1]) {
        printf("Matrix addition not possible.\n");
        return 0;
    }

    /* Initialize result matrix */
    sum[0][0] = sp1[0][0];
    sum[0][1] = sp1[0][1];

    i = j = k = 1;

    /* Add sparse matrices */
    while (i <= sp1[0][2] && j <= sp2[0][2]) {
        if (sp1[i][0] == sp2[j][0] && sp1[i][1] == sp2[j][1]) {
            int val = sp1[i][2] + sp2[j][2];
            if (val != 0) {
                sum[k][0] = sp1[i][0];
                sum[k][1] = sp1[i][1];
                sum[k][2] = val;
                k++;
            }
            i++;
            j++;
        }
        else if (sp1[i][0] < sp2[j][0] ||
                (sp1[i][0] == sp2[j][0] && sp1[i][1] < sp2[j][1])) {
            sum[k][0] = sp1[i][0];
            sum[k][1] = sp1[i][1];
            sum[k][2] = sp1[i][2];
            i++;
            k++;
        }
        else {
            sum[k][0] = sp2[j][0];
            sum[k][1] = sp2[j][1];
            sum[k][2] = sp2[j][2];
            j++;
            k++;
        }
    }

    /* Copy remaining elements */
    while (i <= sp1[0][2]) {
        sum[k][0] = sp1[i][0];
        sum[k][1] = sp1[i][1];
        sum[k][2] = sp1[i][2];
        i++;
        k++;
    }

    while (j <= sp2[0][2]) {
        sum[k][0] = sp2[j][0];
        sum[k][1] = sp2[j][1];
        sum[k][2] = sp2[j][2];
        j++;
        k++;
    }

    sum[0][2] = k - 1;

    /* Display result */
    printf("\nResultant Sparse Matrix after Addition:\n");
    for (i = 0; i <= sum[0][2]; i++) {
        printf("%d %d %d\n", sum[i][0], sum[i][1], sum[i][2]);
    }

    return 0;
}
