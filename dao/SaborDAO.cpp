#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/SaborDAO.h"
#include "../include/Sabor.h"
#include "../include/IngredienteDAO.h"
#include "../include/Ingrediente.h"


IngredienteDAO ingredientesDAO = IngredienteDAO();

//Construtor vazio
SaborDAO::SaborDAO(){};

//Métodos que acessam diretamente o arquivo sabores.txt

Sabor SaborDAO::converteStringParaObjeto(string a){
   int contador = 0, contadorSharp = 0;
    string idString, nome, ingredientes;
    ingredientesDAO.carregarIngredientes();

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
            nome = atributo;
      } else if (contadorSharp == 2) {
            ingredientes = atributo;
      }

      contadorSharp++;
      contador++;

      if (contadorSharp >= 3) {
        break;
      }
    }


    //Converte o idString para id inteiro
    unsigned long int id = stoi(idString);

    //Transforma a string ingredientes em um vetor novamente
    int count = 0, contadorPorcentagem = 0;
    vector<Ingrediente> vetorIngredientes;

    for (int i = 0; i < ingredientes.size(); i++) {
        vector<char> vti;
        while (count < ingredientes.size() && ingredientes[count] != '%') {
            vti.push_back(ingredientes[count]);
            count++;
        }

        string ingString(vti.data(), vti.size());
        Ingrediente ing;

        for(Ingrediente ingrediente : ingredientesDAO.getAllIngredientes()){
            if(ingString == ingrediente.getNome()){
                ing = ingrediente;
                break;
            }
        };

        vetorIngredientes.push_back(ing);
    }

    auto x = Sabor(id, nome, vetorIngredientes);
    return x;
};


vector<Sabor> SaborDAO::carregarSabores(){
  fstream arquivo("database/sabores.txt");

  string linha;

  if (arquivo.is_open()) {
    while (getline(arquivo, linha)) {
      if(!linha.empty()){
        Sabor i = converteStringParaObjeto(linha);
        listaSabores.push_back(i);
      }
    }

  } else {
      cout << "Erro ao abrir o arquivo." << endl;
  }

  arquivo.close();

  return listaSabores;
};


void SaborDAO::salvarSabores(){
    ofstream arquivo("database/sabores.txt");
    if (arquivo.is_open()) {
        for (Sabor sabor : listaSabores) {
            //Transforma o vetor de ingredientes em linha
            string ingredientesEmLinha;
            for(int i = 0; i<sabor.getIngredientes().size(); i++){
                ingredientesEmLinha = ingredientesEmLinha + sabor.getIngredientes()[i].getNome();

                if(i != sabor.getIngredientes().size()-1){
                    ingredientesEmLinha += "%";
                }
            }
            //for(Ingrediente ing : sabor.getIngredientes()){
              //  ingredientesEmLinha = ing.getNome() + "%";
            //}

            arquivo << to_string(sabor.getId()) << "#" 
                    << sabor.getNome() << "#" 
                    << ingredientesEmLinha << endl;
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo." << endl;
    }
};


//Métodos de manipulação de dados

vector<Sabor> SaborDAO::getAllSabores(){
    return listaSabores;
};


Sabor SaborDAO::getSaborByID(unsigned long int id){
    for(Sabor ingrediente : listaSabores){
        if(ingrediente.getId() == id){
            return ingrediente;
            break;
        }
    }
}


bool SaborDAO::inserirSabor(Sabor ingrediente){
    listaSabores.push_back(ingrediente);
    salvarSabores();
    return true;
};


bool SaborDAO::removerSabor(unsigned long int id){
    auto i = listaSabores.begin();
    bool apagou = false;
    while (i != listaSabores.end()) {
        if (i->getId() == id) {
            i = listaSabores.erase(i);
            apagou = true;
            break;
        } else {
            i++;
        }
    }

    salvarSabores();

    return apagou;
}


bool SaborDAO::editarSabor(Sabor ingrediente, unsigned long int id){
    bool encontrou = false;
    for(Sabor& i : listaSabores){
        if(i.getId() == id){
            i = ingrediente;
            encontrou = true;
            break;
        }
    }
    salvarSabores();
    return encontrou;
};
