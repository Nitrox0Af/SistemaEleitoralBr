#include "candidato.h"
candidato::candidato(string* info){
    numero = stoi(info[0]);
    votos_nominais=stoi(info[1]);
    situacao=info[2];
    nome=info[3];
    nome_urna=info[4];
    sexo=info[5];
    data_nasc=info[6];
    destino_voto=info[7];
    numero_partido=stoi(info[8]);
}
candidato::candidato(){
    numero = 0;
    votos_nominais=0;
    situacao="";
    nome="";
    nome_urna="";
    sexo="";
    data_nasc="";
    destino_voto="";
    numero_partido=0;
}

candidato::~candidato(){
}

candidato& candidato::operator=(const candidato& c){
    if (this == &c)
        return *this;
    this->numero=c.numero;
    this->votos_nominais=c.votos_nominais;
    this->nome=c.nome;
    this->situacao=c.situacao;
    this->nome_urna=c.nome_urna;
    this->sexo=c.sexo;
    this->data_nasc=c.data_nasc;
    this->destino_voto=c.destino_voto;
    this->numero_partido=c.numero_partido;
    return *this;
}

int candidato::getSituacao(candidato* c){
    int i=0;
    if(c->situacao == "Eleito"){
        i++;
    }
    return i;
}
int candidato::getNumero_candidato(candidato* c){
    return c->numero;
}
int candidato::getNumero_partido(candidato* c){
    return c->numero_partido;
}

int candidato::getVotos_nominais(candidato* c){
    return c->votos_nominais;
}
string candidato::getNome(candidato* c){
    return c->nome;
}
string candidato::getNome_urna(candidato* c){
    return c->nome_urna;
}
string candidato::getSexo(candidato* c){
    return c->sexo;
}

string candidato::getData_nasc(candidato* c){
    return c->data_nasc;
}

string candidato::getDestino_voto(candidato* c){
    return c->destino_voto;
}
