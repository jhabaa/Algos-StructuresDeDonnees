// Fonction permettant la lecture securisée d'un réel
//---------------------------------------------------------------------------
#include <iostream>
#include <sstream>
#include <string>

#include "inout.h"

//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
	double x;
	do {
		x=ReadDouble("x ? ");
		cout << "x = " << x << endl << endl;
	} while (x>=0);
	return 0;
}
//---------------------------------------------------------------------------
