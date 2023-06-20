#ifndef PEDIDODAO_H
#define PEDIDODAO_H

#include <fstream>
#include <string>
#include <vector>
#include "Pedido.h"

using namespace std;

class PedidoDAO{
  private:
        vector<Pedido> listaPedidos;

    public:
        PedidoDAO();

        Pedido converteStringParaObjeto(string linha);

        vector<Pedido> carregarPedidos();

        void salvarPedidos();

        vector<Pedido> getAllPedidos();

        void imprimirPedidos();

        Pedido getPedidoByID(unsigned long int id);

        vector<Pedido> getPedidosByStatus(Status status);

        vector<Pedido> getPedidosByPizza(unsigned long int idPizza);

        vector<Pedido> getPedidosByBebida(unsigned long int idBebida);

        bool inserirPedido(Pedido pedido);

        bool removerPedido(unsigned long int id);

        bool editarPedido(Pedido pedido, unsigned long int id);

};

#endif 