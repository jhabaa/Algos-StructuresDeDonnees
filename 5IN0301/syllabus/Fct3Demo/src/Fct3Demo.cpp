/*
 Le programme suivant montre deux façons de transmettre un tableau
 à une fonction.
 */
//---------------------------------------------------------------------------
#include<iostream>
using namespace std;
//---------------------------------------------------------------------------
const double MAXIMUM = 1.7e308;
const int DIM = 7;

double minimum_1(double tabl[], int n);
double minimum_2(const double * const ptr_tabl, int n);
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	double t[DIM]= { 1.0, 5.0, -10.0, 50.0, -50.0, 2.0, -1.0 };
	cout << "Minimum_1 --> " << minimum_1(t, DIM) << endl;
	cout << "Minimum_2 --> " << minimum_2(t, DIM) << endl;
	return 0;
}
//---------------------------------------------------------------------------
/*
 La fonction minimum_1() calcule le minimum d'un tableau de "n" valeurs
 de type double.
 Le tableau débute à l'adresse "tabl".
 */
double minimum_1(double tabl[], int n)
{
	double mini=MAXIMUM;
	for (int i=0; i<n; i++)
		if (mini>tabl[i])
			mini=tabl[i];
	return (mini);
}
//---------------------------------------------------------------------------
/*
 La fonction minimum_2() calcule le minimum d'un tableau de "n" valeurs
 de type double.
 Le tableau débute à l'adresse "ptr_tabl".
 */
double minimum_2(const double *ptr_tabl, int n)
{
	double mini=MAXIMUM;
	for (const double *ptr_ele = ptr_tabl; ptr_ele < ptr_tabl+n; ++ptr_ele)
		if (mini>*ptr_ele)
			mini=*ptr_ele;
	return (mini);
}
//---------------------------------------------------------------------------
