#ifndef COMANDADAO_H
#define COMANDADAO_H

#include <fstream>
#include <string>
#include <vector>
#include "Pedido.h"
#include "Comanda.h"

using namespace std;

class ComandaDAO{
  private:
        vector<Comanda> listaComandas;

    public:
        ComandaDAO();

        Comanda converteStringParaObjeto(string linha);

        vector<Comanda> carregarComandas();

        void salvarComandas();

        vector<Comanda> getAllComandas();

        void imprimirComandas();

        Comanda getComandaByID(unsigned long int id);

        Comanda getComandaByNumeroMesa(unsigned long int numeroMesa);

        vector<Comanda> getComandasByUsuario(unsigned long int idUsuario);

        Comanda getComandaByPedido(unsigned long int idPedido);

        bool inserirComanda(Comanda comanda);

        bool removerComanda(unsigned long int id);

        bool editarComanda(Comanda comanda, unsigned long int id);

};

#endif 