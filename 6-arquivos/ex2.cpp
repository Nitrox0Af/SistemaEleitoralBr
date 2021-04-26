#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
	ifstream in("arq.txt"); // fluxo de entrada
	string linha;
	while (getline(in, linha)) // usa a função getline para ler do fluxo de entrada in
        cout << linha << endl;
	in.close();
}

