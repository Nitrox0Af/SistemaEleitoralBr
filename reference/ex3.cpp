#include<cstdio>

int main() {
    int i = 0;
    printf("%d\n", i); // 0

    int* p = &i;
    int& r = i;

    int*& x = p;
    (*x)++;

    printf("%d\n", i); // 1

    return 0;
}
