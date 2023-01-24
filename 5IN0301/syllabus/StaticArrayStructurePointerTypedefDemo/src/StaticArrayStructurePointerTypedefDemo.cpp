/*
 Fichier StaticArrayStructurePointerTypedefDemo.cpp
 Auteur : Mattens Jean-Michel
 Programme : StaticArrayStructurePointerTypedefDemo lit les fiches signialitiques des étudiants
 d'une classe et les stocke dans un tableau d'enregistrements.
 Puis il met le premier caractère du nom,le premier caractère
 du prénom, le caractère definissant le sexe et la chaine de
 caractères definissant la section en majuscules.
 Finalement il affiche les fiches signialitiques ainsi
 modifiées sous forme d'un tableau.
 Version 2 : utilisation de définissions de types utilisateur.
 Hypotheses de travail : l'utilisateur introduit des données valides.
 */
//---------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <string.h>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
const int NBR_ETU_MAX = 30;

struct TStudent {
	char nom[30];
	char prenom[20];
	char sexe;
	unsigned int age;
	char section[5];
};

typedef TStudent TClasse[NBR_ETU_MAX];

void Purge(void);
void LireFicheEtud(TStudent *pEtud);
void LireClasse(TClasse aClasse, int *pNbr);
void MajusculesClasse(TClasse aClasse, int nbr);
void AffClasse(TClasse aClasse, int nbr);
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
	TClasse classe;
	int nbrEtu;
	LireClasse(classe, &nbrEtu);
	MajusculesClasse(classe, nbrEtu);
	AffClasse(classe, nbrEtu);
	return (0);
}
//---------------------------------------------------------------------------
void Purge(void) {
	if (!cin)
		cin.clear();
	cin.ignore(1000, '\n');
}

void LireFicheEtud(TStudent *pEtud) {
	cout << "\nNom :\t\t\t";
	Purge();
	cin.get(pEtud->nom, 30);
	cout << "Prénom :\t\t";
	Purge();
	cin.get(pEtud->prenom, 20);
	do {
		cout << "Sexe <M> ou <F> : \t";
		Purge();
		cin >> pEtud->sexe;
	} while ((toupper(pEtud->sexe)!='M') && (toupper(pEtud->sexe)!='F'));
	cout << "Age :\t\t\t";
	Purge();
	cin >> pEtud->age;
	cout << "Section :\t\t";
	Purge();
	cin.get(pEtud->section, 5);
}

void LireClasse(TClasse aClasse, int *pNbr) {
	cout << "Veuillez introduire le nombre d'étudiants de la classe : ";
	cin >> *pNbr;
	for (int i=0; i<*pNbr; i++)
		LireFicheEtud(&aClasse[i]);
}

void MajusculesClasse(TClasse aClasse, int nbr) {
	for (int i=0; i<nbr; i++) {
		aClasse[i].nom[0]=toupper(aClasse[i].nom[0]);
		aClasse[i].prenom[0]=toupper(aClasse[i].prenom[0]);
		aClasse[i].sexe=toupper(aClasse[i].sexe);
		int l=strlen(aClasse[i].section);
		for (int j=0; j<l; j++)
			aClasse[i].section[j]=toupper(aClasse[i].section[j]);
	}
}

void AffClasse(TClasse aClasse, int nbr) {
	cout << "La classe comporte " << nbr << " etudiants\n\n";
	cout.setf(ios::left);
	cout << setw(31) << "NOM" << setw(21) << "PRENOM" << setw(5) << "SEXE";
	cout << setw(4) << "AGE" << setw(8) << "SECTION" << endl << endl;
	for (int i=0; i<nbr; i++) {
		cout << setw(31) << aClasse[i].nom << setw(21) << aClasse[i].prenom;
		cout << setw(5) << aClasse[i].sexe << setw(4) << aClasse[i].age;
		cout << setw(8) << aClasse[i].section << endl << endl;
	}
}
