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

int getNumber(){
    int number;
    scanf("%d", &number);
    return number;
}

char* getString() {
    // Clear buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Discard characters
    }
    // Define a buffer size
    size_t bufferSize = 256;
    // Allocate memory for the input string
    char* str = (char*)malloc(bufferSize * sizeof(char));
    if (str == NULL) {
        // Handle memory allocation error
        printf("Memory allocation error\n");
        return NULL;
    }
    
    // Prompt the user for input
    printf("Enter a string: ");
    
    // Read the input from the user and store it in the allocated memory
    if (fgets(str, bufferSize, stdin) == NULL) {
        // Handle input error
        free(str);
        return NULL;
    }
    
    // Remove newline character if present
    size_t length = strlen(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
    
    return str;
}

// En manu agregas el puntero al link list de materias y pones las opciones para modificar materias.
// int menuCLI(struct NodeEstudiante* headEst, struct NodeMaterias* headMat){
int menuCLI(struct NodeEstudiante* headEst){
    int state = 1;
    printf("Menu Principal \n");
    printf("\n");
    printf("1) Agregar estudiante \n");
    printf("2) Modificar estudiante \n");
    printf("3) Eliminar estudiante \n");
    printf("4) Lisar estudiantes \n");
    printf("5) Buscar estudiante por nombre \n");
    printf("6) Buscar estutiante por edad \n");
    printf("\n");
    printf("7) Salir \n");
    
    int option = getNumber();
    
    if (option == 1){
        printf("Ingrese el nombre del alumno: \n");
        char *nombre = getString();
        printf("Ingrese la edad del alumno: \n");
        int edad = getNumber();
        printf("Ingrese el legajo del alumno: \n");
        int legajo = getNumber();
        addAtEnd(&headEst, nombre, edad, legajo);
    }
    
    if (option == 3){
        printf("Ingrese el nombre del alumno a borrar: \n");
        char *nombre = getString();
        removeNodeByName(&headEst, nombre);
    }
    
    if (option == 4){
        displayList(headEst);
    }

    if (option == 7){
        state = 0;
    }
    
    return state;
}
