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
    //MenuPrincipal menuPrincipal = MenuPrincipal();
    //menuPrincipal.menu();
    PedidoDAO pedido = PedidoDAO();
    pedido.carregarPedidos();
    pedido.imprimirPedidos();
    
    
}
