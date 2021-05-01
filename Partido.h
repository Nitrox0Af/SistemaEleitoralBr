using namespace std;

#include <iostream>
#include <string>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include "candidatos.h"

class Partido {
public:
    Partido(string num_part, string votos_leg, string nome_part, string sigla_part, candidatos& cands);
    
    void setNum_partido(int num_partido);
    void setVotos_leg(int votos_leg);
    void setVotos_nome(int votos_nome);
    void setNome_part(string nome_part);
    void setSigla_part(string sigla_part);
    
    int getNum_partido();
    int getVotos_leg();
    int getVotos_nome();
    string getNome_part();
    string getSigla_part();
    int getQtd_eleitos();
    candidato* getMaisVotado();
    candidato* getMenosVotado();
private:
    int num_partido;
    int votos_leg = 0;
    int votos_nome;
    string nome_part;
    string sigla_part;
    list<candidato*> cands;
};

