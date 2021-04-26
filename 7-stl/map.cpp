#include <map>
#include <iostream>

using namespace std;

int main() {
    map<string, int> w;

    // adicionando alguns elementos
    // reparem que podemos usar maps, na mesma sintaxe de vetores
    for (int i = 0; i < 10; i++)
        w[to_string(i)] = i;

    // para verificar se um map tem uma chave, usamos o find
    for (int i = 0; i < 20; i++)
        cout << "w tem chave " << i << "? " 
             << !(w.find(to_string(i)) == end(w)) << endl;

    // primeira, acessando diretamente
    for (int i = 0; i < 10; i++)
        cout << w[to_string(i)] << endl;

    // C++ antigo
    for (map<string, int>::iterator it = begin(w); it != end(w); ++it)
        cout << it->first << " " << it->second << endl;

    // C++11 para frente
    // for avançado
    // conceito do auto
    for (const auto& par : w)
        cout << par.first << " " << par.second << endl;

    return 0;
}
