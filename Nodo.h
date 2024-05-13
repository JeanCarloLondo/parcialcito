#ifndef NODO_H
#define NODO_H

#include <memory>
#include "Dato.h"

// Definición de la clase Nodo, que representa un nodo en un árbol binario.
class Nodo
{
public:
    std::shared_ptr<Dato> dato; // Puntero a un objeto Persona
    std::shared_ptr<Nodo> izq;  // Puntero al hijo izquierdo
    std::shared_ptr<Nodo> der;  // Puntero al hijo derecho
    // Constructor de Nodo que inicializa sus punteros.
    Nodo(std::shared_ptr<Dato> dato) : dato(dato), izq(nullptr), der(nullptr) {}
};

#endif // NODO_H
