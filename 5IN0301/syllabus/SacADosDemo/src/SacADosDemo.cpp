//---------------------------------------------------------------------------
// File SacADosDemo.cpp
//---------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <ctype.h>
#include "inout.h"
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
bool SacADos(int masse, int poids[], int nPoids);
//bool Continuer();

class TSacADos {
private:
	TSacADos(int masse, int poids[], int nPoids);
	~TSacADos();
	int n; // on pourrait s'en passer!
	int *p;
	int masse;
	int candidat;
	bool Travail();
	friend bool SacADos(int masse, int poids[], int nPoids);
};
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
	int masse, nPoids;
	int *poids=0;
	cout << "                    SAC A DOS" << endl;
	cout << "                    =========" << endl;
	do {
		cout << endl;
		cout << "Nombre de poids (>0) : ";
		cin >> nPoids;
		poids=new int[nPoids];
		for (int i=0; i<nPoids; ++i) {
			cout << "Poids " << (i+1) << " : ";
			cin >> poids[i];
		}
		cout << "Masse a obtenir : ";
		cin >> masse;
		cout << endl;
		if (!SacADos(masse, poids, nPoids))
			cout << "Pas de solution";
		cout << endl << endl;
	} while (!Stop());
	delete[] poids;
	return 0;
}
//---------------------------------------------------------------------------
TSacADos::TSacADos(int masse, int poids[], int nPoids) :
	n(nPoids), masse(masse), candidat(nPoids-1) {
	p=new int[n];
	for (int i=0; i<n; ++i)
		p[i]=poids[i];
}

TSacADos::~TSacADos() {
	delete[] p;
}

bool TSacADos::Travail() {
	if (masse==0)
		return true;
	else if ((masse<0) || (candidat<0))
		return false;
	else {
		masse-=p[candidat];
		--candidat;
		if (Travail()) {
			cout << setw(4) << p[++candidat];
			return true;
		} else {
			masse+=p[candidat+1];
			if (Travail()) {
				++candidat;
				return true;
			} else {
				++candidat;
				return false;
			}
		}
	}
}
//---------------------------------------------------------------------------
bool SacADos(int masse, int poids[], int nPoids) {
	TSacADos sad(masse, poids, nPoids);
	return sad.Travail();
}

//bool Continuer() {
//	char choix;
//	do {
//		cout << "Voulez-vous continuer <O/N> ? ";
//		cin >> choix;
//		choix = toupper(choix);
//	} while (choix!='O' && choix!='N');
//	return (choix=='O');
//}
//---------------------------------------------------------------------------
