#ifndef PEDIDO_H
#define PEDIDO_H

#include <iostream>
#include <fstream>
#include <iomanip>
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
        //Imprime o id e o status do pedido
        os << "Pedido n° " << objeto.id << "  |  Status: " << objeto.status.getNome() << endl;
        os << "===========================================================\n";
        
        //Imprime as pizzas
        os << "\nPizzas: " << endl;
        os << "\n";

            short contadorPizza = 1;
            for (Pizza pizza : objeto.pizzas) {
                 //Imprime o numero da pizza no pedido
                 os << "Pizza " << contadorPizza++ << " - ";

                 //Imprime o tamanho da pizza
                 os << "Tamanho: "
                   << pizza.getTamanho().getTamanho() << " - "

                 //Imprime os sabores da pizza
                 << "Sabores: ";

                //Variáveis responsáveis por descobrir o final do vetor
                unsigned short saborCount = pizza.getSabores().size();
                unsigned short saborIndice = 0;

                for (const Sabor& sabor : pizza.getSabores()) {
                    os << sabor.getNome();

                    //Garante que a virgula não será impressa na ultima volta
                    if (saborIndice != saborCount - 1) {
                      os << ", ";
                    }
                    saborIndice++;
                }
                os << "\n";
            }

            os <<"\n------------------------------------------------------------\n";

        //Imprime as bebidas
        os << "\nBebidas: " << endl;
        os << "\n";
        for (Bebida bebida : objeto.bebidas) {
            os << bebida.getTipo() << " "
               << bebida.getTamanho() << endl;
        }
        os << "\n------------------------------------------------------------\n\n\n";

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
