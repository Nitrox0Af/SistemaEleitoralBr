#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <chrono>
#include "Arquivo.h"
#include "Partidos.h"

using namespace std;
using namespace chrono;

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

    ofstream saida;

    saida.open("output.txt");

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
    saida << "Número de vagas: " << Numero_eleitos << endl << endl;
    // Fim (Item 1)

    // inicio(Item2)
    candidatos *eleitos = NULL;
    eleitos = candidatos::getCandidatosEleitos(*cand);
    saida << "Vereadores eleitos:" << endl;
    i = 1;
    list<candidato *>::iterator it;
    list<candidato *> listaAux = candidatos::getLista(eleitos);
    for (it = listaAux.begin(); it != listaAux.end(); ++it, i++) {
        saida << i << " - ";
        saida << candidato::getNome(*it) << " / ";
        saida << candidato::getNome_urna(*it) << " (";
        saida << Partidos::getPartido(*parts, *it)->getSigla_part() << ", ";
        saida << candidato::getVotos_nominais(*it) << " votos)" << endl;
    }
    saida << endl;
    //Fim(Item 2)

    //inicio(Item3)
    saida << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;
    candidatos *maisVotados = NULL;
    maisVotados = candidatos::candidatosMaisVotados(*cand);
    i = 1;
    listaAux = candidatos::getLista(maisVotados);
    for (it = listaAux.begin(); i <= Numero_eleitos; ++it, i++) {
        saida << i << " - ";
        saida << candidato::getNome(*it) << " / ";
        saida << candidato::getNome_urna(*it) << " (";
        saida << Partidos::getPartido(*parts, *it)->getSigla_part() << ", ";
        saida << candidato::getVotos_nominais(*it) << " votos)" << endl;
    }
    saida << endl;
    //Fim(Item 3)

    //inicio(Item4)
    saida << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:" << endl;
    saida << "(com sua posição no ranking de mais votados)" << endl;
    candidatos *Teriam_eleitos = NULL;
    Teriam_eleitos = candidatos::candidatosMaisVotados(*cand);
    i = 1;
    listaAux = candidatos::getLista(Teriam_eleitos);
    for (it = listaAux.begin(); i <= Numero_eleitos; ++it, i++) {
        if (candidato::getSituacao(*it) == 1) {
            continue;
        }
        saida << i << " - ";
        saida << candidato::getNome(*it) << " / ";
        saida << candidato::getNome_urna(*it) << " (";
        saida << Partidos::getPartido(*parts, *it)->getSigla_part() << ", ";
        saida << candidato::getVotos_nominais(*it) << " votos)" << endl;
    }
    saida << endl;
    //Fim(Item 4)

    //inicio(Item 5)
    saida << "Eleitos, que se beneficiaram do sistema proporcional:" << endl;
    saida << "(com sua posição no ranking de mais votados)" << endl;
    candidatos *Teriam_nao_eleitos = NULL;
    Teriam_nao_eleitos = candidatos::candidatosMaisVotados(*cand);
    i = 1;
    listaAux = candidatos::getLista(Teriam_eleitos);
    for (it = listaAux.begin(); it != listaAux.end(); ++it, i++) {
        if (i > Numero_eleitos && candidato::getSituacao(*it) == 1) {
            saida << i << " - ";
            saida << candidato::getNome(*it) << " / ";
            saida << candidato::getNome_urna(*it) << " (";
            saida << Partidos::getPartido(*parts, *it)->getSigla_part() << ", ";
            saida << candidato::getVotos_nominais(*it) << " votos)" << endl;
        }
    }
    //Fim(Item 5)

    //Inicio (Item 6)
    saida << "\nVotação dos partidos e número de candidatos eleitos:";
    Partidos* ordenado = parts;
    Partidos::organizaPartidos(*ordenado);
    for (int i = 0; i < Partidos::qtd_partidos(*ordenado); i++) {
        Partido* aux = Partidos::getPartido(*ordenado, i + 1);
        saida << endl << (i + 1) << " - " << aux->getSigla_part() << " - " << aux->getNum_partido() << ", ";

        if ((aux->getVotos_leg() + aux->getVotos_nome()) > 1)
            saida << (aux->getVotos_leg() + aux->getVotos_nome()) << " votos (";
        else
            saida << (aux->getVotos_leg() + aux->getVotos_nome()) << " voto (";

        if (aux->getVotos_nome() > 1)
            saida << aux->getVotos_nome() << " nominais e " << aux->getVotos_leg() << " de legenda), ";
        else
            saida << aux->getVotos_nome() << " nominal e " << aux->getVotos_leg() << " de legenda), ";

        if (aux->getQtd_eleitos() > 1)
            saida << aux->getQtd_eleitos() << " candidatos eleitos";
        else
            saida << aux->getQtd_eleitos() << " candidato eleito";
    }
    //Fim (Item 6)

    //Inicio (Item 7)
    saida << "\n\n" << "Primeiro e último colocados de cada partido:";
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

        saida << endl << (i + 1) << " - " << sigla << " - " << num_part << ", ";

        //mais votado
        saida << candidato::getNome_urna(aux) << " (" << candidato::getNumero_candidato(aux) << ", ";
        if (candidato::getVotos_nominais(aux) > 1)
            saida << candidato::getVotos_nominais(aux) << " votos) / ";
        else
            saida << candidato::getVotos_nominais(aux) << " voto) / ";
        //menos votado
        list<candidato*> ::iterator it = menosVotado.begin();
        candidato* aux2;
        for (int i = 0; i < menosVotado.size(); i++, it++)
            if (candidato::getNumero_partido(*it) == num_part)
                aux2 = *it;
        saida << candidato::getNome_urna(aux2) << " (" << candidato::getNumero_candidato(aux2) << ", ";
        if (candidato::getVotos_nominais(aux2) > 1)
            saida << candidato::getVotos_nominais(aux2) << " votos)";
        else
            saida << candidato::getVotos_nominais(aux2) << " voto)";
    }
    //Fim (Item 7)

    saida << fixed << setprecision(2);

    //Inicio (Item 8)
    saida << "\n\nEleitos, por faixa etária (na data da eleição):";
    int aux[5];
    aux[0] = 0;
    aux[1] = 0;
    aux[2] = 0;
    aux[3] = 0;
    aux[4] = 0;
    vector<int> idades = candidatos::getIdades(data, *eleitos);
    vector<int> ::iterator idade = idades.begin();
    for (int i = 0; i < idades.size(); i++, idade++) {
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
    saida << "\nIdade < 30: " << aux[0];
    saida << "\n30 <= Idade < 40: " << aux[1];
    saida << "\n40 <= Idade < 50: " << aux[2];
    saida << "\n50 <= Idade < 60: " << aux[3];
    saida << "\n0 <= Idade     : " << aux[4];
    //Fim (Item 8)

    //Inicio (Item 9)
    int masculino = candidatos::qtdHomens(eleitos);
    int femenino = candidatos::qtdMulheres(eleitos);
    saida << "\n\nEleitos, por sexo:";

    saida << "\nFeminino: " << femenino << " (" << (femenino * 100.0 / (masculino + femenino)) << "%)";
    saida << "\nMasculino: " << masculino << " (" << (masculino * 100.0 / (masculino + femenino)) << "%)";
    //Fim (Item 9)

    //Inicio (Item 10)
    int nominais = Partidos::VotosNome(*parts);
    int legenda = Partidos::VotosLeg(*parts);
    int validos = nominais + legenda;
    saida << "\n\nTotal de votos válidos:    " << validos;
    saida << "\nTotal de votos nominais:   " << nominais << " (" << (nominais * 100.0 / validos) << "%)";
    saida << "\nTotal de votos de Legenda: " << legenda << " (" << (legenda * 100.0 / validos) << "%)";
    //Fim (Item 10)
    saida << "\n";
    arquivo_Cand.fechar();
    arquivo_Part.fechar();
    saida.close();
    delete cand;
    delete parts;
    delete eleitos;
    delete maisVotados;
    delete Teriam_eleitos;
    delete Teriam_nao_eleitos;
    return 0;
}