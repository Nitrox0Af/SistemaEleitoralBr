#include <iostream>
#include <fstream>
#include <algorithm>
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
    cout<<endl;
    //Fim(Item 2)

    //inicio(Item3)
    cout<<"Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):"<<endl;
    candidatos *maisVotados= NULL;
    maisVotados=candidatos::candidatosMaisVotados(*cand);
    i=1;
    listaAux = candidatos::getLista(maisVotados);
    for (it = listaAux.begin(); i<=Numero_eleitos ; ++it, i++) {
        cout<<i<<" - ";
        cout<<candidato::getNome(*it)<<" / ";
        cout<<candidato::getNome_urna(*it)<<"(";
        cout<<"colocar nome partido"<<", ";
        cout<<candidato::getVotos_nominais(*it)<<" votos)"<<endl;
    }
    cout << endl;
    //Fim(Item 3)

    //inicio(Item4)
    cout<<"Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:" << endl;
    cout<<"(com sua posição no ranking de mais votados)"<<endl;
    candidatos *Teriam_eleitos= NULL;
    Teriam_eleitos= candidatos::candidatosMaisVotados(*cand);
    i=1;
    listaAux = candidatos::getLista(Teriam_eleitos);
    for (it = listaAux.begin(); i<=Numero_eleitos ; ++it, i++) {
        if(candidato::getSituacao(*it)==1){
            continue;
        }
        cout<<i<<" - ";
        cout<<candidato::getNome(*it)<<" / ";
        cout<<candidato::getNome_urna(*it)<<"(";
        cout<<"colocar nome partido"<<", ";
        cout<<candidato::getVotos_nominais(*it)<<" votos)"<<endl;
    }
    cout << endl;
    //Fim(Item 4)

    //inicio(Item 5)
    cout<<"Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:"<<endl;
    cout<<"(com sua posição no ranking de mais votados)"<<endl;
    candidatos *Teriam_nao_eleitos= NULL;
    Teriam_nao_eleitos= candidatos::candidatosMaisVotados(*cand);
    i=1;
    listaAux = candidatos::getLista(Teriam_eleitos);
    for (it = listaAux.begin();it != listaAux.end(); ++it, i++) {
        if( i > Numero_eleitos && candidato::getSituacao(*it)==1) {
            cout << i << " - ";
            cout << candidato::getNome(*it) << " / ";
            cout << candidato::getNome_urna(*it) << "(";
            cout << "colocar nome partido" << ", ";
            cout << candidato::getVotos_nominais(*it) << " votos)" << endl;
        }
    }
    //Fim(Item 5)

    //Inicio (Item 6)
    cout << "\n\n" << "Votação dos partidos e número de candidatos eleitos:";
    Partidos* ordenado = parts;
    Partidos::organizaPartidos(*ordenado);
    for(int i=0; i< Partidos::qtd_partidos(*ordenado); i++){
        Partido* aux = Partidos::getPartido(*ordenado, i+1);
        cout << endl << (i+1) << " - " << aux->getSigla_part() << " - " << aux->getNum_partido() << ", " ;
        
        if((aux->getVotos_leg() + aux->getVotos_nome()) < 2)
            cout << (aux->getVotos_leg() + aux->getVotos_nome()) << " voto (";
        else
            cout << (aux->getVotos_leg() + aux->getVotos_nome()) << " votos (";
        
        if(aux->getVotos_nome() < 2)
            cout << aux->getVotos_nome() << " nominal e " << aux->getVotos_leg() << " de legenda), ";
        else
            cout << aux->getVotos_nome() << " nominais e " << aux->getVotos_leg() << " de legenda), ";
        
        if(aux->getQtd_eleitos() < 2)
            cout << aux->getQtd_eleitos() << " candidato eleito";
        else
            cout << aux->getQtd_eleitos() << " candidatos eleitos";
    }
    //Fim (Item 6)
    
    //Inicio (Item 7)
    cout << "\n\n" << "Primeiro e último colocados de cada partido:";
    candidato** c = new candidato*[Partidos::qtd_partidos(*parts)];
    for(int i=0; i< Partidos::qtd_partidos(*parts); i++){
        Partido* aux = Partidos::getPartido(*parts, i+1);
        c[i] = new candidato[2];
        c[i][0] = *aux->getMaisVotado();
        c[i][1] = *aux->getMenosVotado();
    }
    delete[] c;
    //Fim (Item 7)
    
    arquivo_Cand.fechar();
    arquivo_Part.fechar();
    delete cand;
    delete parts;
    delete eleitos;
    delete maisVotados;
    delete Teriam_eleitos;
    delete Teriam_nao_eleitos;
    return 0;
}