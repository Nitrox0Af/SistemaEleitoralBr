#include <string>
#include <vector>
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
    candidato(string* info);
    //construtor que exige entrada de informacao texto

    candidato();
    //construtor default

    ~candidato();
    //destrutor

    candidato& operator=(const candidato& c);
    //operador de "=" para tipo candidatos
    //copia as informacoes c de para a referencia

    static int getSituacao(candidato* c); // retorna 1 eleito 0 nao eleito
    static int getNumero_candidato(candidato* c); //retorna numero do candidato
    static int getVotos_nominais(candidato* c); // retorna quantidade de votos nominais
    static string getNome(candidato* c); // retorna nome candidato
    static string getNome_urna(candidato* c); //retorna nome de urna do candidato
    static string getSexo(candidato* c); // retorna sexo do candidato
    static string getData_nasc(candidato* c); // retorna string da idade do candidato
    static string getDestino_voto(candidato* c); // retorna o destino do voto
    static int getNumero_partido(candidato* c);//Retorna o numero do partido
};