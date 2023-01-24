// Programme de démonstration de l'espace de validité de variables
//---------------------------------------------------------------------------
#include <iostream>
using namespace std;
//---------------------------------------------------------------------------
int global_i;
void fct(void);
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
	int auto_i=0;
	for (int j=0; j<3; j++) {
		cout << "main() --> j = " << j << " , global_i " << global_i;
		cout << " , auto_i , " << auto_i << endl;
		fct();
		global_i++;
		auto_i++;
	}
	return 0;
}
//---------------------------------------------------------------------------
void fct(void) {
	static int static_i=0;
	int auto_i=0;
	cout << "fct()  --> global_i = " << global_i << " , auto_i = " << auto_i;
	cout << " , static_i = " << static_i << endl;
	static_i++;
	auto_i++;
	global_i++;
}
//---------------------------------------------------------------------------
