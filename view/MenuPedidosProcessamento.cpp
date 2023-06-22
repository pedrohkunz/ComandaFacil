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
    unsigned short respostaMenu, idPedido, idStatus;
    Pedido pedidoProc;
    Status statusProc;

    cout <<"//////////////////////////////////// Pedidos em Processamento ////////////////////////////////////////\n" << endl;

    pedidosDAO.imprimirPedidosByStatus(1);

    cout << endl
         << "1- Alterar o status do pedido  |  "
         << "2- Voltar ao menu principal  |  "
         << "3- Sair" << endl;

    respostaMenu = menuPrincipalProcessamento.inputIsInt();

    cout << endl;

    //Validação da resposta
    while(respostaMenu != 1 && respostaMenu != 2 && respostaMenu != 3){
        cout <<"Opção inválida, por favor tente novamente: " << endl;

        respostaMenu = menuPrincipalProcessamento.inputIsInt();

        cout << endl;
    }

    switch (respostaMenu) {
    case 1:
        cout << "Digite o ID do pedido: " << endl;
        cin >> idPedido;
        cout << endl;
        pedidoProc = pedidosDAO.getPedidoByID(idPedido);

        statusDAO.imprimirStatus();

        cout << "Digite o ID do novo status do pedido: " << endl;
        cin >> idStatus;
        cout << endl;
        statusProc = statusDAO.getStatusByID(idStatus);

        pedidoProc.setStatus(statusProc);
        pedidosDAO.removerPedido(idPedido);
        pedidosDAO.inserirPedido(pedidoProc);
        
        cout << "Status alterado com sucesso" << endl;
        menuPedidosProcessamento();
        break;

    case 2:
        menuPrincipalProcessamento.menu();
        break;

    case 3:
        cout << "Saindo..." << endl;
        break;

    };
};
