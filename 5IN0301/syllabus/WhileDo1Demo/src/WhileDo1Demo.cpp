// Programme de jeu
//---------------------------------------------------------------------------
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "inout.h"
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
const int MAX = 999;
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
	srand(time(NULL));
	cout << "Vous devez deviner un nombre compris entre 0 et " << MAX << endl;
	int nombre, essai, nbrEssais;
	nombre=rand()%MAX+1;
	essai = ReadInt("Votre nombre : ", 0, MAX);
	nbrEssais=1;
	while (essai!=nombre) {
		if (essai<nombre)
			cout << essai << " est trop petit" << endl;
		else
			cout << essai << " est trop grand" << endl;
		essai = ReadInt("Votre nombre : ", 0, MAX);
		nbrEssais++;
	}
	cout << endl << "Vous avez trouvé en " << nbrEssais << " essais" << endl;
	return 0;
}
//---------------------------------------------------------------------------
