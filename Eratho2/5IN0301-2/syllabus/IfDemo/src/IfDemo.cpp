// Résolution d'une équation du premier degré a X + b = 0
//---------------------------------------------------------------------------
#include <iostream>

using namespace std;
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
	cout << "Résolution d'une équation du premier degré a X + b = 0" << endl;
	float a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	if (a!=0) {
		cout << "La solution du système est unique" << endl;
		cout << "x = " << -b/a;
	} else if (b!=0)
		cout << "Equation impossible";
	else
		cout << "Equation indéterminée";
	return 0;
}
//---------------------------------------------------------------------------
