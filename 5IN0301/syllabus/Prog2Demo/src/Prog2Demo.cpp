/*
 Fichier Prog2Demo.cpp
 Auteur : Mattens Jean-Michel
 Programme : Prog2 lit au clavier deux nombres r�els, calcule
 la somme et affiche le r�sultat a l'�cran.
 Version 1
 Hypoth�ses de travail : l'utilisateur introduit deux nombres r�els
 compatibles avec le type float.
 */
//---------------------------------------------------------------------------
// Inclusion du fichier d'en-t�tes("header files")
// iostream afin de permettre l'utilisation des
// flux standard d'entr�es/sorties :
// op�rateur de sortie <<, op�rateur d'entr�e >>,
#include <iostream>

// Importation de l'espace de noms std
using namespace std;
//---------------------------------------------------------------------------
// Automatiquement g�n�r�.
// Il serait possible d'envoyer des
// information � notre programme!
int main(int argc, char* argv[])
{
	// D�finition des variables locales a, b et somme
	// pouvant contenir des valeurs � virgule
	// flottante.
	float a, b, somme;

	// Affichage d'un message suivi
	// d'un saut de ligne.
	cout << "Entrer a et b" << endl;

	// Lecture au clavier de deux valeurs de type
	// float pour les variables a et b.
	cin >> a >> b;

	// Calcul de la somme des valeurs de a et b
	// et affectation de celle-ci � somme.
	somme=a+b;

	// Affichage � l'�cran du texte " Somme :  "
	// suivi de la valeur de somme et d'un saut de
	// ligne.
	cout << "Somme : " << somme << endl;

	// Fin de la fonction main() et renvoi de la
	// valeur 0 pour indiquer une fin normale du
	// programme.
	return 0;
}
//---------------------------------------------------------------------------

