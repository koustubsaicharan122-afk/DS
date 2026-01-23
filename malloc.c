#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int emp_id;
    char name[50];
    float salary;
};

int main() {
    struct Employee *emp;
    int n, i;

    // Input number of employees
    printf("Enter number of employees: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    emp = (struct Employee *)malloc(n * sizeof(struct Employee));

    // Check if memory allocation is successful
    if (emp == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    // Input employee details
    for (i = 0; i < n; i++) {
        printf("\nEnter details of Employee %d\n", i + 1);

        printf("Employee ID: ");
        scanf("%d", &emp[i].emp_id);

        printf("Name: ");
        scanf(" %[^\n]", emp[i].name);

        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }

    // Display employee details
    printf("\n--- Employee Information ---\n");
    for (i = 0; i < n; i++) {
        printf("\nEmployee %d\n", i + 1);
        printf("Employee ID: %d\n", emp[i].emp_id);
        printf("Name: %s\n", emp[i].name);
        printf("Salary: %.2f\n", emp[i].salary);
    }

    // Free allocated memory
    free(emp);

    return 0;
}
