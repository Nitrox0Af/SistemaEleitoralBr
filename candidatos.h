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
        static int* getCandidatosEleitos(candidatos& c, int n);
        ~candidatos();
};