#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float total_marks;
};

int main() {
    struct Student s[2];
    float average;
    int i;

    for (i = 0; i < 2; i++) {
        printf("\nEnter details of Student %d\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Age: ");
        scanf("%d", &s[i].age);

        printf("Total Marks: ");
        scanf("%f", &s[i].total_marks);
    }

    printf("\n--- Student Information ---\n");
    for (i = 0; i < 2; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Name: %s\n", s[i].name);
        printf("Age: %d\n", s[i].age);
        printf("Total Marks: %.2f\n", s[i].total_marks);
    }

    average = (s[0].total_marks + s[1].total_marks) / 2;

    printf("\nAverage of Total Marks: %.2f\n", average);

    return 0;
}
