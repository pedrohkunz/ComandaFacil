#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include "../include/PedidoDAO.h"
#include "../include/StatusDAO.h"
#include "../include/MenuPedidosProcessamento.h"
#include "../include/MenuPrincipal.h"

using namespace std;

MenuPedidosProcessamento::MenuPedidosProcessamento(){};
MenuPrincipal menuPrincipalProcessamento = MenuPrincipal();
PedidoDAO pedidosDAO = PedidoDAO();
StatusDAO statusDAO = StatusDAO();


void MenuPedidosProcessamento::menuPedidosProcessamento(){
    unsigned short respostaMenu;

    cout <<"//////////////////////////////////// Pedidos em Processamento ////////////////////////////////////////\n" << endl;

    pedidosDAO.imprimirPedidosByStatus(1);

    cout << endl
         << "1- Voltar ao menu principal  |  "
         << "2- Sair" << endl;

    respostaMenu = menuPrincipalProcessamento.inputIsInt();

    cout << endl;

    //Validação da resposta
    while(respostaMenu != 1 && respostaMenu != 2){
        cout <<"Opção inválida, por favor tente novamente: " << endl;

        respostaMenu = menuPrincipalProcessamento.inputIsInt();

        cout << endl;
    }

    switch (respostaMenu) {
    case 1:
        menuPrincipalProcessamento.menu();
        break;

    case 2:
        cout << "Saindo..." << endl;
        break;

    };
};
