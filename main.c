#include <stdio.h>
#include <stdlib.h>
#include "ll_estudiantes.h"

int main() {
    // Inicializa la lista de estudiantes
    struct NodeEstudiante* headEst = NULL;

    // Adding elements to the list
    addAtEnd(&headEst, "Matías", 24, 55155);
    addAtEnd(&headEst, "Fede", 22, 51324);
    addAtEnd(&headEst, "Gastón", 28, 48512);
    addAtEnd(&headEst, "Tomás", 18, 57826);

    // Displaying the list
    printf("Original List:\n");
    displayList(headEst);

    // Removing a nodes by value
    removeNodeByLegajo(&headEst, 51324);
    removeNodeByName(&headEst, "Gastón");

    // Displaying the list after removing the node
    printf("List after removing:\n");
    displayList(headEst);

    // Freeing the allocated memory
    struct NodeEstudiante* temp;
    while (headEst != NULL) {
        temp = headEst;
        headEst = headEst->next;
        free(temp);
    }

    return 0;
}
