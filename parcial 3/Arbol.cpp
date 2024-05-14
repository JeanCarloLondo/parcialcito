#include "Arbol.h"

void Arbol::insertar(int cedula, std::string nombre, std::string programa_academico)
{
    // Verificar si la cédula ya existe en el árbol
    if (buscarCedula(raiz, cedula))
    {
        std::cerr << "La cédula ingresada ya existe. Por favor, ingrese una cédula válida."
                     "por suplantacion de identidad"
                  << std::endl;
        return;
    }

    // Crear un nuevo objeto Dato con los datos proporcionados
    std::shared_ptr<Dato> item = std::make_shared<Dato>(cedula, nombre, programa_academico);

    // Insertar el nuevo dato en el árbol recursivamente
    raiz = insertarRecursivo(raiz, item);
}

bool Arbol::buscarCedula(std::shared_ptr<Nodo> nodo, int cedula)
{
    if (nodo == nullptr)
    {
        return false;
    }

    // Verificar si la cédula está presente en el nodo actual
    if (nodo->dato->cedula == cedula)
    {
        return true;
    }

    // Buscar en los subárboles izquierdo y derecho recursivamente
    return buscarCedula(nodo->izq, cedula) || buscarCedula(nodo->der, cedula);
}

bool Arbol::eliminar(int cedula)
{
    if (!raiz)
    {
        return false; // Si el árbol está vacío, no se puede eliminar
    }

    // Llamar a la función recursiva para eliminar el nodo
    raiz = eliminarRecursivo(raiz, cedula, nullptr);
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
    raiz = eliminarRecursivo(raiz, cedula, nullptr);

    // Reemplazar la raíz actual con el nodo elegido como nueva raíz
    raiz = nodo;
    // Conectar los subárboles izquierdo y derecho originales al nuevo nodo raíz
    conectarSubarboles(raizOriginal, raiz);

    // Mostrar información sobre la nueva raíz y los subárboles originales
    std::cout << "Nueva raíz: " << nodo->dato->nombre << " (Cedula: " << nodo->dato->cedula
              << " - Programa Academico: " << nodo->dato->programa_academico << ")" << std::endl;

    return nodo;
}

void Arbol::conectarSubarboles(std::shared_ptr<Nodo> &original, std::shared_ptr<Nodo> &nuevaRaiz)
{
    if (original == nullptr)
    {
        return;
    }

    // Recorrer el subárbol original en orden
    conectarSubarboles(original->izq, nuevaRaiz);

    // Insertar el nodo actual en el nuevo subárbol si no está presente
    if (!buscarCedula(nuevaRaiz, original->dato->cedula))
    {
        nuevaRaiz = insertarRecursivo(nuevaRaiz, original->dato);
    }
    // Recorrer el subárbol derecho original
    conectarSubarboles(original->der, nuevaRaiz);
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

std::shared_ptr<Nodo> Arbol::eliminarRecursivo(std::shared_ptr<Nodo> nodo, int cedula, std::shared_ptr<Nodo> padre)
{
    if (nodo == nullptr)
    {
        return nullptr;
    }
    else if (cedula < nodo->dato->cedula)
    {
        nodo->izq = eliminarRecursivo(nodo->izq, cedula, nodo); // Eliminar en el subárbol izquierdo
    }
    else if (cedula > nodo->dato->cedula)
    {
        nodo->der = eliminarRecursivo(nodo->der, cedula, nodo); // Eliminar en el subárbol derecho
    }
    else // Se encontró el nodo a eliminar
    {
        if (nodo->izq == nullptr)
        {
            // Conectar el nodo derecho con el padre del nodo a eliminar
            return nodo->der;
        }
        else if (nodo->der == nullptr)
        {
            // Conectar el nodo izquierdo con el padre del nodo a eliminar
            return nodo->izq;
        }

        // Nodo con dos hijos: obtener el sucesor inmediato
        std::shared_ptr<Nodo> temp = minValorNodo(nodo->der);
        nodo->dato = temp->dato;                                            // Copiar los datos del sucesor al nodo actual
        nodo->der = eliminarRecursivo(nodo->der, temp->dato->cedula, nodo); // Eliminar el sucesor
    }

    return nodo;
}

std::shared_ptr<Nodo> Arbol::buscarNodo(std::shared_ptr<Nodo> nodo, int cedula)
{
    if (nodo == nullptr)
    {
        return nullptr;
    }

    if (nodo->dato->cedula == cedula)
    {
        return nodo;
    }

    // Buscar en los subárboles izquierdo y derecho recursivamente
    std::shared_ptr<Nodo> encontradoIzq = buscarNodo(nodo->izq, cedula);
    if (encontradoIzq != nullptr)
    {
        return encontradoIzq;
    }

    std::shared_ptr<Nodo> encontradoDer = buscarNodo(nodo->der, cedula);
    if (encontradoDer != nullptr)
    {
        return encontradoDer;
    }

    return nullptr;
}

std::shared_ptr<Nodo> Arbol::minValorNodo(std::shared_ptr<Nodo> nodo)
{
    std::shared_ptr<Nodo> current = nodo;
    while (current && current->izq != nullptr)
    {
        current = current->izq; // Avanzar hacia el hijo izquierdo
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
        // Imprimir el subárbol derecho recursivamente
        imprimirArbolRecursivo(nodo->der, prefix + (isLeft ? "│   " : "    "), false);
    }

    // Imprimir el nodo actual
    std::cout << prefix << (isLeft ? "└── " : "┌── ") << nodo->dato->nombre << " (Cedula: " << nodo->dato->cedula
              << " - Programa Academico: " << nodo->dato->programa_academico << ")" << std::endl;

    if (nodo->izq)
    {
        // Imprimir el subárbol izquierdo recursivamente
        imprimirArbolRecursivo(nodo->izq, prefix + (isLeft ? "    " : "│   "), true);
    }
}