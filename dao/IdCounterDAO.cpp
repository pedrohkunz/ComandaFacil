#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/IdCounterDAO.h"
#include "../include/IdCounter.h"

//Construtor vazio
IdCounterDAO::IdCounterDAO(){};


IdCounter IdCounterDAO::converteStringParaObjeto(string linha){
    int contador = 0, contadorSharp = 0;
    string contadorIdString, nomeDoObjeto;

    for (int i = 0; i < linha.size(); i++) {
        vector<char> vt;
        while (contador < linha.size() && linha[contador] != '#') {
            vt.push_back(linha[contador]);
            contador++;
        }

        // Converter vetor de char para string correspondente
        string atributo(vt.data(), vt.size());

        if (contadorSharp == 0) {
            contadorIdString = atributo;
        } else if (contadorSharp == 1) {
            nomeDoObjeto = atributo;
        }

        contadorSharp++;
        contador++;

        if (contadorSharp >= 2) {
            break;
        }
    }

    //Converte as strings para outros tipos de dados
    unsigned long int contadorId = stoi(contadorIdString);

    auto novoItem = IdCounter(contadorId, nomeDoObjeto);
    return novoItem;
};


vector<IdCounter> IdCounterDAO::carregarContadores(){
    fstream arquivo("database/counterID.txt");

    string linha;

    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {
        if(!linha.empty()){
            IdCounter i = converteStringParaObjeto(linha);
            listaContadores.push_back(i);
        }
        }

    } else {
        cout << "Erro ao abrir o arquivo." << endl;
    }

    arquivo.close();

    return listaContadores;
};

void IdCounterDAO::salvarContadores(){
    ofstream arquivo("database/counterID.txt");
    if (arquivo.is_open()) {
        for (IdCounter idCounter : listaContadores) {
            arquivo << to_string(idCounter.getContadorId()) << "#"
                    << idCounter.getNomeDoObjeto() << endl;
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo." << endl;
    }
};


unsigned long int IdCounterDAO::gerarID(string nomeDoObjeto){
    carregarContadores();

    unsigned long int idIncrementado;
    bool encontrado = false;
    while(!encontrado){
        for(IdCounter idCounter : listaContadores){
            if(idCounter.getNomeDoObjeto() == nomeDoObjeto){
                idIncrementado = idCounter.getContadorId() + 1;
                idCounter.setContadorId(idIncrementado);
                encontrado = true;
                break;
            }
        }
    }

    salvarContadores();
    
    if(encontrado){
        return idIncrementado;
    }
}
