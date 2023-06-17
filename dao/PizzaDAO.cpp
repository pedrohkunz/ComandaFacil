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

SaborDAO saboresDAO = SaborDAO();
TamanhoPizzaDAO tamanhosDAO = TamanhoPizzaDAO();

//Métodos que acessam diretamente o arquivo pizzas.txt

Pizza PizzaDAO::converteStringParaObjeto(string linha){
    int contador = 0, contadorSharp = 0;
    string idString, tamanhoString, sabores;
    saboresDAO.carregarSabores();
    tamanhosDAO.carregarTamanhos();

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

    for (int i = 0; i < sabores.size(); i++) {
        vector<char> vti;
        while (count < sabores.size() && sabores[count] != '%') {
            vti.push_back(sabores[count]);
            count++;
        }

        string sabString(vti.data(), vti.size());
        Sabor sab;

        for(Sabor sabor : saboresDAO.getAllSabores()){
            if(sabString == sabor.getNome()){
                sab = sabor;
                break;
            }
        };

        vetorSabores.push_back(sab);
    }
  
    //Converte as strings para outros tipos de dados
    unsigned long int id = stoi(idString);
    unsigned long int idTamanho = stoi(tamanhoString);
    TamanhoPizza tamanho = tamanhosDAO.getTamanhoByID(idTamanho);

    auto novoItem = Pizza(id, tamanho, vetorSabores);
    return novoItem;
};


vector<Pizza> PizzaDAO::carregarPizzas(){
  fstream arquivo("database/pizza.txt");

  string linha;

  if (arquivo.is_open()) {
    while (getline(arquivo, linha)) {
      if(!linha.empty()){
        Pizza i = converteStringParaObjeto(linha);
        listaPizzas.push_back(i);
      }
    }

  } else {
      cout << "Erro ao abrir o arquivo." << endl;
  }

  arquivo.close();

  return listaPizzas;
};


void PizzaDAO::salvarPizzas(){
    ofstream arquivo("database/pizzasPizza.txt");
    if (arquivo.is_open()) {
        for (Pizza pizza : listaPizzas) {
            arquivo << to_string(pizza.getId()) << "#" 
                    << to_string(pizza.getTamanho().getId()) 
                    << endl;
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo." << endl;
    }
};


//Métodos de manipulação de dados

vector<Pizza> PizzaDAO::getAllPizzas(){
    return listaPizzas;
};

Pizza PizzaDAO::getPizzaByID(unsigned long int id){
    for(Pizza pizza : listaPizzas){
        if(pizza.getId() == id){
            return pizza;
            break;
        }
    }
}


bool PizzaDAO::inserirPizza(Pizza pizza){
    listaPizzas.push_back(pizza);
    salvarPizzas();
    return true;
};


bool PizzaDAO::removerPizza(unsigned long int id){
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


