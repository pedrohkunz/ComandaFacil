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

using namespace std;

MenuEstoque::MenuEstoque(){};
MenuPrincipal menuPrincipal = MenuPrincipal();

void MenuEstoque::menuEstoque() {
  unsigned short resposta;
  LoteDAO lote = LoteDAO();
  lote.carregarLotes();
  MenuEstoqueBuscar buscar = MenuEstoqueBuscar();

  cout <<"///////////////////////////////////////////// Menu Estoque ////////////////////////////////////////////////" << endl;

  cout << "1- Ver todos os itens  |  " 
       << "2- Buscar  |  "
       << "3- Adicionar lote  |  "
       << "4- Voltar ao menu principal" << endl
       << "Qual atividade você deseja realizar? " << endl;
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
    lote.imprimirLotes();
    cout << endl;
    this->menuEstoque();
    break;


  case 2:
    buscar.menuEstoqueBuscar();
    this->menuEstoque();
    break;

  case 3:
    cout << "Adicionar lote" << endl;
    this->menuEstoque();
    break;

  case 4:
    menuPrincipal.menu();
    break;
  }
}
