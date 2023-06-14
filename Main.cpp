#include <iostream>
#include <windows.h>
#include "include/LoteDAO.h"
#include "include/IngredienteDAO.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    IngredienteDAO i = IngredienteDAO();
    LoteDAO l = LoteDAO();

    l.carregarLotes();
    i.carregarIngredientes();

    l.inserirLote(Lote(2, 390, "28/01/2005", i.getIngredienteByID(1)));
}
