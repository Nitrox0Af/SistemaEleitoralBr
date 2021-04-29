#include <iostream>
#include <fstream>
#include "Arquivo.h"
#include "Partidos.h"
using namespace std;

int main(int argc, char** argv) {
    string arq_nomeCand = "candidatos.csv";
    string arq_nomePart = "partidos.csv";
    string data = "15/05/2000";


    Arquivo arquivo_Cand = Arquivo(arq_nomeCand);
    if (!arquivo_Cand.arquivo.is_open()) {
        cout << "\nNão foi possivel abrir o arquivo: " << arq_nomeCand << endl;
        return 0;
    }
    Arquivo arquivo_Part = Arquivo(arq_nomePart);
    if (!arquivo_Cand.arquivo.is_open()) {
        cout << "\nNão foi possivel abrir o arquivo: " << arq_nomePart << endl;
        return 0;
    }
    

    string line;
    string texto[2000];
    int i = 0;
    getline(arquivo_Cand.arquivo, line);
    while(getline(arquivo_Cand.arquivo, line)) {
        texto[i] = line;
        i++;
    }
    cout<< i << endl;
    candidatos *cand = new candidatos(texto, i);
    
    Partidos* parts = new Partidos(arquivo_Part.arquivo, *cand);
    
    //Inicio (Item 1)
    int Numero_eleitos = candidatos::num_eleitos(*cand);
    cout << "Numero de vagas: " << Numero_eleitos << endl << endl;
    // Fim (Item 1)
    
    // inicio(Item2)
    candidatos eleitos;
    //int *eleitos;
    i = 0;
    eleitos = candidatos::getCandidatosEleitos(*cand);

    //Fim(Item 2)
    
    //Inicio (Item 6)
    cout << endl;
    cout << "Votação dos partidos e número de candidatos eleitos:" << endl;
    for(int i=0; i< Partidos::qtd_partidos(*parts); i++){
        Partido* Aux = Partidos::pegaPartido(*parts, i+1);
        cout << (i+1) << " - " << Aux->getSigla_part() << " - " << Aux->getNum_partido() << ", " ;
        cout << Aux->getVotos_leg() << endl;        
    }
    
    arquivo_Cand.fechar();
    arquivo_Part.fechar();
    delete cand;
    delete parts;
    return 0;
}