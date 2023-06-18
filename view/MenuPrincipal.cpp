#include <iostream>
#include "../include/MenuPrincipal.h"
#include "../include/MenuEstoque.h"
#include "../include/MenuNovoPedido.h"

using namespace std;

MenuPrincipal::MenuPrincipal(){};
MenuEstoque menuEstoqueMenuPrincipal = MenuEstoque();
MenuNovoPedido menuNovoPedido = MenuNovoPedido();

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
         
    cout <<"Qual atividade você deseja realizar? ";
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
        cout << "Pedidos em processamento" << endl;
        this->menu();
        break;

    case 3:
        cout << "Histórico de pedidos" << endl;
        this->menu();
        break;

    case 4:
        menuEstoqueMenuPrincipal.menuEstoque();
        this->menu();
        break;

    case 5:
        break;
    }

}
