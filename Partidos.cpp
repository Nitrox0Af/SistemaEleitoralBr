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
    string del = ",";
    int start = 0;
    int end = s.find(del);
    int i=0;
    string* texto = new string[4];
    while (end != -1)
    {
        texto[i]=s.substr(start, end - start);
        i++;
        start = end + del.size();
        end = s.find(del, start);
    }
    texto[i]=s.substr(start, end - start);
    return texto;
}

int Partidos::qtd_partidos(Partidos& p){
    return p.lista.size();
}

Partido* Partidos::pegaPartido(Partidos& p, int n){
    int i=0;
    
    list <Partido*> :: iterator it;
    for(it = p.lista.begin(); i<n-1; i++, it++);
    
    return *it;
}

Partidos::~Partidos(){
    Partido* aux;
    while(!this->lista.empty()){
        aux=this->lista.back();
        this->lista.pop_back(); 
        delete aux; 
    }
}