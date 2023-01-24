// Programme de calcul des factorielles de nombres naturels.
//---------------------------------------------------------------------------
#include <iostream>
#include <limits.h>
#include "inout.h"
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
unsigned long Factorial(int x);
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    do {
        int nbr = ReadInt("n ? ", 0, 12);
        unsigned long fact = Factorial(nbr);
        cout << nbr << "! = " << fact << endl;
    } while (!Stop());
}
//---------------------------------------------------------------------------
unsigned long Factorial(int x)
{
    if (x < 0 || x > 12) return 0L;
    unsigned long fact = 1L;
    while (x> 1) {
        fact = fact * x;
        x = x - 1;
    }
    return fact;
}
//---------------------------------------------------------------------------
