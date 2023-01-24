//---------------------------------------------------------------------------
#ifndef COMPLEX_H
#define COMPLEX_H
//---------------------------------------------------------------------------
#include <iostream>
//---------------------------------------------------------------------------
namespace isibmath {
//---------------------------------------------------------------------------
class Complex {

public:

	Complex(double r=0.0, double i=0.0);

	double   Reel() const;
	double   Imag() const;
	double   Mod()  const;
	double   Arg()  const;
	Complex Conj() const;
	Complex Rac()  const;

	bool operator==(const Complex& c2) const;
	bool operator!=(const Complex& c2) const;

	Complex operator+(const Complex& c2) const;
	Complex operator-(const Complex& c2) const;
	Complex operator*(const Complex& c2) const;
	Complex operator/(const Complex& c2) const;

	Complex& operator=(const Complex& c);
	Complex& operator+=(const Complex& c2);
	Complex& operator-=(const Complex& c2);
	Complex& operator*=(const Complex& c2);
	Complex& operator/=(const Complex& c2);

	Complex operator+() const;
	Complex operator-() const;

	void Lire();

private:

	double re,im;

	friend std::istream& operator>>(std::istream& is, Complex& c);

};
//---------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os,const Complex& c);
Complex Polaire(double mod, double arg=0);
//---------------------------------------------------------------------------
} // namespace isibmath
//---------------------------------------------------------------------------
#endif
