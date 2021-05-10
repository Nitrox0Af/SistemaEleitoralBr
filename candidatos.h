#include "candidato.h"
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
#include <iterator>
#include <ctime>

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
    candidatos& operator=(const candidatos& c);
    //operador de "=" para tipo candidatos
    //se a referencia tiver vazia, o metodo aloca novos espacos e copia as informacoes de c,
    //caso contrario, o metodo destroi as informacoes dele e aloca novos espacos
    //alem de copiar as informacoes de c;

    //Metodos:

    static candidatos* getCandidatosEleitos(const candidatos& c);
    //retorno dos candidatos eleitos, tipo candiatos alocado;
    //parametro de entrada: a lista dos candidatos

    static list<candidato*> getLista(const candidatos* c);
    //retorno do ponteiro da lista de candidato contida no tipo condidatos;
    //parametro de entrada: a lista dos candidatos

    static int num_eleitos(const candidatos& c);
    //retorno do numero de candidatos eleitos;
    //parametro de entrada: a lista dos candidatos

    static int organizar_por_idade(const candidato* c,const candidato* d);
    // retorno do numero que representa se candidato c eh ou nao mais velho que candidato d
    //1 para d mais velho e 0 para c mais velho
    //parametro de entrada: candidato denominado c e candidato denominado d

    static void organizar_por_votos_nominais(candidatos *c);
    //retorno void, o tipo passado como parametro sera organizadode forma
    //a lista eh ordenada pela quantidade de votos, ou seja,
    // o primeiro é aquele com mais votos e o ultimo aquele com menos
    //parametro de entrada: a lista de candidato;

    static candidatos* candidatosMaisVotados(const candidatos &c);
    //retorno tipo candidato alocado, o tipo passado como parametro sera organizadode forma
    //a lista eh ordenada pela quantidade de votos, ou seja,
    // o primeiro é aquele com mais votos e o ultimo aquele com menos
    //parametro de entrada: a lista de candidato;

    static int qtd_candidatos(candidatos& c);
    //recebe como parametro uma lista de candidatos
    //retorna a quantidade de candidatos de uma lista
    
    static int qtdHomens(candidatos* c);
    //recebe como parametro uma lista de candidatos
    //retorna a quantidade de homens presente na lista
    static int qtdMulheres(candidatos* c);
    //recebe como parametro uma lista de candidatos
    //retorna a quantidade de mulheres presente na lista

    static candidato* getCandidato(candidatos& c, int n);
    //recebe como parametro uma lista de candidatos e um inteiro referente a posição do candidato
    //retorna o candidato na posição n
    
    static bool getMaisVotado(candidato* A, candidato* B);
    //recebe como parametro dois candidatos
    //retorna true se o candidato A é mais votado
    //retorna else se o candidato B é mais votado
    static bool getMenosVotado(candidato* A, candidato* B);
    //recebe como parametro dois candidatos
    //retorna true se o candidato A é o menos votado
    //retorna else se o candidato B é o menos votado
    
    static vector<int>  getIdades(string data, candidatos& c);
    //recebe como parametro a data da eleição e uma lista de candidatos
    //retorna um vetor contendo a lista das idades dos candidatos
};