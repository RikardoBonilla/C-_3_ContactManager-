// src/contact.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"

void add_contact() 
{
    char name[50], phone[50], email[50];
    FILE *file;

    printf("Add the contact name: ");
    if (scanf("%49s", name) != 1) {
        printf(COLOR_RED "Error: Invalid input. Please, set a name.\n" COLOR_RESET);
        while (getchar() != '\n');
        return;
    }
    printf("Add the contact phone: ");
    if (scanf("%49s", phone) != 1) {
        printf(COLOR_RED "Error: Invalid input. Please, set a phone.\n" COLOR_RESET);
        while (getchar() != '\n');
        return;
    }
    printf("Add the contact email: ");
    if (scanf("%49s", email) != 1) {
        printf(COLOR_RED "Error: Invalid input. Please, set a email.\n" COLOR_RESET);
        while (getchar() != '\n');
        return;
    }
    
    // Abrir el archivo en modo de agregar (append)
    file = fopen("data/contacts.txt", "a");
    if (file == NULL) {
        printf(COLOR_RED "Error: Could not open file to save contact.\n" COLOR_RESET);
        return;
    }
    // Escribir el contacto en el archivo en formato CSV
    fprintf(file, "%s,%s,%s\n", name, phone, email);

    // Cerrar el archivo
    fclose(file);

    printf(COLOR_GREEN "Contact saved successfully!\n" COLOR_RESET);
}

void list_contacts() {
    FILE *file;
    char line[256];
    int count = 0;

    // Abrir el archivo en modo de lectura
    file = fopen("data/contacts.txt", "r");
    if (file == NULL) {
        printf(COLOR_RED "No contacts found or error opening the file.\n" COLOR_RESET);
        return;
    }

    printf(COLOR_CYAN "List of Contacts:\n" COLOR_RESET);
    printf("--------------------------------------------------\n");

    // Leer cada línea del archivo y mostrarla
    while (fgets(line, sizeof(line), file)) {
        char name[50], phone[50], email[50];

        // Eliminar el salto de línea al final
        line[strcspn(line, "\n")] = 0;

        // Dividir la línea en campos usando strtok
        char *token = strtok(line, ",");
        if (token != NULL) {
            strcpy(name, token);
            token = strtok(NULL, ",");
        }
        if (token != NULL) {
            strcpy(phone, token);
            token = strtok(NULL, ",");
        }
        if (token != NULL) {
            strcpy(email, token);
        }

        // Mostrar el contacto
        printf(COLOR_YELLOW "Contact %d:\n" COLOR_RESET, ++count);
        printf("    Name: %s\n", name);
        printf("    Phone: %s\n", phone);
        printf("    Email: %s\n", email);
        printf("--------------------------------------------------\n");
    }

    if (count == 0) {
        printf(COLOR_RED "No contacts to display.\n" COLOR_RESET);
    }

    // Cerrar el archivo
    fclose(file);
}


