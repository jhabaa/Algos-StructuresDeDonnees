/*
 Fichier Prog2Demo.cpp
 Auteur : Mattens Jean-Michel
 Programme : Prog2 lit au clavier deux nombres réels, calcule
 la somme et affiche le résultat a l'écran.
 Version 1
 Hypothèses de travail : l'utilisateur introduit deux nombres réels
 compatibles avec le type float.
 */
//---------------------------------------------------------------------------
// Inclusion du fichier d'en-têtes("header files")
// iostream afin de permettre l'utilisation des
// flux standard d'entrées/sorties :
// opérateur de sortie <<, opérateur d'entrée >>,
#include <iostream>

// Importation de l'espace de noms std
using namespace std;
//---------------------------------------------------------------------------
// Automatiquement généré.
// Il serait possible d'envoyer des
// information à notre programme!
int main(int argc, char* argv[])
{
	// Définition des variables locales a, b et somme
	// pouvant contenir des valeurs à virgule
	// flottante.
	float a, b, somme;

	// Affichage d'un message suivi
	// d'un saut de ligne.
	cout << "Entrer a et b" << endl;

	// Lecture au clavier de deux valeurs de type
	// float pour les variables a et b.
	cin >> a >> b;

	// Calcul de la somme des valeurs de a et b
	// et affectation de celle-ci à somme.
	somme=a+b;

	// Affichage à l'écran du texte " Somme :  "
	// suivi de la valeur de somme et d'un saut de
	// ligne.
	cout << "Somme : " << somme << endl;

	// Fin de la fonction main() et renvoi de la
	// valeur 0 pour indiquer une fin normale du
	// programme.
	return 0;
}
//---------------------------------------------------------------------------

