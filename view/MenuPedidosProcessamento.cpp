#include "../include/PedidoDAO.h"
#include "../include/StatusDAO.h"
#include "../include/MenuPedidosProcessamento.h"
#include "../include/MenuPrincipal.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

MenuPedidosProcessamento::MenuPedidosProcessamento(){};
MenuPrincipal menuPrincipalMenuPP = MenuPrincipal();
PedidoDAO pedidosMenuPP = PedidoDAO();
StatusDAO statusDAOMenuPP = StatusDAO();

void MenuPedidosProcessamento::menuPedidosProcessamento(){
    cout <<"//////////////////////////////////// Menu Pedidos em Processamento ////////////////////////////////////////" << endl;

    pedidosMenuPP.carregarPedidos();
    statusDAOMenuPP.carregarStatus();
    
    Status status = statusDAOMenuPP.getStatusByID(1);
    
    cout << (pedidosMenuPP.getPedidoByStatus(status)) << endl;
    
    cout << endl
         << "1- Voltar ao menu principal  |  "
         << "2- Sair" << endl;
    unsigned short respostaMenuPP;
    cin >> respostaMenuPP;

    //Validação da resposta
    while(respostaMenuPP != 1 && respostaMenuPP != 2){
        cout <<"Opção inválida, por favor tente novamente: " << endl;
        cin >> respostaMenuPP;
        cout << endl;
    }

    switch (respostaMenuPP) {
    case 1:
        menuPrincipalMenuPP.menu();
        break;

    case 2:
        cout << "Saindo..." << endl;
        break;
    
    };
};