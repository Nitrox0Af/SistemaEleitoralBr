#include <string>
#include <iostream>
using namespace std;

// Passando argumento dessa forma, r vai uma cópia de s.
// isso é não eficiente se for feito muitas vezes ou se s for uma string grande!
// Isso é o que não devemos fazer
void f(string r) {
}

// Passando pro referência, a cópia não é feita!!!
// Mas se fizer dessa forma, agora a função pode modificar s como efeito colateral
void g(string& r) {
}

// Dessa forma, a passagem é por referência e o conteúdo de s não pode ser modificado!!!
void h(const string& r) {
}

int main () {
	string s = "teste!";
    f(s);
    g(s);
    h(s);
}
