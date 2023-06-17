#include <iostream>
#include "../include/MenuPrincipal.h"

using namespace std;

MenuPrincipal::MenuPrincipal(){};

void MenuPrincipal::menu(){
    unsigned short resposta;

    cout <<"/////////////////////////////////// Bem-vindo(a) à pizzaria LaPizza /////////////////////////////////////" << endl;

    cout <<"1- Novo pedido  |  2- Pedidos em processamento  |  3- Histórico de pedidos  |  4- Estoque" << endl;
    cout <<"Qual atividade você deseja realizar? " << endl;
    cin >> resposta;

    //Validação da resposta
    while(resposta != 1 && resposta != 2 && resposta != 3 && resposta != 4){
        cout <<"Opção inválida, por favor tente novamente: " << endl;
        cin >> resposta;
    }

    switch (resposta)
    {
    case 1:
        cout << "Novo pedido aqui" << endl;
        break;

    case 2:
        cout << "Pedidos em processamento" << endl;
        break;

    case 3:
        cout << "Histórico de pedidos" << endl;
        break;

    case 4:
        cout << "Estoque" << endl;
        break;

    }
}
