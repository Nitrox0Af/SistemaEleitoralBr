#include <string>
#include <iostream>
using namespace std;

int main () {
	string resposta;        // declarando uma string
	bool resultado = true;  // Em C++, temos bool
	
	while (resultado) {
		getline(cin, resposta);     // lendo uma linha e salvando o conteúdo em resposta!
		int cmp = resposta.compare("S"); // retorna 0 se resposta for 'S'
                                         // resposta == "N"
		resultado = cmp;                 // inteiros são automaticamente convertidos para bool
	}
}
