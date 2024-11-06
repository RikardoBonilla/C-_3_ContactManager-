// contact.h
#ifndef CONTACT_H
#define CONTACT_H

// Definiciones para colores en la interfaz
#define COLOR_RESET   "\x1b[0m"
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"

// Definición de constantes para el menú
#define ADD_CONTACT     1
#define LIST_CONTACT    2
#define FIND_CONTACT    3
#define DELETE_CONTACT  4
#define EXIT            5

// Estructura para guardar el contacto
typedef struct {
    char name[50];
    char phone[50];
    char email[50];
} Contact;

// Declaración de funciones
void add_contact();
void list_contacts();
void find_contact();
void delete_contact();

#endif
