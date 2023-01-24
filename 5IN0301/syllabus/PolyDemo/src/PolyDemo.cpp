//---------------------------------------------------------------------------
#include <iostream>
#include "inout.h"
#include "poly.h"
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
	TPoly p1(3), p2(4), p;
	do {
		cout << "p1 ? \t";
		cin >> p1;
		cout << "p1 : \t" << p1 << endl;;
		cout << "p2 ? \t";
		cin >> p2;
		cout << "p2 : \t" << p2 << endl;;
		cout << endl;
		cout << "p1.Degre() : \t" << p1.Degre() << endl;
		cout << "p2.Degre() : \t" << p2.Degre() << endl;
		cout << endl;
		cout << "p1+p2 : \t" << (p1+p2) << endl;
		cout << "p1-p2 : \t" << (p1-p2) << endl;
		cout << endl;
		p=p1;
		p+=p2;
		cout << "p=p1; p+=p2 : \t" << p << endl;
		p=p1;
		p-=p2;
		cout << "p=p1; p-=p2 : \t" << p << endl;
		cout << endl;
		cout << "+p1 : \t" << +p1 << endl;
		cout << "-p1 : \t" << -p1 << endl;
		cout << endl;
		cout << "p1(0.0) : \t" << p1(0.0) << endl;
		cout << "p1(1.0) : \t" << p1(1.0) << endl;
		cout << "p1(2.0) : \t" << p1(2.0) << endl;
		cout << endl;
		for (unsigned i=p1.Degre()+1; i>0; --i)
			if (p1.EstNul(i)) {
				p1[i]=1.0;
				cout << "p1[" << i << "] = 1.0 -> \t" << p1 << endl;
			} else {
				p1.Zero(i);
				cout << "p1.Zero(" << i << ") -> \t" << p1 << endl;
			}
	} while (!Stop());
	return 0;
}
//---------------------------------------------------------------------------
