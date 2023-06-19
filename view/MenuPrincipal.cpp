#include <iostream>
#include "../include/MenuPrincipal.h"
#include "../include/MenuEstoque.h"
#include "../include/MenuHistoricoPedidos.h"
#include "../include/MenuPedidosProcessamento.h"
#include "../include/MenuNovoPedido.h"
#include "../include/PedidoDAO.h"

using namespace std;

MenuPrincipal::MenuPrincipal(){};
MenuEstoque menuEstoqueMenuPrincipal = MenuEstoque();
MenuNovoPedido menuNovoPedido = MenuNovoPedido();
MenuHistoricoPedidos menuHistoricoPedidosMenuPrincipal= MenuHistoricoPedidos();
MenuPedidosProcessamento menuPedidosProcessamentoMenuPrincipal= MenuPedidosProcessamento();
PedidoDAO pedidoDaoMenuPrincipal = PedidoDAO();

void MenuPrincipal::menu(){
    unsigned short resposta;

    cout << endl;
    cout <<"///////////////////////////////////// Bem-vindo(a) à pizzaria LaPizza /////////////////////////////////////" << endl;
    cout <<"//////////////////////////////////////////// Menu Principal ///////////////////////////////////////////////" << endl;

    cout << endl
         << "1- Novo pedido  |  "
         << "2- Pedidos em processamento  |  "
         << "3- Histórico de pedidos  |  "
         << "4- Estoque  |  "
         << "5- Sair" << endl;
         
    cout <<"Qual atividade você deseja realizar? " << endl;
    cin >> resposta;                                                                                     
    cout << endl;

    //Validação da resposta
    while(resposta != 1 && resposta != 2 && resposta != 3 && resposta != 4 && resposta != 5){
        cout <<"Opção inválida, por favor tente novamente: " << endl;
        cin >> resposta;
        cout << endl;
    }

    switch (resposta)
    {
    case 1:
        menuNovoPedido.menu();
        this->menu();
        break;

    case 2:
        menuPedidosProcessamentoMenuPrincipal.menuPedidosProcessamento();
        break;

    case 3:
        menuHistoricoPedidosMenuPrincipal.menuHistoricoPedidos();
        this->menu();
        break;

    case 4:
        menuEstoqueMenuPrincipal.menuEstoque();
        break;

    case 5:
        cout << "Saindo..." << endl;
        break;
    }

}
