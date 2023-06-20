#ifndef IDCOUNTER_H_
#define IDCOUNTER_H_

#include <iostream>
using namespace std;

class IdCounter {
    private:
        unsigned long int contadorId;
        string nomeDoObjeto;
    public:
        IdCounter(unsigned long int contadorId, string nomeDoObjeto);

        unsigned long int getContadorId();
        void setContadorId(unsigned long int contadorId);

        string getNomeDoObjeto();
        void setNomeDoObjeto(string nomeDoObjeto);

};

#endif
