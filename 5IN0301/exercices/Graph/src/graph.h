#ifndef GRAPH_H_
#define GRAPH_H_

/*
 * Malheureusement le code ne se lance qu'en mode Debug. Il persiste un bug avec la longueur qui m'empêche d'évoluer. 
 * 
 * */

//---------------------------------------------------------------------------
const double INFINITY = 10e100;
//---------------------------------------------------------------------------
class TGraph;
//---------------------------------------------------------------------------
class TDest {
	//TODO
public:
	double& operator[](int index){return pValues[index];}
	const double& operator[](int index) const{return pValues[index];}
private:
	TDest();
	~TDest();
	double* pValues;
	friend class TGraph;
};
//---------------------------------------------------------------------------
class TGraph {
public:
	// TODO
	//int** graphArray = new int*[dim];

	TGraph(int d); //Constructor to create a TGraph with a dim
	int Dim() const; // function which return dim in int
	
	inline TDest& operator[](int index){ //operator [index] is an array. Then [index][index2] is a double
		return ppDest[index];
	}
	inline const TDest& operator[](int index) const{
		return ppDest[index];
	}


	
	
	void operator=(const TGraph& _graph){ //redefinition for = operation on TGraph
		this->dim = _graph.dim;
		this->ppDest = _graph.ppDest;
	}
	
	
	
private:
	int dim;
	TDest* ppDest;
};
//---------------------------------------------------------------------------
class TPath {
public:

	//TPath is a int array 
	TPath(); //TPath constructor
	TPath(int _lengthMax); //
	TPath(const TPath& _path);
	~TPath();
	TPath& operator=(const TPath& _path);
	int LengthMax() const;
	int Length() const;
	void Erase();
	bool Add(int _s);
	bool Remove();
	int Last() const;
	int& operator[](int _i);
	const int& operator[](int _i) const;
	
private:
	int* pNodes;
	int lengthMax;
	int length;
};
//---------------------------------------------------------------------------
bool ComputeShortestPath(const TGraph& _graph, int _start, int _end, TPath& _path,
		double& _length);
//---------------------------------------------------------------------------
#endif /*GRAPH_H_*/
