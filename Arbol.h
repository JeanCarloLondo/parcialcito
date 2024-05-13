#ifndef ARBOL_H
#define ARBOL_H

#include <memory>
#include "Nodo.h"
#include "Dato.h"

class Arbol
{
public:
    std::shared_ptr<Nodo> raiz;
    std::shared_ptr<Nodo> raizOriginal;

    Arbol() : raiz(nullptr) {}

    void insertar(int cedula, std::string nombre, std::string programa_academico);
    bool eliminar(int cedula);
    std::shared_ptr<Nodo> elegirRaiz(int cedula);
    void imprimirArbol();

private:
    std::shared_ptr<Nodo> insertarRecursivo(std::shared_ptr<Nodo> nodo, std::shared_ptr<Dato> dato);
    bool buscarCedula(std::shared_ptr<Nodo> nodo, int cedula);
    std::shared_ptr<Nodo> eliminarRecursivo(std::shared_ptr<Nodo> nodo, int cedula);
    std::shared_ptr<Nodo> buscarNodo(std::shared_ptr<Nodo> nodo, int cedula);
    std::shared_ptr<Nodo> minValorNodo(std::shared_ptr<Nodo> nodo);
    void imprimirArbolRecursivo(std::shared_ptr<Nodo> nodo, const std::string &prefix, bool isLeft);
    void actualizarArbol(std::shared_ptr<Nodo> &original, std::shared_ptr<Nodo> &nuevaRaiz);
};

#endif
