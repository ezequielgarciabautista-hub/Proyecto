#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[50];
    char telefono[15];
    char email[50];
} Contacto;

void agregarContacto() {
    FILE *archivo = fopen("contactos.txt", "a");
    Contacto c;

    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

    printf("Nombre: ");
    scanf(" %[^\n]", c.nombre);

    printf("Telefono: ");
    scanf(" %[^\n]", c.telefono);

    printf("Email: ");
    scanf(" %[^\n]", c.email);

    fprintf(archivo, "%s,%s,%s\n", c.nombre, c.telefono, c.email);
    fclose(archivo);

    printf("✅ Contacto guardado\n");
}

void mostrarContactos() {
    FILE *archivo = fopen("contactos.txt", "r");
    Contacto c;

    if (archivo == NULL) {
        printf("No hay contactos guardados\n");
        return;
    }

    printf("\n📒 CONTACTOS\n");

    while (fscanf(archivo, "%49[^,],%14[^,],%49[^\n]\n",
                  c.nombre, c.telefono, c.email) != EOF) {
        printf("Nombre: %s | Tel: %s | Email: %s\n",
               c.nombre, c.telefono, c.email);
    }

    fclose(archivo);
}

int main() {
    int opcion;

    do {
        printf("\n📱 AGENDA DE CONTACTOS\n");
        printf("1. Agregar contacto\n");
        printf("2. Mostrar contactos\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: agregarContacto(); break;
            case 2: mostrarContactos(); break;
            case 0: printf("Saliendo...\n"); break;
            default: printf("Opcion invalida\n");
        }
    } while (opcion != 0);

    return 0;
}