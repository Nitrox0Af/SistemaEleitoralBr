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
    static Partido* getPartido(Partidos& p, int pos);
    static Partido* getPartido(Partidos& p, candidato* c);
    static int VotosNome(Partidos& p);
    static int VotosLeg(Partidos& p);
    static void organizaPartidos(Partidos& p);
    static bool comparaVotos(Partido* a, Partido* b);
    ~Partidos();
private:
    ifstream arquivo;
    list<Partido*> lista;
    
};
#endif