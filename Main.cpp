#include <iostream>
#include <windows.h>

using namespace std;

#include "include/MenuPrincipal.h"
#include "include/ComandaDAO.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    //MenuPrincipal menuPrincipal = MenuPrincipal();
    //menuPrincipal.menu();
    ComandaDAO comandas = ComandaDAO();
    comandas.imprimirComandas();

    }
