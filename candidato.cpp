#include "candidato.h"
candidato::candidato(string* info, int n){
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
int candidato::candidato::getNumero_partido(candidato* c){
    return c->numero_partido;
}

 candidato& candidato::operator=(const candidato& c){
     cout<<"entrou aki oh"<<endl;
    if (this == &c)
        return *this;
        this->numero=c.numero;
        this->votos_nominais=c.votos_nominais;
        this->situacao=c.situacao;
        this->nome=c.nome;
        this->nome_urna=c.nome_urna;
        this->sexo=c.sexo;
        this->data_nasc=c.data_nasc;
        this->destino_voto=c.destino_voto;
        this->numero_partido=c.numero_partido;
    return *this;
}

candidato::~candidato(){}