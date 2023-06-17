#ifndef PIZZADAO_H_
#define PIZZADAO_H_

#include <iostream>
#include <vector>

#include "Pizza.h"

using namespace std;

class PizzaDAO {
    private:
        vector<Pizza> listaPizzas;

    public:
        PizzaDAO();

        Pizza converteStringParaObjeto(string linha);

        vector<Pizza> carregarPizzas();

        void salvarPizzas();

        vector<Pizza> getAllPizzas();

        Pizza getPizzaByID(unsigned long int id);

        bool inserirPizza(Pizza pizza);

        bool removerPizza(unsigned long int id);

        bool editarPizza(Pizza pizza, unsigned long int id);

};

#endif