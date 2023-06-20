#include "../include/PedidoDAO.h"
#include "../include/MenuPrincipal.h"
#include "../include/MenuHistoricoPedidos.h"
#include "../include/MenuHistoricoPedidosBuscar.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

MenuPrincipal menuPrincipalMenuHP = MenuPrincipal();
MenuHistoricoPedidosBuscar menuHPB = MenuHistoricoPedidosBuscar();
MenuHistoricoPedidos::MenuHistoricoPedidos(){};
PedidoDAO pedidosMenuHP = PedidoDAO();
int iMHP = 0;

void MenuHistoricoPedidos::menuHistoricoPedidos(){
    unsigned short respostaMenuHP;
    
    while (iMHP < 1) {
        //pedidosMenuHP.carregarPedidos();
        iMHP++;
    }

    cout <<"////////////////////////////////////// Menu Histórico de Pedidos //////////////////////////////////////////" << endl;

    cout << endl
         << "1- Ver todos os pedidos  |  "
         << "2- Buscar  |  "
         << "3- Voltar ao menu principal  |  "
         << "4- Sair" << endl;
    cin >> respostaMenuHP;
    cout << endl;

    //Validação da resposta
    while (respostaMenuHP != 1 && respostaMenuHP != 2 && respostaMenuHP != 3 && respostaMenuHP != 4){
        cout <<"Opção inválida, por favor tente novamente: " << endl;
        cin >> respostaMenuHP;
        cout << endl;
    }

    switch (respostaMenuHP) {
    case 1:
        pedidosMenuHP.imprimirPedidos();
        cout << endl;
        this->menuHistoricoPedidos();
        break;

    case 2:
        menuHPB.menuHistoricoPedidosBuscar();
        break;
    
    case 3:
        menuPrincipalMenuHP.menu();
        break;
    
    case 4:
        cout << "Saindo..." << endl;
        break;
    
    };

}