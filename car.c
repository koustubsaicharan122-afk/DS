#include <stdio.h>

struct Car {
    int car_id;
    char model[50];
    float rate_per_day;
};

int main() {
    struct Car c[3];
    int days, i;
    float total_cost;

    for (i = 0; i < 3; i++) {
        printf("\nEnter details of Car %d\n", i + 1);

        printf("Car ID: ");
        scanf("%d", &c[i].car_id);

        printf("Model: ");
        scanf(" %[^\n]", c[i].model);

        printf("Rental Rate per Day: ");
        scanf("%f", &c[i].rate_per_day);
    }

    printf("\nEnter number of rental days: ");
    scanf("%d", &days);

    printf("\n--- Car Rental Details ---\n");
    for (i = 0; i < 3; i++) {
        total_cost = c[i].rate_per_day * days;

        printf("\nCar %d\n", i + 1);
        printf("Car ID: %d\n", c[i].car_id);
        printf("Model: %s\n", c[i].model);
        printf("Rental Rate per Day: %.2f\n", c[i].rate_per_day);
        printf("Total Rental Cost for %d days: %.2f\n", days, total_cost);
    }

    return 0;
}
