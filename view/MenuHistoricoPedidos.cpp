#include "../include/PedidoDAO.h"
#include "../include/MenuHistoricoPedidos.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

MenuHistoricoPedidos::MenuHistoricoPedidos(){};
PedidoDAO pedidosMenuHP = PedidoDAO();
int iMHP = 0;

void MenuHistoricoPedidos::menuHistoricoPedidos(){
    cout <<"////////////////////////////////////// Menu Histórico de Pedidos //////////////////////////////////////////" << endl;
    while(iMHP < 1) {
        pedidosMenuHP.carregarPedidos();
        pedidosMenuHP.imprimirPedidos(); 
        iMHP++;
    }
    cout << endl;

}
