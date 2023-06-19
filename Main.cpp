#include <iostream>
#include <windows.h>

#include "include/IngredienteDAO.h"
#include "include/LoteDAO.h"
#include "include/TamanhoPizza.h"
#include "include/MenuPrincipal.h"
#include "include/UsuarioDAO.h"
#include "include/TamanhoPizzaDAO.h"
#include "include/SaborDAO.h"
#include "include/PizzaDAO.h"
#include "include/BebidaDAO.h"
#include "include/ComandaDAO.h"
#include "include/StatusDAO.h"
#include "include/PedidoDAO.h"


#include  <string>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    MenuPrincipal menuPrincipal = MenuPrincipal();
    menuPrincipal.menu();
    /*PedidoDAO pedidoMP = PedidoDAO();
    pedidoMP.carregarPedidos();
    StatusDAO statusMP = StatusDAO();
    statusMP.carregarStatus();
    Status statusMP2 = statusMP.getStatusByID(1);
    cout << statusMP2;
    Pedido pedido = pedidoMP.getPedidoByID(1);
    cout << pedido;
    IngredienteDAO ingredienteDAOMP = IngredienteDAO();
    ingredienteDAOMP.carregarIngredientes();
    Ingrediente ingred = ingredienteDAOMP.getIngredienteByID(2);
    cout << ingred;*/

    
}
