#include <string>
#include<fstream>
#include <iostream>
using namespace std;

class candidato {
    private:
        int numero;
        int votos_nominais;
        string situacao;
        string nome;
        string nome_urna;
        string sexo;
        string data_nasc;
        string destino_voto;
        int numero_partido;

    public:
    candidato(string* info, int n);
    candidato& operator=(const candidato& c);
    static int getSituacao(candidato* c);
    static int getNumero_candidato(candidato* c);
    ~candidato();
};