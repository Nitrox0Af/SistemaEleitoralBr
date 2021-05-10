using namespace std;

#include <iostream>
#include <string>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include "candidatos.h"

class Partido {
public:
    Partido(string num_part, string votos_leg, string nome_part, string sigla_part, candidatos* cands);
    // construtor do partido que recebe strings respctivas a cada atributa do partido e a lista de candidatos do partido
    
    Partido();
    //construtor default
    
    void setNum_partido(int num_partido);   // seta o numero do partido
    void setVotos_leg(int votos_leg);       // seta os votos de legenda do partido
    void setVotos_nome(int votos_nome);     // seta os votos nominais do partido
    void setNome_part(string nome_part);    // seta o nome do partido
    void setSigla_part(string sigla_part);  // seta a sigla do partido
    
    int         getNum_partido() const;    // retorna o numero do partido
    int         getVotos_leg()   const;    // retorna os votos de legenda do partido
    int         getVotos_nome()  const;    // retorna os votos nominais do partido
    string      getNome_part()   const;    // retorna o nome do partido
    string      getSigla_part()  const;    // retorna a sigla do partido
    int         getQtd_eleitos() const;    // retorna a quantidade de quantidatos eleitos
    
    candidato*  getMaisVotado()  ;    
    // retorna o candidato mais votado do partido
    // lista de candidatos do partido tem sua ordem modificada
    
    candidato*  getMenosVotado() ;    
    // retorna o candidato menos votado do partido
    // lista de candidatos do partido tem sua ordem modificada
private:
    int num_partido;
    int votos_leg ;
    int votos_nome;
    string nome_part;
    string sigla_part;
    list<candidato*> cands;
};