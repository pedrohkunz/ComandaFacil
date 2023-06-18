#ifndef LOTEDAO_H_
#define LOTEDAO_H_

#include <iostream>
#include <vector>

#include "Lote.h"
#include "IngredienteDAO.h"

using namespace std;

class LoteDAO {
    private:
        vector<Lote> listaLotes;
    public:
        LoteDAO();
        IngredienteDAO ingredientes;

        Lote converteStringParaObjeto(string linha);

        vector<Lote> carregarLotes();

        void salvarLotes();

        vector<Lote> getAllLotes();

        void imprimirLotes();

        Lote getLoteByID(unsigned long int id);

        Lote getLoteByDataValidade(string dataValidade);

        Lote getLoteByIngrediente(Ingrediente ingrediente);

        bool inserirLote(Lote lote);

        bool removerLote(unsigned long int id);

        bool editarLote(Lote lote, unsigned long int id);

};



#endif
