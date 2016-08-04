#include"complex.h"
#include<math.h>

    Complex::Complex(const double re, const double im) {
		real = re;
		imag = im;
	}

    Complex::Complex(const Complex& c) {
		real = c.real;
		imag = c.imag;
	}

    Complex& Complex::operator=(const Complex& c) {
		real = c.real;
		imag = c.imag;
		return *this;
	}

	/*polar cor*/
    Complex Complex::Polar(const double leng, const double arg) {
		real = leng * cos(arg);
		imag = leng * sin(arg);
		return *this;
	}

    double Complex::Real() { return real; }
    double Complex::Imag() { return imag; }
    double Complex::Norm() { return real * real + imag * imag; }
    double Complex::Abs() { return sqrt(Norm()); }
    /*atan2 returns the principal value of the arc tangent of y/x.*/
	double Complex::Arg() { return atan2(Imag(), Real()); }

    Complex Complex::operator++() {
		++real;
		return *this;
	}

    Complex Complex::operator++(int) {
		Complex temp(*this);
		++real;
		return temp;
	}

    Complex Complex::operator--() {
		--real;
		return *this;
	}

    Complex Complex::operator--(int) {
		Complex temp(*this);
		--real;
		return temp;
	}

    Complex::~Complex() {}

    Complex Polar(const double leng, const double arg) {
		return Complex(leng * cos(arg), leng * sin(arg));
	}

    double Norm(const Complex& x) { return x.real * x.real + x.imag * x.imag; }
    double Abs(const Complex& x) { return sqrt(Norm(x)); }
    double Arg(const Complex& x) { return atan2(x.imag, x.real); }
    
    Complex operator+(const Complex& x, const Complex& y) {
		return Complex(x.real+y.real, x.imag+y.imag);
	}

    Complex operator-(const Complex& x, const Complex& y) {
		return Complex(x.real-y.real, x.imag-y.imag);
	}

    Complex operator*(const Complex& x, const Complex& y) {
		return Complex(x.real*y.real-x.imag*y.imag, x.imag*y.real+x.real*y.imag);
	}

    Complex operator/(const Complex& x, const Complex& y) {
		return Complex((((x.real)*(y.real))+((x.imag)*(y.imag)))/(pow(y.real,2)+pow(y.imag,2)), (((y.real)*(x.imag))-((x.real)*(y.imag)))/(pow(y.real,2)+pow(y.imag,2)));
	}

    Complex operator+=(Complex& x, const Complex& y) {
		x = x+y;
		return x;
	}

    Complex operator-=(Complex& x, const Complex& y) {
		x = x-y;
		return x;
	}

    Complex operator*=(Complex& x, const Complex& y) {
		x = x*y;
		return x;
	}

    Complex operator/=(Complex& x, const Complex& y) {
		x = x/y;
		return x;
	}

    bool operator==(const Complex& x, const Complex& y) {
		if(x.real == y.real && x.imag == y.imag) return true;
		else return false;
	}

    bool operator!=(const Complex& x, const Complex& y) {
		if(x.real != y.real || x.imag != y.imag) return true;
		else return false;
	}

    ostream& operator<<(ostream& o, const Complex& x) { 
        return o << "(" << x.real << ',' << x.imag << ')';
    }
