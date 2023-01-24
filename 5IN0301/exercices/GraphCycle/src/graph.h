#ifndef GRAPH_H_
#define GRAPH_H_
//---------------------------------------------------------------------------
const double INFINITY = 10e100;
//---------------------------------------------------------------------------
class TGraph;
//---------------------------------------------------------------------------
class TDest {
	// TODO
public :
	double& operator[](int index) { return pValues[index]; }
	const double& operator[](int index) const { return pValues[index]; }

private:
	TDest();
	~TDest();
	double* pValues;
	friend class TGraph;
};
//---------------------------------------------------------------------------
class TGraph {
public:
	// TODO ...
	TGraph(int d);
	inline TDest& operator[](int j)
	{
		return ppDest[j];
	}
	inline const TDest& operator[](int j) const
	{
		return ppDest[j];
	}
	int Dim() const;

	void Realloc();
	// TODO declaration of constructor witch accepts a pointer to the 
	// beginning of a bi-dimensional square array of double and his dimension
	TGraph(double* begin , int d);
private:
	int dim;
	TDest* ppDest;
};
//---------------------------------------------------------------------------
class TPath {
public:
	TPath(int _lengthMax);
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
//bool ComputeShortestPath(const TGraph& _graph, int _start, int _end, TPath& _path,double& _length);
//---------------------------------------------------------------------------
// TODO declaration of function IsCyclic
//---------------------------------------------------------------------------
bool IsCyclic(const TGraph& graph, TPath path);

#endif /*GRAPH_H_*/
