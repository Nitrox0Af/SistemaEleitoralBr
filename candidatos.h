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
        candidatos& operator=(const candidatos& c);
        static int num_eleitos(candidatos& c);
        static candidatos getCandidatosEleitos(candidatos& c);
        static void organizar_por_idade(candidatos& c);
        ~candidatos();
};