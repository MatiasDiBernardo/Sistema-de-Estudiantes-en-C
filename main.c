#include <stdio.h>
#include <stdlib.h>
#include "ll_estudiantes.h"
#include "ll_materias.h"
#include "CLI.h"


struct NodeEstudiante* inicializacionEstudiantes(){
    struct NodeEstudiante* headEst = NULL;
    
    char *materias1[] = {"Física I", "Análisis Matemátcio I", "Historia"};
    int notas1[] = {6, 2, 9};
    addAtEnd(&headEst, "Matias Di Bernardo", 24, 55155, materias1, notas1, 3);

    char *materias2[] = {"Algebra I", "Historia"};
    int notas2[] = {0, 7};
    addAtEnd(&headEst, "Lucia Gonzales", 22, 53135, materias2, notas2, 2);

    // char *materias[] = {"Algoritmos y Programación I"};
    // int notas[] = {6};
    // addAtEnd(&headEst, "Jerinimo Igoldi", 25, 54567, materias, notas, 2);

    // char *materias[] = {"Algebra I", "Historia"};
    // int notas[] = {8, 2};
    // addAtEnd(&headEst, "Luz Pattini", 31, 47685, materias, notas, 2);

    // char *materias[] = {"Física I", "Análisis Matemátcio I", "Algebra I"};
    // int notas[] = {1, 3, 9};
    // addAtEnd(&headEst, "Simon Mellino", 19, 61249, materias, notas, 3);
    
    return headEst;
}

int main() {

    printf("Hasta aca 1");
    struct NodeEstudiante* headEst = inicializacionEstudiantes();
    printf("Hasta aca 2");
    int state = 1;

    while (state == 1){
        state = menuCLI(headEst);
    }

    return 0;
}
