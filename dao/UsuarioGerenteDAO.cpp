#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/UsuarioGerenteDAO.h"
#include "../include/UsuarioGerenteDAO.h"

using namespace std;

//Construtor vazio
UsuarioGerenteDAO::UsuarioGerenteDAO(){};

//Métodos que acessam diretamente o arquivo bebidas.txt
UsuarioGerente UsuarioGerenteDAO::converteStringParaObjeto(string linha){
    int contador = 0, contadorSharp = 0;
    string idString, nome, email, senha;

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
        } else if(contadorSharp == 2){
            email = atributo;
        } else if(contadorSharp == 3){
            senha = atributo;
        }


        contadorSharp++;
        contador++;

        if (contadorSharp >= 4) {
            break;
        }
    }

    //Converte as strings para outros tipos de dados
    unsigned long int id = stoi(idString);

    auto novoItem = UsuarioGerente(id, nome, email, senha);
    return novoItem;
};


vector<UsuarioGerente> UsuarioGerenteDAO::carregarUsuariosGerentes(){
  fstream arquivo("database/UsuariosGerentes.txt");

  string linha;

  if (arquivo.is_open()) {
    while (getline(arquivo, linha)) {
      if(!linha.empty()){
        UsuarioGerente i = converteStringParaObjeto(linha);
        bool UsuarioGerenteRepetido = false;

        // Verificar se o UsuarioGerente já está na lista
        for (UsuarioGerente UsuarioGerente : listaUsuariosGerentes) {
          if (UsuarioGerente.getId() == i.getId()) {
            UsuarioGerenteRepetido = true;
            break;
          }
        }

        // Adicionar o UsuarioGerente apenas se não estiver repetido
        if (!UsuarioGerenteRepetido) {
          listaUsuariosGerentes.push_back(i);
        }
      }
    }
  } else {
      cout << "Erro ao abrir o arquivo." << endl;
  }

  arquivo.close();

  return listaUsuariosGerentes;
};


void UsuarioGerenteDAO::salvarUsuariosGerentes(){
    ofstream arquivo("database/UsuariosGerentes.txt");
    if (arquivo.is_open()) {
        for (UsuarioGerente UsuarioGerente : listaUsuariosGerentes)
            arquivo << to_string(UsuarioGerente.getId()) << "#"
                    << UsuarioGerente.getNome() << "#"
                    << UsuarioGerente.getEmail() << "#"
                    << UsuarioGerente.getSenha() << endl;

        arquivo.close();

    } else {
        cout << "Erro ao abrir o arquivo." << endl;
    }
};


//Métodos de manipulação de dados

vector<UsuarioGerente> UsuarioGerenteDAO::getAllUsuariosGerentes(){
    carregarUsuariosGerentes();
    return listaUsuariosGerentes;
};


void UsuarioGerenteDAO::imprimirUsuariosGerentes(){
    carregarUsuariosGerentes();
    cout << "ID | Nome | E-mail" << endl;
    for (const auto& objeto : listaUsuariosGerentes) {
        cout << objeto << endl;
    }
};


UsuarioGerente UsuarioGerenteDAO::getUsuarioGerenteByID(unsigned long int id){
    carregarUsuariosGerentes();
    bool encontrou = false;
    for(UsuarioGerente UsuarioGerente : listaUsuariosGerentes){
        if(UsuarioGerente.getId() == id){
            encontrou = true;
            return UsuarioGerente;
            break;
        }
    }
    if(encontrou == false) {
        cout << "Erro: ID UsuarioGerente não encontrado." << endl;
    }
}

UsuarioGerente UsuarioGerenteDAO::getUsuarioGerenteByNome(string nome){
    carregarUsuariosGerentes();
    bool encontrou = false;
    for(UsuarioGerente UsuarioGerente : listaUsuariosGerentes){
        if(UsuarioGerente.getNome() == nome){
            encontrou = true;
            return UsuarioGerente;
            break;
        }
    }
    if(encontrou == false) {
        cout << "Erro: Nome UsuarioGerente não encontrado." << endl;
    }
}


bool UsuarioGerenteDAO::inserirUsuarioGerente(UsuarioGerente UsuarioGerente){
    carregarUsuariosGerentes();
    listaUsuariosGerentes.push_back(UsuarioGerente);
    salvarUsuariosGerentes();
    return true;
};


bool UsuarioGerenteDAO::removerUsuarioGerente(unsigned long int id){
    carregarUsuariosGerentes();
    auto i = listaUsuariosGerentes.begin();
    bool apagou = false;
    while (i != listaUsuariosGerentes.end()) {
        if (i->getId() == id) {
            i = listaUsuariosGerentes.erase(i);
            apagou = true;
            break;
        } else {
            i++;
        }
    }

    salvarUsuariosGerentes();

    return apagou;
}