#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLI.h"
#include "ll_estudiantes.h"

// Funcion para crear CLI 
struct CLI_Interface* createCLI(struct NodeEstudiante* headEst, struct NodeMaterias* headMat) {
    struct CLI_Interface* newCLI = (struct CLI_Interface*)malloc(sizeof(struct CLI_Interface));
    newCLI->estudiantesHead = headEst;
    newCLI->materiasHead = headMat;
    return newCLI;
}

// Obtener un número del usuario
int getNumber(){
    int number;
    scanf("%d", &number);
    return number;
}

// Obtener un string del usuario
char* getString() {
    // Limpia el buffer (sin esta línea tenía un bug con los caracteres en blanco)
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Acá limpia el buffer  
    }
    size_t bufferSize = 256;
    // Se designa memoria para el input en formato string
    char* str = (char*)malloc(bufferSize * sizeof(char));
    if (str == NULL) {
        printf("Error en la asignación de memoria del programa.\n");
        return NULL;
    }
    
    printf("Enter a string: ");
    
    // Lee el input y lo guadra en el espacio de memoria específicado 
    if (fgets(str, bufferSize, stdin) == NULL) {
        // Detección de errores 
        free(str);
        return NULL;
    }
    
    // Remueve saltos de línea en el input 
    size_t length = strlen(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
    
    return str;
}
void buscarPorNombre(struct NodeEstudiante** head, char* nombre){
    struct NodeEstudiante* temp = *head;
    
    // Itera sobre la lista y avanza hasta encontrar el nombre
    while (temp != NULL && strcmp(temp->nombre, nombre) != 0) {
        temp = temp->next;
    }
    
    if (temp==NULL){
        printf("No se encontro el alumno solicitado.\n");
    }else{
        printf("El almuno solicitado es: ");
        printf("Nombre: %s | Edad: %d |  Legajo: %d \n", temp->nombre, temp->edad, temp->legajo);
    }

}

struct NodeEstudiante* buscarPorNombreModificar(struct NodeEstudiante** head, char* nombre){
    struct NodeEstudiante* temp = *head;
    
    // Itera sobre la lista y avanza hasta encontrar el nombre
    while (temp != NULL && strcmp(temp->nombre, nombre) != 0) {
        temp = temp->next;
    }
    
    if (temp==NULL){
        printf("No se encontro el alumno solicitado.\n");
        return temp;
    }else{
        printf("El almuno a modificar es: ");
        printf("Nombre: %s | Edad: %d |  Legajo: %d \n", temp->nombre, temp->edad, temp->legajo);
        return temp;
    }

}

void buscarPorEdad(struct NodeEstudiante** head, int edadMin, int edadMax){
    struct NodeEstudiante* temp = *head;
    struct NodeEstudiante* edadBien = NULL;

    // Itera sobre la lista y agrega a la otra lista si cumple la condición
    while (temp != NULL) {
        if ((temp->edad >=  edadMin) && (temp->edad <= edadMax)){
            // Si no hay ningún elemento en la lista de edades lo inicializo
            if (edadBien == NULL){
                edadBien = temp;
            }else{
                edadBien->next = temp;
                edadBien = edadBien->next;
            }
        }
        temp = temp->next;
    }
    
    if (edadBien == NULL){
        printf("Ningún estudiante cumple con el rango de edad específicado.\n");
    }else{
        displayList(edadBien);
    }
    
}

// En manu agregas el puntero al link list de materias y pones las opciones para modificar materias.
// int menuCLI(struct NodeEstudiante* headEst, struct NodeMaterias* headMat){
int menuCLI(struct NodeEstudiante* headEst){
    system("cls");
    int state = 1;
    printf("Menu Principal \n");
    printf("\n");
    printf("1) Agregar estudiante \n");
    printf("2) Modificar estudiante \n");
    printf("3) Eliminar estudiante \n");
    printf("4) Listar estudiantes \n");
    printf("5) Buscar estudiante por nombre \n");
    printf("6) Buscar estudiante por edad \n");
    printf("\n");
    printf("7) Salir \n");
    
    int option = getNumber();
    
    if (option == 1){
        system("cls");
        printf("Ingrese el nombre del alumno: \n");
        char *nombre = getString();
        printf("Ingrese la edad del alumno: \n");
        int edad = getNumber();
        printf("Ingrese el legajo del alumno: \n");
        int legajo = getNumber();
        addAtEnd(&headEst, nombre, edad, legajo);
    }
    
    if (option == 2){
        struct NodeEstudiante* alumnoAModificar = NULL;
        printf("Ingrese el nombre del alumno a modificar: \n");
        char *nombre = getString();
        alumnoAModificar = buscarPorNombreModificar(&headEst, nombre);
        if (alumnoAModificar != NULL){
            printf("Ingrese el campo a modificar: \n");
            printf("1) Nombre \n");
            printf("2) Edad \n");
            printf("3) Legajo \n");
            int optionMod = getNumber();

            if (optionMod == 1){
                printf("Ingrese el nuevo nombre: \n");
                char *nuevoNombre = getString();
                strcpy(alumnoAModificar->nombre, nuevoNombre);
            }

            if (optionMod == 2){
                printf("Ingrese la edad actualizada: \n");
                int edadNueva = getNumber();
                alumnoAModificar->edad = edadNueva;
            }

            if (optionMod == 3){
                printf("Ingrese el legajo actualizado: \n");
                int legajoNuevo = getNumber();
                alumnoAModificar->legajo = legajoNuevo;
            }
        }
    }
    
    if (option == 3){
        system("cls");
        printf("Ingrese el nombre del alumno a borrar: \n");
        char *nombre = getString();
        removeNodeByName(&headEst, nombre);
    }
    
    if (option == 4){
        system("cls");
        displayList(headEst);
        printf("\n");
        printf("si desea volver al menu eliga 1 si desea salir eliga 2\n");
        int opcion = getNumber();
        if (opcion==2){
            state=0;
        }
        //system("pause");
    }
    
    if (option == 5){
        printf("Ingrese el nombre del alumno a buscar: \n");
        char *nombre = getString();
        buscarPorNombre(&headEst, nombre);
    }

    if (option == 6){
        printf("Ingrese la edad mínima: \n");
        int edadMin = getNumber();
        printf("Ingrese la edad maxima: \n");
        int edadMax = getNumber();
        buscarPorEdad(&headEst, edadMin, edadMax);
    }

    if (option == 7){
        state = 0;
    }
    
    return state;
}
