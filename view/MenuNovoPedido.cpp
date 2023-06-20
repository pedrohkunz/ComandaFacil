#include <iostream>
#include <string>
#include <limits>

using namespace std;

#include "../include/MenuNovoPedido.h"

#include "../include/TamanhoPizzaDAO.h"

MenuNovoPedido::MenuNovoPedido(){};

string MenuNovoPedido::nomeCliente(){
    string nomeCliente;

    cout <<"\n/////////////////////////////////// Preencha os dados do cliente /////////////////////////////////////\n";

    cout << "\nDigite o nome do cliente: ";
    cin >> nomeCliente;
    cout << endl;

    //Verifica o nome do cliente
    while(nomeCliente.empty()){
        cout << "\nO nome do cliente não pode ficar vazio, insira um nome válido: ";
        cin >> nomeCliente;
        cout << endl;
    }

    return nomeCliente;
}


string MenuNovoPedido::numeroDaMesa(){
    string numeroMesa;

    cout << "\nDigite o número da mesa: ";
    cin >> numeroMesa;
    cout << endl;

    //Valida o número da mesa
    while(numeroMesa.empty()){
        cout << "\nO número da mesa não pode ficar vazio, por favor insira um novo número: ";
        cin >> numeroMesa;
        cout << endl;
    }

    return numeroMesa;
}


string MenuNovoPedido::escolherCPF(){
    unsigned short cpfNota;
    string cpf;

    cout << "\nO cliente deseja CPF na nota?";
    cout << "\n 1- Sim | 2- Não\n";
    cin >> cpfNota;
    cout << endl;

    //Verifica se a resposta em relação ao CPF está válida
    while(cpfNota != 1 && cpfNota != 2){
        cout << "\nInsira uma resposta válida: ";
        cin >> cpfNota;
        cout << endl;
    }

    //Se o cliente não informar o CPF, ele será vazio
    if(cpfNota == 1){
        cout << "\nInsira o CPF do cliente: ";
        cin >> cpf;
        cout << endl;

        while(cpf.length() != 11){
            cout <<"\ninsira um CPF válido: ";
            cin >> cpf;
            cout << endl;
        }
    } else {
        cpf = "";
    }

    return cpf;
}


TamanhoPizza MenuNovoPedido::escolherTamanhoDaPizza(){
    unsigned short tamanhoPizza;
    TamanhoPizzaDAO tamanhoPizzaDAO = TamanhoPizzaDAO();

    //tamanhoPizzaDAO.carregarTamanhos();

    cout <<"\n/////////////////////////////////// Escolha o tamanho da pizza /////////////////////////////////////\n";

    cout << endl;

    //Imprime a tabela com todos os tamanhos de pizza
    tamanhoPizzaDAO.imprimirTamanhos();

    cout << endl;

    cout <<"Qual tamanho de pizza o cliente deseja? " << endl;

    //Garante que o valor de entrada seja um inteiro
    while (!(cin >> tamanhoPizza)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada inválida. Digite o ID de um tamanho: " << endl;
    }

    //Procura o Tamanho na base de dados com base no id
    TamanhoPizza tamanhoSelecionado;
    bool encontrou = false;

    //Verifica se o tamanho foi encontrado no vetor, caso não pedirá um novo tamanho
    while (!encontrou) {
        for (TamanhoPizza tamanho : tamanhoPizzaDAO.getAllTamanhos()) {
            if (tamanho.getId() == tamanhoPizza) {
                tamanhoSelecionado = tamanho;
                encontrou = true;
                break;
            }
        }

        if (!encontrou) {
            cout << "O tamanho selecionado não existe, insira um ID de tamanho válido: ";
            //Garante que o valor de entrada seja um inteiro
            while (!(cin >> tamanhoPizza)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada inválida. Digite o ID de um tamanho: ";
            }
        }
    }

    return tamanhoSelecionado;
}



void MenuNovoPedido::menu(){
    escolherTamanhoDaPizza();
}
