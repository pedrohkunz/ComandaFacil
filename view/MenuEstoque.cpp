#include "lote.h"
#include "loteDAO.h"
#include "ingredienteDAO.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void menuEstoque() {
  unsigned short resposta;

  cout << "\n1- Ver todos os itens  |  2- Buscar  |  3- Adicionar lote";
  cout << "\n* Qual atividade você deseja realizar? ";
  cin >> resposta;

  // Validação da resposta
  while (resposta != 1 && resposta != 2 && resposta != 3) {
    cout << "\nOpção inválida, por favor tente novamente: ";
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
