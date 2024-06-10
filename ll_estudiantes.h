#ifndef LL_ESTUDIANTES_H
#define LL_ESTUDIANTES_H

#// Define el node de estudiantes
struct NodeEstudiante {
    char nombre[100];
    int edad;
    int legajo;
    struct NodeMateria* materias;
    struct NodeEstudiante* next;
};

// Function declarations
struct NodeEstudiante* createNode(char* nombre, int edad, int legajo, struct NodeMateria* listaMaterias);
void addAtEnd(struct NodeEstudiante** head, char* nombre, int edad, int legajo, struct NodeMateria* listaMaterias);
void displayList(struct NodeEstudiante* head);
void removeNodeByLegajo(struct NodeEstudiante** head, int legajo);
void removeNodeByName(struct NodeEstudiante** head, char* nombre);

#endif 
