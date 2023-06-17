#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "../include/TamanhoPizza.h"

TamanhoPizza::TamanhoPizza(unsigned long int id, string tamanho, double valor){
    this->id = id;
    this->tamanho = tamanho;
    this->valor = valor;
}

TamanhoPizza::TamanhoPizza(){};

unsigned long int TamanhoPizza::getId(){
    return id;
}

string TamanhoPizza::getTamanho(){
    return tamanho;
}

void TamanhoPizza::setTamanho(string tamanho){
    this->tamanho = tamanho;
}

double TamanhoPizza::getValor(){
    return valor;
}

void TamanhoPizza::setValor(double valor){
    this->valor = valor;
}
