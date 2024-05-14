#include <iostream>
#include <string>
#include <limits> // Para utilizar std::numeric_limits
#include "Arbol.h"

// Función para obtener una opción válida del menú
int obtenerOpcionValida()
{
    int opcion;
    std::cout << "Seleccione una opción: ";
    std::cin >> opcion;

    // Verificar si la entrada es válida
    if (std::cin.fail())
    {
        std::cin.clear();  // Limpiar el estado de error del flujo de entrada
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar la entrada no válida
        std::cerr << "Error: Entrada no válida. Por favor, ingrese un número válido." << std::endl;
        return 0; // Devolver 0 para indicar una entrada inválida
    }

    // Verificar que la opción esté en el rango de 1 a 5
    if (opcion >= 1 && opcion <= 5)
    {
        return opcion; // Devolver la opción válida
    }
    else
    {
        std::cerr << "Error: Opción fuera de rango. Por favor, seleccione una opción válida." << std::endl;
        return 0; // Devolver 0 para indicar una opción inválida
    }
}

// Función que muestra el menú y permite interactuar con el árbol
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

        opcion = obtenerOpcionValida(); // Obtener una opción válida del usuario

        switch (opcion)
        {
        case 1:
            std::cout << "Ingrese cedula: ";
            std::cin >> cedula;
            std::cout << "Ingrese nombre: ";
            std::cin.ignore();              // Limpiar el buffer de entrada antes de leer la línea
            std::getline(std::cin, nombre); // Leer el nombre completo incluyendo espacios
            std::cout << "Ingrese programa academico: ";
            std::getline(std::cin, programa_academico);
            arbol.insertar(cedula, nombre, programa_academico);
            break;

        case 2:
            if (!arbol.raiz)
            {
                std::cerr << "El árbol está vacío. No se puede eliminar una persona.\n";
                break;
            }
            std::cout << "Ingrese cedula: ";
            std::cin >> cedula;
            if (arbol.eliminar(cedula))
            {
                std::cout << "Persona eliminada correctamente.\n";
            }
            else
            {
                std::cout << "No se encontró la persona en el árbol.\n";
            }
            break;

        case 3:
            arbol.imprimirArbol();
            break;

        case 4:
            if (!arbol.raiz)
            {
                std::cerr << "El árbol está vacío. No se puede elegir una nueva raíz.\n";
                break;
            }
            std::cout << "Ingrese cedula de la nueva raiz: ";
            std::cin >> cedula;
            std::cout << "Ingrese nombre de la nueva raiz: ";
            std::cin.ignore(); // Limpiar el buffer de entrada antes de leer la línea
            std::getline(std::cin, nombre);
            std::cout << "Ingrese programa academico de la nueva raiz: ";
            std::getline(std::cin, programa_academico);
            arbol.elegirRaiz(cedula);
            break;

        case 5:
            std::cout << "Saliendo del programa.\n";
            return;

        default:
            break;
        }
    }
}