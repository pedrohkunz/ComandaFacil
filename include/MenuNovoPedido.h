#ifndef MENUNOVOPEDIDO_H_
#define MENUNOVOPEDIDO_H_

#include <iostream>
#include <string>
#include <vector>

#include "TamanhoPizza.h"
#include "Sabor.h"
#include "Bebida.h"
#include "Pedido.h"

using namespace std;

class MenuNovoPedido {
    private:
        string nomeCliente();
        unsigned short numeroDaMesa();
        string escolherCPF();
        TamanhoPizza escolherTamanhoDaPizza();
        vector<Sabor> escolherSabores();
        Bebida escolherBebida();
        Pedido adicionarPedido();
        string formaDePagamento();

    public:
        MenuNovoPedido();
        void menu();
};

#endif
