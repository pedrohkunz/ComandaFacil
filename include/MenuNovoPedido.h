#ifndef MENUNOVOPEDIDO_H_
#define MENUNOVOPEDIDO_H_

#include <iostream>
#include <string>
#include <vector>

#include "TamanhoPizza.h"
#include "Sabor.h"
#include "Bebida.h"
#include "Pedido.h"
#include "Pizza.h"

using namespace std;

class MenuNovoPedido {
    private:
        string nomeCliente();
        unsigned short numeroDaMesa();
        string escolherCPF();
        TamanhoPizza escolherTamanhoDaPizza();
        vector<Sabor> escolherSabores();
        Sabor verificarSabor(unsigned short id);
        Bebida escolherBebida();
        Pedido adicionarPedido();
        string formaDePagamento();
        Pizza novaPizza();
        void menuNovaComanda();

    public:
        MenuNovoPedido();
        void menu();
};

#endif
