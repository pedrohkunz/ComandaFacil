#include <iostream>
#include "../include/MenuPrincipal.h"

using namespace std;

MenuPrincipal::MenuPrincipal(){};

void MenuPrincipal::menu(){
    unsigned short resposta;

    cout <<"\n/////////////////////////////////// Bem-vindo(a) a pizzaria LaPizza /////////////////////////////////////\n";

    cout <<"\n1- Novo pedido  |  2- Pedidos em processamento  |  3- Histórico de pedidos  |  4- Estoque\n";
    cout <<"\n* Qual atividade você deseja realizar? ";
    cin >> resposta;

    //Validação da resposta
    while(resposta != 1 && resposta != 2 && resposta != 3 && resposta != 4){
        cout <<"\nOpção inválida, por favor tente novamente: ";
        cin >> resposta;
    }

    switch (resposta)
    {
    case 1:
        cout << "Novo pedido aqui";
        break;

    case 2:
        cout << "Pedidos em processamento";
        break;

    case 3:
        cout << "Histórico de pedidos";
        break;

    case 4:
        cout << "Estoque";
        break;

    }
}
