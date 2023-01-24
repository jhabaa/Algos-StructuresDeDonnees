// Programme grades
//---------------------------------------------------------------------------
#include <iostream>
using namespace std;
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
	int n;
	cout << "Note sur 20 : ";
	cin >> n;
	switch (n) {
	case 12:
	case 13:
		cout << "Satisfaction" << endl;
		break;
	case 14:
	case 15:
		cout << "Distinction" << endl;
		break;
	case 16:
	case 17:
		cout << "Grande distinction" << endl;
		break;
	case 18:
		cout << "La plus grande distinction" << endl;
		break;
	case 19:
	case 20:
		cout << "Félicitations du jury" << endl;
		cout << "a la plus grande satisfaction des parents" << endl;
		break;
	default:
		cout << "Résultat insuffisant" << endl;
	}
	return 0;
}
//---------------------------------------------------------------------------
