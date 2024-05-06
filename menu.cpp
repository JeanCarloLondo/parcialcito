#include <iostream>
#include <string>
#include <memory>
#include "Arbol.h"
#include <limits>

int obtenerOpcionValida()
{
    int opcion;
    std::cout << "Seleccione una opción: ";
    std::cin >> opcion;
    // Validar que la opción esté en el rango de 1 a 5
    if (opcion >= 1 && opcion <= 6)
    {
        return opcion; // Convertir el código ASCII a número
    }
    return 0; // Si no está en el rango, devuelve 0
}

void menu(Arbol &arbol)
{
    int opcion;
    int cedula;
    std::string nombre;
    std::string programa_academico;

    while (true)
    {
        std::cout << "\nMenú:\n";
        std::cout << "1. Agregar Persona\n";
        std::cout << "2. Eliminar Persona\n";
        std::cout << "3. Mostrar Árbol\n";
        std::cout << "4. Elegir Nueva Raíz\n";
        std::cout << "5. Salir\n";
        std::cout << "Seleccione una opción: ";

        int opcion = obtenerOpcionValida();

        switch (opcion)
        {
        case 1:
        {
            std::cout << "Ingrese cedula: ";
            std::cin >> cedula;
            std::cout << "Ingrese nombre: ";
            std::cin.ignore();              // Limpiar el buffer de entrada antes de leer la línea
            std::getline(std::cin, nombre); // Para leer toda la linea incluidos espacios
            std::cout << "Ingrese programa academico: ";
            std::cin.ignore();
            std::getline(std::cin, programa_academico);
            arbol.insertar(cedula, nombre, programa_academico);
            break;
        }
        case 2:
        {
            std::cout << "Ingrese cedula: ";
            std::cin >> cedula;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer de entrada

            arbol.eliminar(cedula);
            std::cout << "Persona eliminada.\n";

            break;
        }

        case 3:
            arbol.imprimirArbol();
            break;
        case 4:
            std::cout << "Ingrese cedula de la nueva raiz: ";
            std::cin >> cedula;
            std::cout << "Ingrese nombre de la nueva raiz: ";
            std::cin.ignore();              // Limpiar el buffer de entrada antes de leer la línea
            std::getline(std::cin, nombre); // Para leer toda la línea incluidos espacios
            std::cout << "Ingrese programa academico de la nueva raiz: ";
            std::getline(std::cin, programa_academico);
            arbol.elegirRaiz(cedula, nombre, programa_academico);
            break;

        case 5:
            return;
        default:
            std::cout << "Opción inválida. Intente de nuevo.\n";
        }
    }
}
