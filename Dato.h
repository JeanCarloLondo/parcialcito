#ifndef DATO_H
#define DATO_H

#include <iostream>
#include <string>

// Definición de la clase Dato, que representa a una persona con cedula, nombre y prog_acad.
class Dato
{
public:
    int cedula; // Cédula de la persona
    std::string nombre; // Nombre de la persona
    std::string programa_academico; // Programa académico de la persona

    // Constructor de la clase Dato.
    // @param cedula: La cédula de la persona.
    // @param nombre: El nombre de la persona.
    // @param programa_academico: El programa académico de la persona.
    Dato(int cedula, std::string nombre, std::string programa_academico);
};

#endif // DATO_H