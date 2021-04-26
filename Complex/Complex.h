class Complex {
  private:
	double x;
	double y;

  public:
	Complex();
	Complex(double x, double y);
	Complex(Complex& o);
	
	Complex operator+(const Complex& o) const;
	Complex operator*(const Complex& o) const;
	Complex& operator=(const Complex& o);

	void setX(double x) {
		this->x = x;
	}
	
	void setY(double y) {
		this->y = y;
	}

	void print() const;
	void println() const;

	~Complex();
};
