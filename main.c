#include <stdio.h>
#include <stdlib.h>
#include "ll_estudiantes.h"
#include "CLI.h"

struct NodeEstudiante* inicializacionEstudiantes(){
    struct NodeEstudiante* headEst = NULL;

    addAtEnd(&headEst, "Matias Di Bernardo", 24, 55155);
    addAtEnd(&headEst, "Lucia Gonzales", 22, 53135);
    addAtEnd(&headEst, "Jerinimo Igoldi", 25, 54567);
    addAtEnd(&headEst, "Luz Pattini", 31, 47685);
    addAtEnd(&headEst, "Simon Mellino", 19, 61249);
    
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
