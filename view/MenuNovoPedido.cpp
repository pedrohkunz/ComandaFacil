#include <iostream>
#include <string>
#include <limits>

using namespace std;

#include "../include/MenuNovoPedido.h"

#include "../include/TamanhoPizzaDAO.h"
#include "../include/SaborDAO.h"
#include "../include/BebidaDAO.h"

//Construtor
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


unsigned short MenuNovoPedido::numeroDaMesa(){
    unsigned short numeroMesa;

    cout << "\nDigite o número da mesa: ";

    //Garante que o valor de entrada seja um inteiro
    while (!(cin >> numeroMesa)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada inválida. Apenas números são aceitos: ";
    }

    //Valida se o número é menor que zero ou maior que 100
    while(numeroMesa < 0 || numeroMesa > 100){
        cout << "\nNúmero inválido. Digite um número entre 0 e 100: ";
        while (!(cin >> numeroMesa)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Apenas números são aceitos: ";
        }
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


vector<Sabor> MenuNovoPedido::escolherSabores(){
    unsigned short quantSabores;
    SaborDAO saborDAO = SaborDAO();

    saborDAO.carregarSabores();

     cout <<"\n/////////////////////////////////// Escolha os sabores da pizza /////////////////////////////////////\n";

     cout <<"\nQuantos sabores o cliente deseja? ";

     //Garante que o valor de entrada seja um inteiro
     while (!(cin >> quantSabores)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada inválida. Apenas números são aceitos: ";
    }


     //Valida a quantidade de sabores
     while(quantSabores != 1 && quantSabores != 2 && quantSabores !=3 && quantSabores != 4){
        if(quantSabores < 1){
            cout <<"A quantidade mínima de sabores é 1, insira uma quantidade válida: ";
        } else if(quantSabores > 4){
            cout <<"A quantidade máxima de sabores é 4, insira uma quantidade válida: ";
        }

        //Garante que o valor de entrada seja um inteiro
        while (!(cin >> quantSabores)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Apenas números são aceitos: ";
        }
     }

     cout << endl;

    //Imprime sabores
    saborDAO.imprimirSabores();

    cout << endl;

    //Armazena os sabores escolhidos em um vetor
    vector<Sabor> saboresPedido;
    for(int i= 0; i< quantSabores; i++){
        unsigned short s;

        bool encontrado = false;
        while(encontrado == false) {
            cout <<"\nEscolha o sabor " << i+1 <<": ";

            //Garante que o valor de entrada seja um inteiro
            while (!(cin >> s)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada inválida. Digite o ID de um sabor: ";
            }

            //Procura o sabor selecionado na base de dados
            for(Sabor sabor : saborDAO.getAllSabores()){
                if(sabor.getId() == s){
                    saboresPedido.push_back(sabor);
                    encontrado = true;
                    break;
                }
            }

            if(!encontrado){
                cout <<"\nO sabor digitado não foi encontrado!\n";
            }
        }
    }

     return saboresPedido;
}


vector<Bebida> MenuNovoPedido::escolherBebidas(){
    unsigned short quantBebidas;
    BebidaDAO bebidaDAO = BebidaDAO();

    bebidaDAO.carregarBebidas();

    cout <<"\n/////////////////////////////////// Escolha as bebidas /////////////////////////////////////\n";

    cout <<"\nQuantas bebidas o cliente deseja? ";

    //Garante que o valor de entrada seja um inteiro
    while (!(cin >> quantBebidas)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada inválida. Apenas números são aceitos: ";
    }

    cout << endl;

    //Imprime bebidas
    bebidaDAO.imprimirBebidas();

    cout << endl;

    //Armazena as bebidas escolhidas em um vetor
    vector<Bebida> bebidasPedido;
    for(int i= 0; i< quantBebidas; i++){
        unsigned short b;

        bool encontrado = false;
        while(encontrado == false) {
            cout <<"\nEscolha a bebida " << i+1 <<": ";

            //Garante que o valor de entrada seja um inteiro
            while (!(cin >> b)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada inválida. Digite o ID de um sabor: ";
            }

            //Procura o sabor selecionado na base de dados
            for(Bebida bebida : bebidaDAO.getAllBebidas()){
                if(bebida.getId() == b){
                    bebidasPedido.push_back(bebida);
                    encontrado = true;
                    break;
                }
            }

            if(!encontrado){
                cout <<"\nA bebida digitada não foi encontrada!\n";
            }
        }
    }

     return bebidasPedido;
}


void MenuNovoPedido::menu(){
    //nomeCliente();
    //numeroDaMesa();
    //escolherCPF();
    //escolherTamanhoDaPizza();
    //escolherSabores();
    //escolherBebidas();

}
