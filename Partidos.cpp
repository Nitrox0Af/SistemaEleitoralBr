#include <algorithm>

#include "Partidos.h"

string* split(string s);

Partidos::Partidos (ifstream& arquivo, candidatos& cands){
    string linha;
    
    getline(arquivo, linha);
    while(getline(arquivo, linha)) {
        string* palavras = split(linha);
        this->lista.push_back(new Partido(palavras[0], palavras[1], palavras[2], palavras[3], cands));
        delete[] palavras;
    }
}

string* split(string s){
    string* texto = new string[4];
    
    for(int i=0; i < 4; i++){
        texto[i] = s.substr(0, s.find(","));
        s = s.substr(s.find(",")+1, s.size()-1);
    }
    return texto;
}

int Partidos::qtd_partidos(Partidos& p){
    return p.lista.size();
}

Partido* Partidos::getPartido(Partidos& p, int pos){
    list <Partido*> :: iterator it =p.lista.begin();
    
    for(int i=0; i<pos-1; i++, it++);
    
    return *it;
}
Partido* Partidos::getPartido(Partidos& p, candidato* c){
    list <Partido*> :: iterator it =p.lista.begin();
    int num_part = candidato::getNumero_partido(c);
    
    for(int i=0; i<p.lista.size(); i++, it++){
        Partido* aux = *it;
        if(aux->getNum_partido() == num_part)
            return aux;
    }
    return NULL;
}

void Partidos::organizaPartidos(Partidos& p){
    p.lista.sort(Partidos::comparaVotos);
}

bool Partidos::comparaVotos(Partido* a, Partido* b){
    int votosA = a->getVotos_nome() + a->getVotos_leg();
    int votosB = b->getVotos_nome() + b->getVotos_leg();
    if (votosA > votosB)
       return true;
    else if(votosA == votosB)
        if(a->getNum_partido() < b->getNum_partido())
            return true;
    return false;
}

Partidos::~Partidos(){
    Partido* aux;
    while(!this->lista.empty()){
        aux=this->lista.back();
        this->lista.pop_back(); 
        delete aux; 
    }
}