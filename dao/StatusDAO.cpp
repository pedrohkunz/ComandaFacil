#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/StatusDAO.h"
#include "../include/Status.h"

//Construtor vazio
StatusDAO::StatusDAO(){};

//Métodos que acessam diretamente o arquivo Status.txt

Status StatusDAO::converteStringParaObjeto(string linha){
    int contador = 0, contadorSharp = 0;
    string idString, nome;

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
            nome = atributo;
        }

        contadorSharp++;
        contador++;

        if (contadorSharp >= 2) {
            break;
        }
    }

    //Converte as strings para outros tipos de dados
    unsigned long int id = stoi(idString);

    auto novoItem = Status(id, nome);
    return novoItem;
}


vector<Status> StatusDAO::carregarStatus(){
  fstream arquivo("database/status.txt");

  string linha;

  if (arquivo.is_open()) {
    while (getline(arquivo, linha)) {
      if(!linha.empty()){
        Status i = converteStringParaObjeto(linha);
        bool statusRepetido = false;

        // Verificar se o status já está na lista
        for (Status status : listaStatus) {
          if (status.getId() == i.getId()) {
            statusRepetido = true;
            break;
          }
        }

        // Adicionar o status apenas se não estiver repetido
        if (!statusRepetido) {
          listaStatus.push_back(i);
        }
      }
    }
  } else {
      cout << "Erro ao abrir o arquivo." << endl;
  }

  arquivo.close();

  return listaStatus;
};


void StatusDAO::salvarStatus(){
    ofstream arquivo("database/status.txt");
    if (arquivo.is_open()) {
        for (Status status : listaStatus) {
            arquivo << to_string(status.getId()) << "#"
                    << status.getNome() << endl;
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo." << endl;
    }
};


//Métodos de manipulação de dados

vector<Status> StatusDAO::getAllStatus(){
    carregarStatus();
    return listaStatus;
};


void StatusDAO::imprimirStatus(){
    carregarStatus();
    cout << "ID | Nome" << endl;
    for (const auto& objeto : listaStatus) {
        cout << objeto << endl;
    }
};


Status StatusDAO::getStatusByID(unsigned long int id){
    carregarStatus();
    bool encontrou = false;
    for(Status status : listaStatus){
        if(status.getId() == id){
            encontrou = true;
            return status;
            break;
        }
    }
    if(encontrou == false) {
        cout << "Erro: ID Status não encontrado." << endl;
    }
}


Status StatusDAO::getStatusByNome(string nome){
    carregarStatus();
    bool encontrou = false;
    for(Status status : listaStatus){
        if(status.getNome() == nome){
            encontrou = true;
            return status;
            break;
        }
    }
    if(encontrou == false) {
        cout << "Erro: Nome Status não encontrado." << endl;
    }
}


bool StatusDAO::inserirStatus(Status Status){
    carregarStatus();
    listaStatus.push_back(Status);
    salvarStatus();
    return true;
};


bool StatusDAO::removerStatus(unsigned long int id){
    carregarStatus();
    auto i = listaStatus.begin();
    bool apagou = false;
    while (i != listaStatus.end()) {
        if (i->getId() == id) {
            i = listaStatus.erase(i);
            apagou = true;
            break;
        } else {
            i++;
        }
    }

    salvarStatus();

    return apagou;
}


bool StatusDAO::editarStatus(Status status, unsigned long int id){
    carregarStatus();
    bool encontrou = false;
    for(Status& i : listaStatus){
        if(i.getId() == id){
            i = status;
            encontrou = true;
            break;
        }
    }
    salvarStatus();
    return encontrou;
};


