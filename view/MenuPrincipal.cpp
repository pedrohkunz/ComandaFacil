#include <iostream>
#include <limits>
#include <string>
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
            //Garante que o valor de entrada seja um inteiro
            while (!(cin >> resposta)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada inválida. Digite o número da atividade que você deseja: ";
            }
    cout << endl;

    //Validação da resposta
    while(resposta != 1 && resposta != 2 && resposta != 3 && resposta != 4 && resposta != 5){
        cout <<"Opção inválida, por favor tente novamente: " << endl;
            //Garante que o valor de entrada seja um inteiro
            while (!(cin >> resposta)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada inválida. Digite o número da atividade que você deseja: ";
            }
        cout << endl;
    }

    switch (resposta){
    case 1:
        menuNovoPedido.menu();
        break;

    case 2:
        menuPedidosProcessamentoMenuPrincipal.menuPedidosProcessamento();
        break;

    case 3:
        menuHistoricoPedidosMenuPrincipal.menuHistoricoPedidos();
        break;

    case 4:
        menuEstoqueMenuPrincipal.menuEstoque();
        break;

    case 5:
        cout << "Saindo..." << endl;
        break;
    }

}
