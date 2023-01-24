// Programme de création dynamique d'une table de nombres aléatoires
//---------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <stdlib.h>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
const int ELE_MAX = 1000;
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
	unsigned graine;
	int *aTabl;
	int nbrEle;

	cout << "Création d'une table de nombres aléatoires\n\n";
	cout << "Nombre d'éléments dans la table : ";
	cin >> nbrEle;

	try {
		aTabl=new int[nbrEle];
	} catch (std::bad_alloc const&) {
		cerr << "Impossible de creer la table";
		exit(1);
	}

	cout << "Graine (nombre naturel) pour le générateur : ";
	cin >> graine;

	srand(graine);
	for (int i=0; i<nbrEle; i++)
		aTabl[i]=rand()%(ELE_MAX+1);

	cout << "\nTable de nombres aleatoires :\n";
	for (int i=0; i<nbrEle; i++) {
		if (i > 0 && i % 10 == 0)
			cout << endl;
		cout << setw(8) << aTabl[i];
	}

	delete [] aTabl;

	return 0;
}
//---------------------------------------------------------------------------
