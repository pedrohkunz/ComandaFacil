#ifndef STATUS_H
#define STATUS_H

#include <iostream>
#include <vector>

using namespace std;

class Status{
  private:
    unsigned long int id;
    string nome;

    friend ostream& operator<<(ostream& os, const Status& objeto) {
        os << objeto.id << " | " 
           << objeto.nome;
        return os;
    }

  public:
    Status(int id, string nome);
    Status();

    int getId();
    void setId(unsigned long int id);
    
    string getNome() const;
    void setNome(string nome);

    bool operator==(const Status& status) const {
        if (this-> id == status.id && this->nome == status.nome){
          return true;
        } else {
          return false;
        }
        // Defina sua lógica de comparação aqui.
        // Compare os atributos relevantes dos objetos Ingrediente.
        // Retorne true se os objetos forem iguais e false caso contrário.
    }
};

#endif