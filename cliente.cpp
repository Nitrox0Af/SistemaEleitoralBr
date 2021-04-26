#include <iostream>
#include <fstream>
#include <string>
#include "candidatos.h"

using namespace std;

int main()
{
    string line;
    ifstream myfile("candidatos.csv");
    string texto[2000];
    int i = 0;
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            if(i==0){
                i++;
                getline(myfile, line);
                continue;
            }
            getline(myfile, line);
            texto[i-1] = line;
            i++;
        }
        candidatos *cand = new candidatos(texto, i-1);
        //Inicio (Item 1)
        int Numero_eleitos = candidatos::num_eleitos(*cand);
        cout<<"Numero de vagas: "<< Numero_eleitos <<endl << endl;
        // Fim (Item 1)

        // inicio(Item2)
        //candidatos eleitos;
        int *eleitos = new int[Numero_eleitos];
        i=0;
        eleitos=candidatos::getCandidatosEleitos(*cand, Numero_eleitos);

        //Fim(Item 2)

        delete cand;
        myfile.close();
    }
    else
        cout << "Unable to open file";

    return 0;
}
//https://www.geeksforgeeks.org/how-to-split-a-string-in-cc-python-and-java/ 25/03
//https://www.portalgsti.com.br/2018/04/listas-pilhas-e-filas-em-c.html dia 25/03
//https://www.hardware.com.br/comunidade/ler-arquivos/1061210/ dia 25/03
//https://stackoverflow.com/questions/9654507/using-int-list-in-c dia 26/03