// http://www.cplusplus.com/reference/string/

#include <string>   // inclui classe string!!!!
using namespace std; // incluindo um espaço de nome!!!

int main () {
	string s1 = "Um", s2("Dois"); // criando duas strings
	if (s1 != s2) { // comparando duas strings, podemos usar ==, <, >, <=, >=, !=
		int tam = s1.length(); // número de caracteres
		s2.clear();            // limpa o conteúdo da string
		
		if (s2.empty()) {
			s2 = s1 + " mais Um"; // concatenação de string
			char c = s2.at(0);    // .at(i) retorna o i-ésimo caracter
			const char *cStr = s1.c_str(); // converter para uma string em C (char *).
		}
	}
    // podemos fazer cópia sem medo (operator = e construtor de cópia já definidos)!!!
}
