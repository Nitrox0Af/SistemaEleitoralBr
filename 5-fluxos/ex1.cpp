#include <iostream>     // biblioteca de entrada e saída do C++
using namespace std;    // vamos usar, sem se preocupar por agora...

// cout é fluxo de saída padrão (stdout no C). Operador << (Operador de inserção)
// cin é fluxo de entrada padrão (stdin no C). Operador >> (Operador de extração)
// Esses operadores funcionam com a classe string

int main () {
    string t("teste");
	cout << "Hello, world!\n";
	cout << "Um inteiro: ";
	cout << 10;
	cout << " e um float: " << 10.5 << '\n';
    cout << t << '\n'; // o operador funciona com tipo string

	int valor;
	cout << "Digite um valor: ";
	cin >> valor;
	cout << "O dobro é: " << valor * 2 << '\n';
}

