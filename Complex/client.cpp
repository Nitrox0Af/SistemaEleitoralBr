#include "Complex.h"

int main() {
    Complex i; // 0
    Complex j(2, 2); // 2 + 2i
    Complex k(-1, 1); // -1 + i
    i.println();
    j.println();
    k.println();

    j = j + k + i;
    j.println();

    k = k * j;
    k.println();
 
    return 0;
}
