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

    while (count < ingredientes.size()) {
        vector<char> vti;
        while (count < ingredientes.size() && ingredientes[count] != '%') {
            vti.push_back(ingredientes[count]);
            count++;
        }

        string ingString(vti.data(), vti.size());
        Ingrediente ing;

        // Percorre o vetor de ingredientes e procura o ingrediente com o nome correspondente ao ingString
        // Se encontrado, o ingrediente é armazenado na variável ing
        for (Ingrediente ingrediente : ingredientesDAO.getAllIngredientes()) {
            if (ingString == ingrediente.getNome()) {
                ing = ingrediente;
                break;
            }
        }

        vetorIngredientes.push_back(ing);

        count++;
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


void SaborDAO::salvarSabores() {
    ofstream arquivo("database/sabores.txt");
    if (arquivo.is_open()) {
        for (Sabor sabor : listaSabores) {
            // Transforma o vetor de ingredientes em linha
            string ingredientesEmLinha;
            vector<Ingrediente> ingredientes = sabor.getIngredientes();
            for (int i = 0; i < ingredientes.size(); i++) {
                ingredientesEmLinha += ingredientes[i].getNome();

                if (i != sabor.getIngredientes().size() - 1) {
                    ingredientesEmLinha += "%";
                }
            }

            arquivo << to_string(sabor.getId()) << "#" 
                    << sabor.getNome() << "#" 
                    << ingredientesEmLinha << endl;
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo." << endl;
    }
}


//Métodos de manipulação de dados

vector<Sabor> SaborDAO::getAllSabores(){
    return listaSabores;
};


void SaborDAO::imprimirSabores(){
    cout << "ID | Nome | Ingredientes" << endl;
    for (const auto& objeto : listaSabores) {
        cout << objeto << endl;
    }
};


Sabor SaborDAO::getSaborByID(unsigned long int id){
    for(Sabor sabor : listaSabores){
        if(sabor.getId() == id){
            return sabor;
            break;
        } else {
            cout << "Erro: ID Sabor não encontrado." << endl;
        }
    }
}


Sabor SaborDAO::getSaborByNome(string nome){
    for(Sabor sabor : listaSabores){
        if(sabor.getNome() == nome){
            return sabor;
            break;
        } else {
            cout << "Erro: Nome Sabor não encontrado." << endl;
        }
    }
}


bool SaborDAO::inserirSabor(Sabor sabor){
    listaSabores.push_back(sabor);
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


bool SaborDAO::editarSabor(Sabor sabor, unsigned long int id){
    bool encontrou = false;
    for(Sabor& s : listaSabores){
        if(s.getId() == id){
            s = sabor;
            encontrou = true;
            break;
        }
    }
    salvarSabores();
    return encontrou;
};
