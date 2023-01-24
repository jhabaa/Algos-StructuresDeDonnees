// Programme qui calcule la somme des n premiers naturels.
//---------------------------------------------------------------------------
#include <iostream>
using namespace std;
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
	unsigned int n;
	cout << "Somme des n premiers nombres naturels\n\n";
	cout << "n ? ";
	cin >> n;
	unsigned long somme=0;
	for (unsigned int i=0; i<=n; i++)
		somme+=i;
	cout << "\nLa somme vaut " << somme;
	return 0;
}
//---------------------------------------------------------------------------
