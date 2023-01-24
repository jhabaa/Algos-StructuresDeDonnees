#if !defined(MATRIX_H)
#define MATRIX_H
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
//---------------------------------------------------------------------------
namespace isibmath {
//---------------------------------------------------------------------------
class Matrix {
public:
	class BadSize: public std::exception {
	public:
		virtual const char* what() const throw () {
			return "Bad matrix size";
		}
	};
	class IncompatibleSizes: public std::exception {
	public:
		virtual const char* what() const throw () {
			return "Incompatible matrix sizes";
		}
	};
protected:
	class Row {
	public:
		inline double& operator[](int j) {
			return pValues[j];
		}
		inline const double& operator[](int j) const {
			return pValues[j];
		}
	private:
		inline Row() :
			pValues(0) {
		}
		inline ~Row() {
			delete[] pValues;
		}
		double* pValues;
		friend class Matrix;
	};
public:
	static const double EPSILON;

	Matrix(int nr = 0, int nc = 0);
	Matrix(const double* t, int nr, int nc);
	Matrix(const Matrix& m);
	~Matrix();
	static Matrix Zero(int nr, int nc);
	static Matrix One(int dim);
	Matrix& Zero();
	Row& operator[](int i);
	const Row& operator[](int i) const;
	Matrix& operator=(const Matrix& m);
	Matrix operator*(const Matrix& m) const;
	Matrix& operator*=(const Matrix& m);
	Matrix operator+(const Matrix& m) const;
	Matrix& operator+=(const Matrix& m);
	bool operator==(const Matrix& m2) const;
	int GetNbrRows() const;
	int GetNbrColumns() const;
	double Norm() const;
	double DetRec() const;
	std::string ToString() const;
	std::string ToTabularString() const;

protected:
	void Realloc(int nl, int nc);  // throw (BadSize);
	void Copy(const Matrix&);
	int nRows, nColumns;
	Row* pRows;
	friend std::istream& operator >>(std::istream& is, Matrix& m);
};
//---------------------------------------------------------------------------
std::ostream& operator <<(std::ostream& os, const Matrix& m);
//---------------------------------------------------------------------------
} // namespace isibmath
//---------------------------------------------------------------------------
#endif
