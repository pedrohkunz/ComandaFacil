#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/UsuarioDAO.h"
#include "../include/UsuarioDAO.h"

using namespace std;

//Construtor vazio
UsuarioDAO::UsuarioDAO(){};

//Métodos que acessam diretamente o arquivo bebidas.txt
Usuario UsuarioDAO::converteStringParaObjeto(string linha){
    int contador = 0, contadorSharp = 0;
    string idString, email, senha;

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
            email = atributo;
        } else if(contadorSharp == 2){
            senha = atributo;
        } 

        contadorSharp++;
        contador++;

        if (contadorSharp >= 3) {
            break;
        }
    }

    //Converte as strings para outros tipos de dados
    unsigned long int id = stoi(idString);

    auto novoItem = Usuario(id, email, senha);
    return novoItem;
};


vector<Usuario> UsuarioDAO::carregarUsuarios(){
  fstream arquivo("database/usuarios.txt");

  string linha;

  if (arquivo.is_open()) {
    while (getline(arquivo, linha)) {
      if(!linha.empty()){
        Usuario i = converteStringParaObjeto(linha);
        listaUsuarios.push_back(i);
      }
    }

  } else {
      cout << "Erro ao abrir o arquivo." << endl;
  }

  arquivo.close();

  return listaUsuarios;
};


void UsuarioDAO::salvarUsuarios(){
    ofstream arquivo("database/usuarios.txt");
    if (arquivo.is_open()) {
        for (Usuario usuario : listaUsuarios) 
            arquivo << to_string(usuario.getId()) << "#" << usuario.getEmail() << "#" << usuario.getSenha() << endl;
        
        arquivo.close();

    } else {
        cout << "Erro ao abrir o arquivo." << endl;
    }
};


//Métodos de manipulação de dados

vector<Usuario> UsuarioDAO::getAllUsuarios(){
    return listaUsuarios;
};


Usuario UsuarioDAO::getUsuarioByID(unsigned long int id){
    for(Usuario usuario : listaUsuarios){
        if(usuario.getId() == id){
            return usuario;
            break;
        }
    }
}


bool UsuarioDAO::criarUsuario(Usuario usuario){
    listaUsuarios.push_back(usuario);
    salvarUsuarios();
    return true;
};


bool UsuarioDAO::removerUsuario(unsigned long int id){
    auto i = listaUsuarios.begin();
    bool apagou = false;
    while (i != listaUsuarios.end()) {
        if (i->getId() == id) {
            i = listaUsuarios.erase(i);
            apagou = true;
            break;
        } else {
            i++;
        }
    }

    salvarUsuarios();

    return apagou;
}
