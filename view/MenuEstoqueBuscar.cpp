#include "../include/Lote.h"
#include "../include/LoteDAO.h"
#include "../include/IngredienteDAO.h"
#include "../include/MenuEstoqueBuscar.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

MenuEstoqueBuscar::MenuEstoqueBuscar(){};
IngredienteDAO ingredientesMenuEstoqueBuscar = IngredienteDAO();
LoteDAO lote = LoteDAO();

void MenuEstoqueBuscar::menuEstoqueBuscar(){
  unsigned short resposta;

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
    lote.carregarLotes();
    unsigned long int id;
    cout << "Digite o ID: " << endl;
    cin >> id;
    cout << move(lote.getLoteByID(id)) << endl;
    
};


void MenuEstoqueBuscar::buscarPorDataValidade(){
    lote.carregarLotes();
    string data;
    cout << "Digite a data de validade: " << endl;
    cin >> data;
    cout << move(lote.getLoteByDataValidade(data)) << endl;

};


void MenuEstoqueBuscar::buscarPorIngrediente(){
    lote.carregarLotes();
    ingredientesMenuEstoqueBuscar.carregarIngredientes();
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
            ingrediente = ingredientesMenuEstoqueBuscar.getIngredienteByNome(nome);
            cout << (loteMenuEstoqueBuscar.getLoteByIngrediente(ingrediente)) << endl;
            break;

        case 2:
            cout << "Digite o id do ingrediente: " << endl;
            cin >> id;
            ingrediente = ingredientesMenuEstoqueBuscar.getIngredienteByID(id);
            cout << (loteMenuEstoqueBuscar.getLoteByIngrediente(ingrediente)) << endl;
            break;

        }

};

