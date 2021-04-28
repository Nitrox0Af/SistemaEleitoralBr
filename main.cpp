#include <iostream>
#include <fstream>
#include "Arquivo.h"
#include "Partidos.h"
using namespace std;

int main(int argc, char** argv) {
    string arq_nomeCand = argv[1];
    string arq_nomePart = argv[2];
    string data = argv[3];


    Arquivo arquivo_Cand = Arquivo(arq_nomeCand);
    if (!arquivo_Cand.arquivo.is_open()) {
        cout << "\nNão foi possivel abrir o arquivo: " + arq_nomeCand;
        return 0;
    }
    Arquivo arquivo_Part = Arquivo(arq_nomePart);
    if (!arquivo_Cand.arquivo.is_open()) {
        cout << "\nNão foi possivel abrir o arquivo: " + arq_nomePart;
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
    candidatos *cand = new candidatos(texto, i);
    //Inicio (Item 1)
    int Numero_eleitos = candidatos::num_eleitos(*cand);
    cout << "Numero de vagas: " << Numero_eleitos << endl << endl;
    // Fim (Item 1)
    
    // inicio(Item2)
    //candidatos eleitos;
    
    int *eleitos = new int[Numero_eleitos];
    i = 0;
    eleitos = candidatos::getCandidatosEleitos(*cand, Numero_eleitos);
    //Fim(Item 2)
    
    
    Partidos* partidos = new Partidos(arquivo_Part.arquivo, *cand);
    
    arquivo_Cand.fechar();
    arquivo_Part.fechar();
    delete cand;
    delete partidos;
    return 0;
}