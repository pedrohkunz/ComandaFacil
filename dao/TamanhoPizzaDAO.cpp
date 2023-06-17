#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/TamanhoPizzaDAO.h"
#include "../include/TamanhoPizza.h"

//Construtor vazio
TamanhoPizzaDAO::TamanhoPizzaDAO(){};

//Métodos que acessam diretamente o arquivo tamanhosPizza.txt

TamanhoPizza TamanhoPizzaDAO::converteStringParaObjeto(string linha){
    int contador = 0, contadorSharp = 0;
    string idString, tamanho, valorString;

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
            tamanho = atributo;
        } else if(contadorSharp == 2){
            valorString = atributo;
        }

        contadorSharp++;
        contador++;

        if (contadorSharp >= 3) {
            break;
        }
    }

    //Converte as strings para outros tipos de dados
    unsigned long int id = stoi(idString);
    float valor = stod(valorString);

    auto novoItem = TamanhoPizza(id, tamanho, valor);
    return novoItem;
};


vector<TamanhoPizza> TamanhoPizzaDAO::carregarTamanhos(){
  fstream arquivo("database/tamanhosPizza.txt");

  string linha;

  if (arquivo.is_open()) {
    while (getline(arquivo, linha)) {
      if(!linha.empty()){
        TamanhoPizza i = converteStringParaObjeto(linha);
        listaTamanhos.push_back(i);
      }
    }

  } else {
      cout << "Erro ao abrir o arquivo." << endl;
  }

  arquivo.close();

  return listaTamanhos;
};


void TamanhoPizzaDAO::salvarTamanhos(){
    ofstream arquivo("database/tamanhosPizza.txt");
    if (arquivo.is_open()) {
        for (TamanhoPizza tamanho : listaTamanhos) {
            arquivo << to_string(tamanho.getId()) << "#" 
                    << tamanho.getTamanho() << "#" 
                    << to_string(tamanho.getValor()) << endl;
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo." << endl;
    }
};


//Métodos de manipulação de dados

vector<TamanhoPizza> TamanhoPizzaDAO::getAllTamanhos(){
    return listaTamanhos;
};

TamanhoPizza TamanhoPizzaDAO::getTamanhoByID(unsigned long int id){
    for(TamanhoPizza tamanho : listaTamanhos){
        if(tamanho.getId() == id){
            return tamanho;
            break;
        }
    }
}


bool TamanhoPizzaDAO::inserirTamanho(TamanhoPizza tamanho){
    listaTamanhos.push_back(tamanho);
    salvarTamanhos();
    return true;
};


bool TamanhoPizzaDAO::removerTamanho(unsigned long int id){
    auto i = listaTamanhos.begin();
    bool apagou = false;
    while (i != listaTamanhos.end()) {
        if (i->getId() == id) {
            i = listaTamanhos.erase(i);
            apagou = true;
            break;
        } else {
            i++;
        }
    }

    salvarTamanhos();

    return apagou;
}


bool TamanhoPizzaDAO::editarTamanho(TamanhoPizza tamanho, unsigned long int id){
    bool encontrou = false;
    for(TamanhoPizza& t : listaTamanhos){
        if(t.getId() == id){
            t = tamanho;
            encontrou = true;
            break;
        }
    }
    salvarTamanhos();
    return encontrou;
};
