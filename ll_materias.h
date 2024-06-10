#ifndef LL_MATERIAS_H
#define LL_MATERIAS_H

#// Define el nodo de materias 
struct NodeMateria {
    char nombreMateria[20];
    int estadoMateria;  // 0 no esta cursando, 1 esta cursando, 2 aprobada, 3 reprobado
    int notaMateria;
    struct NodeMateria *next;
};

// Function declarations
struct NodeMateria* createMateria(char* nombreMateria, int estado, int notaMat);
void agregarMateriaAlFinal(struct NodeMateria** head, char* nombreMateria, int idMat, int notaMat);
struct NodeMateria* creaListaBaseDeMaterias();
struct NodeMateria* creaMateriasSegunAlumno(char *nombreMaterias[], int notaMaterias[], int cantidadCursadas);
void displayMaterias(struct NodeMateria* head);

#endif 
