#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/PedidoDAO.h"
#include "../include/Pedido.h"
#include "../include/PizzaDAO.h"
#include "../include/Pizza.h"
#include "../include/BebidaDAO.h"
#include "../include/Bebida.h"


PizzaDAO pizzasDAO = PizzaDAO();
BebidaDAO bebidasDAO = BebidaDAO();

//Construtor vazio
PedidoDAO::PedidoDAO(){};

//Métodos que acessam diretamente o arquivo txt

Pedido PedidoDAO::converteStringParaObjeto(string a){
   int contador = 0, contadorSharp = 0;
    string idString, pizzas, bebidas;

    for (int i = 0; i < a.size(); i++) {
      vector<char> vt;

      while (contador < a.size() && a[contador] != '#') {
        vt.push_back(a[contador]);
        contador++;
      }

      // Converter vetor de char para string correspondente
      string atributo(vt.data(), vt.size());

      if (contadorSharp == 0) {
            idString = atributo;
      } else if (contadorSharp == 1) {
            pizzas = atributo;
      } else if (contadorSharp == 2) {
            bebidas = atributo;
      }

      contadorSharp++;
      contador++;

      if (contadorSharp >= 3) {
        break;
      }
    }

    //Converte o idString para id inteiro
    unsigned long int id = stoi(idString);

    //Transforma a string pizzas em um vetor novamente
    int count = 0, contadorPorcentagem = 0;
    vector<Pizza> vetorPizzas;

    for (int i = 0; i < pizzas.size(); i++) {
        vector<char> vti;
        while (count < pizzas.size() && pizzas[count] != '%') {
            vti.push_back(pizzas[count]);
            count++;
        }

        string pedString(vti.data(), vti.size());
        int pedId = stoi(pedString);
        Pizza piz;

        for(Pizza pizza : pizzasDAO.getAllPizzas()){
            if(pedId == pizza.getId()){
                piz = pizza;
                break;
            }
        };

        vetorPizzas.push_back(piz);
    }

    //Transforma a string bebidas em um vetor novamente
    count = 0;
    contadorPorcentagem = 0;
    vector<Bebida> vetorBebidas;

    for (int i = 0; i < bebidas.size(); i++) {
        vector<char> vti;
        while (count < bebidas.size() && bebidas[count] != '%') {
            vti.push_back(bebidas[count]);
            count++;
        }

        string bebString(vti.data(), vti.size());
        int bebId = stoi(bebString);
        Bebida beb;

        for(Bebida bebida : bebidasDAO.getAllBebidas()){
            if(bebId == bebida.getId()){
                beb = bebida;
                break;
            }
        };

        vetorBebidas.push_back(beb);
    }

    auto x = Pedido(id, vetorPizzas, vetorBebidas);
    return x;
};


vector<Pedido> PedidoDAO::carregarPedidos(){
  fstream arquivo("database/pedidos.txt");

  string linha;

  if (arquivo.is_open()) {
    while (getline(arquivo, linha)) {
      if(!linha.empty()){
        Pedido i = converteStringParaObjeto(linha);
        listaPedidos.push_back(i);
      }
    }

  } else {
      cout << "Erro ao abrir o arquivo." << endl;
  }

  arquivo.close();

  return listaPedidos;
};


void PedidoDAO::salvarPedidos(){
    ofstream arquivo("database/pedidos.txt");
    if (arquivo.is_open()) {
        for (Pedido pedido : listaPedidos) {
            arquivo << to_string(pedido.getId()) << "#";
                    //salvar vetor de pizzas e bebidas
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo." << endl;
    }
};


//Métodos de manipulação de dados

vector<Pedido> PedidoDAO::getAllPedidos(){
    return listaPedidos;
};


Pedido PedidoDAO::getPedidoByID(unsigned long int id){
    for(Pedido pedido : listaPedidos){
        if(pedido.getId() == id){
            return pedido;
            break;
        }
    }
}


bool PedidoDAO::inserirPedido(Pedido pedido){
    listaPedidos.push_back(pedido);
    salvarPedidos();
    return true;
};


bool PedidoDAO::removerPedido(unsigned long int id){
    auto i = listaPedidos.begin();
    bool apagou = false;
    while (i != listaPedidos.end()) {
        if (i->getId() == id) {
            i = listaPedidos.erase(i);
            apagou = true;
            break;
        } else {
            i++;
        }
    }

    salvarPedidos();

    return apagou;
}


bool PedidoDAO::editarPedido(Pedido pedido, unsigned long int id){
    bool encontrou = false;
    for(Pedido& i : listaPedidos){
        if(i.getId() == id){
            i = pedido;
            encontrou = true;
            break;
        }
    }

    salvarPedidos();
    return encontrou;
};
