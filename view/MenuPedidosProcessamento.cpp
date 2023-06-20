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

int iMPP = 0;

void MenuPedidosProcessamento::menuPedidosProcessamento(){
    unsigned short respostaMenuPP;
    while(iMPP < 1){
        //pedidosMenuPP.carregarPedidos();
        //statusDAOMenuPP.carregarStatus();
        iMPP++;
    }

    cout <<"//////////////////////////////////// Menu Pedidos em Processamento ////////////////////////////////////////" << endl;
    
    Status status = statusDAOMenuPP.getStatusByID(1);
    
    for (Pedido p : pedidosMenuPP.getPedidosByStatus(status)){
        cout << p << endl;
    }
    
    cout << endl
         << "1- Voltar ao menu principal  |  "
         << "2- Sair" << endl;
    cin >> respostaMenuPP;
    cout << endl;

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
