#include "candidatos.h"
string* entrada(string s);

candidatos::candidatos(){
}
candidatos::candidatos(string* texto, int n){
    string* info;
    for(int i = 0; i < n-1; i++)
    {
        info=entrada(texto[i]);
        lista.push_front(new candidato(info, 9));
        delete[] info;
    }
}

string* entrada(string s)
{
    string del = ",";
    int start = 0;
    int end = s.find(del);
    int i=0;
    string* texto = new string[9];
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

candidatos::~candidatos(){
    candidato* aux;
    while(!lista.empty()){
        aux=lista.back();
        lista.pop_back(); /* delete the pointer from the list */
        delete aux; /* free the allocated memory */
    }
}

candidatos& candidatos::operator=(const candidatos& c){
    return *this;
}

int candidatos::num_eleitos(candidatos& c){
    int i=0;
    list <candidato*> :: iterator it;
    for(it = c.lista.begin(); it != c.lista.end(); ++it){
        if(candidato::getSituacao(*it)){
            i++;
        }
    }
    return i;
}

int* candidatos::getCandidatosEleitos(candidatos& c, int n){
    int *aux = new int[n];
    //candidatos* aux= new candidatos;
    //candidato* aux1;
    int i=0;
    list <candidato*> :: iterator it;
    for(it = c.lista.begin(); it != c.lista.end(); ++it){
        if(candidato::getSituacao(*it)){
            aux[i]=candidato::getNumero_candidato(*it);
            //aux1=*it;
            //aux->lista.push_front(aux1);
            i++;
        }
    }
    return aux;
}