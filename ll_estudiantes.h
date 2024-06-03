#ifndef LL_ESTUDIANTES_H
#define LL_ESTUDIANTES_H

#// Define the node structure
struct NodeEstudiante {
    char nombre[100];
    int edad;
    int legajo;
    struct NodeMaterias* materias;
    struct NodeEstudiante* next;
};

// Function declarations
struct NodeEstudiante* createNode(char* nombre, int edad, int legajo);
void addAtEnd(struct NodeEstudiante** head, char* nombre, int edad, int legajo);
void displayList(struct NodeEstudiante* head);
void removeNodeByLegajo(struct NodeEstudiante** head, int legajo);
void removeNodeByName(struct NodeEstudiante** head, char* nombre);

#endif 
