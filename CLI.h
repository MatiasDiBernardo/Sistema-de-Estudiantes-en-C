#ifndef CLI_H
#define CLI_H

#// Define the node structure
struct CLI_Interface {
    struct NodeMaterias* materiasHead;
    struct NodeEstudiante* estudiantesHead;
};
// Function declarations
struct CLI_Interface* createCLI(struct NodeEstudiante* headEst, struct NodeMaterias* headMat);
int menuCLI(struct NodeEstudiante* headEst);
// void buscarPorNombre(const char* nombre);
// void buscarPorEdad(int edadMinima, int edadMaxima);

#endif 