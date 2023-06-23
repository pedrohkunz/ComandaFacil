#include <iostream>
#include <limits>
#include <string>
#include "../include/MenuLogin.h"
#include "../include/MenuPrincipal.h"
#include "../include/MenuNovoPedido.h"
#include "../include/MenuGerenciarComandas.h"
#include "../include/MenuPedidosProcessamento.h"
#include "../include/MenuHistoricoPedidos.h"
#include "../include/MenuEstoque.h"

using namespace std;

MenuPrincipal::MenuPrincipal(){};
MenuNovoPedido menuNovoPedido = MenuNovoPedido();
MenuGerenciarComandas menuGerenciarComandasMenuPrincipal = MenuGerenciarComandas();
MenuPedidosProcessamento menuPedidosProcessamentoMenuPrincipal= MenuPedidosProcessamento();
MenuHistoricoPedidos menuHistoricoPedidosMenuPrincipal= MenuHistoricoPedidos();
MenuEstoque menuEstoqueMenuPrincipal = MenuEstoque();


unsigned short MenuPrincipal::inputIsInt(){
    unsigned short resposta;
    while (!(cin >> resposta)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada inválida. Digite um número por favor: ";
        this->inputIsInt();
    }

    return resposta;
}

void MenuPrincipal::menu(){
    unsigned short resposta;

    cout << endl;
    cout <<"///////////////////////////////////// Bem-vindo(a) à pizzaria LaPizza /////////////////////////////////////" << endl;
    cout <<"//////////////////////////////////////////// Menu Principal ///////////////////////////////////////////////" << endl;

    cout << endl
         << "1- Novo pedido  |  "
         << "2- Gerenciar comandas  |  "
         << "3- Pedidos em processamento  |  "
         << "4- Histórico de pedidos  |  "
         << "5- Estoque  |  "
         << "6- Sair" << endl;

    cout <<"Qual atividade você deseja realizar? " << endl;
    resposta = inputIsInt();

    cout << endl;

    //Validação da resposta
    while(resposta != 1 && resposta != 2 && resposta != 3 && resposta != 4 && resposta != 5 && resposta != 6){
        cout << "Opção inválida, por favor tente novamente: " << endl;
        resposta = inputIsInt();
        cout << endl;
    }

    switch (resposta){
    case 1:
        menuNovoPedido.menu();
        break;

    case 2:
        menuGerenciarComandasMenuPrincipal.menuGerenciarComandas();
        break;

    case 3:
        menuPedidosProcessamentoMenuPrincipal.menuPedidosProcessamento();
        break;

    case 4:
        menuHistoricoPedidosMenuPrincipal.menuHistoricoPedidos();
        break;

    case 5:
        menuEstoqueMenuPrincipal.menuEstoque();
        break;

    case 6:
        cout << "Saindo..." << endl;
        break;
    }

}
