#include <iostream>
#include <windows.h>
#include "include/SaborDAO.h"
#include "include/IngredienteDAO.h"
#include "include/MenuPrincipal.h"
#include  <string>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    IngredienteDAO ingredientes = IngredienteDAO();
    SaborDAO sabor = SaborDAO();
    MenuPrincipal menuPrincipal = MenuPrincipal();

    ingredientes.carregarIngredientes();
    sabor.carregarSabores();

    menuPrincipal.menu();





}
