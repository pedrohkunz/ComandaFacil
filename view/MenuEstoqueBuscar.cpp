#include "../include/Lote.h"
#include "../include/LoteDAO.h"
#include "../include/IngredienteDAO.h"
#include "../include/MenuEstoqueBuscar.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

MenuEstoqueBuscar::MenuEstoqueBuscar(){};
IngredienteDAO ingredientesMenuEB = IngredienteDAO();
LoteDAO loteMenuEB = LoteDAO();
int iMEB = 0;

void MenuEstoqueBuscar::menuEstoqueBuscar(){
  unsigned short resposta;
  while(iMEB < 1) {
    loteMenuEB.carregarLotes();
    ingredientesMenuEB.carregarIngredientes();
    iMEB++;
  }

  cout <<"//////////////////////////////////////// Menu Estoque | Buscar ////////////////////////////////////////////" << endl;

  cout << "1- Filtrar lotes  |  "
       << "2- Buscar por ID  |  "
       << "3- Buscar por data de validade | "
       << "4- Buscar por ingrediente" << endl
       << "Qual atividade você deseja realizar?" << endl;

  cin >> resposta;
  cout << endl;

  // Validação da resposta
  while (resposta != 1 && resposta != 2 && resposta != 3 && resposta != 4) {
    cout << "Opção inválida, por favor tente novamente: " << endl;
    cin >> resposta;
    cout << endl;
  }

  switch (resposta) {
  case 1:
    filtrar();
    break;


  case 2:
    buscarPorId();
    break;


  case 3:
    buscarPorDataValidade();
    break;


  case 4:
    buscarPorIngrediente();
    break;

  }
}


void MenuEstoqueBuscar::filtrar(){

};


void MenuEstoqueBuscar::buscarPorId(){
    unsigned long int id;
    cout << "Digite o ID: " << endl;
    cin >> id;
    cout << move(loteMenuEB.getLoteByID(id)) << endl;
    
};


void MenuEstoqueBuscar::buscarPorDataValidade(){
    string data;
    cout << "Digite a data de validade: " << endl;
    cin >> data;
    cout << move(loteMenuEB.getLoteByDataValidade(data)) << endl;

};


void MenuEstoqueBuscar::buscarPorIngrediente(){
    Ingrediente ingrediente;
    string nome;
    unsigned long int id;
    unsigned short resposta;
        cout << "1- Buscar por nome do ingrediente  |  "
             << "2- Buscar por ID  do ingrediente" << endl;
        cin >> resposta;
        cout << endl;

        // Validação da resposta
        while (resposta != 1 && resposta != 2) {
            cout << "Opção inválida, por favor tente novamente: " << endl;
            cin >> resposta;
            cout << endl;
        }

        switch (resposta) {
        case 1:
            cout << "Digite o nome do ingrediente: " << endl;
            cin >> nome;
            ingrediente = ingredientesMenuEB.getIngredienteByNome(nome);
            cout << (loteMenuEB.getLoteByIngrediente(ingrediente)) << endl;
            break;

        case 2:
            cout << "Digite o id do ingrediente: " << endl;
            cin >> id;
            ingrediente = ingredientesMenuEB.getIngredienteByID(id);
            cout << (loteMenuEB.getLoteByIngrediente(ingrediente)) << endl;
            break;

        }

};

