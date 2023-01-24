// Programme de démonstration d'allocation dynamique de memoire
//---------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string.h>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
struct TStudent {
	char name[30];
	char firstname[20];
	struct TStudent *pNext;
};

typedef TStudent *TPStudent;

void CreateStudList(TPStudent& studList);
void ReadStudList(TPStudent studList);
void WriteStudList(TPStudent studList);
void DestroyStudList(TPStudent studList);
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
	TPStudent studList;
	cout << "MANIPULATION D'UNE LISTE D'ETUDIANTS\n\n";
	cout << "Création de la liste des étudiants\n\n";
	CreateStudList(studList);
	cout << "Lecture de la liste des étudiants\n";
	ReadStudList(studList);
	cout << "\nAffichage de la liste des etudiants\n";
	WriteStudList(studList);
	cout << "\nDestruction de la liste des etudiants\n\n";
	DestroyStudList(studList);
	return 0;
}
//---------------------------------------------------------------------------
void CreateStudList(TPStudent& studList) {
	studList = new TStudent;
	studList->pNext = 0;
}
//---------------------------------------------------------------------------
void ReadStudList(TPStudent studList) {
	TPStudent pStudNext;
	char achName[30];

	pStudNext = studList;
	cout << "Entrer <<$>> pour terminer\n";

	while (true) {
		cout << "Nom :    ";
		cin >> achName; /* !!! non sécurisé */
		if (achName[0] == '$')
			break;
		pStudNext->pNext = new TStudent;
		pStudNext = pStudNext->pNext;
		pStudNext->pNext = NULL;
		strcpy(pStudNext->name, achName);
		cout << "Prénom : ";
		cin >> pStudNext->firstname;
	}
}
//---------------------------------------------------------------------------
void WriteStudList(TPStudent studList) {
	TPStudent pStud;

	cout.setf(ios::left, ios::adjustfield);
	pStud = studList->pNext;
	while (pStud != 0) {
		cout << "Nom : " << setw(30) << pStud->name;
		cout << "Prénom : " << setw(30) << pStud->firstname << endl;
		pStud = pStud->pNext;
	}
}
//---------------------------------------------------------------------------
void DestroyStudList(TPStudent studList) {
	TPStudent pStud, pTemp;

	pStud = studList->pNext;
	delete studList;
	studList = 0;
	while (pStud != 0) {
		pTemp = pStud;
		pStud = pStud->pNext;
		delete pTemp;
	}
}
//---------------------------------------------------------------------------
