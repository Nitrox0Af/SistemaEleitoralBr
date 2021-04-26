#include<cstdio>

int main() {
    int i = 0;
    printf("%d\n", i); // 0

    int& j = i;
    j++;

    printf("%d\n", i); // 1
    return 0;
}
