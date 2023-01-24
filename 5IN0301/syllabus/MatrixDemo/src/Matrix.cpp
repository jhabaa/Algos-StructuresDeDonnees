#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include <math.h>
#include "Matrix.h"
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
namespace isibmath {
//---------------------------------------------------------------------------
class WorkClassDet {
private:
	WorkClassDet(const Matrix* p);
	~WorkClassDet();
	double DetR();
	const Matrix* pm;
	int dim;
	int l;
	bool *pc;
	friend class Matrix;
};
//---------------------------------------------------------------------------
const double Matrix::EPSILON = 0.0;

Matrix::Matrix(int nr, int nc) :
	nRows(0), nColumns(0), pRows(0) {
	Realloc(nr, nc);
	Zero(); // inutile si new[]()...
}

Matrix::Matrix(const double* t, int nr, int nc) :
	nRows(0), nColumns(0), pRows(0) {
	Realloc(nr, nc);
	for (int r = 0; r < nr; ++r)
		for (int c = 0; c < nc; ++c)
			pRows[r].pValues[c] = *(t + r * nc + c);
}

Matrix::Matrix(const Matrix& m) :
	nRows(0), nColumns(0), pRows(0) {
	Copy(m);
}

Matrix::~Matrix() {
	delete[] pRows;
}

Matrix Matrix::Zero(int nr, int nc) {
	Matrix m(nr, nc);
	return m;
}

Matrix Matrix::One(int dim) {
	Matrix m(dim, dim);
	for (int i = 0; i < dim; ++i)
		m[i][i] = 1.0;
	return m;
}

Matrix& Matrix::Zero() {
	for (int l = 0; l < nRows; ++l)
		for (int c = 0; c < nColumns; ++c)
			pRows[l].pValues[c] = 0.0;
	return *this;
}

Matrix::Row& Matrix::operator[](int i) {
	return pRows[i];
}

const Matrix::Row& Matrix::operator[](int i) const {
	return pRows[i];
}

Matrix& Matrix::operator=(const Matrix& m) {
	if (this != &m)
		Copy(m);
	return *this;
}

Matrix Matrix::operator*(const Matrix& m) const {
	if (nColumns != m.nRows)
		throw IncompatibleSizes();
	Matrix mt(nRows, m.nColumns);
	for (int l = 0; l < mt.nRows; ++l)
		for (int c = 0; c < mt.nColumns; ++c)
			for (int i = 0; i < nColumns; ++i)
				mt.pRows[l].pValues[c] += pRows[l].pValues[i]
				                          * m.pRows[i].pValues[c];
	return mt;
}

Matrix& Matrix::operator*=(const Matrix& m) {
	if (nColumns != m.nRows || nColumns != m.nColumns)
		throw IncompatibleSizes();
	if (this == &m)
		*this = (*this) * m;
	else {
		double* temp = new double[nColumns];  // new double[nColumns]() -> initialization 0 (ISO c++03)
		for (int l = 0; l < nRows; ++l) {
			for (int c = 0; c < nColumns; ++c)
				temp[c] = pRows[l].pValues[c];
			for (int c = 0; c < nColumns; ++c) {
				pRows[l].pValues[c] = 0.0;
				for (int i = 0; i < nColumns; ++i)
					pRows[l].pValues[c] += temp[i] * m.pRows[i].pValues[c];
			}
		}
		delete[] temp;
	}
	return *this;
}

Matrix Matrix::operator+(const Matrix& m) const {
	if (nRows != m.nRows || nColumns != m.nColumns)
		throw IncompatibleSizes();
	Matrix mt(*this);
	return mt += m;
}

Matrix& Matrix::operator+=(const Matrix& m) {
	if (nRows != m.nRows || nColumns != m.nColumns)
		throw IncompatibleSizes();
	if (nRows == m.nRows && nColumns == m.nColumns)
		for (int l = 0; l < nRows; ++l)
			for (int c = 0; c < nColumns; ++c)
				pRows[l].pValues[c] += m.pRows[l].pValues[c];
	return *this;
}

bool Matrix::operator==(const Matrix& m2) const {
	if (nRows != m2.nRows || nColumns != m2.nColumns)
		return false;
	for (int r = 0; r < nRows; ++r)
		for (int c = 0; c < nColumns; ++c)
			if (fabs(pRows[r].pValues[c] - m2.pRows[r].pValues[c]) > EPSILON)
				return false;

	return true;
}

int Matrix::GetNbrRows() const {
	return nRows;
}

int Matrix::GetNbrColumns() const {
	return nColumns;
}

double Matrix::Norm() const {
	double norm = 0.0;
	// double norm = -numeric_limits<double>::max(); // ERROR ...
	double d;
	for (int r = 0; r < nRows; ++r) {
		d = 0.0;
		for (int c = 0; c < nColumns; ++c)
			d += fabs(pRows[r].pValues[c]);
		if (d > norm)
			norm = d;
	}
	return norm;
}

string Matrix::ToString() const {
	ostringstream oss;
	oss << *this;
	return oss.str();
}

string Matrix::ToTabularString() const {
	ostringstream oss;
	oss << fixed << setprecision(2);
	for (int r = 0; r < GetNbrRows(); ++r) {
		for (int c = 0; c < GetNbrColumns(); ++c)
			oss << setw(10) << pRows[r].pValues[c];
		oss << endl;
	}
	return oss.str();
}

void Matrix::Realloc(int nr, int nc) /* throw (BadSize) */ {
	if (nRows != nr || nColumns != nc) {
		delete[] pRows;
		nRows = nColumns = 0;
		pRows = 0;
		if (nr < 0 || nc < 0 || (nr == 0 && nc != 0) || (nc == 0 && nr != 0))
			throw BadSize();
		if (nr != 0) {
			try {
				pRows = new Row[nr /* * 100000000 */];
				for (int i = 0; i < nr; ++i) // inutile
					pRows[i].pValues = 0;    // inutile (cf. constructeur de Row)
				for (int i = 0; i < nr; ++i)
					pRows[i].pValues = new double[nc]; // new double[nc]() -> 0 (ISO c++03)
				nRows = nr;
				nColumns = nc;
			} catch (...) {
				delete[] pRows;
				nRows = nColumns = 0;
				pRows = 0;
				throw;
			}
		}
	}
}

void Matrix::Copy(const Matrix& m) {  // ok si &m == this car ...
	Realloc(m.nRows, m.nColumns);
	for (int i = 0; i < nRows; ++i)
		for (int j = 0; j < nColumns; ++j)
			pRows[i].pValues[j] = m.pRows[i].pValues[j];
}

double Matrix::DetRec() const {
	if ((nColumns != nRows) || (nRows == 0))
		throw BadSize();
	WorkClassDet td(this);
	return td.DetR();
}
//---------------------------------------------------------------------------
istream& operator >>(istream& is, Matrix& m) {
	int nr=-1, nc=-1;  // pour Realloc en cas d'activation de failbit
	is >> nr;
	is.get();
	is >> nc;
	m.Realloc(nr, nc);
	for (int i = 0; i < m.GetNbrRows(); ++i)
		for (int j = 0; j < m.GetNbrColumns(); ++j) {
			is.get();
			is >> m[i][j];
		}
	return is;
}

ostream& operator <<(ostream& os, const Matrix& m) {
	os << m.GetNbrRows() << ' ' << m.GetNbrColumns();
	for (int i = 0; i < m.GetNbrRows(); ++i)
		for (int j = 0; j < m.GetNbrColumns(); ++j)
			os << ' ' << m[i][j];
	return os;
}
//---------------------------------------------------------------------------

WorkClassDet::WorkClassDet(const Matrix* p) :
	pm(p), dim(p->GetNbrRows()), l(0), pc(0) {
	pc = new bool[dim];
	for (int i = 0; i < dim; ++i)
		pc[i] = true;
}

WorkClassDet::~WorkClassDet() {
	delete[] pc;
}

double WorkClassDet::DetR() {
	int c;
	if (l == dim - 1) {
		for (c = 0; !pc[c]; ++c)
			;
		return (*pm)[l][c];
	} else {
		double d = 0;
		int cc = 0;
		for (c = 0, cc = 0; cc < dim - l; ++c)
			if (pc[c]) {
				++cc;
				pc[c] = false;
				if (cc % 2)
					d += (*pm)[l++][c] * DetR();
				else
					d -= (*pm)[l++][c] * DetR();
				pc[c] = true;
				--l;
			}
		return d;
	}
}
//---------------------------------------------------------------------------
} // namespace isibmath
//---------------------------------------------------------------------------
