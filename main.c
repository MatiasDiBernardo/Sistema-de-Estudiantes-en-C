#include <stdio.h>
#include <stdlib.h>
#include "ll_estudiantes.h"
#include "ll_materias.h"
#include "CLI.h"

struct NodeEstudiante* inicializacionEstudiantes(){
    struct NodeEstudiante* headEst = NULL;
    
    char* materias1[] = {"Física I", "Análisis I", "Historia"};
    int notas1[] = {6, 2, 9};
    struct NodeMateria* matEst1 = creaMateriasSegunAlumno(materias1, notas1, 3);
    addAtEnd(&headEst, "Matias Di Bernardo", 24, 55155, matEst1);

    char* materias2[] = {"Algebra I", "Historia"};
    int notas2[] = {0, 7};
    struct NodeMateria* matEst2 = creaMateriasSegunAlumno(materias2, notas2, 2);
    addAtEnd(&headEst, "Lucia Gonzales", 22, 53135, matEst2);

    char *materias3[] = {"Algoritmos I"};
    int notas3[] = {6};
    struct NodeMateria* matEst3 = creaMateriasSegunAlumno(materias3, notas3, 1);
    addAtEnd(&headEst, "Jerinimo Igoldi", 25, 54567, matEst3);

    char *materias4[] = {"Algebra I", "Historia"};
    int notas4[] = {8, 2};
    struct NodeMateria* matEst4 = creaMateriasSegunAlumno(materias4, notas4, 2);
    addAtEnd(&headEst, "Luz Pattini", 31, 47685, matEst4);

    char *materias5[] = {"Física I", "Análisis I", "Algebra I"};
    int notas5[] = {1, 3, 9};
    struct NodeMateria* matEst5 = creaMateriasSegunAlumno(materias5, notas5, 2);
    addAtEnd(&headEst, "Simon Mellino", 19, 61249, matEst5);
    
    return headEst;
}

int main() {

    struct NodeEstudiante* headEst = inicializacionEstudiantes();
    int state = 1;

    while (state == 1){
        state = menuCLI(headEst);
    }

    return 0;
}
