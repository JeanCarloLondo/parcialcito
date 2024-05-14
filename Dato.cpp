#include <iostream>
#include <string>
#include "Dato.h"
#include <sstream>

using namespace std;

// Constructor de la clase Dato que inicializa sus atributos.
// @param cedula: La cédula de la persona.
// @param nombre: El nombre de la persona.
// @param programa_academico: El programa académico de la persona.
Dato::Dato(int cedula, std::string nombre, std::string programa_academico)
    : cedula(cedula), nombre(nombre), programa_academico(programa_academico) {}