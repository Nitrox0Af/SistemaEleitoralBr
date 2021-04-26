#include<iostream>
#include<fstream>

using namespace std;

class String {
  private:
	char* s;
	int length;

	String(const char* s, int length);
  
  public:
	String();
	String(const char* s);
	String(String& o);
	
	String operator+(const String& o) const;
	String& operator=(const String& o);

	~String();
    
	friend ostream& operator<<(ostream& os, const String& s);
};
