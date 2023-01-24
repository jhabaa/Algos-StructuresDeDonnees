#ifndef POLY_H_
#define POLY_H_
//---------------------------------------------------------------------------
#include <iostream>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
const unsigned DEGRE_DEFAUT = 10;
const double EPSILON = 1e-18; // un double de valeur absolue
// <= EPSILON est considéré nul.
/*
 L'opérateur [] utilisé avec un indice i supérieur au degré du polynôme
 mais inférieur ou égal au degré maximum entraîne la mise à 1.0
 du coefficient du terme de degré i (le polynôme aura donc le degré i).
 L'opérateur [] utilisé avec un indice i supérieur au degré maximum du
 polynôme entraîne un arrêt du programme.
 L'opérateur [] ne peut pas être utilisé pour mettre à 0 le coefficient
 du terme du degré du polynôme : il faut utiliser la fonction Zero().
 */
class TPoly {
public:
	TPoly(unsigned t=DEGRE_DEFAUT); // t doit être >= 0
	TPoly(const TPoly& poly);
	~TPoly();
	TPoly& operator=(const TPoly& poly2);
	TPoly& operator+=(const TPoly& poly2);
	TPoly& operator-=(const TPoly& poly2);
	unsigned Degre() const;
	bool EstNul(unsigned i) const;
	unsigned Zero(unsigned i);
	const double& operator[](unsigned i) const;
	double& operator[](unsigned i);
	double operator()(double x) const;
	TPoly operator+(const TPoly& poly2) const;
	TPoly operator-(const TPoly& poly2) const;
	const TPoly& operator+() const;
	TPoly operator-() const;
private:
	double* pCoeff;
	unsigned degre;
	unsigned degre_max;
	friend ostream& operator<<(ostream& os, const TPoly& poly);
	friend istream& operator>>(istream& is, TPoly& poly);
};
//---------------------------------------------------------------------------
#endif /*POLY_H_*/
