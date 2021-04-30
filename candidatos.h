#include "candidato.h"
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <iterator>

using namespace std;

class candidatos{
    private:
        list<candidato*> lista;
    public:
        candidatos(string* texto, int n);
        candidatos();
        candidatos& operator=(candidatos& c);
        static int num_eleitos(candidatos& c);
        static candidatos* getCandidatosEleitos(candidatos& c);
        static int organizar_por_idade(candidato* c,candidato* d);//1 para d mais velho e 0 para c mais velho
        static list<candidato*> getLista(candidatos* c);
        static void organizar_por_votos_nominais(candidatos *c);
        static  candidatos* candidatosMaisVotados(candidatos &c, int Num_max);


        static int qtd_candidatos(candidatos& c);
        static candidato* pegaCandidato(candidatos& c, int n);
        ~candidatos();
};