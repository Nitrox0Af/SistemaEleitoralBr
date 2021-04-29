#include "Partidos.h"

string* split(string s);

Partidos::Partidos (ifstream& arquivo, candidatos& cands){
    string linha;
    
    getline(arquivo, linha);
    for(;getline(arquivo, linha); this->qtd_partidos++) {
        string* palavras = split(linha);
        partidos.push_back(new Partido(palavras[0], palavras[1], palavras[2], palavras[3], cands));
        delete[] palavras;
    }
    this->qtd_partidos = this->qtd_partidos + 1;
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

Partidos::~Partidos(){
    Partido* aux;
    while(!this->partidos.empty()){
        aux=this->partidos.back();
        this->partidos.pop_back(); 
        delete aux; 
    }
}