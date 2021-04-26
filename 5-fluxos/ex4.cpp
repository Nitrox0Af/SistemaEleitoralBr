#include <iostream>
#include <string>
using namespace std;

int main () {
	string nome;
	cout << "Qual é o seu nome?\n";
	getline(cin, nome);         // lê a linha toda!!!!
	cout << "Olá, " << nome << "!\n";
}


