/*
 Fichier Prog1Demo.cpp
 Auteur : Mattens Jean-Michel
 Programme : Prog1 lit au clavier deux nombres réels, calcule
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
// objets cin, cout, cerr etc.
#include <iostream>

// Automatiquement généré.
// Il serait possible d'envoyer des
// information à notre programme!
int main(int argc, char* argv[]) {
	// Définition des variables locales a, b et somme
	// pouvant contenir des valeurs à virgule
	// flottante.
	float a, b, somme;

	// Affichage d'un message suivi
	// d'un saut de ligne.
	std::cout << "Entrer a et b" << std::endl;

	// Lecture au clavier de deux valeurs de type
	// float pour les variables a et b.
	std::cin >> a >> b;

	// Calcul de la somme des valeurs de a et b
	// et affectation de celle-ci à somme.
	somme=a+b;

	// Affichage à l'écran du texte " Somme :  "
	// suivi de la valeur de somme et d'un saut de
	// ligne.
	std::cout << "Somme : " << somme << std::endl;

	// Fin de la fonction main() et renvoi de la
	// valeur 0 pour indiquer une fin normale du
	// programme.
	return 0;
}
//---------------------------------------------------------------------------
