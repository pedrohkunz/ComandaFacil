#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/IngredienteDAO.h"
#include "../include/Ingrediente.h"

//Construtor vazio
IngredienteDAO::IngredienteDAO(){};

//Métodos que acessam diretamente o arquivo ingredientes.txt

Ingrediente IngredienteDAO::converteStringParaObjeto(string linha){
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

    auto novoItem = Ingrediente(id, nome);
    return novoItem;
}


vector<Ingrediente> IngredienteDAO::carregarIngredientes(){
  fstream arquivo("database/ingredientes.txt");

  string linha;

  if (arquivo.is_open()) {
    while (getline(arquivo, linha)) {
      if(!linha.empty()){
        Ingrediente i = converteStringParaObjeto(linha);
        listaIngredientes.push_back(i);
      }
    }

  } else {
      cout << "Erro ao abrir o arquivo." << endl;
  }

  arquivo.close();

  return listaIngredientes;
};


void IngredienteDAO::salvarIngredientes(){
    ofstream arquivo("database/ingredientes.txt");
    if (arquivo.is_open()) {
        for (Ingrediente ingrediente : listaIngredientes) {
            arquivo << to_string(ingrediente.getId()) << "#" 
                    << ingrediente.getNome() << endl;
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo." << endl;
    }
};


//Métodos de manipulação de dados

vector<Ingrediente> IngredienteDAO::getAllIngredientes(){
    return listaIngredientes;
};


Ingrediente IngredienteDAO::getIngredienteByID(unsigned long int id){
    for(Ingrediente ingrediente : listaIngredientes){
        if(ingrediente.getId() == id){
            return ingrediente;
            break;
        }
    }
}


Ingrediente IngredienteDAO::getIngredienteByNome(string nome){
    for(Ingrediente ingrediente : listaIngredientes){
        if(ingrediente.getNome() == nome){
            return ingrediente;
            break;
        }
    }
}


bool IngredienteDAO::inserirIngrediente(Ingrediente ingrediente){
    listaIngredientes.push_back(ingrediente);
    salvarIngredientes();
    return true;
};


bool IngredienteDAO::removerIngrediente(unsigned long int id){
    auto i = listaIngredientes.begin();
    bool apagou = false;
    while (i != listaIngredientes.end()) {
        if (i->getId() == id) {
            i = listaIngredientes.erase(i);
            apagou = true;
            break;
        } else {
            i++;
        }
    }

    salvarIngredientes();

    return apagou;
}


bool IngredienteDAO::editarIngrediente(Ingrediente ingrediente, unsigned long int id){
    bool encontrou = false;
    for(Ingrediente& i : listaIngredientes){
        if(i.getId() == id){
            i = ingrediente;
            encontrou = true;
            break;
        }
    }
    salvarIngredientes();
    return encontrou;
};
