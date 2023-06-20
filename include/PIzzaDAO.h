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

        void imprimirPizzas();

        Pizza getPizzaByID(unsigned long int id);

        vector<Pizza> getPizzasByTamanho(unsigned long int idTamanho);

        vector<Pizza> getPizzasBySabor(unsigned long int idSabor);

        bool inserirPizza(Pizza pizza);

        bool removerPizza(unsigned long int id);

        bool editarPizza(Pizza pizza, unsigned long int id);

};

#endif