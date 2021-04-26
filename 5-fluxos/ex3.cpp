#include <iostream>
using namespace std;

int main () {
    string nome;                        // string nome
	cout << "Qual é o seu nome?\n";
	cin >> nome;                        // lê o nome (o delimitador do cin é o espaço)
	cout << "Olá, " << nome << "!\n";   // imprime o nome
}

