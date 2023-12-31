#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

#include "../include/BebidaDAO.h"
#include "../include/Bebida.h"

using namespace std;

//Construtor vazio
BebidaDAO::BebidaDAO(){};

//Métodos que acessam diretamente o arquivo bebidas.txt

Bebida BebidaDAO::converteStringParaObjeto(string linha){
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


vector<Bebida> BebidaDAO::carregarBebidas(){
  fstream arquivo("database/bebidas.txt");

  string linha;

  if (arquivo.is_open()) {
    while (getline(arquivo, linha)) {
      if(!linha.empty()){
        Bebida i = converteStringParaObjeto(linha);
        bool bebidaRepetida = false;

        // Verificar se a bebida já está na lista
        for (Bebida bebida : listaBebidas) {
          if (bebida.getId() == i.getId()) {
            bebidaRepetida = true;
            break;
          }
        }

        // Adicionar a bebida apenas se não estiver repetida
        if (!bebidaRepetida) {
          listaBebidas.push_back(i);
        }
      }
    }
  } else {
      cout << "Erro ao abrir o arquivo." << endl;
  }

  arquivo.close();

  return listaBebidas;
};


void BebidaDAO::salvarBebidas(){
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

vector<Bebida> BebidaDAO::getAllBebidas(){
    carregarBebidas();
    return listaBebidas;
};


void BebidaDAO::imprimirBebidas(){
    carregarBebidas();
    
    cout << "ID | Tipo           | Tamanho  | Valor" << endl;
    cout << "------------------------------------" << endl;
    for (Bebida bebida : listaBebidas) {
        cout << left << setw(2) << bebida.getId() << " | "
             << setw(14) << bebida.getTipo() << " | "
             << setw(8) << bebida.getTamanho() << " | "
             << setw(2) << "R$ " << fixed << setprecision(2) << bebida.getValor() << endl;
    }
};


Bebida BebidaDAO::getBebidaByID(unsigned long int id){
    carregarBebidas();
    bool encontrou = false;
    for(Bebida bebida : listaBebidas){
        if(bebida.getId() == id){
            encontrou = true;
            return bebida;
            break;
        }
    }
    if(encontrou == false) {
        cout << "Erro: ID Bebida não encontrado." << endl;
    }
}


bool BebidaDAO::inserirBebida(Bebida bebida){
    carregarBebidas();
    listaBebidas.push_back(bebida);
    salvarBebidas();
    return true;
};


bool BebidaDAO::removerBebida(unsigned long int id){
    carregarBebidas();
    auto b = listaBebidas.begin();
    bool apagou = false;
    while (b != listaBebidas.end()) {
        if (b->getId() == id) {
            b = listaBebidas.erase(b);
            apagou = true;
            break;
        } else {
            b++;
        }
    }

    salvarBebidas();

    return apagou;
}


bool BebidaDAO::editarBebida(Bebida bebida, unsigned long int id){
    carregarBebidas();
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
