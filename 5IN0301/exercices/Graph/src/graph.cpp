//---------------------------------------------------------------------------
#include "graph.h"
# include <iostream>
#include <cstddef>
#include <vector>
using namespace std;
//---------------------------------------------------------------------------
class TWork {

public:		
	// TODO
	TWork(const TGraph& _graph, int _begin, int _end, TPath& _path, double& _length);
	~TWork();
private:
	// TODO
	
	
	TGraph graph;
	double bestLength = 0;
	int begin;
	int end;
	TPath path;
	double* lenght;
	//TPath tmpPath;
	//double tmpLenght;
	void DoWork(); //Function to find the best path
	friend bool ComputeShortestPath(const TGraph& , int, int, TPath& , double& );
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
	//delete[] ppDest;
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

TPath::TPath() {
	this->lengthMax = 0;
	this->length = 0;
	this->pNodes = NULL;
	
	}

TPath::TPath(int _lengthMax){
	cout << endl << "Creation d'un chemin : " << _lengthMax << endl;//Debug
	//this->pNodes = new int[lengthMax];
	//creation d'un pNodes
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
	
	if (this->length <= this->lengthMax){
		this->pNodes[length] = _s;
		this->lengthMax++;
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

	
TWork::TWork(const TGraph& _graph, int _begin, int _end, TPath& _path, double& _length)
	:graph(_graph), path(_path), lenght(&_length) {
	// begin & end init
	this->begin = _begin;
	this->end = _end;

	//Pour le DoWork
}

/*

TWork::TWork(const TGraph& _graph, int _begin, int _end, TPath& _path, double& _length) :graph(_graph), path(_path), lenght(&_length),tmpLenght(0)
{
	//TWORK will set All values together
	cout << "Creation ork" << endl;
	//Initialize the graph, begin and end nodes, path and length
	//If begin or end are not valid nodes, path must be empty and length must be set to INFINITY
	//If begin or end are not valid nodes, return false
	//If begin equals end, path must contain only begin and length must be set to 0
	//this->graph = _graph;
	this->begin = _begin;
	this->end = _end;
	//this->path = _path;
	//*this->lenght = INFINIT;

	//tmpPath = TPath(_graph.Dim());
	//tmpPath.Add(begin);


}
*/
TWork::~TWork(){
		this->path.Erase();
	}


	void TWork::DoWork()
	{
		cout << "DoWork stuff" << endl;
		//Get 

		// function to walk in the graph, find the shortest length between begin and end and set it to bestlength variable
		/*
		if (begin == end) {
			this->bestLength = 0;
			this->lenght = 0;
		}
		*/

		

		//Analyse the shortest path and set this in path variable
		this->bestLength = INFINITY;
		int index = 0;
		//vector<int> visited;
		bool continueProcedure = true;
		while (continueProcedure)
		{
			
			for (auto j = 0; j < this->graph.Dim(); j++) {
				cout << "[" << index <<" , " << j << "]" <<" = "<< this->graph[index][j] << endl;
				//cout << "Index: " << index << " j : " << j << endl;
				if (this->graph[index][j] != INFINITY && index != j) {
					if (this->graph[index][j] <= this->bestLength) {
						//cout << "Nouveau lien  " << index << " de " <<graph[index][j]<< endl;
						this->bestLength = this->graph[index][j];
						*this->lenght += this->graph[index][j];
						//lenght += this->graph[index][j];
						path.Add(index);
						if (index == end && j == end) {
							continueProcedure = false;
						}
						index = j;
						j = 0;
					
					}
					else if(index == end && j == end){
						continueProcedure = false;
					}
				}else if (index == end && j == end) {
					continueProcedure = false;
				}
			}
		}


		cout << "==========================  DoWork result ======================================" << endl;
		cout << "graph dimension: " << graph.Dim() << endl;
		cout << "begin : " << begin << endl;
		cout << "end : " << end << endl;
		cout << "path : " << path.Length() << " And max : " << path.LengthMax() << endl;
		cout << "length : " << this->lenght << endl;
		cout << "length : " << lenght << endl;
		cout << "Best_length : " << this->bestLength << endl;
		
		
	}


//---------------------------------------------------------------------------
bool ComputeShortestPath(const TGraph& _graph, int _begin, int _end, TPath& _path, double& _length) {

	cout << "ComputeShortestPath has ......................................." << endl;
	cout << "graph dimension: " << _graph.Dim() << endl;
	cout << "begin : " << _begin << endl;
	cout << "end : " << _end << endl;
	cout << "path : " << _path.Length() <<" And max : "<<_path.LengthMax() << endl;
	cout << "length : " << _length << endl;
	// TODO
	//Compute the shortest path from _begin to _end in _graph
	//return false if no path exists, true otherwise
	//The result path and length are returned in _path and _length
	//_path is a sequence of nodes from _begin to _end
	//_length is the sum of the values of the edges along _path
	//_path and _length must be set to the shortest path found
	//If several paths have the same length, any of them can be returned
	//If no path exists, _path must be empty and _length must be set to INFINITY
	//If _begin equals _end, _path must contain only _begin and _length must be set to 0
	//The function must return false if no path exists, true otherwise
	//The function must not change _graph
	//The function must return immediately if _begin or _end are out of range
	//The function must not change _path or _length if no path exists
	//The function must not change _path or _length if _begin or _end are out of range
	//The function must not change _path or _length if _begin equals _end
	//The function must not change _path or _length if no path exists
	//The function must not change _path or _length if _begin or _end are out of range
	//The function must not change _path or _length if _begin equals _end
	//_length = INFINITY;
	//If _begin or _end are out of range
	if (_begin < 0 || _end < 0 || _begin > _graph.Dim() || _end > _graph.Dim()) {
		_length = INFINITY;
		return false;
	}
	//If _begin equals _end
	if (_begin == _end) {
		_path.Erase();
		_path.Add(_begin);
		_length = 0;
		
		return true;
	}
	//If no path exists
	if (_graph[_begin][_end] == INFINITY) {
		_length = INFINITY;
		return false;
	}

	//Else we have some paths to get
	//We create a TWork
	TWork work(_graph, _begin, _end, _path, _length);
	//We call the DoWork function
	work.DoWork();

	return true;
}
//---------------------------------------------------------------------------




