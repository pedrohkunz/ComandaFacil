#ifndef COMANDA_H
#define COMANDA_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Pedido.h"
#include "Usuario.h"

using namespace std;

class Comanda{
private:
    unsigned long int id;
    short int formaPagamento;
    Usuario usuario;
    vector<Pedido> pedidos;

public:
    Comanda(unsigned long int id, short int formaPagamento, Usuario usuario, vector<Pedido> pedidos);
    Comanda();

    unsigned long int getId();

    short int getFormaPagamento();
    void setFormaPagamento(short int formaPagamento);
    
    Usuario getUsuario();
    void setUsuario(Usuario usuario);

    vector<Pedido> getPedidos();
    void setPedidos(vector<Pedido> pedidos);

};

#endif