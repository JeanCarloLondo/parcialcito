#include "Arbol.h"

void Arbol::insertar(int cedula, std::string nombre, std::string programa_academico)
{
    // Verificar si la cédula ya existe en el árbol
    if (buscarCedula(raiz, cedula))
    {
        std::cerr << "La cédula ingresada ya existe. Por favor, ingrese una cédula válida." << std::endl;
        return;
    }

    std::shared_ptr<Dato> item = std::make_shared<Dato>(cedula, nombre, programa_academico);
    raiz = insertarRecursivo(raiz, item);
}

bool Arbol::buscarCedula(std::shared_ptr<Nodo> nodo, int cedula)
{
    if (nodo == nullptr)
    {
        return false;
    }

    if (nodo->dato->cedula == cedula)
    {
        return true;
    }

    return buscarCedula(nodo->izq, cedula) || buscarCedula(nodo->der, cedula);
}

bool Arbol::eliminar(int cedula)
{
    if (!raiz)
    {
        return false;
    }

        raiz = eliminarRecursivo(raiz, cedula);
        return true;
    
}

std::shared_ptr<Nodo> Arbol::elegirRaiz(int cedula)
{

    // Guardar una copia del árbol original
    raizOriginal = raiz;

    // Buscar el nodo que el usuario desea elegir como la nueva raíz
    std::shared_ptr<Nodo> nodo = buscarNodo(raiz, cedula);

    if (nodo == nullptr)
    {
        std::cerr << "No se encontró el nodo especificado." << std::endl;
        return nullptr;
    }

    // Verificar si el nodo ya es la raíz
    if (nodo == raiz)
    {
        std::cout << "El nodo seleccionado ya es la raíz." << std::endl;
        return nodo;
    }

    // Eliminar recursivamente ese nodo del árbol
    raiz = eliminarRecursivo(raiz, cedula);

    // Reemplazar la raíz actual con el nodo elegido como nueva raíz
    raiz = nodo;

    // Conectar los subárboles izquierdo y derecho originales al nuevo nodo raíz
    nodo->izq = raizOriginal;
    nodo->der = nullptr;

    // Recorrer recursivamente y actualizar referencias
    actualizarArbol(raizOriginal, nodo);

    // Mostrar información sobre la nueva raíz y los subárboles originales
    std::cout << "Nueva raíz: " << nodo->dato->nombre << " (Cedula: " << nodo->dato->cedula
              << " - Programa Academico: " << nodo->dato->programa_academico << ")" << std::endl;

    return nodo;
}

std::shared_ptr<Nodo> Arbol::insertarRecursivo(std::shared_ptr<Nodo> nodo, std::shared_ptr<Dato> dato)
{
    if (nodo == nullptr)
    {
        return std::make_shared<Nodo>(dato);
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

std::shared_ptr<Nodo> Arbol::eliminarRecursivo(std::shared_ptr<Nodo> nodo, int cedula)
{
    if (nodo == nullptr)
    {
        return nullptr;
    }
    else if (cedula < nodo->dato->cedula)
    {
        nodo->izq = eliminarRecursivo(nodo->izq, cedula);
    }
    else if (cedula > nodo->dato->cedula)
    {
        nodo->der = eliminarRecursivo(nodo->der, cedula);
    }
    else // Se encontró el nodo a eliminar
    {
        if (nodo->izq == nullptr)
        {
            return nodo->der;
        }
        else if (nodo->der == nullptr)
        {
            return nodo->izq;
        }

        // Buscar el nodo mínimo en el subárbol derecho
        std::shared_ptr<Nodo> temp = minValorNodo(nodo->der);

        // Intercambiar los datos del nodo actual con el nodo mínimo encontrado
        nodo->dato = temp->dato;

        // Eliminar recursivamente el nodo mínimo del subárbol derecho
        nodo->der = eliminarRecursivo(nodo->der, temp->dato->cedula);
    }

    return nodo;
}

void Arbol::actualizarArbol(std::shared_ptr<Nodo> &original, std::shared_ptr<Nodo> &nuevaRaiz)
{
    if (original == nullptr)
    {
        return;
    }

    // Insertar el nodo original en el árbol con la nueva raíz, si no existe ya
    if (original != nuevaRaiz && !buscarNodo(nuevaRaiz, original->dato->cedula))
    {
        nuevaRaiz = insertarRecursivo(nuevaRaiz, original->dato);
    }

    // Recorrer el árbol original y actualizar los punteros de los nodos
    if (original->izq != nullptr)
    {
        // Llamar recursivamente a la función para el subárbol izquierdo, pasando la nueva raíz como padre
        actualizarArbol(original->izq, nuevaRaiz);
    }

    if (original->der != nullptr)
    {
        // Llamar recursivamente a la función para el subárbol derecho, pasando la nueva raíz como padre
        actualizarArbol(original->der, nuevaRaiz);
    }
}

std::shared_ptr<Nodo> Arbol::buscarNodo(std::shared_ptr<Nodo> nodo, int cedula)
{

    if (nodo->dato->cedula == cedula)
    {
        return nodo;
    }

    std::shared_ptr<Nodo> encontradoIzq = buscarNodo(nodo->izq, cedula);
    std::shared_ptr<Nodo> encontradoDer = buscarNodo(nodo->der, cedula);

    if (encontradoIzq != nullptr)
    {
        return encontradoIzq;
    }
    else
    {
        return encontradoDer;
    }
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