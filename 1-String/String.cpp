#include "String.h"
#include<cstdio>
#include<cstring>

String::String() {
    this->s = new char[1];
    this->s[0] = '\0';
    this->length = 0;
}

String::String(const char *s, int length) {
    this->length = length;
    this->s = new char[this->length + 1];
    strcpy(this->s, s);
}

String::String(const char *s) {
    this->length = strlen(s);
    this->s = new char[this->length + 1];
    strcpy(this->s, s);
}

String::String(String& o) {
    this->length = o.length;
    this->s = new char[this->length + 1];
    strcpy(this->s, o.s);
}

String String::operator+(const String& o) const {
    int length = this->length + o.length;
    char *s = new char[length + 1];
    strcpy(s, this->s);
    strcpy(s + this->length, o.s);
    String j(s, length);
    delete[] s;
    return j;
}

String& String::operator=(const String& o) {
    if (this == &o)
        return *this;
    this->length = o.length;
    delete[] this->s;
    this->s = new char[this->length + 1];
    strcpy(this->s, o.s);
    return *this;
}

String::~String(){
    delete[] this->s;
}

ostream& operator<<(ostream& os, const String& s) {
    os << s.s;
    return os;
}	

