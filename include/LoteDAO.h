#ifndef LOTEDAO_H_
#define LOTEDAO_H_

#include <iostream>
#include <vector>

#include "Lote.h"

using namespace std;

class LoteDAO {
    private:
        vector<Lote> listaLotes;
    public:
        LoteDAO();

        Lote converteStringParaObjeto(string linha);

        vector<Lote> carregarLotes();

        void salvarLotes();

        vector<Lote> getAllLotes();

        Lote getLoteByID(unsigned long int id);

        bool inserirLote(Lote lote);

        bool removerLote(unsigned long int id);

        bool editarLote(Lote lote, unsigned long int id);

};



#endif
