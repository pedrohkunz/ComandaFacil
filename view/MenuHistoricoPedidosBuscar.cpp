#include "../include/Pedido.h"
#include "../include/PedidoDAO.h"
#include "../include/PizzaDAO.h"
#include "../include/BebidaDAO.h"
#include "../include/StatusDAO.h"
#include "../include/MenuHistoricoPedidosBuscar.h"
#include "../include/MenuHistoricoPedidos.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

MenuHistoricoPedidosBuscar::MenuHistoricoPedidosBuscar(){};
MenuHistoricoPedidos menuHistoricoPedidosMenuHPB = MenuHistoricoPedidos();
PizzaDAO pizzasMenuHPB = PizzaDAO();
BebidaDAO bebidasMenuHPB = BebidaDAO();
PedidoDAO pedidosMenuHPB = PedidoDAO();
StatusDAO statusMenuHPB = StatusDAO();
int iMHPB = 0;

void MenuHistoricoPedidosBuscar::menuHistoricoPedidosBuscar(){
  unsigned short resposta;
  while(iMHPB < 1) {
    //pedidosMenuHPB.carregarPedidos();
    //pizzasMenuHPB.carregarPizzas();
   // bebidasMenuHPB.carregarBebidas();
    //statusMenuHPB.carregarStatus();
    iMHPB++;
  }

  cout <<"////////////////////////////////////// Menu Histórico de Pedidos | Buscar //////////////////////////////////////////" << endl;

  cout << "1- Filtrar Pedidos  |  "
       << "2- Buscar por ID  |  "
       << "3- Buscar por status  |  "
       << "4- Voltar  |  "
       << "5- Sair" << endl
       << "Qual atividade você deseja realizar?" << endl;

  cin >> resposta;
  cout << endl;

  // Validação da resposta
  while (resposta != 1 && resposta != 2 && resposta != 3 && resposta != 4 && resposta != 5) {
    cout << "Opção inválida, por favor tente novamente: " << endl;
    cin >> resposta;
    cout << endl;
  }

  switch (resposta) {
  case 1:
    filtrar();
    this->menuHistoricoPedidosBuscar();
    break;


  case 2:
    buscarPorId();
    this->menuHistoricoPedidosBuscar();
    break;


  case 3:
    buscarPorStatus();
    this->menuHistoricoPedidosBuscar();
    break;

  case 4:
    menuHistoricoPedidosMenuHPB.menuHistoricoPedidos();
    break;

  case 5:
    cout << "Saindo..." << endl;
    break;

  }
}


void MenuHistoricoPedidosBuscar::filtrar(){

};


void MenuHistoricoPedidosBuscar::buscarPorId(){
    unsigned long int id;
    cout << "Digite o ID: " << endl;
    cin >> id;
    cout << endl;
    cout << (pedidosMenuHPB.getPedidoByID(id)) << endl;

};


void MenuHistoricoPedidosBuscar::buscarPorStatus(){
    unsigned short idStatus;
    cout << "Status: " << endl;
    statusMenuHPB.imprimirStatus();

    cout << "Digite o ID do status desejado: " << endl;
    cin >> idStatus;
    cout << endl;

    // Validação da resposta
        while (idStatus != 1 && idStatus != 2) {
            cout << "Opção inválida, por favor tente novamente: " << endl;
            cin >> idStatus;
            cout << endl;
        }

    for (Pedido p : pedidosMenuHPB.getPedidosByStatus(idStatus)){
        cout << p << endl;
    }

};
