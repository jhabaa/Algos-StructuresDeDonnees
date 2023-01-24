//============================================================================
// Name        : StructDemo.cpp
// Author      : Mattens JM
// Version     :
// Description : Struct Demo
//============================================================================
#include <iostream>
#include <iomanip>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
const int NBR_DIVIS_MAX = 2000;

struct TListeDivis {
	unsigned long int nombre;
	unsigned long int divis[NBR_DIVIS_MAX];
	int nbrDivis;
};
//---------------------------------------------------------------------------
int main()
{
	TListeDivis listeDivis;
	cout << "Votre nombre (>0) ? ";
	cin >> listeDivis.nombre;
	unsigned long int divi;
	for (divi=1, listeDivis.nbrDivis=0; divi<=listeDivis.nombre; ++divi)
		if (listeDivis.nombre%divi == 0)
			listeDivis.divis[listeDivis.nbrDivis++] = divi;
	for (int i=0; i<listeDivis.nbrDivis; ++i)
		cout << "Diviseur " << setw(4) << i+1 << " : " << setw(10)
		     << listeDivis.divis[i] << endl;
	return 0;
}
//---------------------------------------------------------------------------
