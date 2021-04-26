#include<cstdio>

class A {
    private:
        int i;
    
    public:
        A() {
            this->i = 0;
        }

        A(int i) {
            this->i = i;
        }

    friend class B; // B é uma classe amiga de A!!!!
};

class B {
    private:
        A a; // B tem um membro de dado da classe A.

    public:
        B(A a) {            // Construtor
            this->a = a;
        }
        void println() const {   // Função para imprimir!!!
            printf("%d\n", a.i); // acessando membro i do objeto a DIRETAMENTE, mesmo
                                 // ele sendo privado
        }
};

int main() {
    A a(10);
    B b(a);
    b.println();
    return 0;
}
