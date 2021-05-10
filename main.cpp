#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <chrono>
#include "Arquivo.h"
#include "Partidos.h"
#include <locale>
#include <locale.h>

using namespace std;
using namespace chrono;

int main(int argc, char** argv) {
    string arq_nomeCand = "candidatos.csv";
    string arq_nomePart = "partidos.csv";
    string data = argv[3];
    
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
    while (getline(arquivo_Cand.arquivo, line)) {
        texto[i] = line;
        i++;
    }
    candidatos *cand = new candidatos(texto, i);
    Partidos* parts = new Partidos(arquivo_Part.arquivo, *cand);

    //Inicio (Item 1)
    int Numero_eleitos = candidatos::num_eleitos(*cand);
    cout << "Número de vagas: " << Numero_eleitos << endl << endl;
    // Fim (Item 1)

    // inicio(Item2)
    candidatos *eleitos = NULL;
    eleitos = candidatos::getCandidatosEleitos(*cand);
    cout << "Vereadores eleitos:" << endl;
    i = 1;
    list<candidato *>::iterator it;
    list<candidato *> listaAux = candidatos::getLista(eleitos);
    for (it = listaAux.begin(); it != listaAux.end(); ++it, i++) {
        cout << i << " - ";
        cout << candidato::getNome(*it) << " / ";
        cout << candidato::getNome_urna(*it) << " (";
        cout << Partidos::getPartido(*parts, *it)->getSigla_part() << ", ";
        cout << candidato::getVotos_nominais(*it) << " votos)" << endl;
    }
    cout << endl;
    //Fim(Item 2)

    //inicio(Item3)
    cout << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;
    candidatos *maisVotados = NULL;
    maisVotados = candidatos::candidatosMaisVotados(*cand);
    i = 1;
    listaAux = candidatos::getLista(maisVotados);
    for (it = listaAux.begin(); i <= Numero_eleitos; ++it, i++) {
        cout << i << " - ";
        cout << candidato::getNome(*it) << " / ";
        cout << candidato::getNome_urna(*it) << " (";
        cout << Partidos::getPartido(*parts, *it)->getSigla_part() << ", ";
        cout << candidato::getVotos_nominais(*it) << " votos)" << endl;
    }
    cout << endl;
    //Fim(Item 3)

    //inicio(Item4)
    cout << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;
    candidatos *Teriam_eleitos = NULL;
    Teriam_eleitos = candidatos::candidatosMaisVotados(*cand);
    i = 1;
    listaAux = candidatos::getLista(Teriam_eleitos);
    for (it = listaAux.begin(); i <= Numero_eleitos; ++it, i++) {
        if (candidato::getSituacao(*it) == 1) {
            continue;
        }
        cout << i << " - ";
        cout << candidato::getNome(*it) << " / ";
        cout << candidato::getNome_urna(*it) << " (";
        cout << Partidos::getPartido(*parts, *it)->getSigla_part() << ", ";
        cout << candidato::getVotos_nominais(*it) << " votos)" << endl;
    }
    cout << endl;
    //Fim(Item 4)

    //inicio(Item 5)
    cout << "Eleitos, que se beneficiaram do sistema proporcional:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;
    candidatos *Teriam_nao_eleitos = NULL;
    Teriam_nao_eleitos = candidatos::candidatosMaisVotados(*cand);
    i = 1;
    listaAux = candidatos::getLista(Teriam_eleitos);
    for (it = listaAux.begin(); it != listaAux.end(); ++it, i++) {
        if (i > Numero_eleitos && candidato::getSituacao(*it) == 1) {
            cout << i << " - ";
            cout << candidato::getNome(*it) << " / ";
            cout << candidato::getNome_urna(*it) << " (";
            cout << Partidos::getPartido(*parts, *it)->getSigla_part() << ", ";
            cout << candidato::getVotos_nominais(*it) << " votos)" << endl;
        }
    }
    //Fim(Item 5)

    //Inicio (Item 6)
    cout << "\nVotação dos partidos e número de candidatos eleitos:";
    Partidos* ordenado = parts;
    Partidos::organizaPartidos(*ordenado);
    for (int i = 0; i < Partidos::qtd_partidos(*ordenado); i++) {
        Partido* aux = Partidos::getPartido(*ordenado, i + 1);
        cout << endl << (i + 1) << " - " << aux->getSigla_part() << " - " << aux->getNum_partido() << ", ";
        if ((aux->getVotos_leg() + aux->getVotos_nome()) > 1)
            cout << (aux->getVotos_leg() + aux->getVotos_nome()) << " votos (";
        else
            cout << (aux->getVotos_leg() + aux->getVotos_nome()) << " voto (";
        if (aux->getVotos_nome() > 1)
            cout << aux->getVotos_nome() << " nominais e " << aux->getVotos_leg() << " de legenda), ";
        else
            cout << aux->getVotos_nome() << " nominal e " << aux->getVotos_leg() << " de legenda), ";

        if (aux->getQtd_eleitos() > 1)
            cout << aux->getQtd_eleitos() << " candidatos eleitos";
        else
            cout << aux->getQtd_eleitos() << " candidato eleito";
    }
    //Fim (Item 6)

    //Inicio (Item 7)
    cout << "\n\n" << "Primeiro e último colocados de cada partido:";
    list<candidato*> maisVotado;
    list<candidato*> menosVotado;
    for (int i = 0; i < Partidos::qtd_partidos(*parts); i++) {
        Partido* aux = Partidos::getPartido(*parts, i + 1);
        if (aux->getVotos_leg() == 0)
            continue;
        maisVotado.insert(++maisVotado.begin(), aux->getMaisVotado());
        menosVotado.insert(++menosVotado.begin(), aux->getMenosVotado());
    }
    maisVotado.sort(candidatos::getMaisVotado);
    for (int i = 0; maisVotado.front(); i++, maisVotado.pop_front()) {
        candidato* aux = maisVotado.front();
        string sigla = Partidos::getPartido(*parts, aux)->getSigla_part();
        int num_part = Partidos::getPartido(*parts, aux)->getNum_partido();

        cout << endl << (i + 1) << " - " << sigla << " - " << num_part << ", ";

        //mais votado
        cout << candidato::getNome_urna(aux) << " (" << candidato::getNumero_candidato(aux) << ", ";
        if (candidato::getVotos_nominais(aux) > 1)
            cout << candidato::getVotos_nominais(aux) << " votos) / ";
        else
            cout << candidato::getVotos_nominais(aux) << " voto) / ";
        //menos votado
        list<candidato*> ::iterator it = menosVotado.begin();
        candidato* aux2;
        int tam = menosVotado.size();
        for (int i = 0; i < tam; i++, it++)
            if (candidato::getNumero_partido(*it) == num_part)
                aux2 = *it;
        cout << candidato::getNome_urna(aux2) << " (" << candidato::getNumero_candidato(aux2) << ", ";
        if (candidato::getVotos_nominais(aux2) > 1)
            cout << candidato::getVotos_nominais(aux2) << " votos)";
        else
            cout << candidato::getVotos_nominais(aux2) << " voto)";
    }
    //Fim (Item 7)

    cout << fixed << setprecision(2);

    //Inicio (Item 8)
    cout << "\n\nEleitos, por faixa etária (na data da eleição):";
    int aux[5];
    aux[0] = 0;
    aux[1] = 0;
    aux[2] = 0;
    aux[3] = 0;
    aux[4] = 0;
    vector<int> idades = candidatos::getIdades(data, *eleitos);
    vector<int> ::iterator idade = idades.begin();
    int tam = idades.size();
    for (int i = 0; i < tam; i++, idade++) {
        if (*idade < 30)
            aux[0] = aux[0] + 1;
        else if (*idade < 40)
            aux[1] = aux[1] + 1;
        else if (*idade < 50)
            aux[2] = aux[2] + 1;
        else if (*idade < 60)
            aux[3] = aux[3] + 1;
        else if (*idade >= 60)
            aux[4] = aux[4] + 1;
    }
    cout << "\n      Idade < 30: " << aux[0] << " (";
    cout.imbue(locale("pt_BR.utf8"));
    cout << (aux[0] * 100.0 / (aux[0]+aux[1]+aux[2]+aux[3]+aux[4])) <<"%)";
    cout.imbue(locale("C"));
    
    cout << "\n30 <= Idade < 40: " << aux[1] << " (";
    cout.imbue(locale("pt_BR.utf8"));
    cout << (aux[1] * 100.0 / (aux[0]+aux[1]+aux[2]+aux[3]+aux[4])) <<"%)";
    cout.imbue(locale("C"));
    
    cout << "\n40 <= Idade < 50: " << aux[2] << " (";
    cout.imbue(locale("pt_BR.utf8"));
    cout << (aux[2] * 100.0 / (aux[0]+aux[1]+aux[2]+aux[3]+aux[4])) <<"%)";
    cout.imbue(locale("C"));
    
    cout << "\n50 <= Idade < 60: " << aux[3] << " (";
    cout.imbue(locale("pt_BR.utf8"));
    cout << (aux[3] * 100.0 / (aux[0]+aux[1]+aux[2]+aux[3]+aux[4])) <<"%)";
    cout.imbue(locale("C"));
    
    
    cout << "\n60 <= Idade     : " << aux[4] << " (";
    cout.imbue(locale("pt_BR.utf8"));
    cout << (aux[4] * 100.0 / (aux[0]+aux[1]+aux[2]+aux[3]+aux[4])) <<"%)";
    cout.imbue(locale("C"));
    //Fim (Item 8)
    
    //Inicio (Item 9)
    int masculino = candidatos::qtdHomens(eleitos);
    int femenino = candidatos::qtdMulheres(eleitos);
    cout << "\n\nEleitos, por sexo:";

    cout << "\nFeminino:  " << femenino << " (";
    
    cout.imbue(locale("pt_BR.utf8"));
    cout << (femenino * 100.0 / (masculino + femenino)) << "%)";
    cout.imbue(locale("C"));
    
    cout << "\nMasculino: " << masculino << " (";
    
    cout.imbue(locale("pt_BR.utf8"));
    cout << (masculino * 100.0 / (masculino + femenino)) << "%)";
    cout.imbue(locale("C"));
    //Fim (Item 9)
    
    //Inicio (Item 10)
    int nominais = Partidos::VotosNome(*parts);
    int legenda = Partidos::VotosLeg(*parts);
    int validos = nominais + legenda;
    cout << "\n\nTotal de votos válidos:    " << validos;
    cout << "\nTotal de votos nominais:   " << nominais << " (";
    
    cout.imbue(locale("pt_BR.utf8"));
    cout << (nominais * 100.0 / validos) << "%)";
    cout.imbue(locale("C"));
    
    cout << "\nTotal de votos de Legenda: " << legenda << " (";
    
    cout.imbue(locale("pt_BR.utf8"));
    cout << (legenda * 100.0 / validos) << "%)";
    cout.imbue(locale("C"));    
    //Fim (Item 10)
    
    cout << endl << endl;
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