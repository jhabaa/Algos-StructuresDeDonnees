//============================================================================
// Name        : ErathostenesSucc3.cpp
// Author      : 
// Version     :
// Copyright   :
// Description :
//============================================================================
#include <iostream>
#include <iomanip>
#include <math.h>
#include <deque>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
const int MAX = 2147483647; // (2^31-1)
struct TListPrimes {
    int maximum;
    int* pPrimes;
    int cPrimes;
};
//---------------------------------------------------------------------------
//  TODO ...
//---------------------------------------------------------------------------
//  TODO declarations of Compute3Succ, Show3Succ, ...
//---------------------------------------------------------------------------

void Compute3Succ(TListPrimes l, int* p, int d, int ns); 
void Show3Succ (TListPrimes l, int* p, int ns);
//FONCTIONS
void InitializeTListPrimes(TListPrimes& x);
void Erathostenes(TListPrimes& x);
void ShowPrimes(TListPrimes& x);
void DestroyTListPrimes(TListPrimes& x);




int main(int argc, char* argv[])
{
    clock_t ct1, ct2;
    TListPrimes listPrimes;
    int max=2147483647;
 
    InitializeTListPrimes(listPrimes);
    listPrimes.maximum = max;
    ct1 = clock();
    Erathostenes(listPrimes);
    ct2 = clock();
    cout << "Duree calculs : " << setprecision(4) << ((double)(ct2 - ct1) / CLOCKS_PER_SEC) << endl;
    ShowPrimes(listPrimes);

    ct1 = clock();
    int dind3 = 5000000;
    int* pind3 = new int[dind3];
    int ns;
    Compute3Succ(listPrimes,pind3,dind3,ns);
    ct2 = clock();
    cout << "Duree calculs : " << setprecision(4) << ((double)(ct2 - ct1) / CLOCKS_PER_SEC) << endl;
    
    Show3Succ(listPrimes,pind3,ns);
  
    delete[] pind3;
    DestroyTListPrimes(listPrimes);

    return 0;
}
//---------------------------------------------------------------------------
// TODO ...
//---------------------------------------------------------------------------
//  TODO definitions of Compute3Succ, Show3Succ, ...
//---------------------------------------------------------------------------


void Compute3Succ(TListPrimes x, int* p, int d, int ns){
	// p pointe un tableau qui contient les les premiers indices des triplets pour lequels la somme donne un nombre premier
	// d est l'indice maximal
	// ns est le nombre de triplets
	int* triplets = new int [d]; 
	//On parcours le tableau des nombres premiers et on vérifie si nous obtenons un nombre premier
	deque<int> primeValues; //Nous creons un tableau des nombres premiers
	for(unsigned int i=0; i < ns; i += 1){
		if(!x.pPrimes[i]){
			//std::cout << "Nombre premier n \t"<< count10 << " : \t" <<  i << endl;
			primeValues.push_back(i);
		}
	}
	
	int currentInd = 0;
	int n=0;
	int counter = 0;
	int sumOfNumbers =0;
	int sol[3];
	
	for(int i=currentInd; i<d ; i += 1){

		if(!x.pPrimes[i]){
			++counter;
			sumOfNumbers += i;
			
			//Si nous sommmes sur le 3eme, on verifie que le tableau contienne la somme des trois
			if (counter == 3){
				
				if (x.pPrimes[sumOfNumbers]){
					triplets[n] = currentInd;
					++currentInd;
					++n;
				}
			}
		}
	}
	
}
void Show3Succ (TListPrimes l, int* p, int ns){
	cout<< "Find" << ns << "triplets"<<endl;
	cout<< "Solution \t" << ns << "Nombre 1"<<endl;
	
}


void InitializeTListPrimes(TListPrimes& x){
	////std::optional
	cout<<"initialisation" << endl;
    x = {{0},{NULL},{0}};
}

void Erathostenes(TListPrimes& x){
	
	unsigned int nsqrt = x.maximum;
	int* is_prime = new int[nsqrt]{};
	int o = 0;
	//mettre à faux les cases d'indice pair > 2
	for(o = 2; o<nsqrt; o+=1){
		if(o>2 && o%2 == 0){is_prime[o]=true;}
	}
	is_prime[0] = true;
	is_prime[1] = true;
	unsigned int i = 3;
	unsigned int j = 0;
	while(i*i < nsqrt){
		if (is_prime[i] == false) {
            for (j = i * i; j < nsqrt; j += 2*i){
				is_prime[j] = true;
			}
        }
		i = i+1;
	}
	x.pPrimes = is_prime;
}

void ShowPrimes(TListPrimes& x){
	unsigned int t = 1;
	//int counter2 = x.cPrimes - 10;
	//Nous comptons ici les valeurs premieres du tableau
	int nsqrt = x.maximum;
	int count10=1;
	unsigned int all = 0;
	//calcul de la limite
	for (int a=0; a< x.maximum; a +=1){
		if(!x.pPrimes[a]){
			all +=1;
		}
	}
	cout << "Tous les chiffres premiers "<<endl;
	std::cout << "Il y a "<< all<<" nombres premiers inferieurs a "<<x.maximum<<endl;
	
	

	
	//Affichage des 10 premiers
	for(unsigned int i=0; i<x.maximum && count10 <= 10; i += 1){
		
		if(!x.pPrimes[i]){
			std::cout << "Nombre premier n \t"<< count10 << " : \t" <<  i << endl;
			count10 += 1;
		}
		
	}
	count10 = 0;
	cout<<""<<endl <<"..."<<endl<<""<<endl;
	//Calcul des 10 derniers
	deque<int> lastvalues;
	for(unsigned int i=x.maximum; i>0 && count10 < 10; i -= 1){
		
		if(!x.pPrimes[i]){
			//std::cout << "Nombre premier n \t"<< count10 << " : \t" <<  i << endl;
			lastvalues.push_front(i);
			count10 += 1;
		}
		
	}

	//Afiichage des 10 derniers
	for(int u(0); u<lastvalues.size(); u +=1){
		std::cout << "Nombre premier n \t"<< all-10+u << " : \t" <<  lastvalues[u] << endl;
	}
	

}
void DestroyTListPrimes(TListPrimes& x){
	delete [] x.pPrimes;
	x.maximum = 0;
	x.cPrimes = 0;
}
