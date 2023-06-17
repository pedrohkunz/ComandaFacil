#include <iostream>
#include <windows.h>
#include "include/SaborDAO.h"
#include "include/IngredienteDAO.h"
#include  <string>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    IngredienteDAO ingredientes = IngredienteDAO();
    SaborDAO sabor = SaborDAO();

    ingredientes.carregarIngredientes();
    sabor.carregarSabores();

    sabor.salvarSabores();





}
