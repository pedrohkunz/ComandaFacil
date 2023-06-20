#include <iostream>
using namespace std;

#include "../include/IdCounter.h"

IdCounter::IdCounter(unsigned long int contadorId, string nomeDoObjeto){
    this->contadorId = contadorId;
    this->nomeDoObjeto = nomeDoObjeto;
}

unsigned long int IdCounter::getContadorId(){
    return contadorId;
}

void IdCounter::setContadorId(unsigned long int contadorId){
    this->contadorId = contadorId;
}

string IdCounter::getNomeDoObjeto(){
    return nomeDoObjeto;
}

void IdCounter::setNomeDoObjeto(string nomeDoObjeto){
    this->nomeDoObjeto = nomeDoObjeto;
}

