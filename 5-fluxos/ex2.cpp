#include <iostream>
using namespace std;

int main () {
	cout << "Hello, world!\n";
	cout << "Um inteiro: ";
	cout << 10;
	cout << " e um float: " << 10.5 << endl; // endl = '\n', constante com quebra de linha!

	int valor;
	cout << "Digite um valor: ";
	cin >> valor;
	cout << "O dobro é: " << valor * 2 << endl;
}

