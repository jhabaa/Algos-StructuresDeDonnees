// Effectue un tri par sélection sur un tableau d'entiers entrés au clavier.
//---------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include "inout.h"
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
void ReadArray(int tabl[], int dim);
void ShowArray(int tabl[], int dim);
void Sort(int tabl[], int dim);
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
	int dim;
	cout << "Tri par sélection" << endl;
	dim = ReadInt("Dimension ? ", 0, 100);
	int* tableau = new int[dim];
	ReadArray(tableau, dim);
	cout << "Avant : ";
	ShowArray(tableau, dim);
	Sort(tableau, dim);
	cout << "Après : ";
	ShowArray(tableau, dim);
	delete[] tableau;
}
//---------------------------------------------------------------------------
void ReadArray(int tabl[], int dim) {
	for (int i = 0; i < dim; ++i) {
		cout << "Element " << i << " ? ";
		tabl[i] = ReadInt("", -1000, 1000);
	}
}
//---------------------------------------------------------------------------
void ShowArray(int tabl[], int dim) {
	for (int i = 0; i < dim; ++i) {
		cout << setw(6) << tabl[i];
	}
	cout << endl;
}
//---------------------------------------------------------------------------
void Sort(int tabl[], int dim) {
	int len = dim - 1;
	while (len > 0) {
		int maxi = 0;
		for (int i = 1; i <= len; i++) {
			if (tabl[i] > tabl[maxi])
				maxi = i;
		}
		int temp = tabl[maxi];
		tabl[maxi] = tabl[len];
		tabl[len] = temp;
		len--;
	}
}
//---------------------------------------------------------------------------
