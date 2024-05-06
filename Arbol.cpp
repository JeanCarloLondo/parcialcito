#include "Arbol.h"

// Función para insertar un nuevo dato en el árbol.
void Arbol::insertar(int cedula, std::string nombre, std::string programa_academico)
{
    std::shared_ptr<Dato> item = std::make_shared<Dato>(cedula, nombre, programa_academico);
    raiz = insertarRecursivo(raiz, item);
}

// Función para eliminar un dato del árbol.
bool Arbol::eliminar(int cedula, std::string nombre, std::string programa_academico)
{
    std::shared_ptr<Dato> item = std::make_shared<Dato>(cedula, nombre, programa_academico);
    bool encontrado;
    raiz = eliminarRecursivo(raiz, item);
    return encontrado;
}

void Arbol::elegirRaiz(int cedula, std::string nombre, std::string programa_academico)
{
    std::shared_ptr<Dato> item = std::make_shared<Dato>(cedula, nombre, programa_academico);

    // Buscar el nodo que elija el usuario
    std::shared_ptr<Nodo> nodo = buscarNodo(raiz, item);

    if (nodo == nullptr)
    {
        std::cerr << "No se encontró el nodo especificado." << std::endl;
        return;
    }

    // Si se encuentra se elimina
    raiz = eliminarRecursivo(raiz, nodo->dato);

    // Se vuelve a insertar y esta vez como raiz
    raiz = insertarRecursivo(raiz, nodo->dato);
}

// Imprime visualmente el árbol. Si el árbol está vacío, se muestra un mensaje indicativo.
void Arbol::imprimirArbol()
{
    if (!raiz)
    {
        std::cout << "El árbol está vacío." << std::endl;
    }
    else
    {
        imprimirArbolRecursivo(raiz, "", true);
    }
}

std::shared_ptr<Nodo> Arbol::insertarRecursivo(std::shared_ptr<Nodo> nodo, std::shared_ptr<Dato> dato)
{
    if (nodo == nullptr)
    {
        nodo = std::make_shared<Nodo>(dato); // Construir el nodo con el dato proporcionado
    }
    else if (dato->cedula < nodo->dato->cedula)
    {
        nodo->izq = insertarRecursivo(nodo->izq, dato);
    }
    else if (dato->cedula > nodo->dato->cedula)
    {
        nodo->der = insertarRecursivo(nodo->der, dato);
    }
    return nodo;
}

std::shared_ptr<Nodo> Arbol::eliminarRecursivo(std::shared_ptr<Nodo> nodo, std::shared_ptr<Dato> dato)
{
    if (nodo == nullptr)
    {
        std::cerr << "El árbol está vacío" << std::endl;
        return nullptr;
    }
    else if (dato->cedula < nodo->dato->cedula)
    {
        nodo->izq = eliminarRecursivo(nodo->izq, dato);
    }
    else if (dato->cedula > nodo->dato->cedula)
    {
        nodo->der = eliminarRecursivo(nodo->der, dato);
    }

    if (nodo->izq == nullptr)
    {
        return nodo->der;
    }
    else if (nodo->der == nullptr)
    {
        return nodo->izq;
    }

    std::shared_ptr<Nodo> temp = minValorNodo(nodo->der);
    nodo->dato = temp->dato;
    nodo->der = eliminarRecursivo(nodo->der, temp->dato);
    
    return nodo;
}

std::shared_ptr<Nodo> Arbol::buscarNodo(std::shared_ptr<Nodo> nodo, std::shared_ptr<Dato> objetivo)
{
    if (nodo == nullptr)
    {
        std::cerr << "La lista se encuentra vacía" << std::endl;
        return nullptr;
    }

    if (nodo->dato->cedula == objetivo->cedula &&
        nodo->dato->nombre == objetivo->nombre &&
        nodo->dato->programa_academico == objetivo->programa_academico)
    {
        return nodo;
    }
                                      
    // Buscar en el subárbol izquierdo y derecho
    std::shared_ptr<Nodo> encontradoIzq = buscarNodo(nodo->izq, objetivo);
    std::shared_ptr<Nodo> encontradoDer = buscarNodo(nodo->der, objetivo);

    // Devuelve el nodo encontrado (si está) o nullptr
    if (encontradoIzq != nullptr)
        return encontradoIzq;
    else
        return encontradoDer;
}

std::shared_ptr<Nodo> Arbol::minValorNodo(std::shared_ptr<Nodo> nodo)
{
    std::shared_ptr<Nodo> current = nodo;
    while (current && current->izq != nullptr)
    {
        current = current->izq;
    }
    return current;
}

void Arbol::imprimirArbolRecursivo(std::shared_ptr<Nodo> nodo, const std::string &prefix, bool isLeft)
{
    if (nodo->der)
    {
        imprimirArbolRecursivo(nodo->der, prefix + (isLeft ? "│   " : "    "), false);
    }

    std::cout << prefix << (isLeft ? "└── " : "┌── ") << nodo->dato->nombre << " (Cedula: " << nodo->dato->cedula
              << " - Programa Academico: " << nodo->dato->programa_academico << ")" << std::endl;

    if (nodo->izq)
    {
        imprimirArbolRecursivo(nodo->izq, prefix + (isLeft ? "    " : "│   "), true);
    }
}