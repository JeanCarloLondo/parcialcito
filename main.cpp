#include <iostream>
#include <string>
#include <memory>
#include "Arbol.h"
#include "menu.h"

void setupConsole() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
}

int main() {
    setupConsole();
    Arbol arbol;
    menu(arbol);
    return 0;
}
