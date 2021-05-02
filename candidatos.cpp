#include "candidatos.h"

vector<int> Retorna_data(string s);
//retorna um vetor do tipo int
//configorado da seguinte forma dd/mm/aaaa

string *entrada(string s);
//funcao auxiliar de canidatos
//recebe uma string e retorna um vetor de strings alocados
//esse vetor tera sempre 9 strings alocados
//cada string recebe uma informacao de s,
//sendo s contem as informacoes de cada candidato separado por virgulas

//construtores:
candidatos::candidatos() {
}

candidatos::candidatos(string *texto, int n) {
    string *info;
    for (int i = 0; i < n; i++) {
        info = entrada(texto[i]);
        lista.push_front(new candidato(info));
        delete[] info;
    }
}

//destrutor:
candidatos::~candidatos() {
    candidato *aux;
    while (!lista.empty()) {
        aux = lista.back();
        lista.pop_back(); /* delete the pointer from the list */
        delete aux; /* free the allocated memory */
    }
}

//operadores:
candidatos& candidatos::operator=(candidatos &c) {
    if(!this->lista.empty()){
        delete this;
    }
    list<candidato*>::iterator it;
    for (it = c.lista.begin(); it != c.lista.end(); ++it) {
        candidato *aux1 = new candidato();
        *aux1 = *(*it);
        this->lista.push_front(aux1);
    }
    return *this;
}

//Funcoes
candidatos* candidatos::getCandidatosEleitos(candidatos &c) {
    candidatos* aux = new candidatos;
    int i = 0;
    list<candidato *>::iterator it;
    for (it = c.lista.begin(); it != c.lista.end(); ++it) {
        if (candidato::getSituacao(*it)) {
            candidato *aux1 = new candidato();
            *aux1 = *(*it);
            aux->lista.push_front(aux1);
            i++;
        }
    }
    organizar_por_votos_nominais(aux);
    return aux;
}

list<candidato*> candidatos::getLista(candidatos* c){
    return c->lista;
}

int candidatos::num_eleitos(candidatos &c) {
    int i = 0;
    list<candidato *>::iterator it;
    for (it = c.lista.begin(); it != c.lista.end(); ++it) {
        if (candidato::getSituacao(*it)) {
            i++;
        }
    }
    return i;
}

int candidatos::organizar_por_idade(candidato* c,candidato* d){
    candidato *aux;
    string aux1;
    string aux2;
    vector<int> num1;
    vector<int> num2;
    aux1 = candidato::getData_nasc(c);
    aux2 = candidato::getData_nasc(d);
    num1 = Retorna_data(aux1);
    num2 = Retorna_data(aux2);
    if (num1[2] > num2[2]) {
        return 1; //c mais novo
    } else if (num1[2] < num2[2]) {
        return 0; // d mais velho
    }
    else if (num1[2] == num2[2]) {
        if (num1[1] > num2[1]) {
            return 1;
        } else if (num1[1] < num2[1]) {
            return 0;
        }
        else if (num1[1] == num2[1]) {
            if (num1[0] > num2[0]) {
                return 1;
            } else if (num1[0] <= num2[0]) {
                return 0;
            }
        }
    }
    return 0;
}

void candidatos::organizar_por_votos_nominais(candidatos *c) {
    candidato *aux1;
    list<candidato *>::iterator it;
    list<candidato *>::iterator it2;
    int i = 1;
    int aux2;
    int aux3;
    vector<int> num1;
    vector<int> num2;
    for (it = c->lista.begin(); it != c->lista.end(); ++it, i++) {
        for (it2 = it, ++it2; it2 != c->lista.end(); ++it2) {
            aux2 = candidato::getVotos_nominais(*it);
            aux3 = candidato::getVotos_nominais(*it2);
            if (aux3 > aux2) {
                aux1 = *it;
                *it = *it2;
                *it2 = aux1;
            } else if (aux3 < aux2) {
                //fazer nada
            } else if (aux3 == aux2) {
                if(organizar_por_idade(*it,*it2)){
                    aux1 = *it;
                    *it = *it2;
                    *it2 = aux1;
                }
            }
        }
    }
}

candidatos* candidatos::candidatosMaisVotados(candidatos &c){
    candidatos* aux = new candidatos;
    *aux=c;
    organizar_por_votos_nominais(aux);
    return aux;
}

vector<int> Retorna_data(string s) {
    vector<int> aux;
    string del = "/";
    int start = 0;
    int end = s.find(del);
    aux.push_back(stoi(s.substr(start, end - start)));
    start = end + del.size();
    end = s.find(del, start);
    aux.push_back(stoi(s.substr(start, end - start)));
    start = end + del.size();
    end = s.find(del, start);
    aux.push_back(stoi(s.substr(start, end - start)));
    return aux;
}

string *entrada(string s) {
    string del = ",";
    int start = 0;
    int end = s.find(del);
    int i = 0;
    string *texto = new string[9];
    while (end != -1) {
        texto[i] = s.substr(start, end - start);
        i++;
        start = end + del.size();
        end = s.find(del, start);
    }
    texto[i] = s.substr(start, end - start);
    return texto;
}


int candidatos::qtd_candidatos(candidatos& c){
    return c.lista.size();
}

int candidatos::qtdHomens(candidatos *c){
    list<candidato*> ::iterator it =  c->lista.begin();
    int cont =0;
    
    for(int i=0; i<c->lista.size(); i++, it++)
        if(!candidato::getSexo(*it).compare("M"))
            cont++;
    return cont;
}

int candidatos::qtdMulheres(candidatos* c){
    list<candidato*> ::iterator it =  c->lista.begin();
    int cont =0;
    
    for(int i=0; i<c->lista.size(); i++, it++)
        if(!candidato::getSexo(*it).compare("F"))
            cont++;
    return cont;
}

candidato* candidatos::getCandidato(candidatos& c, int n){
    int i=0;
    
    list <candidato*> :: iterator it;
    for(it = c.lista.begin(); i<n-1; i++, it++);
    
    return *it;
}

bool candidatos::getMaisVotado(candidato* A, candidato* B){
    int votosA = candidato::getVotos_nominais(A);
    int votosB = candidato::getVotos_nominais(B);
    if (votosA > votosB)
       return true;
    else if(votosA == votosB)
        if(candidato::getNumero_candidato(A)<candidato::getNumero_candidato(B))
            return true;
    return false;
}
bool candidatos::getMenosVotado(candidato* A, candidato* B){
    int votosA = candidato::getVotos_nominais(A);
    int votosB = candidato::getVotos_nominais(B);
    if (votosA < votosB)
       return true;
    else if(votosA == votosB)
        if(candidato::getNumero_candidato(A)<candidato::getNumero_candidato(B))
            return true;
    return false;
}