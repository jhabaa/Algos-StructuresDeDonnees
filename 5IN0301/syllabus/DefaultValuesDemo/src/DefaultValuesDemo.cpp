/*
 Le programme suivant montre comment définir
 des valeurs par défaut pour les paramètres.
 */
//---------------------------------------------------------------------------
#include<iostream>
using namespace std;
//---------------------------------------------------------------------------
void Fct(int a, int b=20, int c=30);
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
	cout << "Fct(1,2,3) --> ";
	Fct(1, 2, 3);
	cout << "Fct(1,2,3) --> ";
	Fct(1, 2);
	cout << "Fct(1,2,3) --> ";
	Fct(1);
	return 0;
}
//---------------------------------------------------------------------------
void Fct(int a, int b, int c) {
	cout << "a = " << a << "\t b = " << b <<"\t c = " << c << endl;
}
//---------------------------------------------------------------------------