#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void quebraLinha(const string& s) { // passando por referência e como const
    istringstream ss(s); // define um fluxo sobre a string
    string token;
    while (getline(ss, token, ' '))
        cout << token << endl;
}

int main () {
	ifstream in("arq.txt");
	string linha;
	while (getline(in, linha)) { // lendo a linha do arquivo
        quebraLinha(linha);      // quebrar a linha em tokens separados por ' '
    }
	in.close();
}
