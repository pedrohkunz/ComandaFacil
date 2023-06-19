#ifndef PEDIDO_H
#define PEDIDO_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Pizza.h"
#include "Bebida.h"
#include "Status.h"

using namespace std;

class Pedido{
  private:
    unsigned long int id;
    Status status;
    vector<Pizza> pizzas;
    vector<Bebida> bebidas;

    friend ostream& operator<<(ostream& os, const Pedido& objeto) {
        os << objeto.id << " | "
           << objeto.status.getNome() << " | " ;

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
    Pedido(unsigned long int id, Status status, vector<Pizza> pizzas, vector<Bebida> bebidas);
    Pedido();

    unsigned long int getId();
    void setId(unsigned long int id);

    Status getStatus();
    void setStatus(Status status);

    vector<Pizza> getPizzas();
    void setPizzas(vector<Pizza> pizzas);

    vector<Bebida> getBebidas();
    void setBebidas(vector<Bebida> bebidas);

};

#endif