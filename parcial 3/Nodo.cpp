#include <iostream>
#include <string>
#include <memory>
#include "Dato.cpp"

// Definición de la clase Nodo, que representa un nodo en un árbol binario.
class Nodo
{
public:
    std::shared_ptr<Dato> dato; // Puntero compartido a un objeto Dato
    std::shared_ptr<Nodo> izq;  // Puntero compartido al hijo izquierdo
    std::shared_ptr<Nodo> der;  // Puntero compartido al hijo derecho

    // Constructor de la clase Nodo que inicializa sus punteros.
    // @param dato: Puntero compartido al objeto Dato que contiene la información del nodo.
    Nodo(std::shared_ptr<Dato> dato) : dato(dato), izq(nullptr), der(nullptr) {}
};