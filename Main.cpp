#include <iostream>
#include <windows.h>
/*

#include "include/IngredienteDAO.h"
#include "include/LoteDAO.h"
#include "include/TamanhoPizza.h"
#include "include/MenuPrincipal.h"
#include "include/UsuarioDAO.h"
#include "include/TamanhoPizzaDAO.h"
#include "include/SaborDAO.h"
#include "include/PizzaDAO.h"
#include "include/BebidaDAO.h"*/
#include "include/ComandaDAO.h"

#include "include/PedidoDAO.h"


#include  <string>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    /*MenuPrincipal menuPrincipal = MenuPrincipal();

    // testando imprimir ingredientes
    IngredienteDAO ingredientes = IngredienteDAO();
    ingredientes.carregarIngredientes();
    ingredientes.imprimirIngredientes();

    // testando imprimir sabores
    SaborDAO sabor = SaborDAO();
    sabor.carregarSabores();
    sabor.imprimirSabores();
   
    // testando imprimir  lotes 
    LoteDAO lote = LoteDAO();
    lote.carregarLotes();
    lote.imprimirLotes();

    // testando imprimir bebidas
    BebidaDAO bebida = BebidaDAO();
    bebida.carregarBebidas();
    bebida.imprimirBebidas();
    
    // testando imprimir tamanhos
    TamanhoPizzaDAO tamanho = TamanhoPizzaDAO();
    tamanho.carregarTamanhos();
    tamanho.imprimirTamanhos();

    // testando imprimir usuarios
    UsuarioDAO usuario = UsuarioDAO();
    usuario.carregarUsuarios();
    usuario.imprimirUsuarios();
   
    // testando imprimir pizzas   
    PizzaDAO pizza = PizzaDAO();
    pizza.carregarPizzas();
    pizza.imprimirPizzas();
    
    // testando imprimir pedidos
    PedidoDAO pedido = PedidoDAO();
    pedido.carregarPedidos();
    pedido.imprimirPedidos();*/
    
    ComandaDAO comanda = ComandaDAO();
    comanda.carregarComandas();
    comanda.imprimirComandas();
}
