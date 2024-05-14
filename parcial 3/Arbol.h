#ifndef ARBOL_H
#define ARBOL_H

#include <memory>
#include "Nodo.h"
#include "Dato.h"

class Arbol
{
public:
    std::shared_ptr<Nodo> raiz;         // Puntero compartido a la raíz del árbol
    std::shared_ptr<Nodo> raizOriginal; // Puntero compartido a la raíz original del árbol

    // Constructor que inicializa la raíz como nula
    Arbol() : raiz(nullptr) {}

    // Método para insertar un nuevo nodo en el árbol
    void insertar(int cedula, std::string nombre, std::string programa_academico);

    // Método para eliminar un nodo del árbol dado su número de cédula
    bool eliminar(int cedula);

    // Método para elegir una nueva raíz para el árbol basado en una cédula dada
    std::shared_ptr<Nodo> elegirRaiz(int cedula);

    // Método para imprimir el árbol en preorden
    void imprimirArbol();

private:
    // Método privado para realizar la inserción recursiva de un nodo en el árbol
    std::shared_ptr<Nodo> insertarRecursivo(std::shared_ptr<Nodo> nodo, std::shared_ptr<Dato> dato);

    // Método privado para buscar si una cédula específica existe en el árbol
    bool buscarCedula(std::shared_ptr<Nodo> nodo, int cedula);

    // Método privado para realizar la eliminación recursiva de un nodo del árbol
    std::shared_ptr<Nodo> eliminarRecursivo(std::shared_ptr<Nodo> nodo, int cedula, std::shared_ptr<Nodo> padre);

    // Método privado para buscar un nodo específico dado su número de cédula
    std::shared_ptr<Nodo> buscarNodo(std::shared_ptr<Nodo> nodo, int cedula);

    // Método privado para encontrar el nodo con el valor mínimo en un subárbol
    std::shared_ptr<Nodo> minValorNodo(std::shared_ptr<Nodo> nodo);

    // Método privado que recorre el arbol original, para insertar por izquierda o por derecha
    void conectarSubarboles(std::shared_ptr<Nodo> &original, std::shared_ptr<Nodo> &nuevaRaiz);

    // Método privado para imprimir el árbol recursivamente en preorden
    void imprimirArbolRecursivo(std::shared_ptr<Nodo> nodo, const std::string &prefix, bool isLeft);
};

#endif