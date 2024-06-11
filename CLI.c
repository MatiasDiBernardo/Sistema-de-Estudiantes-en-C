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

// En esta función se maneja toda la aplicación
int menuCLI(struct NodeEstudiante* headEst){
    int state = 1;
    printf("Menu Principal \n");
    printf("\n");
    printf("1) Agregar estudiante \n");
    printf("2) Modificar estudiante \n");
    printf("3) Eliminar estudiante \n");
    printf("4) Listar estudiantes \n");
    printf("5) Buscar estudiante por nombre \n");
    printf("6) Buscar estudiante por edad \n");
    printf("7) Listar Materias\n");
    printf("8) Anotarse en materia\n");
    printf("9) Rendir materia\n");
    printf("\n");
    printf("0) Salir \n");
    
    int option = getNumber();
    
    // Agregar estudiante
    if (option == 1){
        system("cls");
        printf("Ingrese el nombre del alumno: \n");
        char *nombre = getString();
        printf("Ingrese la edad del alumno: \n");
        int edad = getNumber();
        printf("Ingrese el legajo del alumno: \n");
        int legajo = getNumber();
        struct NodeMateria* materiasBase = creaListaBaseDeMaterias();
        addAtEnd(&headEst, nombre, edad, legajo, materiasBase);
    }
    
    // Modificar estudiante
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
    
    // Borrar estudiante
    if (option == 3){
        system("cls");
        printf("Ingrese el nombre del alumno a borrar: \n");
        char *nombre = getString();
        removeNodeByName(&headEst, nombre);
    }
    
    // Listar estudiantes
    if (option == 4){
        system("cls");
        displayList(headEst);
        printf("\n");
        volverAlMenu();
        //system("pause");
    }

    // Busca estudiante por nombre
    if(option == 5){
        system("cls");
        printf("Ingrese el nombre del alumno a buscar: \n");
        char *nombre = getString();
        buscarPorNombre(&headEst, nombre);
        volverAlMenu();
    }

    // Busca estudiante por edad
    if(option == 6){
        system("cls");
        printf("Ingrese la edad mínima: \n");
        int edadMin = getNumber();
        printf("Ingrese la edad maxima: \n");
        int edadMax = getNumber();
        buscarPorEdad(&headEst, edadMin, edadMax);
        volverAlMenu();
    }

    // Listar materias
    if (option == 7){
        struct NodeMateria* materiasBase = creaListaBaseDeMaterias();
        displayMaterias(materiasBase);
    }

    // Anotarse en materia
    if (option == 8){
        system("cls");
      
        printf("Tendría que preguntar por el estudiante y después preguntar por las materias a agregar. \n");
        printf("Ingrese el nombre del alumno que quiere anotarse a la materia: \n");
         struct NodeEstudiante* alumno = NULL;
         char *nombreAlumno = getString();
           alumno=buscarPorNombreModificar(&headEst, nombreAlumno);
         printf("Ingrese el nombre de la materia\n");
          char *nombreMateria = getString();
          struct NodeMateria* materia = alumno->materias;
          agregarMateriaAlFinal(&materia,nombreMateria,1,0);

        // Guardas el string
        // Hacers la lógica para que aparezca como cursando (nota de materia == 0)

    }

    // Rendir materia 
    if (option == 9){
        system("cls");
        struct NodeEstudiante* alumno = NULL;
         printf("Ingrese el nombre del alumno que quiere rendir la materia: \n");
         char *nombreAlumno = getString();
           alumno=buscarPorNombreModificar(&headEst, nombreAlumno);
         printf("Ingrese el nombre de la materia\n");
          char *nombreMateria = getString();
          printf("Ingrese la nota del alumno\n");
          int nota = getNumber();
        char *nombreMateria = getString();
        struct NodeMateria* materia = alumno->materias;
        actualizaListaMaterias(&materia,nombreMateria,nota);
        
       // printf("Lo mismo que arriba. Tendría que preguntar por el estudiante y después preguntar por la materia a rendir. \n");
    }

    if (option == 0){
        state = 0;
    }
    
    return state;
}
