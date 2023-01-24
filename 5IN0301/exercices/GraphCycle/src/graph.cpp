//---------------------------------------------------------------------------
#include "graph.h"
#include <stdexcept>
#include <iostream>

//---------------------------------------------------------------------------
class TWork {
private:
	// TODO
	//friend bool ComputeShortestPath(const TGraph& _graph, int _begin, int _end,TPath& _path, double& _length);
};
//---------------------------------------------------------------------------
class TWorkCycle
{
private:
	// TODO ...
	// TODO DoWork witch look for a cycle stating at vextex 0 
	//     (call of recursive function DoWorkRecur) and then,
	//     if not found, starting at 1, ...
    void DoWork();
	// TODO DoWorkRecur witch take the starting vertex as parameter
	// TODO declare IsCyclic as friend
    friend bool IsCyclic(const TGraph& graph, TPath path);

};
//---------------------------------------------------------------------------
// TODO definitions for TDest
TDest::TDest(){this->pValues = 0;}
TDest::~TDest()
{
	delete[] pValues;
	pValues = NULL;
}
//---------------------------------------------------------------------------
// TODO definitions for TGraph
// TODO definition of constructor witch accepts a pointer to the beginning 
//     of a bi-dimensional square array of double and his dimension
//     reminder : t[i][j]  <--> *(t + i * dim + j)
//---------------------------------------------------------------------------
// TODO definitions for TPath
//---------------------------------------------------------------------------
// TODO definitions for TWork
//---------------------------------------------------------------------------
// TODO definitions for TWorkCycle
//---------------------------------------------------------------------------

/*bool ComputeShortestPath(const TGraph& _graph, int _begin, int _end, TPath& _path,
                         double& _length)
{
    if (_begin >= _graph.Dim() || _end >= _graph.Dim() || _path.LengthMax()
        < _graph.Dim())
        return false;
    TWork t(_graph, _begin, _end, _path, _length);
    t.DoWork();
    _length = t.bestLength;
    if (_length < INFINITY)
        return true;
    else
        return false;
}*/

//---------------------------------------------------------------------------
// TODO definition of function IsCyclic
//     Il will create a TWorkCycle object, call DoWork in it, and,
//     if a cycle is found, construct a path with the cycle.
//---------------------------------------------------------------------------
bool IsCyclic(const TGraph& graph, TPath path)
{
	return true;
}

TPath::TPath(int _lengthMax)
{
    this->pNodes = new int[this->lengthMax];
    this->lengthMax = _lengthMax;
    this->length = 0;
    this->pNodes = NULL;
}

TPath::TPath(const TPath& _path)
{
    this->length = _path.length;
    this->lengthMax = _path.lengthMax;
    pNodes = new int[_path.lengthMax];
    for (auto i = 0; i < length; i++) {
        pNodes[i] = _path.pNodes[i];
    }
}

TPath::~TPath()
{
    this->lengthMax = 0;
    this->length = 0;
    delete[] this->pNodes;
    this->pNodes = NULL;
}

TPath& TPath::operator=(const TPath& _path)
{
    // // O: insert return statement here
    if (this != &_path) {
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

void TPath::Erase()
{
    delete[] this->pNodes;
    this->pNodes = NULL; //And set array to NULL

    this->lengthMax = 0;
    this->length = 0;
}

bool TPath::Add(int _s)
{
    if (this->length < this->lengthMax) {
        this->pNodes[length] = _s;
        this->length++;
        return true;
    }
    return false;
}

bool TPath::Remove()
{
    if (this->length > 0) {
        return true;
    }
    return false;
}

int TPath::Last() const
{
    return pNodes[length - 1];
}

int& TPath::operator[](int _i)
{
    // // O: insert return statement here
    return pNodes[_i];
}

const int& TPath::operator[](int _i) const
{
    // // O: insert return statement here
    return pNodes[_i];
}

TGraph::TGraph(int d)
{
    this->dim = d;
    int s = this->dim; //Set Size
    delete[] ppDest;
    ppDest = 0;
    if (s != 0) {
        ppDest = new TDest[s];
        for (int i = 0; i < s; i++) {
            ppDest[i].pValues = new double[s]; //New array of 3 columns. Start, End, Value
        }
        for (int i = 0; i < s; i++) {
            for (auto j = 0; j < s; j++) {
                ppDest[i][j] = (j == i) ? 0 : INFINITY; //Set 0 on the diagonal ie 0-0 -> 0 
            }
        }


    }
}

int TGraph::Dim() const
{
    return this->dim;
}


TGraph::TGraph(double* begin, int d)
{
	std::cout << "initialisation du graphe: ...."  << std::endl;
    this->dim = d;
    int s = this->dim;
    //delete[] ppDest;
    this->ppDest = 0;
	std::cout << "Debut creation du graphe: ...."  << std::endl;
    if (s != 0) {
        ppDest = new TDest[s];
        for (int i = 0; i < s; i++) {
            ppDest[i].pValues = new double[s]; //New array of 3 columns. Start, End, Value
        }
		std::cout << "Tableau crée. Placement de la diagonale à O : ...."  << std::endl;
        for (int i = 0; i < s; i++) {
            for (auto j = 0; j < s; j++) {
                *(begin + i * d + j) = (j == i) ? 0 : INFINITY; //Set 0 on the diagonal ie 0-0 -> 0 
            }
        }
    }
}

void TWorkCycle::DoWork()
{
}


