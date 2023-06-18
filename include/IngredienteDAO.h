#ifndef INGREDIENTEDAO_H_
#define INGREDIENTEDAO_H_

#include <iostream>
#include <vector>

#include "Ingrediente.h"

using namespace std;

class IngredienteDAO {
    private:
        vector<Ingrediente> listaIngredientes;
    public:
        IngredienteDAO();

        Ingrediente converteStringParaObjeto(string linha);

        vector<Ingrediente> carregarIngredientes();

        void salvarIngredientes();

        vector<Ingrediente> getAllIngredientes();

        void imprimirIngredientes();

        Ingrediente getIngredienteByID(unsigned long int id);

        Ingrediente getIngredienteByNome(string nome);

        bool inserirIngrediente(Ingrediente ingrediente);

        bool removerIngrediente(unsigned long int id);

        bool editarIngrediente(Ingrediente ingrediente, unsigned long int id);

};

#endif
