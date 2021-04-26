#include<cstdio>

// a implementação do método/função vai ser inserida no código que a chama!!!
inline void swap(int& x, int& y) { // função para trocar valores de dois inteiros!!!
    int tmp = x;
    x = y;
    y = tmp;
}

int main() {
    int x = 1;
    int y = 2;
    printf("%d %d\n", x, y);
    swap(x, y);             // trocar os valores de x e y!!
    printf("%d %d\n", x, y);
    return 0;
}
