#include <stdio.h>

int main() {
    int mat[10][10];
    int sp[20][3], tr[20][3];
    int rows, cols;
    int i, j, k = 1, t = 1;

    printf("Enter number of rows and columns:\n");
    scanf("%d %d", &rows, &cols);

    
    printf("Enter matrix elements:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\nNormal Matrix:\n\n");

    printf("        ");
    for (j = 0; j < cols; j++) {
        printf("Col %d  ", j + 1);
    }
    printf("\n");

    for (i = 0; i < rows; i++) {
        printf("Row %d   ", i + 1);
        for (j = 0; j < cols; j++) {
            printf("%3d    ", mat[i][j]);
        }
        printf("\n");
    }
    sp[0][0] = rows;
    sp[0][1] = cols;
    sp[0][2] = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                sp[k][0] = i + 1;
                sp[k][1] = j + 1;       
                sp[k][2] = mat[i][j];   
                k++;
                sp[0][2]++;
            }
        }
    }
    printf("\nSparse Matrix (Triplet Form: row column value):\n");
    for (i = 0; i <= sp[0][2]; i++) {
        printf("%d %d %d\n", sp[i][0], sp[i][1], sp[i][2]);
    }

    tr[0][0] = sp[0][1];
    tr[0][1] = sp[0][0];
    tr[0][2] = sp[0][2];
    for (i = 1; i <= sp[0][1]; i++) {
        for (j = 1; j <= sp[0][2]; j++) {
            if (sp[j][1] == i) {
                tr[t][0] = sp[j][1];
                tr[t][1] = sp[j][0];
                tr[t][2] = sp[j][2];
                t++;
            }
        }
    }
    printf("\nTranspose Sparse Matrix (Triplet Form):\n");
    for (i = 0; i <= tr[0][2]; i++) {
        printf("%d %d %d\n", tr[i][0], tr[i][1], tr[i][2]);
    }

    return 0;
}
