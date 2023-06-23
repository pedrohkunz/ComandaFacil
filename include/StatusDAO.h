#ifndef STATUSDAO_H_
#define STATUSDAO_H_

#include <iostream>
#include <vector>

#include "Status.h"

using namespace std;

class StatusDAO {
    private:
        vector<Status> listaStatus;
    public:
        StatusDAO();

        Status converteStringParaObjeto(string linha);

        vector<Status> carregarStatus();

        void salvarStatus();

        vector<Status> getAllStatus();

        void imprimirStatusPedidos();

        void imprimirStatusComandas();

        Status getStatusByID(unsigned long int id);

        Status getStatusByNome(string nome);

        bool inserirStatus(Status status);

        bool removerStatus(unsigned long int id);

        bool editarStatus(Status status, unsigned long int id);

};

#endif
