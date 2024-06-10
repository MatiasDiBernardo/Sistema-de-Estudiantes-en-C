#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll_estudiantes.h"
#include "CLI.h"
#include "ll_materias.h"

// Funcion para crear un nodo del struct materia 
struct NodeMateria* crearMateria(char* nombreMateria, int estado, int notaMat){
    struct NodeMateria* newMateria = (struct NodeMateria*)malloc(sizeof(struct NodeMateria));
    strcpy(newMateria->nombreMateria, nombreMateria);
    newMateria->estadoMateria = estado;
    newMateria->notaMateria = notaMat;
    return newMateria;
}

// Funcion para agregar un nodo al final de la linked list de materias
void agregarMateriaAlFinal(struct NodeMateria** head, char* nombreMateria, int idMat, int notaMat){
    struct NodeMateria* newNode = crearMateria(nombreMateria, idMat, notaMat);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct NodeMateria* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Inicializa las materias en 0 y según el alumno se completa su estado y nota (se podrían agregar mas materias)
struct NodeMateria* creaListaBaseDeMaterias(){
    struct NodeMateria* headMat = NULL;
    
    agregarMateriaAlFinal(&headMat, "Análisis Matemático I", 0, 0);
    agregarMateriaAlFinal(&headMat, "Física I", 0, 0);
    agregarMateriaAlFinal(&headMat, "Algoritmos y Programación I", 0, 0);
    agregarMateriaAlFinal(&headMat, "Historia", 0, 0);
    agregarMateriaAlFinal(&headMat, "Algebra I", 0, 0);
    return headMat;
}

// Funcion que actualiza una ll de materias según los datos del alumno
void actualizaListaMaterias(struct NodeMateria* head, char* nombreMateria, int notaMateria){
    // Recorro la lista hasta encontrar la materia asociada
    while (head != NULL && strcmp(head->nombreMateria, nombreMateria) != 0) {
        head->notaMateria = notaMateria;
        // Esta aprobado
        if (notaMateria >= 4){
            head->estadoMateria = 2;
        }

        // Esta reprobado
        if (notaMateria < 4 && notaMateria >= 1){
            head->estadoMateria = 3;
        }

        // Esta cursando
        if (notaMateria == 0){
            head->estadoMateria = 1;
        }

    }
}
// Se le pasa un string con las materias que cursó y la nota.
struct NodeMateria* creaMateriasSegunAlumno(char *nombreMaterias[], int notaMaterias[], int cantidadCursadas){
    struct NodeMateria* materiasDelAlumno = creaListaBaseDeMaterias();

    // Recorro los nombres
    for (int i = 0; i < cantidadCursadas; i++) {
        // Recorro la lista y ajusto según el estado del alumno
        actualizaListaMaterias(materiasDelAlumno, nombreMaterias[i], notaMaterias[i]);
    }
    return materiasDelAlumno;
}

// Funcion que muestra todas las materias
void displayMaterias(struct NodeMateria* head){
    struct NodeMateria* temp = head;
    if(temp==NULL){
        printf("No hay materias para mostrar\n");
    }else{
    while (temp != NULL) {
        // Acá abría que hacer una función que me pase el estado de la materia al string
        printf("Nombre materia: %s | Estado Materia: %d |  Nota Materia: %d \n", temp->nombreMateria, temp->estadoMateria, temp->notaMateria);
        temp = temp->next;
    }}
}