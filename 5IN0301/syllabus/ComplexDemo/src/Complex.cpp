//---------------------------------------------------------------------------
#include <iostream>
#include <sstream>
#include <math.h>
#include <string>
#include "../../InOut/src/inout.h"
#include "Complex.h"
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
namespace isibmath {
//---------------------------------------------------------------------------
Complex::Complex(double r, double i)
	: re(r),im(i) {
}
//---------------------------------------------------------------------------
double  Complex::Reel() const {
	return(re);
}
//---------------------------------------------------------------------------
double  Complex::Imag() const {
	return(im);
}
//---------------------------------------------------------------------------
double  Complex::Mod() const {
	return(sqrt(re*re+im*im));
}
//---------------------------------------------------------------------------
double  Complex::Arg()  const {
	return( re==0 && im==0 ? 0 : atan2(im,re));
}
//---------------------------------------------------------------------------
Complex Complex::Conj() const {
	return(Complex(re,-im));
}
//---------------------------------------------------------------------------
Complex Complex::Rac() const {
	double m = sqrt(this->Mod());
	double a = this->Arg()/2.;
	return Polaire(m,a);
}
//---------------------------------------------------------------------------
bool Complex::operator==(const Complex& c2) const {
	return(re==c2.re && im==c2.im);
}
//---------------------------------------------------------------------------
bool Complex::operator!=(const Complex& c2) const {
	return(re!=c2.re||im!=c2.im);
}
//---------------------------------------------------------------------------
Complex Complex::operator+(const Complex& c2) const {
	Complex tmp=*this;
	return(tmp+=c2);
}
//---------------------------------------------------------------------------
Complex Complex::operator-(const Complex& c2) const {
	Complex tmp=*this;
	return(tmp-=c2);
}
//---------------------------------------------------------------------------
Complex Complex::operator*(const Complex& c2) const {
	Complex tmp=*this;
	return(tmp*=c2);
}
//---------------------------------------------------------------------------
Complex Complex::operator/(const Complex& c2) const {
	Complex tmp=*this;
	return(tmp/=c2);
}
//---------------------------------------------------------------------------
Complex& Complex::operator=(const Complex& c) {
	re=c.re;
	im=c.im;
	return(*this);
}
//---------------------------------------------------------------------------
Complex& Complex::operator+=(const Complex& c2) {
	re+=c2.re;
	im+=c2.im;
	return(*this);
}
//---------------------------------------------------------------------------
Complex& Complex::operator-=(const Complex& c2) {
	re-=c2.re;
	im-=c2.im;
	return(*this);
}
//---------------------------------------------------------------------------
Complex& Complex::operator*=(const Complex& c2) {
	double tmp=re*c2.re-im*c2.im;
	im=im*c2.re+re*c2.im;
	re=tmp;
	return(*this);
}
//---------------------------------------------------------------------------
Complex& Complex::operator/=(const Complex& c2) {
	double denom = c2.re*c2.re+c2.im*c2.im;
	double r     = (re*c2.re+im*c2.im)/denom;
	double i     = (c2.re*im-re*c2.im)/denom;
	re=r;
	im=i;
	return(*this);
}
//---------------------------------------------------------------------------
Complex Complex::operator+() const {
	return(*this);
}
//---------------------------------------------------------------------------
Complex Complex::operator-() const {
	return(Complex(-re,-im));
}
//---------------------------------------------------------------------------
void Complex::Lire() {
	string buf;
	bool good;
	do {
		good=false;
		Purge();
		cin >> buf;
		buf.append("\n");
		istringstream iss(buf);
		iss >> *this;
		if (iss.get()=='\n') good=iss.good();
	} while ( !good );
	return;
}
//---------------------------------------------------------------------------
Complex Polaire(double mod, double arg) {
	return(Complex(mod*cos(arg),mod*sin(arg)));
}
//---------------------------------------------------------------------------
ostream& operator<<(ostream& os,const Complex& c) {
	if (c.Imag()>=0) os<<c.Reel()<<'+'<<c.Imag() <<'i';
	else os<<c.Reel()<<'-'<<fabs(c.Imag())<<'i';
	return(os);
}
//---------------------------------------------------------------------------
istream& operator>>(istream& is, Complex& c) {
	double r=0,i=0;
	char ch;
	is >> r;
	is >> i;
	is >> ch;
	if (ch!='i') is.clear(ios::failbit);
	else if (is) c=Complex(r,i);
	return(is);
}
//---------------------------------------------------------------------------
} // namespace isibmath
//---------------------------------------------------------------------------
