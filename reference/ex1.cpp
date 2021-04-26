#include<cstdio>

void f(int& j) {
    j++;
}

void g(int j) {
    j++;
}

int main() {
    int i = 0;
    printf("%d\n", i); // 0

    g(i);
    printf("%d\n", i); // 0
    
    f(i);
    printf("%d\n", i); // 1

    return 0;
}
