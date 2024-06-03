#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll_estudiantes.h"

// Function to create a new node
struct NodeEstudiante* createNode(char* nombre, int edad, int legajo) {
    struct NodeEstudiante* newNode = (struct NodeEstudiante*)malloc(sizeof(struct NodeEstudiante));
    strcpy(newNode->nombre, nombre);
    newNode->edad = edad;
    newNode->legajo = legajo;
    // Falta agregar el puntero a la ll de materias
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void addAtEnd(struct NodeEstudiante** head, char* nombre, int edad, int legajo) {
    struct NodeEstudiante* newNode = createNode(nombre, edad, legajo);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct NodeEstudiante* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the linked list
void displayList(struct NodeEstudiante* head) {
    struct NodeEstudiante* temp = head;
    if(temp==NULL){
        printf("No hay alumnos en la lista\n");
    }else{
    while (temp != NULL) {
        printf("Nombre: %s | Edad: %d |  Legajo: %d \n", temp->nombre, temp->edad, temp->legajo);
        temp = temp->next;
    }}

   // printf("NULL\n");
}

// Function to remove a node with a specific value from the list
void removeNodeByLegajo(struct NodeEstudiante** head, int legajo) {
    struct NodeEstudiante* temp = *head;
    struct NodeEstudiante* prev = NULL;

    // Ver que agregar para borrar por nombre
    // If the head node itself holds the value to be deleted
    if (temp != NULL && temp->legajo == legajo) {
        *head = temp->next; // Change head
        free(temp); // Free old head
        return;
    }

    // Search for the value to be deleted, keep track of the previous node
    while (temp != NULL && temp->legajo != legajo) {
        prev = temp;
        temp = temp->next;
    }

    // If value was not present in list
    if (temp == NULL) return;

    // Unlink the node from the linked list
    prev->next = temp->next;

    free(temp); // Free memory
}

void removeNodeByName(struct NodeEstudiante** head, char* nombre) {
    struct NodeEstudiante* temp = *head;
    struct NodeEstudiante* prev = NULL;

    // Ver que agregar para borrar por nombre
    // If the head node itself holds the value to be deleted
    if (temp != NULL && strcmp(temp->nombre, nombre) == 0) {
        *head = temp->next; // Change head
        free(temp); // Free old head
        return;
    }

    // Search for the value to be deleted, keep track of the previous node
    while (temp != NULL && strcmp(temp->nombre, nombre) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // If value was not present in list
    if (temp == NULL) return;

    // Unlink the node from the linked list
    prev->next = temp->next;

    free(temp); // Free memory
}
