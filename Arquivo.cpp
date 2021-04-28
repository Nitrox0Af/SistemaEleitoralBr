#include "Arquivo.h"

Arquivo::Arquivo (string arq_nome){
    setNome(arq_nome);
    try {
        
        try {
            this->arquivo.open("" + this->arq_nome);
        } catch (exception& e) {
            try {
                this->arquivo.open("exemplos/capitais/" + this->arq_nome);
            } catch (exception& ex) {
                this->arquivo.open("exemplos/ES/" + this->arq_nome);
            }
        }
        
    } catch (exception& e) {
        ;
    }
}

void Arquivo::setNome(string nome) {
    this->arq_nome= nome;
}

string Arquivo::getNome() {
    return this->arq_nome;
}

void Arquivo::fechar(){
    this->arquivo.close();
}