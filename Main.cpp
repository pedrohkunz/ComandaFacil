#include <iostream>
#include <windows.h>
#include "include/LoteDAO.h"
#include "include/IngredienteDAO.h"
#include  <string>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    IngredienteDAO ingredientes = IngredienteDAO();
    LoteDAO l = LoteDAO();

    ingredientes.carregarIngredientes();
    l.carregarLotes();

    //l.inserirLote(Lote(10, 390, "28/01/2005", ingredientes.getIngredienteByID(2)));

    for(Lote lote : l.getAllLotes()){
      cout << lote;
    }


}
