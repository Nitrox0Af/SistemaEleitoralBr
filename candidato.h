#include <string>
#include<fstream>
#include <iostream>
using namespace std;

class candidato {
    private:
        int numero;//
        int votos_nominais;//
        string situacao;//
        string nome;
        string nome_urna;
        string sexo;
        string data_nasc;
        string destino_voto;
        int numero_partido;//

    public:
    candidato(string* info, int n);
    candidato();
    candidato& operator=(const candidato& c);
    static int getSituacao(candidato* c); // retorna 1 eleito 0 nao eleito
    static int getNumero_candidato(candidato* c); //retorna numero do candidato
    static int getVotos_nominais(candidato* c); // retorna quantidade de votos nominais
    static string getNome(candidato* c); // retorna nome candidato
    static string getNome_urna(candidato* c); //retorna nome de urna do candidato
    static string getSexo(candidato* c); // retorna sexo do candidato
    static string getData_nasc(candidato* c); // retorna string da idade do candidato
    static string getDestino_voto(candidato* c); // retirna o destino do voto
    static int getNumero_partido(candidato* c);//Retorna o numero do partido
    ~candidato();
};