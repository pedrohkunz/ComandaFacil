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

    friend ostream& operator<<(ostream& os, Pedido& objeto) {
        os << objeto.id << " | ";

          for (Pizza i : objeto.pizzas){
             os << " ( Id: " << i.getId() << ", "
                << i.getTamanho().getTamanho() << ", "
                << "Sabores: ";
                for (Sabor s : i.getSabores()){
                os << s.getNome() << " ";
                }
             os << ")  ";
          }

        os << " | ";

          for (Bebida i : objeto.bebidas){
             os << " ( Id: " << i.getId() << ", "
                << i.getTipo() << ", "
                << i.getTamanho() << " ) ";
          }

        return os;
    }
    
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