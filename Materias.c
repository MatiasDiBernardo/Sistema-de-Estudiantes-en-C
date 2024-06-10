#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll_estudiantes.h"
#include "ll_estudiantes.c"
#include "CLI.h"

typedef struct Materia{
    char nombreMateria[20];
    char estadoMateria[20];
    int notaMateria;
    struct Materia *sig;
}Materia;

void crearMateria(Materia **primera,char nombreMateria[20]){
    Materia *nuevaMateria = malloc(sizeof(Materia));
    strcpy(nuevaMateria->nombreMateria, nombreMateria);
    strcpy(nuevaMateria->estadoMateria, "Cursando");
    nuevaMateria->notaMateria = 0;

    if((*primera) == NULL){
        *primera = nuevaMateria;
    }
    else{
        Materia *cursor = (*primera);

        while(cursor->sig != NULL) {
            cursor = cursor->sig;
        }
        cursor->sig = nuevaMateria;
    }
}

void asignarMateria(struct NodeEstudiante*estudiante, char nombreMateria[20]){
    Materia *materia = malloc(sizeof(Materia));
    strcpy(materia->nombreMateria, nombreMateria);
    strcpy(materia->estadoMateria, "Cursando");
    materia->notaMateria = 0;
    materia->sig = NULL;
   if (estudiante->listaMaterias == NULL) {
        estudiante->listaMaterias = materia;
        printf("\n%s es la primera materia de %s \n", materia->nombreMateria, estudiante->nombre);
    }else{
        Materia *nodo = estudiante->listaMaterias;
        nodo->sig = materia;
        }
}

