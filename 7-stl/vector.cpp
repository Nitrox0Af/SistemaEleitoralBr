#include <vector>
#include <iostream>

using namespace std;

// Por padrão, em C++, toda passagem de parâmetro é por cópia!
// Uma cópia de x vai ser feita quando chamarmos a função!
void fBad(vector<int> x) {
    for (int i : x)
        cout << i << endl;
}

// Passagem por referência não faz cópia
// O 'const' indica que não vamos modificar o conteúdo do vector.
void fGood(const vector<int>& x) {

    // auto, o tipo do i vai ser inferido pelo compilador.
    // A referência garante que não vou fazer cópias dos elementos de x para i
    // O const garante que não vamos modificar i
    for (const auto& i : x)
        cout << i << endl;
}

int main() {
    vector<int> v;
    vector<string> w;

    for (int i = 0; i < 10; i++) {
        v.push_back(i);
        w.push_back(to_string(i));
    }

    fBad(v);
    cout << "--" << endl;
    fGood(v);

    return 0;
}
