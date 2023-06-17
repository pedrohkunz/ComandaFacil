#ifndef PEDIDO_H
#define PEDIDO_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Pizza.h"
#include "Bebida.h"

using namespace std;

class Pedido{
  private:
    unsigned long int id;
    vector<Pizza> pizzas;
    vector<Bebida> bebidas;
    
  public:
    Pedido(unsigned long int id, vector<Pizza> pizzas, vector<Bebida> bebidas);
    Pedido();

    unsigned long int getId();

    vector<Pizza> getPizzas();
    void setPizzas(vector<Pizza> pizzas);

    vector<Bebida> getBebidas();
    void setBebidas(vector<Bebida> bebidas);

};

#endif