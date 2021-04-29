#include "Partido.h"

Partido::Partido(string num_part, string votos_leg, string nome_part, string sigla_part, candidatos& cands) {
    
    setNum_partido(stoi(num_part));
    setVotos_leg(stoi(votos_leg));
    setNome_part(nome_part);
    setSigla_part(sigla_part);  
    
    for (int i = 0; i < candidatos::qtd_candidatos(cands); i++)
        if (candidato::getNumero_partido(candidatos::pegaCandidato(cands, i+1)) == this->num_partido)
            this->cands.push_front(candidatos::pegaCandidato(cands, i+1));
}
void Partido::setNum_partido(int num_partido){
    this->num_partido = num_partido;
}
void Partido::setVotos_leg(int votos_leg){
    this->votos_leg = votos_leg;
}
void Partido::setNome_part(string nome_part){
    this->nome_part = nome_part;
}
void Partido::setSigla_part(string sigla_part){
    this->sigla_part = sigla_part;
}

int Partido::getNum_partido(){
    return this->num_partido;
}
int Partido::getVotos_leg(){
    return this->votos_leg;
}
string Partido::getNome_part(){
    return this->nome_part;
}
string Partido::getSigla_part(){
    return this->sigla_part;
}