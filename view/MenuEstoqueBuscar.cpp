#include "../include/Lote.h"
#include "../include/LoteDAO.h"
#include "../include/IngredienteDAO.h"
#include "../include/MenuEstoque.h"
#include "../include/MenuEstoqueBuscar.h"
#include "../include/MenuPrincipal.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

MenuEstoqueBuscar::MenuEstoqueBuscar(){};
MenuEstoque menuEstoqueMEB = MenuEstoque();
IngredienteDAO ingredientesMenuEB = IngredienteDAO();
LoteDAO loteMenuEB = LoteDAO();
MenuPrincipal menuPrincipalEstoqueBuscar = MenuPrincipal();

void MenuEstoqueBuscar::menuEstoqueBuscar(){
  unsigned short resposta;

  cout <<"//////////////////////////////////////// Menu Estoque | Buscar ////////////////////////////////////////////" << endl;

  cout << "1- Filtrar lotes  |  "
       << "2- Buscar por ID  |  "
       << "3- Buscar por data de validade  |  "
       << "4- Buscar por ingrediente  |  "
       << "5- Voltar  |  "
       << "6- Sair" << endl
       << "Qual atividade você deseja realizar?" << endl;

  resposta = menuPrincipalEstoqueBuscar.inputIsInt();
  cout << endl;

  // Validação da resposta
  while (resposta != 1 && resposta != 2 && resposta != 3 && resposta != 4 && resposta != 5 && resposta != 6) {
    cout << "Opção inválida, por favor tente novamente: " << endl;

    resposta = menuPrincipalEstoqueBuscar.inputIsInt();

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

  case 5:
    menuEstoqueMEB.menuEstoque();
    break;

  case 6:
    cout << "Saindo..." << endl;
    break;

  }
}


void MenuEstoqueBuscar::filtrar(){

};


void MenuEstoqueBuscar::buscarPorId(){
    unsigned long int id;
    cout << "Digite o ID: " << endl;
    cin >> id;
    cout << endl;
    cout << loteMenuEB.getLoteByID(id) << endl;
    
};


void MenuEstoqueBuscar::buscarPorDataValidade(){
    string data;
    cout << "Digite a data de validade: " << endl;
    cin >> data;
    cout << endl;

    for (Lote l : loteMenuEB.getLotesByDataValidade(data)){
      cout << l << endl;
    }

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
            cout << endl;

            ingrediente = ingredientesMenuEB.getIngredienteByNome(nome);

            for (Lote l : loteMenuEB.getLotesByIngrediente(ingrediente)){
                cout << l << endl;
            }

            break;

        case 2:
            cout << "Digite o id do ingrediente: " << endl;
            cin >> id;
            cout << endl;

            ingrediente = ingredientesMenuEB.getIngredienteByID(id);
            
            for (Lote l : loteMenuEB.getLotesByIngrediente(ingrediente)){
                cout << l << endl;
            }

            break;

        }

};

