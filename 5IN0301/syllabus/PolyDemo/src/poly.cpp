//---------------------------------------------------------------------------
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "poly.h"
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
TPoly::TPoly(unsigned t) :
	pCoeff(0), degre(0), degre_max(t) {
	pCoeff = new double[degre_max+1];
	pCoeff[0] = 0.0;
}
//---------------------------------------------------------------------------
TPoly::TPoly(const TPoly& poly) :
	degre(poly.degre), degre_max(poly.degre_max) {
	pCoeff = new double[degre_max+1];
	degre = poly.degre;
	double *p1, *p2;
	for (p1=pCoeff, p2=poly.pCoeff; p2<=poly.pCoeff+poly.degre; ++p1, ++p2)
		*p1 = *p2;
}
//---------------------------------------------------------------------------
TPoly::~TPoly() {
	delete[] pCoeff; // modif
}
//---------------------------------------------------------------------------
TPoly& TPoly::operator=(const TPoly& poly2) {
	if ((this!=&poly2) && (degre_max>=poly2.degre)) {
		degre = poly2.degre;
		double *p1,*p2;
		for (p2=poly2.pCoeff,p1=pCoeff; p2<=poly2.pCoeff+poly2.degre; ++p1,++p2)
			*p1 = *p2;
	}
	return *this;
}
//---------------------------------------------------------------------------
TPoly& TPoly::operator+=(const TPoly& poly2) {
	unsigned i;
	if (degre==poly2.degre) {
		unsigned degre_nouv = 0;
		for (i=0; i<=degre; ++i)
			if (fabs(pCoeff[i]+=poly2.pCoeff[i]) > EPSILON) degre_nouv = i;
		degre = degre_nouv;
	} else if (degre<poly2.degre) {
		for (i=0; i<=degre; ++i) pCoeff[i]+=poly2.pCoeff[i];
		for (; i<=poly2.degre && i<=degre_max; ++i) pCoeff[i]=poly2.pCoeff[i];
		degre = i-1;
	} else {
		for (i=0; i<=poly2.degre; ++i) pCoeff[i]+=poly2.pCoeff[i];
	}
	return *this;
}
//---------------------------------------------------------------------------
TPoly& TPoly::operator-=(const TPoly& poly2) {
	unsigned i;
	if (degre==poly2.degre) {
		unsigned degre_nouv = 0;
		for (i=0; i<=degre; ++i)
			if (fabs(pCoeff[i]-=poly2.pCoeff[i]) > EPSILON) degre_nouv = i;
		degre = degre_nouv;
	} else if (degre<poly2.degre) {
		for (i=0; i<=degre; ++i) pCoeff[i]-=poly2.pCoeff[i];
		for (; i<=poly2.degre && i<=degre_max; ++i) pCoeff[i]=-poly2.pCoeff[i];
		degre = i-1;
	} else {
		for (i=0; i<=poly2.degre; ++i) pCoeff[i]-=poly2.pCoeff[i];
	}
	return *this;
}
//---------------------------------------------------------------------------
unsigned TPoly::Degre() const {
	return degre;
}
//---------------------------------------------------------------------------
bool TPoly::EstNul(unsigned i) const {
	if (i>degre)
		return true;
	else if (fabs(pCoeff[i])<=EPSILON)
		return true;
	return false;
}
//---------------------------------------------------------------------------
unsigned TPoly::Zero(unsigned i) {
	if (i<degre)
		pCoeff[i] = 0.0;
	else if (i==degre) {
		pCoeff[degre] = 0.0;
		if (degre>0)
			--degre;
		for (; degre>0 && fabs(pCoeff[degre])<=EPSILON; --degre)
			;
	}
	return degre;
}
//---------------------------------------------------------------------------
const double& TPoly::operator[](unsigned i) const {
	if (i>degre_max) exit(1);
	if (i>degre) pCoeff[i] = 0.0;
	return pCoeff[i];
}
//---------------------------------------------------------------------------
double& TPoly::operator[](unsigned i) {
	if (i>degre_max) exit(1);
	if (i>degre) {
		for (unsigned j=degre+1; j<i; ++j) pCoeff[j] = 0.0;
		pCoeff[i] = 1.0;
		degre = i;
	}
	return pCoeff[i];
}
//---------------------------------------------------------------------------
double TPoly::operator()(double x) const {
	double v = pCoeff[0],px=1.0;
	for (unsigned i=1; i<=degre; ++i) {
		px*=x;
		v+=pCoeff[i]*px;
	}
	return v;
}
//---------------------------------------------------------------------------
TPoly TPoly::operator+(const TPoly& poly2) const {
	if (poly2.degre<=degre)
		return (TPoly(*this)+=poly2);
	else {
		return (TPoly(poly2)+=*this);
	}
}
//---------------------------------------------------------------------------
TPoly TPoly::operator-(const TPoly& poly2) const {
	if (poly2.degre<=degre)
		return (TPoly(*this)-=poly2);
	else {
		return (-(TPoly(poly2)-=*this));
	}
}
//---------------------------------------------------------------------------
const TPoly& TPoly::operator+() const {
	return (*this);
}
//---------------------------------------------------------------------------
TPoly TPoly::operator-() const {
	TPoly pt(*this);
	for (double* p=pt.pCoeff; p<=pt.pCoeff+degre; ++p) *p = -*p;
	return pt;
}
//---------------------------------------------------------------------------
ostream& operator<<(ostream& os, const TPoly& poly) {
	double* p;
	unsigned i;
	for (p=poly.pCoeff, i=0; i<=poly.degre; ++p, ++i)
		if (fabs(*p)<=EPSILON)
			os << "+0*x^" << i;
		else if (*p>EPSILON)
			os << "+" << *p << '*' << "x^" << i;
		else
			os << "-" << fabs(*p) << '*' << "x^" << i;
	return os;
}
//---------------------------------------------------------------------------
istream& operator>>(istream& is, TPoly& poly) {
	poly.degre=0;
	unsigned d, deg=0;
	char c='+';
	do {
		is >> poly.pCoeff[deg];
		if (c=='-')
			poly.pCoeff[deg]=-poly.pCoeff[deg];
		c=is.get();
		if (c!='*')
			is.clear(ios::failbit);
		c=is.get();
		if (c!='x')
			is.clear(ios::failbit);
		c=is.get();
		if (c!='^')
			is.clear(ios::failbit);
		is >> d;
		if (d!=deg)
			is.clear(ios::failbit);
		if (is) {
			if (fabs(poly.pCoeff[deg])>EPSILON)
				poly.degre = deg;
			c=is.get();
		}
		++deg;
	} while (is && (c=='+' || c=='-') && poly.degre < poly.degre_max);
	return is;
}
//---------------------------------------------------------------------------
