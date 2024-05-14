#include <iostream>
#include <string>
#include <memory>
#include "Arbol.h"
#include "menu.h"

// Función auxiliar para configurar la consola para admitir salida en UTF-8 en sistemas Windows
void setupConsole() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
}

// Función principal que inicia el programa
int main() {
    setupConsole(); // Configurar la consola

    Arbol arbol; // Crear un objeto de la clase Arbol para almacenar el árbol binario

    menu(arbol); // Iniciar el menú interactivo y pasar el objeto Arbol como argumento

    return 0; // Devolver un valor entero para indicar que el programa se ejecutó correctamente
}