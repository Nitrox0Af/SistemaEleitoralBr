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
    //construtor que pega em seus arqumentos a lista de candidatos é o arquivo
    Partidos();
    //construtor default
    
    static Partido* getPartido(Partidos& p, int pos);       //retorna o partido da lista de acordo com sua posição na lista
    static Partido* getPartido(Partidos& p, const candidato* c);  //retorna o partido deacordo com o numero de partido do candidato
    static int qtd_partidos(Partidos* p);                   //retorna a quantidade de partidos da lista de patidos passada como parametro
    static int VotosNome(Partidos& p);                      //retorna a quantidade de votos nominais de todos os partidos
    static int VotosLeg(Partidos& p);                       //retorna a quantidade de votos de legenda de todos os partidos
    static void organizaPartidos(Partidos& p);              //organiza a lista de partidos pela ordem dos mais votados
    
    static bool comparaVotos(Partido* a, Partido* b);       
    //compara os votos de dois partidos
    //retorna true  para se o partido A é o mais votado
    //retorna false para se o partido B é o mais votado
    ~Partidos();
private:
    ifstream arquivo;
    list<Partido*> lista;
    
};
#endif