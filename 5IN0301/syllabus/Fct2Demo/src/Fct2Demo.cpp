/*
 Le programme suivant lit deux valeurs entières dans deux variables
 puis échange à deux reprises le contenu des deux variables.
 */
//---------------------------------------------------------------------------
#include<iostream>
using namespace std;
//---------------------------------------------------------------------------
void Permut1(int& ra, int& rb);
void Permut2(int* pa, int* pb);
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
	int v1, v2;
	cout << "Introduire les valeurs pour les variables v1 et v2.\n";
	cout << "v1 ? ";
	cin >> v1;
	cout << "v2 ? ";
	cin >> v2;
	Permut1(v1, v2);
	cout << "Contenus des variables v1 et v2 après appel à Permut1() :\n";
	cout << "v1 : " << v1 << endl;
	cout << "v2 : " << v2 << endl;
	Permut2(&v1, &v2);
	cout << "Contenus des variables v1 et v2 après appel à Permut2() :\n";
	cout << "v1 : " << v1 << endl;
	cout << "v2 : " << v2 << endl;
	return 0;
}
//---------------------------------------------------------------------------
/*
 La fonction Permut1() échange les valeurs des
 variables référencées par ra et rb.
 */
void Permut1(int& ra, int& rb) {
	int temp = ra;
	ra = rb;
	rb = temp;
}
//---------------------------------------------------------------------------
/*
 La fonction Permut2() échange les valeurs
 pointées par pa et pb.
 */
void Permut2(int* pa, int* pb) {
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}
//---------------------------------------------------------------------------
