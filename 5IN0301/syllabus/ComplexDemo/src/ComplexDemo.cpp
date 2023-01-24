//---------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include "../../InOut/src/inout.h"
#include "complex.h"
//---------------------------------------------------------------------------
using namespace std;
using namespace isibmath;
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
	Complex c1,c2,c;
	cout.precision(2);
	cout.setf(ios::fixed,ios::floatfield);
	do {
		cout << "c1.Lire() <a+bi> : ";
		c1.Lire();
		cout << "c2.Lire() <a+bi> : ";
		c2.Lire();
		cout << endl;
		cout << "c1.Reel() : \t" << c1.Reel()
		     << "\t\tc1.Imag() : \t" << c1.Imag() << endl;
		cout << "c1.Mod()  : \t" << c1.Mod()
		     << "\t\tc1.Arg()  : \t" << c1.Arg()  << endl;
		cout << "Polaire(c1.Mod(),c1.Arg()) --> \t" << Polaire(c1.Mod(),c1.Arg()) << endl;
		cout << "c1.Rac()  : \t" << c1.Rac() << endl;
		cout << "c1.Rac()*c1.Rac() --> \t\t" << c1.Rac()*c1.Rac() << endl;
		cout << "c1.Conj() : \t" << c1.Conj() << endl;
		cout << endl;
		cout << "c1==c2 : \t" << ((c1==c2) ? "true" : "false")
		     << "\t\tc1!=c2 : \t" << ((c1!=c2) ? "true" : "false") << endl;
		cout << endl;

		cout << "c1+c2 : \t" << (c1+c2)
		     << "\tc1-c2 : \t" << (c1-c2) << endl;
		cout << "c1*c2 : \t" << (c1*c2)
		     << "\tc1/c2 : \t" << (c1/c2) << endl;
		cout << endl;
		c=c1;
		c+=c2;
		cout << "c=c1; c+=c2 : \t" << c;

		c=c1;
		c-=c2;
		cout << "\tc=c1; c-=c2 : \t" << c << endl;
		c=c1;
		c*=c2;
		cout << "c=c1; c*=c2 : \t" << c;
		c=c1;
		c/=c2;
		cout << "\tc=c1; c/=c2 : \t" << c << endl;
		cout << endl;
		cout << "+c1 : \t\t" << +c1
		     << "\t-c1 : \t\t" << -c1 << endl;
	} while (!Stop());
	return 0;
}
//---------------------------------------------------------------------------
