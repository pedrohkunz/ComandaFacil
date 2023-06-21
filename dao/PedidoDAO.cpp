#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

#include "../include/PedidoDAO.h"
#include "../include/Pedido.h"
#include "../include/PizzaDAO.h"
#include "../include/Pizza.h"
#include "../include/BebidaDAO.h"
#include "../include/Bebida.h"
#include "../include/StatusDAO.h"
#include "../include/Status.h"


PizzaDAO pizzasDAOped = PizzaDAO();
BebidaDAO bebidasDAOped = BebidaDAO();
StatusDAO statusDAOped = StatusDAO();

//Construtor vazio
PedidoDAO::PedidoDAO(){};

//Métodos que acessam diretamente o arquivo txt

Pedido PedidoDAO::converteStringParaObjeto(string a){
   int contador = 0, contadorSharp = 0;
    string idString, statusString, pizzas, bebidas;

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
            statusString = atributo;
      } else if (contadorSharp == 2) {
            pizzas = atributo;
      } else if (contadorSharp == 3) {
            bebidas = atributo;
      }

      contadorSharp++;
      contador++;

      if (contadorSharp >= 4) {
        break;
      }
    }

    //Converte o idString para id inteiro
    unsigned long int id = stoi(idString);
    unsigned long int idStatus = stoi(statusString);
    Status status = statusDAOped.getStatusByID(idStatus);

    //Transforma a string pizzas em um vetor novamente
    int count = 0, contadorPorcentagem = 0;
    vector<Pizza> vetorPizzas;

    while (count < pizzas.size()) {
        vector<char> vti;
        while (count < pizzas.size() && pizzas[count] != '%') {
            vti.push_back(pizzas[count]);
            count++;
        }

        string pizString(vti.data(), vti.size());
        unsigned long int pizId = stoi(pizString);
        Pizza piz;

        // Percorre o vetor de pizzas e procura a pizza com o id correspondente ao pizId
        // Se encontrado, a pizza é armazenada na variável piz
        for (Pizza pizza : pizzasDAOped.getAllPizzas()) {
            if (pizId == pizza.getId()) {
                piz = pizza;
                break;
            }
        }

        vetorPizzas.push_back(piz);

        count++;
    }

    //Transforma a string bebidas em um vetor novamente
    count = 0;
    vector<Bebida> vetorBebidas;

    while (count < bebidas.size()) {
        vector<char> vti;
        while (count < bebidas.size() && bebidas[count] != '%') {
            vti.push_back(bebidas[count]);
            count++;
        }

        string bebString(vti.data(), vti.size());
        unsigned long int bebId = stoi(bebString);
        Bebida beb;

        // Percorre o vetor de bebidas e procura a bebida com o id correspondente ao bebId
        // Se encontrado, a bebida é armazenada na variável beb
        for (Bebida bebida : bebidasDAOped.getAllBebidas()) {
            if (bebId == bebida.getId()) {
                beb = bebida;
                break;
            }
        }

        vetorBebidas.push_back(beb);

        count++;
    }

    auto x = Pedido(id, status, vetorPizzas, vetorBebidas);
    return x;
};


vector<Pedido> PedidoDAO::carregarPedidos(){
  fstream arquivo("database/pedidos.txt");

  string linha;

  if (arquivo.is_open()) {
    while (getline(arquivo, linha)) {
      if(!linha.empty()){
        Pedido i = converteStringParaObjeto(linha);
        bool pedidoRepetido = false;

        // Verificar se o pedido já está na lista
        for (Pedido pedido : listaPedidos) {
          if (pedido.getId() == i.getId()) {
            pedidoRepetido = true;
            break;
          }
        }

        // Adicionar o pedido apenas se não estiver repetido
        if (!pedidoRepetido) {
          listaPedidos.push_back(i);
        }
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
            // Transforma o vetor de pizzas em linha
            string pizzasEmLinha;
            vector<Pizza> pizzas = pedido.getPizzas();
            for (int i = 0; i < pizzas.size(); i++) {
                pizzasEmLinha += to_string(pizzas[i].getId());

                if (i != pedido.getPizzas().size() - 1) {
                    pizzasEmLinha += "%";
                }
            }
            // Transforma o vetor de bebidas em linha
            string bebidasEmLinha;
            vector<Bebida> bebidas = pedido.getBebidas();
            for (int i = 0; i < bebidas.size(); i++) {
                bebidasEmLinha += to_string(bebidas[i].getId());

                if (i != pedido.getBebidas().size() - 1) {
                    bebidasEmLinha += "%";
                }
            }

            arquivo << to_string(pedido.getId()) << "#"
                    << to_string(pedido.getStatus().getId()) << "#"
                    << pizzasEmLinha << "#"
                    << bebidasEmLinha;
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo." << endl;
    }
};


//Métodos de manipulação de dados

vector<Pedido> PedidoDAO::getAllPedidos(){
    carregarPedidos();
    return listaPedidos;
};


void PedidoDAO::imprimirPedidos(){

};

void PedidoDAO::imprimirPedidosByStatus(unsigned short statusID){
    carregarPedidos();

    for (Pedido pedido : getPedidosByStatus(statusID)) {
        cout << pedido;
    }
};


Pedido PedidoDAO::getPedidoByID(unsigned long int id){
    carregarPedidos();
    bool encontrou = false;
    for(Pedido pedido : listaPedidos){
        if(pedido.getId() == id){
            encontrou = true;
            return pedido;
            break;
        }
    }
    if(encontrou == false) {
        cout << "Erro: ID Pedido não encontrado." << endl;
    }
}


vector<Pedido> PedidoDAO::getPedidosByStatus(unsigned short statusID){
    carregarPedidos();
    bool encontrou = false;
    vector<Pedido> pedidos;

    for (Pedido p : listaPedidos){
        if (p.getStatus().getId() == statusID){
            encontrou = true;
            pedidos.push_back(p);
        }
    }

    cout << endl;
    if (!encontrou) {
        cout << "Erro: Status Pedido não encontrado." << endl;
    } else {
         return pedidos;
    }
}


vector<Pedido> PedidoDAO::getPedidosByPizza(unsigned long int idPizza){
    carregarPedidos();
    bool encontrou = false;
    vector<Pedido> pedidos;

    for (Pedido p : listaPedidos){
        for (Pizza pz : p.getPizzas()){
            if (pz.getId() == idPizza){
                encontrou = true;
                pedidos.push_back(p);
            }
        }
    }

    return pedidos;
    cout << endl;

    if (encontrou == false) {
        cout << "Erro: Pizza Pedido não encontrado." << endl;
    }
}


vector<Pedido> PedidoDAO::getPedidosByBebida(unsigned long int idBebida){
    carregarPedidos();
    bool encontrou = false;
    vector<Pedido> pedidos;

    for (Pedido p : listaPedidos){
        for (Bebida b : p.getBebidas()){
            if (b.getId() == idBebida){
                encontrou = true;
                pedidos.push_back(p);
            }
        }
    }
    return pedidos;
    cout << endl;
    if (encontrou == false) {
        cout << "Erro: Bebida Pedido não encontrada." << endl;
    }
}


bool PedidoDAO::inserirPedido(Pedido pedido){
    carregarPedidos();
    listaPedidos.push_back(pedido);
    salvarPedidos();
    return true;
};


bool PedidoDAO::removerPedido(unsigned long int id){
    carregarPedidos();
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
    carregarPedidos();
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
