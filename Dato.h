#ifndef DATO_H
#define DATO_H

#include <iostream>
#include <string>

// Definición de la clase Dato, que representa a una persona con cedula, nombre y prog_acad.
class Dato {
public:
    int cedula;
    std::string nombre;
    std::string programa_academico;

    Dato(int cedula, std::string nombre, std::string programa_academico);
};

#endif // DATO_H
