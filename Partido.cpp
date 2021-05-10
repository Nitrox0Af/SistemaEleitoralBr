#include "Partido.h"

Partido::Partido(string num_part, string votos_leg, string nome_part, string sigla_part, candidatos& cands) {
    int num = stoi(num_part);
    setNum_partido(num);
    num = stoi(votos_leg);
    setVotos_leg(num);
    setNome_part(nome_part);
    setSigla_part(sigla_part);  
    
    for (int i = 0; i < candidatos::qtd_candidatos(cands); i++)
        if (candidato::getNumero_partido(candidatos::getCandidato(cands, i+1)) == this->num_partido)
            this->cands.push_front(candidatos::getCandidato(cands, i+1));
    
    list<candidato*>::iterator it = this->cands.begin();
    int tam = this->cands.size();
    int cont = 0;
    for(int i=0; i < tam; i++, it++)
        if(!candidato::getDestino_voto(*it).compare("Válido"))
            cont += candidato::getVotos_nominais(*it);
    setVotos_nome(cont);
}
Partido::Partido(){
    this->num_partido  = 0;
    this->votos_leg    = 0;
    this->votos_nome   = 0;
    this->nome_part    = "";
    this->sigla_part   = "";
}

void Partido::setNum_partido(int num_partido){
    this->num_partido = num_partido;
}
void Partido::setVotos_leg(int votos_leg){
    this->votos_leg = votos_leg;
}
void Partido::setVotos_nome(int votos_nome){
    this->votos_nome = votos_nome;
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
int Partido::getVotos_nome(){
    return this->votos_nome;
}
string Partido::getNome_part(){
    return this->nome_part;
}
string Partido::getSigla_part(){
    return this->sigla_part;
}
int Partido::getQtd_eleitos(){
    list<candidato*>::iterator it = this->cands.begin();
    int cont = 0;
    
    int tam = this->cands.size();
    for(int i=0; i < tam; i++, it++)
        if(candidato::getSituacao(*it))
            cont++;
    return cont;
}
candidato* Partido::getMaisVotado(){
    this->cands.sort(candidatos::getMaisVotado);
    return this->cands.front();
}
candidato* Partido::getMenosVotado(){
    this->cands.sort(candidatos::getMenosVotado);
    return this->cands.front();
}