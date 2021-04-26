#include "String.h"

int main() {
    String i;
    String j("PIII");
    String k(" eh muito de boa");

    cout << i << endl;
    cout << j << endl;
    cout << k << endl;

    i = k;
    cout << i << endl;

    j = j + i;
    cout << j << endl;

    return 0;
}
