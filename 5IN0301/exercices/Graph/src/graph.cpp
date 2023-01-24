//---------------------------------------------------------------------------
#include "graph.h"
# include <iostream>
#include <cstddef>
using namespace std;
//---------------------------------------------------------------------------
class TWork {

public:		
	// TODO
	TWork(const TGraph& _graph, int _begin, int _end, TPath& _path, double& _length);
	~TWork();
private:
	// TODO
	
	
	const TGraph graph;
	double bestLength = 0;
	int begin;
	int end;
	TPath path;
	double* lenght;
	TPath tmpPath;
	double tmpLenght;
	void DoWork(); //Function to find the best path
	friend bool ComputeShortestPath(const TGraph& _graph, int _begin, int _end,
			TPath& _path, double& _length);
};


//---------------------------------------------------------------------------
// TODO definitions for TDest
TDest::TDest(){this->pValues = 0;}
TDest::~TDest(){
	delete[] pValues;
	pValues = NULL;
	}
//double& TDest::operator[](int index){}
//const double& TDest::operator[](int index) const{}

//---------------------------------------------------------------------------
// TODO definitions for TGraph
TGraph::TGraph(int d){
	/* A 2D array array is already available with dim rows. Here we just need to set rows number as
	 * as dim and allocate memory
	 */
	this->dim = d;
	int s = this->dim; //Set Size
	delete[] ppDest;
	ppDest = 0;
	if (s!=0){
				ppDest = new TDest[s];
			for (int i = 0; i<s; i++){
				ppDest[i].pValues = new double[s]; //New array of 3 columns. Start, End, Value
			}
			for (int i = 0; i < s; i++) {
				for(auto j=0; j < s ; j++){
					ppDest[i][j] = (j==i) ?  0 : INFINITY;
				}
			}


	}

}
	//const TDest& TGraph::operator[](int index) const{}


int TGraph::Dim() const{
	return this->dim;
}

//---------------------------------------------------------------------------
// TODO definitions for TPath

TPath::TPath(){
	//TPath constructor can initialize the pNode array with lenghtMax
	cout << "Initialisation de TPath avec une longueur : " << this->LengthMax() << endl;
	this->pNodes = new int[this->LengthMax()];
	}

TPath::TPath(int _lengthMax){
	

	this->pNodes = new int[this->LengthMax()];
	//
	cout << endl<<"Longueur Max en entrée : "<< _lengthMax << endl;//Debug
	this->lengthMax = _lengthMax;
	this->length = 0;
	this->pNodes = NULL;
	
}



TPath::TPath(const TPath& _path){
		//If we get a TPath as param, we can replace the actuel pNode array by the new one
		//*this = _path;
		this->length = _path.length;
		this->lengthMax = _path.lengthMax;
		pNodes = new int[_path.lengthMax];
		for (auto i = 0; i < length; i++) {
			pNodes[i] = _path.pNodes[i];
		}
	}

TPath::~TPath(){
	this->lengthMax=0;
	this->length=0;
	delete[] this->pNodes;
	this->pNodes = NULL;
	
}



TPath& TPath::operator=(const TPath& _path)
{
	// // O: insert return statement here
		if (this != &_path){
			this->length = _path.length;
			this->lengthMax = _path.lengthMax;
			pNodes = new int[_path.lengthMax];
			for (auto i = 0; i < length; i++) {
				pNodes[i] = _path.pNodes[i];
			}
		}
		return *this;

	
}

int TPath::LengthMax() const
{
	return lengthMax;
}

int TPath::Length() const
{
	return length;
}

void TPath::Erase(){
	//Erase will deallocate memory 
	delete[] this->pNodes;
	this->pNodes = NULL; //And set array to NULL
	
	this->lengthMax = 0;
	this->length = 0;
	
}

bool TPath::Add(int _s){
	//Function to add value to a PNode
	
	if (this->length < this->lengthMax){
		this->pNodes[length] = _s;
		this->length++;
		return true; 
	}
	return false;
}

bool TPath::Remove()
{
	//I think this function should remove de last index... maybe
	if (this->length > 0){
		return true;
	}
	return false;
	
}

int TPath::Last() const{
	return this->pNodes[this->length - 1];
}

int& TPath::operator[](int _i) {
	return pNodes[_i] ;
}

const int& TPath::operator[](int _i) const
{
	return pNodes[_i];
}


//---------------------------------------------------------------------------
// TODO definitions for TWork

	//Constructor for t
	TWork::TWork(const TGraph& _graph, int _begin, int _end, TPath& _path, double& _length) : graph(_graph){

		this->path = _path;
		this->begin = _begin;
		this->end = _end;
		*lenght = INFINITY;
		this->lenght = &_length;
		
		//Temp TWORK
		this->tmpLenght = 0; // We set the cursor to 0 for the temp
		this->tmpPath =  TPath(_graph.Dim()); // With the same dimension a the original TGraph
		this->tmpPath.Add(_begin); // And we add the first element
	}

	TWork::~TWork(){
		this->path.Erase();
	}

	void TWork::DoWork(){
		//DFS function to find the bestlenght from start to end
		//Let's creat an array of size dim to store first nodes connected to current TDest/node
		//We can use the *PNode in TPath (which is a pointer to an array -- I guess)
		//int* connected_Nodes = new int[this->graph.Dim()];
		
		cout << "Starting DoWork " << endl; 
		cout << "temp Graph max" << tmpPath.LengthMax() << endl;
		cout << "temp Graph " << tmpPath.Length() << endl;
		
		//buggggg
		
	}


//---------------------------------------------------------------------------
bool ComputeShortestPath(const TGraph& _graph, int _begin, int _end, TPath& _path, double& _length) {
	if (_begin >= _graph.Dim() || _end >= _graph.Dim() || _path.LengthMax() < _graph.Dim()){
		return false;
	}
				
	
	TWork t(_graph, _begin, _end, _path, _length);
	cout << endl << "Execution de t.Dowwork() " << endl; //Debug
	t.DoWork();
	_length = t.bestLength;
	if (_length < INFINITY)
		return true;
	else
		return false;
}
//---------------------------------------------------------------------------




