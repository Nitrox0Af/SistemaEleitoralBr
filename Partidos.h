#ifndef PARTIDOS_H
#define PARTIDOS_H

#include <exception>
#include <typeinfo>

using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Partido.h"
#include "Arquivo.h"

class Partidos {
public:
    Partidos(ifstream& arquivo, candidatos& cands);
    Partidos& operator=(const Partidos& p);
    ~Partidos();
private:
    ifstream arquivo;
    int qtd_partidos = 0;
    list<Partido*> partidos;
    
};
#endif