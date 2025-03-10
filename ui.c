#include <stdio.h>

#include "service.h"

void ui_add_medicine() {
    char name[50];
    int concentration;
    int quantity;
    float price;

    printf("Enter medicine name: ");
    scanf("%49s", name);
    printf("Enter concentration: ");
    scanf("%d", &concentration);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    printf("Enter price: ");
    scanf("%f", &price);

    if (service_add_medicine(name, concentration, quantity, price)) {
        printf("Medicine added successfully!\n");
    } else {
        printf("Error: Medicine already exists!\n");
    }
}

void ui_delete_medicine() {
    char name[50];
    int concentration;

    printf("Enter medicine name to delete: ");
    scanf("%49s", name);
    printf("Enter concentration: ");
    scanf("%d", &concentration);

    if (service_delete_medicine(name, concentration)) {
        printf("Medicine deleted successfully!\n");
    } else {
        printf("Error: Medicine not found!\n");
    }
}

void ui_update_medicine() {
    char name[50];
    int concentration;
    int new_quantity;
    float new_price;

    printf("Enter medicine name to update: ");
    scanf("%49s", name);
    printf("Enter concentration: ");
    scanf("%d", &concentration);
    printf("Enter new quantity: ");
    scanf("%d", &new_quantity);
    printf("Enter new price: ");
    scanf("%f", &new_price);

    if (service_update_medicine(name, concentration, new_quantity, new_price)) {
        printf("Medicine updated successfully!\n");
    } else {
        printf("Error: Medicine not found!\n");
    }
}

void run_ui() {
    int choice;
    while (1) {
        printf("\nMedicine Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Delete Medicine\n");
        printf("3. Update Medicine\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                ui_add_medicine();
                break;
            case 2:
                ui_delete_medicine();
                break;
            case 3:
                ui_update_medicine();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

