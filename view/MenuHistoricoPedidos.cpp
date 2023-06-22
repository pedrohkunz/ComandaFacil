#include "../include/PedidoDAO.h"
#include "../include/MenuPrincipal.h"
#include "../include/MenuHistoricoPedidos.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

MenuPrincipal menuPrincipalMenuHP = MenuPrincipal();
MenuHistoricoPedidos::MenuHistoricoPedidos(){};
PedidoDAO pedidosMenuHP = PedidoDAO();

void MenuHistoricoPedidos::menuHistoricoPedidos(){
    unsigned short respostaMenuHP;

    cout <<"////////////////////////////////////// Menu Histórico de Pedidos //////////////////////////////////////////" << endl;

    cout << endl
         << "1- Ver todos os pedidos  |  "
         << "2- Voltar ao menu principal  |  "
         << "3- Sair" << endl;
    respostaMenuHP = menuPrincipalMenuHP.inputIsInt();
    cout << endl;

    //Validação da resposta
    while (respostaMenuHP != 1 && respostaMenuHP != 2 && respostaMenuHP != 3){
        cout <<"Opção inválida, por favor tente novamente: " << endl;

        respostaMenuHP = menuPrincipalMenuHP.inputIsInt();

        cout << endl;
    }

    switch (respostaMenuHP) {
    case 1:
        pedidosMenuHP.imprimirPedidosByStatus(2);
        cout << endl;
        this->menuHistoricoPedidos();
        break;

    case 2:
        menuPrincipalMenuHP.menu();
        break;

    case 3:
        cout << "Saindo..." << endl;
        break;

    };

}
