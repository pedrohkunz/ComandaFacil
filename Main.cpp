#include <iostream>
#include <windows.h>

using namespace std;

#include "include/MenuPrincipal.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    MenuPrincipal menu = MenuPrincipal();
    menu.menu();
    
}
