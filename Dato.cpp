#include <iostream>
#include <string>
#include "Dato.h"
#include <sstream>

using namespace std;

// Constructor de Dato que inicializa sus atributos.
Dato::Dato(int cedula, std::string nombre, std::string programa_academico) : cedula(cedula), nombre(nombre),
                                                                             programa_academico(programa_academico) {}