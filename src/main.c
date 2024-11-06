// src/main.c
#include <stdio.h>
#include "contact.h"

int main() {
    int option;

    do {
        // Mostrar menú
        printf(COLOR_CYAN   "====================================\n" COLOR_RESET);
        printf(COLOR_YELLOW "        Contact Manager             \n" COLOR_RESET);
        printf(COLOR_CYAN   "====================================\n" COLOR_RESET);
        printf("1. Add Contact\n");
        printf("2. List Contacts\n");
        printf("3. Find Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        // Limpiar buffer de entrada
        while (getchar() != '\n');

        switch (option) {
            case ADD_CONTACT:
                add_contact();
                break;
            case LIST_CONTACT:
                list_contacts();
                break;
            case FIND_CONTACT:
                find_contact();
                break;
            case DELETE_CONTACT:
                delete_contact();
                break;
            case EXIT:
                printf("Exiting...\n");
                break;
            default:
                printf(COLOR_RED "Invalid option. Please try again.\n" COLOR_RESET);
                break;
        }
    } while (option != EXIT);

    return 0;
}
