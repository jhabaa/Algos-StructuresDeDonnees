/*
 Programme de démonstration d'utilisation des paramètres
 de la ligne de commande
 */
//---------------------------------------------------------------------------
#include <iostream>
using namespace std;
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
	cout << "Le nombre de paramètres est " << argc << '.' << endl;
	for (int i=0; i<argc; i++)
		cout << "*argv[" << i<< "] : " << argv[i] << endl;
	return 0;
}
//---------------------------------------------------------------------------