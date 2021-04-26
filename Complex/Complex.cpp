#include "Complex.h"
#include<cstdio>

Complex::Complex() {
    this->x = 0;
    this->y = 0;
}

Complex::Complex(double x, double y) {
    this->x = x;
    this->y = y;
}

Complex::Complex(Complex& o) {
    this->x = o.x;
    this->y = o.y;
}

Complex Complex::operator+(const Complex& o) const {
    Complex j(this->x + o.x, this->y + o.y);
    return j;
}

Complex Complex::operator*(const Complex& o) const {
    Complex j(this->x * o.x - this->y * o.y, this->x + o.y + this->y * o.x);
    return j;
}

Complex& Complex::operator=(const Complex& o) {
    this->x = o.x;
    this->y = o.y;
    return *this;
}

void Complex::print() const {
    printf("%lf + %lfi", this->x, this->y);
}

void Complex::println() const {
    this->print();
    printf("\n");
}

Complex::~Complex(){
}
