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
    static int qtd_partidos(Partidos& p);
    static Partido* pegaPartido(Partidos& p, int n);
    ~Partidos();
private:
    ifstream arquivo;
    list<Partido*> lista;
    
};
#endif