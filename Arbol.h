#ifndef ARBOL_H
#define ARBOL_H

#include <memory>
#include "Nodo.h"

class Arbol {
public:
    std::shared_ptr<Nodo> raiz;
    std::shared_ptr<Nodo> raizOriginal;

    Arbol() : raiz(nullptr) {}

    void insertar(int cedula, std::string nombre, std::string programa_academico);
    bool eliminar(int cedula, std::string nombre, std::string programa_academico);
    void elegirRaiz(int cedula, std::string nombre, std::string programa_academico);
    void imprimirArbol();

private:
    std::shared_ptr<Nodo> insertarRecursivo(std::shared_ptr<Nodo> nodo, std::shared_ptr<Dato> dato);
    std::shared_ptr<Nodo> eliminarRecursivo(std::shared_ptr<Nodo> nodo, std::shared_ptr<Dato> dato);
    std::shared_ptr<Nodo> buscarNodo(std::shared_ptr<Nodo> nodo, std::shared_ptr<Dato> objetivo);
    std::shared_ptr<Nodo> minValorNodo(std::shared_ptr<Nodo> nodo);
    void imprimirArbolRecursivo(std::shared_ptr<Nodo> nodo, const std::string &prefix, bool isLeft);
};

#endif 