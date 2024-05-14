#ifndef MENU_H
#define MENU_H

#include "Arbol.h"
#include <windows.h> // Incluye la biblioteca Windows API para utilizar SetConsoleOutputCP

void setupConsole(); // Declaración de la función setupConsole()

void menu(Arbol &arbol);

#endif // MENU_H