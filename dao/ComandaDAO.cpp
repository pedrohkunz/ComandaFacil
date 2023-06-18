#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/ComandaDAO.h"
#include "../include/Comanda.h"
#include "../include/PedidoDAO.h"
#include "../include/Pedido.h"
#include "../include/UsuarioDAO.h"
#include "../include/Usuario.h"

using namespace std;

//Construtor vazio
ComandaDAO::ComandaDAO(){};

UsuarioDAO usuariosDAO = UsuarioDAO();
PedidoDAO pedidosDAO = PedidoDAO();

//Métodos que acessam diretamente o arquivo pedidos.txt

Comanda ComandaDAO::converteStringParaObjeto(string a){
   int contador = 0, contadorSharp = 0;
    string idString, formaPagamentoString, idUsuarioString, pedidos;
    pedidosDAO.carregarPedidos();
    usuariosDAO.carregarUsuarios();

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
            formaPagamentoString = atributo;
      } else if (contadorSharp == 2) {
            idUsuarioString = atributo;
      } else if (contadorSharp == 3) {
            pedidos = atributo;
      }

      contadorSharp++;
      contador++;

      if (contadorSharp >= 4) {
        break;
      }
    }

    //Converte o idString para id inteiro
    unsigned long int id = stoi(idString);
    unsigned long int formaPagamento = stoi(formaPagamentoString);
    unsigned long int idUsuario = stoi(idUsuarioString);
    Usuario usuario = usuariosDAO.getUsuarioByID(idUsuario);

    //Transforma a string pedidos em um vetor novamente
    int count = 0, contadorPorcentagem = 0;
    vector<Pedido> vetorPedidos;

    while (count < pedidos.size()) {
        vector<char> vti;
        while (count < pedidos.size() && pedidos[count] != '%') {
            vti.push_back(pedidos[count]);
            count++;
        }

        string pedString(vti.data(), vti.size());
        unsigned long int pedId = stoi(pedString);
        Pedido ped;

        // Percorre o vetor de pedidos e procura o pedido com o id correspondente ao pedId
        // Se encontrado, o pedido é armazenado na variável ped
        for (Pedido pedido : pedidosDAO.getAllPedidos()) {
            if (pedId == pedido.getId()) {
                ped = pedido;
                break;
            }
        }

        vetorPedidos.push_back(ped);

        count++;
    }

    auto x = Comanda(id, formaPagamento, usuario, vetorPedidos);
    return x;
};


vector<Comanda> ComandaDAO::carregarComandas(){
  fstream arquivo("database/comandas.txt");

  string linha;

  if (arquivo.is_open()) {
    while (getline(arquivo, linha)) {
      if(!linha.empty()){
        Comanda c = converteStringParaObjeto(linha);
        listaComandas.push_back(c);
      }
    }

  } else {
      cout << "Erro ao abrir o arquivo." << endl;
  }

  arquivo.close();

  return listaComandas;
};


void ComandaDAO::salvarComandas(){
    ofstream arquivo("database/comandas.txt");
    if (arquivo.is_open()) {
        for (Comanda comanda : listaComandas) {
            // Transforma o vetor de pedidos em linha
            string pedidosEmLinha;
            vector<Pedido> pedidos = comanda.getPedidos();
            for (int i = 0; i < pedidos.size(); i++) {
                pedidosEmLinha += to_string(pedidos[i].getId());

                if (i != comanda.getPedidos().size() - 1) {
                    pedidosEmLinha += "%";
                }
            }

            arquivo << to_string(comanda.getId()) << "#" 
                    << to_string(comanda.getFormaPagamento()) << "#"
                    << to_string(comanda.getUsuario().getId()) << "#"
                    << pedidosEmLinha;
                    
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo." << endl;
    }
};


//Métodos de manipulação de dados

vector<Comanda> ComandaDAO::getAllComandas(){
    return listaComandas;
};


void ComandaDAO::imprimirComandas(){
    cout << "ID | Forma de Pagamento | Usuário | Pedidos (ID, Pizzas, Bebidas)" << endl;
    for (auto& objeto : listaComandas) {
        cout << objeto << endl;
    }
};


Comanda ComandaDAO::getComandaByID(unsigned long int id){
    for(Comanda comanda : listaComandas){
        if(comanda.getId() == id){
            return comanda;
            break;
        }
    }
}


bool ComandaDAO::inserirComanda(Comanda comanda){
    listaComandas.push_back(comanda);
    salvarComandas();
    return true;
};


bool ComandaDAO::removerComanda(unsigned long int id){
    auto c = listaComandas.begin();
    bool apagou = false;
    while (c != listaComandas.end()) {
        if (c->getId() == id) {
            c = listaComandas.erase(c);
            apagou = true;
            break;
        } else {
            c++;
        }
    }

    salvarComandas();

    return apagou;
}


bool ComandaDAO::editarComanda(Comanda comanda, unsigned long int id){
    bool encontrou = false;
    for(Comanda& c : listaComandas){
        if(c.getId() == id){
            c = comanda;
            encontrou = true;
            break;
        }
    }
  
    salvarComandas();
    return encontrou;
};