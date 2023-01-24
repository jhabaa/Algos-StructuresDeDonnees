//============================================================================
// Name        : ArrayDemo.cpp
// Author      : Mattens JM
// Version     : 1.0
// Description : Array demo
//============================================================================
#include <iostream>
#include <iomanip>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
const int NBR_DIVIS_MAX = 2000;
//---------------------------------------------------------------------------
int main() {
	unsigned long int divis[NBR_DIVIS_MAX];
	unsigned long int nombre;
	int nbrDivis;
	cout << "Votre nombre (>0) : ";
	cin >> nombre;
	unsigned long int divi;
	for (divi=1, nbrDivis=0; divi<=nombre; ++divi)
		if (nombre%divi == 0)
			divis[nbrDivis++] = divi;
	for (int i=0; i<nbrDivis; ++i)
		cout << "Diviseur " << setw(4) << i+1 << " : " << setw(10) << divis[i]
		     << endl;
	return 0;
}
//---------------------------------------------------------------------------
