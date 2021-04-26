#include <set>
#include <iostream>

using namespace std;

int main() {
    set<string> w;

    // inserindo elementos de "0" a "9"
    for (int i = 0; i < 10; i++)
        w.insert(to_string(i));

    // Vou fazer uma busca por todos elementos de "0" a "19"
    // Para fazer busca, usamos 'find'
    // Ela retorna para gente uma referência/ponteiro se ele existe
    // Ela retorna end(w), se não existe
    for (int i = 0; i < 20; i++)
        cout << "w tem " << i << "? " 
             << !(w.find(to_string(i)) == end(w)) << endl;
    

    return 0;
}
