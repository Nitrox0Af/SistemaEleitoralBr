#include "candidato.h"
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

class candidatos{
private:
    list<candidato*> lista;
public:
    candidatos(string* texto, int n);
    //construtor que exige entrada de informacao texto e tamanho de linhas que texto tem

    candidatos();
    //construtor default

    ~candidatos();
    //destrutor

    //operadores:
    candidatos& operator=(candidatos& c);
    //operador de "=" para tipo candidatos
    //se a referencia tiver vazia, o metodo aloca novos espacos e copia as informacoes de c,
    //caso contrario, o metodo destroi as informacoes dele e aloca novos espacos
    //alem de copiar as informacoes de c;

    //Metodos:

    static candidatos* getCandidatosEleitos(candidatos& c);
    //retorno dos candidatos eleitos, tipo candiatos alocado;
    //parametro de entrada: a lista dos candidatos

    static list<candidato*> getLista(candidatos* c);
    //retorno do ponteiro da lista de candidato contida no tipo condidatos;
    //parametro de entrada: a lista dos candidatos

    static int num_eleitos(candidatos& c);
    //retorno do numero de candidatos eleitos;
    //parametro de entrada: a lista dos candidatos

    static int organizar_por_idade(candidato* c,candidato* d);
    // retorno do numero que representa se candidato c eh ou nao mais velho que candidato d
    //1 para d mais velho e 0 para c mais velho
    //parametro de entrada: candidato denominado c e candidato denominado d

    static void organizar_por_votos_nominais(candidatos *c);
    //retorno void, o tipo passado como parametro sera organizadode forma
    //a lista eh ordenada pela quantidade de votos, ou seja,
    // o primeiro é aquele com mais votos e o ultimo aquele com menos
    //parametro de entrada: a lista de candidato;

    static candidatos* candidatosMaisVotados(candidatos &c);
    //retorno tipo candidato alocado, o tipo passado como parametro sera organizadode forma
    //a lista eh ordenada pela quantidade de votos, ou seja,
    // o primeiro é aquele com mais votos e o ultimo aquele com menos
    //parametro de entrada: a lista de candidato;

    static int qtd_candidatos(candidatos& c);
    static int qtdHomens(candidatos* c);
    static int qtdMulheres(candidatos* c);
    static candidato* getCandidato(candidatos& c, int n);
    static bool getMaisVotado(candidato* A, candidato* B);
    static bool getMenosVotado(candidato* A, candidato* B);
};