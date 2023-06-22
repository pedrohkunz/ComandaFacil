#ifndef MENUESTOQUE_H_
#define MENUESTOQUE_H_

#include "Ingrediente.h"

class MenuEstoque {
    public:
        MenuEstoque();
        void menuEstoque();
        void adicionarLote();
        Ingrediente adicionarLoteIngrediente();
        Ingrediente encontrarIngredientePorNome();

};

#endif
