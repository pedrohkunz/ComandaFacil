#include "../include/Lote.h"
#include "../include/LoteDAO.h"
#include "../include/IngredienteDAO.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void menuEstoque() {
  unsigned short resposta;

  cout << "1- Ver todos os itens  |  2- Buscar  |  3- Adicionar lote" << endl;
  cout << "Qual atividade você deseja realizar? " << endl;
  cin >> resposta;

  // Validação da resposta
  while (resposta != 1 && resposta != 2 && resposta != 3) {
    cout << "Opção inválida, por favor tente novamente: " << endl;
    cin >> resposta;
  }

  switch (resposta) {
  case 1:

    break;

  case 2:

    break;

  case 3:

    break;
  }
}
