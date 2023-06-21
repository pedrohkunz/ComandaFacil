#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/PizzaDAO.h"
#include "../include/Pizza.h"
#include "../include/TamanhoPizzaDAO.h"
#include "../include/TamanhoPizza.h"
#include "../include/SaborDAO.h"
#include "../include/Sabor.h"

using namespace std;

//Construtor vazio
PizzaDAO::PizzaDAO(){};

SaborDAO saboresDAOpiz = SaborDAO();
TamanhoPizzaDAO tamanhosDAOpiz = TamanhoPizzaDAO();

//Métodos que acessam diretamente o arquivo pizzas.txt

Pizza PizzaDAO::converteStringParaObjeto(string linha){
    int contador = 0, contadorSharp = 0;
    string idString, tamanhoString, sabores;

    for (int i = 0; i < linha.size(); i++) {
        vector<char> vt;
        while (contador < linha.size() && linha[contador] != '#') {
            vt.push_back(linha[contador]);
            contador++;
        }

        // Converter vetor de char para string correspondente
        string atributo(vt.data(), vt.size());

        if (contadorSharp == 0) {
            idString = atributo;
        } else if (contadorSharp == 1) {
            tamanhoString = atributo;
        } else if(contadorSharp == 2){
            sabores = atributo;
        }

        contadorSharp++;
        contador++;

        if (contadorSharp >= 3) {
            break;
        }
    }

    //Transforma a string sabores em um vetor novamente
    int count = 0, contadorPorcentagem = 0;
    vector<Sabor> vetorSabores;

    while (count < sabores.size()) {
        vector<char> vti;
        while (count < sabores.size() && sabores[count] != '%') {
            vti.push_back(sabores[count]);
            count++;
        }

        string sabString(vti.data(), vti.size());
        Sabor sab;

        // Percorre o vetor de sabores e procura o sabor com o nome correspondente ao sabString, se encontrado, o sabor é armazenado na variável ing
        for (Sabor sabor : saboresDAOpiz.getAllSabores()) {
            if (sabString == sabor.getNome()) {
                sab = sabor;
                break;
            }
        }

        vetorSabores.push_back(sab);

        count++;
    }

    //Converte as strings para outros tipos de dados
    unsigned long int id = stoi(idString);
    unsigned long int idTamanho = stoi(tamanhoString);
    TamanhoPizza tamanho = tamanhosDAOpiz.getTamanhoByID(idTamanho);

    auto novoItem = Pizza(id, tamanho, vetorSabores);
    return novoItem;
};


vector<Pizza> PizzaDAO::carregarPizzas(){
  fstream arquivo("database/pizzas.txt");

  string linha;

  if (arquivo.is_open()) {
    while (getline(arquivo, linha)) {
      if(!linha.empty()){
        Pizza i = converteStringParaObjeto(linha);
        bool pizzaRepetida = false;

        // Verificar se o pizza já está na lista
        for (Pizza pizza : listaPizzas) {
          if (pizza.getId() == i.getId()) {
            pizzaRepetida = true;
            break;
          }
        }

        // Adicionar a pizza apenas se não estiver repetida
        if (!pizzaRepetida) {
          listaPizzas.push_back(i);
        }
      }
    }
  } else {
      cout << "Erro ao abrir o arquivo." << endl;
  }

  arquivo.close();

  return listaPizzas;
};


void PizzaDAO::salvarPizzas(){
    ofstream arquivo("database/pizzas.txt");
    if (arquivo.is_open()) {
        for (Pizza pizza : listaPizzas) {
            // Transforma o vetor de sabores em linha
            string saboresEmLinha;
            vector<Sabor> sabores = pizza.getSabores();
            for (int i = 0; i < sabores.size(); i++) {
                saboresEmLinha += sabores[i].getNome();

                if (i != pizza.getSabores().size() - 1) {
                    saboresEmLinha += "%";
                }
            }

            arquivo << to_string(pizza.getId()) << "#"
                    << to_string(pizza.getTamanho().getId()) << "#"
                    << saboresEmLinha << endl;
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo." << endl;
    }
};


//Métodos de manipulação de dados

vector<Pizza> PizzaDAO::getAllPizzas(){
    carregarPizzas();
    return listaPizzas;
};


void PizzaDAO::imprimirPizzas(){
    carregarPizzas();
    cout << "ID | Tamanho | Sabores" << endl;
    for (auto& objeto : listaPizzas) {
        cout << objeto << endl;
    }
};


Pizza PizzaDAO::getPizzaByID(unsigned long int id){
    carregarPizzas();
    bool encontrou = false;
    for(Pizza pizza : listaPizzas){
        if(pizza.getId() == id){
            encontrou = true;
            return pizza;
            break;
        }
    }
    if(encontrou == false) {
        cout << "Erro: ID Pizza não encontrado." << endl;
    }
};


vector<Pizza> PizzaDAO::getPizzasByTamanho(unsigned long int idTamanho){
    carregarPizzas();
    bool encontrou = false;
    vector<Pizza> pizzas;
    TamanhoPizza tamanho = tamanhosDAOpiz.getTamanhoByID(idTamanho);

    for (Pizza p : listaPizzas){
        if (p.getTamanho() == tamanho){
            encontrou = true;
            pizzas.push_back(p);
        }
    }

    return pizzas;
    cout << endl;

    if (encontrou == false) {
        cout << "Erro: Tamanho Pizza não encontrado." << endl;
    }
};


vector<Pizza> PizzaDAO::getPizzasBySabor(unsigned long int idSabor){
    carregarPizzas();
    bool encontrou = false;
    vector<Pizza> pizzas;

    for (Pizza p : listaPizzas){
        for (Sabor s : p.getSabores()){
            if (s.getId() == idSabor){
                encontrou = true;
                pizzas.push_back(p);
            }
        }
    }

    return pizzas;
    cout << endl;

    if (encontrou == false) {
        cout << "Erro: Tamanho Pizza não encontrado." << endl;
    }
};


bool PizzaDAO::inserirPizza(Pizza pizza){
    carregarPizzas();
    listaPizzas.push_back(pizza);
    salvarPizzas();
    return true;
};


bool PizzaDAO::removerPizza(unsigned long int id){
    carregarPizzas();
    auto i = listaPizzas.begin();
    bool apagou = false;
    while (i != listaPizzas.end()) {
        if (i->getId() == id) {
            i = listaPizzas.erase(i);
            apagou = true;
            break;
        } else {
            i++;
        }
    }

    salvarPizzas();

    return apagou;
}


bool PizzaDAO::editarPizza(Pizza pizza, unsigned long int id){
    carregarPizzas();
    bool encontrou = false;
    for(Pizza& p : listaPizzas){
        if(p.getId() == id){
            p = pizza;
            encontrou = true;
            break;
        }
    }
    salvarPizzas();
    return encontrou;
};


