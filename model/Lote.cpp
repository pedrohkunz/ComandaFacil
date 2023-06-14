#include <iostream>
#include "../include/Lote.h"

using namespace std;

Lote::Lote(unsigned long int id, unsigned long int quantidade, string dataDeValidade, Ingrediente ingrediente){
    this->id = id;
    this->quantidade = quantidade;
    this->dataDeValidade = dataDeValidade;
    this->ingrediente = ingrediente;
}

Lote::Lote(){};

unsigned long int Lote::getId(){
    return id;
}

unsigned long int Lote::getQuantidade(){
    return quantidade;
}

void Lote::setQuantidade(unsigned long int quantidade){
    this->quantidade = quantidade;
}

string Lote::getDataDeValidade(){
    return dataDeValidade;
}

void Lote::setDataDeValidade(string dataDeValidade){
    this->dataDeValidade = dataDeValidade;
}

Ingrediente Lote::getIngredienteLote(){
    return ingrediente;
}

void Lote::setIngredienteLote(Ingrediente ingrediente){
    this->ingrediente = ingrediente;
}

