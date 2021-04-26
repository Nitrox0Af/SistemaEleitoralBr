#include <iostream>
#include <fstream> // biblioteca para ler e escrever em arquivos!!
#include <string>
using namespace std;

const int MAX = 10;

int main () {
	ofstream out("arq.txt"); // criando um arquivo!!!!
	for (int i = 0; i < MAX; i++) 
        out << "Valor de i = " << i << endl; // para escrever, uso o operador de inserção
	out.close();
}

