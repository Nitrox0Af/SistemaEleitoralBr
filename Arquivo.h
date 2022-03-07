#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <exception>
#include <typeinfo>

using namespace std;

#include <iostream>
#include <fstream>
class Arquivo {
private:
    string arq_nome;

public:
    ifstream arquivo;
    Arquivo(string arq_nome);

    string getNome();
    void setNome(string nome);

    void fechar();
};
#endif
//