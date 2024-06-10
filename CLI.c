#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLI.h"
#include "ll_estudiantes.h"
#include "ll_materias.h"

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
void volverAlMenu(){
    printf("si desea volver al menu eliga cualquier numero\n");
    int opcion = getNumber();
    if (opcion == 2){
        printf("Algo para que no se queje el compilador, hay que rehacer esta lógica.");
        
    }
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
    printf("4) Listar estudiantes \n");
    printf("5) Asignar materia\n");
    printf("6) Buscar estudiante por nombre \n");
    printf("7) Buscar estudiante por edad \n");
    printf("\n");
    printf("8) Salir \n");
    
    int option = getNumber();
    
    if (option == 1){
        system("cls");
        printf("Ingrese el nombre del alumno: \n");
        char *nombre = getString();
        printf("Ingrese la edad del alumno: \n");
        int edad = getNumber();
        printf("Ingrese el legajo del alumno: \n");
        int legajo = getNumber();
        printf("Ingrese las materias a agregar y las notas: \n");
        printf("Falta implementar");
        char *materiasFacil[] = {"Física I", "Análisis Matemátcio I", "Historia"};
        int notasFacil[] = {6, 2, 9};
        addAtEnd(&headEst, nombre, edad, legajo, materiasFacil, notasFacil, 3);
    }
    
    if (option == 2){
        system("cls");
        struct NodeEstudiante* alumnoAModificar = NULL;
        printf("Ingrese el nombre del alumno a modificar: \n");
        char *nombre = getString();
        alumnoAModificar = buscarPorNombreModificar(&headEst, nombre);
        if (alumnoAModificar != NULL){
            system("cls");
            printf("Ingrese el campo a modificar: \n");
            printf("1) Nombre \n");
            printf("2) Edad \n");
            printf("3) Legajo \n");
            int optionMod = getNumber();

            if (optionMod == 1){
                system("cls");
                printf("Ingrese el nuevo nombre: \n");
                char *nuevoNombre = getString();
                strcpy(alumnoAModificar->nombre, nuevoNombre);
            }

            if (optionMod == 2){
                system("cls");
                printf("Ingrese la edad actualizada: \n");
                int edadNueva = getNumber();
                alumnoAModificar->edad = edadNueva;
            }

            if (optionMod == 3){
                system("cls");
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
        volverAlMenu();
        //system("pause");
    }

    if (option == 5){
        printf("Tendría que preguntar por el estudiante y después preguntar por las materias a agregar. \n");
    }

    // if(option== 5){
    //     char nombre[20];
    //     char nombreMateria[20];
    //     system("cls");
    //     struct NodeEstudiante* estudiante = NULL;
    //     printf("Inserte nombre del estudiante\n");
    //     scanf("%s", nombre);
    //     estudiante = buscarPorNombreModificar(&headEst,nombre);
    //     if(estudiante != NULL) {
    //                 printf("Inserte nombre de la materia\n",nombreMateria);
    //                 scanf("%s",nombreMateria);
    //                 asignarMateria(estudiante,nombreMateria);
    //      }
    //                // printf(estudiante->Materias);
    // }
    
    if(option == 6){
        system("cls");
        printf("Ingrese el nombre del alumno a buscar: \n");
        char *nombre = getString();
        buscarPorNombre(&headEst, nombre);
        volverAlMenu();
    }

    if(option == 7){
        system("cls");
        printf("Ingrese la edad mínima: \n");
        int edadMin = getNumber();
        printf("Ingrese la edad maxima: \n");
        int edadMax = getNumber();
        buscarPorEdad(&headEst, edadMin, edadMax);
        volverAlMenu();
    }

    if (option == 8){
        state = 0;
    }
    
    return state;
}
