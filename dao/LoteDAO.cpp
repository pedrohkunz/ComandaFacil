#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/LoteDAO.h"
#include "../include/Lote.h"
#include "../include/IngredienteDAO.h"
#include "../include/Ingrediente.h"


//Construtor vazio
LoteDAO::LoteDAO(){};

IngredienteDAO ingredientesDAOlot = IngredienteDAO();

//Métodos que acessam diretamente o arquivo lotes.txt

Lote LoteDAO::converteStringParaObjeto(string linha){
    int contador = 0, contadorSharp = 0;
    string idString, quantidadeString, dataDeValidade, ingredienteString;
    //ingredientes.carregarIngredientes();


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
            quantidadeString = atributo;
        } else if (contadorSharp == 2) {
            dataDeValidade = atributo;
        } else if (contadorSharp == 3) {
            ingredienteString= atributo;
        }

        contadorSharp++;
        contador++;

        if (contadorSharp >= 4) {
            break;
        }
    }

    //Converte as strings para outros tipos de dados
    unsigned long int id = stoi(idString);
    unsigned long int quantidade = stoi(quantidadeString);
    unsigned long int idIngrediente = stoi(ingredienteString);
    Ingrediente ingrediente = ingredientesDAOlot.getIngredienteByID(idIngrediente);

    auto novoItem = Lote(id, quantidade, dataDeValidade, ingrediente);
    return novoItem;
}


vector<Lote> LoteDAO::carregarLotes(){
  fstream arquivo("database/lotes.txt");
  string linha;

  if (arquivo.is_open()) {
    while (getline(arquivo, linha)) {
      if(!linha.empty()){
        Lote i = converteStringParaObjeto(linha);
        bool loteRepetido = false;

        // Verificar se o lote já está na lista
        for (Lote lote : listaLotes) {
          if (lote.getId() == i.getId()) {
            loteRepetido = true;
            break;
          }
        }

        // Adicionar o lote apenas se não estiver repetido
        if (!loteRepetido) {
          listaLotes.push_back(i);
        }
      }
    }

  } else {
      cout << "Erro ao abrir o arquivo." << endl;
  }

  arquivo.close();

  return listaLotes;
};


void LoteDAO::salvarLotes(){
    ofstream arquivo("database/lotes.txt");
    if (arquivo.is_open()) {
        for (Lote lote : listaLotes) {
            arquivo << to_string(lote.getId()) << "#"
                    << to_string(lote.getQuantidade()) << "#"
                    << lote.getDataDeValidade() << "#"
                    << to_string(lote.getIngredienteLote().getId()) << endl;
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo." << endl;
    }
};


//Métodos de manipulação de dados

vector<Lote> LoteDAO::getAllLotes(){
    carregarLotes();
    return listaLotes;
};


void LoteDAO::imprimirLotes(){
    carregarLotes();
    cout << "\nID | Quantidade | Data de Validade | Ingrediente" << endl;
    cout << "--------------------------------------------------" << endl;
    for (const auto& objeto : listaLotes) {
        cout << objeto << endl;
    }
};


Lote LoteDAO::getLoteByID(unsigned long int id){
    carregarLotes();
    bool encontrou = false;
    for(Lote lote : listaLotes){
        if(lote.getId() == id){
            encontrou = true;
            return lote;
            break;
        }
    }
    if(encontrou == false) {
        cout << "Erro: ID Lote não encontrado." << endl;
    }
};


vector<Lote> LoteDAO::getLotesByDataValidade(string dataValidade){
    carregarLotes();
    bool encontrou = false;
    vector<Lote> lotes;

    for(Lote l : listaLotes){
        if(l.getDataDeValidade() == dataValidade){
            encontrou = true;
            lotes.push_back(l);
        }
    }

    return lotes;
    cout << endl;

    if(encontrou == false) {
        cout << "Erro: Data de validade Lote não encontrada." << endl;
    }
};


vector<Lote> LoteDAO::getLotesByIngrediente(Ingrediente ingrediente){
    carregarLotes();
    bool encontrou = false;
    vector<Lote> lotes;

    for(Lote l : listaLotes){
        if (l.getIngredienteLote() == ingrediente){
            encontrou = true;
            lotes.push_back(l);

        }
    }

    return lotes;
    cout << endl;

    if(encontrou == false) {
        cout << "Erro: Ingrediente Lote não encontrado." << endl;
    }

};


bool LoteDAO::inserirLote(Lote lote){
    carregarLotes();
    listaLotes.push_back(lote);
    salvarLotes();
    return true;
};


bool LoteDAO::removerLote(unsigned long int id){
    carregarLotes();
    auto i = listaLotes.begin();
    bool apagou = false;
    while (i != listaLotes.end()) {
        if (i->getId() == id) {
            i = listaLotes.erase(i);
            apagou = true;
            break;
        } else {
            i++;
        }
    }

    salvarLotes();

    return apagou;
}


bool LoteDAO::editarLote(Lote lote, unsigned long int id){
    carregarLotes();
    bool encontrou = false;
    for(Lote& i : listaLotes){
        if(i.getId() == id){
            i = lote;
            encontrou = true;
            break;
        }
    }
    salvarLotes();
    return encontrou;
};
