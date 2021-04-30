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
    candidatos *cand = new candidatos(texto, i);
    
    Partidos* parts = new Partidos(arquivo_Part.arquivo, *cand);
    
    //Inicio (Item 1)
    int Numero_eleitos = candidatos::num_eleitos(*cand);
    cout << "Numero de vagas: " << Numero_eleitos << endl << endl;
    // Fim (Item 1)

    // inicio(Item2)
    candidatos *eleitos=NULL;
    eleitos = candidatos::getCandidatosEleitos(*cand);
    cout<<"Vereadores eleitos:"<<endl;
    i = 1;
    list<candidato *>::iterator it;
    list<candidato *> listaAux = candidatos::getLista(eleitos);
    for (it = listaAux.begin(); it != listaAux.end(); ++it, i++) {
        cout<<i<<" - ";
        cout<<candidato::getNome(*it)<<" / ";
        cout<<candidato::getNome_urna(*it)<<"(";
        cout<<"colocar nome partido"<<", ";
        cout<<candidato::getVotos_nominais(*it)<<" votos)"<<endl;
    }
    //Fim(Item 2)

    //inicio(Item3)
    cout<<"Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):";
    cout << endl<< endl;
    candidatos *maisVotados= NULL;
    maisVotados=candidatos::candidatosMaisVotados(*cand, Numero_eleitos);
    i=1;
    listaAux = candidatos::getLista(maisVotados);
    for (it = listaAux.begin(); i<=6 ; ++it, i++) {
        cout<<i<<" - ";
        cout<<candidato::getNome(*it)<<" / ";
        cout<<candidato::getNome_urna(*it)<<"(";
        cout<<"colocar nome partido"<<", ";
        cout<<candidato::getVotos_nominais(*it)<<" votos)"<<endl;
    }
    //Fim(Item 3)

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