void find_contact() {
    FILE *file;
    char line[256];
    char search_name[50];
    int found = 0;

    printf("Enter the name to search: ");
    if (scanf("%49s", search_name) != 1) {
        printf(COLOR_RED "Error: Invalid input.\n" COLOR_RESET);
        while (getchar() != '\n');
        return;
    }

    // Limpiar el buffer de entrada
    while (getchar() != '\n');

    // Abrir el archivo en modo de lectura
    file = fopen("data/contacts.txt", "r");
    if (file == NULL) {
        printf(COLOR_RED "No contacts found or error opening the file.\n" COLOR_RESET);
        return;
    }

    printf(COLOR_CYAN "Search Results:\n" COLOR_RESET);
    printf("--------------------------------------------------\n");

    // Leer cada línea del archivo y buscar coincidencias
    while (fgets(line, sizeof(line), file)) {
        char name[50], phone[50], email[50];

        // Eliminar el salto de línea al final
        line[strcspn(line, "\n")] = 0;

        // Dividir la línea en campos usando strtok
        char *token = strtok(line, ",");
        if (token != NULL) {
            strcpy(name, token);
            token = strtok(NULL, ",");
        }
        if (token != NULL) {
            strcpy(phone, token);
            token = strtok(NULL, ",");
        }
        if (token != NULL) {
            strcpy(email, token);
        }

        // Convertir ambos nombres a minúsculas para comparación insensible a mayúsculas
        char name_lower[50], search_name_lower[50];
        strcpy(name_lower, name);
        strcpy(search_name_lower, search_name);
        for (int i = 0; name_lower[i]; i++) name_lower[i] = tolower(name_lower[i]);
        for (int i = 0; search_name_lower[i]; i++) search_name_lower[i] = tolower(search_name_lower[i]);

        // Comprobar si el nombre coincide o contiene el término de búsqueda
        if (strstr(name_lower, search_name_lower) != NULL) {
            found = 1;
            // Mostrar el contacto
            printf(COLOR_YELLOW "Name: %s\n" COLOR_RESET, name);
            printf("Phone: %s\n", phone);
            printf("Email: %s\n", email);
            printf("--------------------------------------------------\n");
        }
    }

    if (!found) {
        printf(COLOR_RED "No contacts found matching '%s'.\n" COLOR_RESET, search_name);
    }

    // Cerrar el archivo
    fclose(file);
}


void delete_contact() {
    FILE *file, *temp;
    char line[256];
    char delete_name[50];
    int found = 0;

    printf("Enter the name of the contact to delete: ");
    if (scanf("%49s", delete_name) != 1) {
        printf(COLOR_RED "Error: Invalid input.\n" COLOR_RESET);
        while (getchar() != '\n');
        return;
    }

    // Limpiar el buffer de entrada
    while (getchar() != '\n');

    // Abrir el archivo original en modo lectura y el temporal en modo escritura
    file = fopen("data/contacts.txt", "r");
    temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf(COLOR_RED "Error opening files.\n" COLOR_RESET);
        if (file) fclose(file);
        if (temp) fclose(temp);
        return;
    }

    // Leer cada línea del archivo original
    while (fgets(line, sizeof(line), file)) {
        char name[50], phone[50], email[50];
        char line_copy[256];

        strcpy(line_copy, line); // Hacemos una copia de la línea original

        // Eliminar el salto de línea al final
        line[strcspn(line, "\n")] = 0;

        // Dividir la línea en campos usando strtok
        char *token = strtok(line, ",");
        if (token != NULL) {
            strcpy(name, token);
            token = strtok(NULL, ",");
        }
        if (token != NULL) {
            strcpy(phone, token);
            token = strtok(NULL, ",");
        }
        if (token != NULL) {
            strcpy(email, token);
        }

        // Convertir nombres a minúsculas para comparación insensible a mayúsculas
        char name_lower[50], delete_name_lower[50];
        strcpy(name_lower, name);
        strcpy(delete_name_lower, delete_name);
        for (int i = 0; name_lower[i]; i++) name_lower[i] = tolower(name_lower[i]);
        for (int i = 0; delete_name_lower[i]; i++) delete_name_lower[i] = tolower(delete_name_lower[i]);

        // Comprobar si el nombre coincide exactamente
        if (strcmp(name_lower, delete_name_lower) != 0) {
            // Escribimos la línea en el archivo temporal si no es el contacto a eliminar
            fputs(line_copy, temp);
        } else {
            found = 1;
            printf(COLOR_GREEN "Contact '%s' deleted successfully.\n" COLOR_RESET, name);
        }
    }

    // Cerrar los archivos
    fclose(file);
    fclose(temp);

    if (!found) {
        printf(COLOR_RED "Contact '%s' not found.\n" COLOR_RESET, delete_name);
        // Eliminar el archivo temporal ya que no hubo cambios
        remove("temp.txt");
    } else {
        // Reemplazar el archivo original con el temporal
        remove("data/contacts.txt");
        rename("temp.txt", "data/contacts.txt");
    }
}

