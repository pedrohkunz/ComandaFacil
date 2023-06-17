#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/BebidasDAO.h"
#include "../include/Bebida.h"

using namespace std;

//Construtor vazio
BebidasDAO::BebidasDAO(){};

//Métodos que acessam diretamente o arquivo bebidas.txt

Bebida BebidasDAO::converteStringParaObjeto(string linha){
    int contador = 0, contadorSharp = 0;
    string idString, tipo, tamanho, valorString;

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
            tipo = atributo;
        } else if(contadorSharp == 2){
            tamanho = atributo;
        } else if(contadorSharp == 3){
            valorString = atributo;
        }

        contadorSharp++;
        contador++;

        if (contadorSharp >= 4) {
            break;
        }
    }

    //Converte as strings para outros tipos de dados
    unsigned long int id = stoi(idString);
    float valor = stof(valorString);

    auto novoItem = Bebida(id, tipo, tamanho, valor);
    return novoItem;
};


vector<Bebida> BebidasDAO::carregarBebidas(){
  fstream arquivo("database/bebidas.txt");

  string linha;

  if (arquivo.is_open()) {
    while (getline(arquivo, linha)) {
      if(!linha.empty()){
        Bebida i = converteStringParaObjeto(linha);
        listaBebidas.push_back(i);
      }
    }

  } else {
      cout << "Erro ao abrir o arquivo." << endl;
  }

  arquivo.close();

  return listaBebidas;
};


void BebidasDAO::salvarBebidas(){
    ofstream arquivo("database/bebidas.txt");
    if (arquivo.is_open()) {
        for (Bebida bebida : listaBebidas) {
            arquivo << to_string(bebida.getId()) << "#" 
                    << bebida.getTipo() << "#" 
                    << bebida.getTamanho() << "#" 
                    << to_string(bebida.getValor()) << endl;
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo." << endl;
    }
};


//Métodos de manipulação de dados

vector<Bebida> BebidasDAO::getAllBebidas(){
    return listaBebidas;
};


Bebida BebidasDAO::getBebidaByID(unsigned long int id){
    for(Bebida bebida : listaBebidas){
        if(bebida.getId() == id){
            return bebida;
            break;
        }
    }
}


bool BebidasDAO::inserirBebida(Bebida bebida){
    listaBebidas.push_back(bebida);
    salvarBebidas();
    return true;
};


bool BebidasDAO::removerBebida(unsigned long int id){
    auto i = listaBebidas.begin();
    bool apagou = false;
    while (i != listaBebidas.end()) {
        if (i->getId() == id) {
            i = listaBebidas.erase(i);
            apagou = true;
            break;
        } else {
            i++;
        }
    }

    salvarBebidas();

    return apagou;
}


bool BebidasDAO::editarBebida(Bebida bebida, unsigned long int id){
    bool encontrou = false;
    for(Bebida& b : listaBebidas){
        if(b.getId() == id){
            b = bebida;
            encontrou = true;
            break;
        }
    }
    salvarBebidas();
    return encontrou;
};
