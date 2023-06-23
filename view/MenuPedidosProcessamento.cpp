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

void alterarStatusPedido(){
        unsigned short idPedido;

        cout << "Digite o ID do pedido: ";

        idPedido = menuPrincipalProcessamento.inputIsInt();

        cout << endl;

        bool encontrou = false;
        while(!encontrou){
            for(Pedido pedido : pedidosDAO.getPedidosByStatus(1)){
                if(pedido.getId() == idPedido){
                    pedidosDAO.editarPedido(Pedido(pedido.getId(), statusDAO.getStatusByID(2), pedido.getPizzas(), pedido.getBebidas()), pedido.getId());
                    encontrou = true;
                    break;
                }
            }

            if(!encontrou){
                cout << "Pedido não encontrado, digite um ID válido: ";
                idPedido = menuPrincipalProcessamento.inputIsInt();
            }
        }

        cout << "Status alterado com sucesso!\n" << endl;
}


void MenuPedidosProcessamento::menuPedidosProcessamento(){
    unsigned short respostaMenu, idStatus;
    Pedido pedidoProc;
    Status statusProc;

    cout <<"//////////////////////////////////// Pedidos em Processamento ////////////////////////////////////////\n" << endl;

    pedidosDAO.imprimirPedidosByStatus(1);

    cout << endl
         << "1- Concluir pedido  |  "
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
        if(!pedidosDAO.getPedidosByStatus(1).empty()){
            alterarStatusPedido();
        } 

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
