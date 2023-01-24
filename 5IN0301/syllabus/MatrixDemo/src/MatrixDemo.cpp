//---------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include "../../InOut/src/inout.h"
#include "Matrix.h"
//---------------------------------------------------------------------------
using namespace std;
using namespace isibmath;
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    double t2[1] = { 1.5 };
    double t3[6] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
    //	double t4[2][3] = { 6.0, 5.0, 4.0, 3.0, 2.0, 1.0 }; // OK
    double t4[2][3] = { { 6.0, 5.0, 4.0 }, { 3.0, 2.0, 1.0 } };
    double
    t5[][3] = { { 1.0, 2.0, 3.0 }, { 4.0, 5.0, 6.0 }, { 7.0, 8.0, 9.0 } };
    double t6[][2] = { { 0.0, 1.0 }, { 0.0, 1.0 }, { 1.0, 1.0 } };

    Matrix m0;
    cout << "Matrix m0; -> " << m0 << endl;
    Matrix m1(2, 3);
    cout << "Matrix m1(2, 3); -> " << m1.ToString() << endl;

    Matrix m2(t2, 1, 1);
    cout << "Matrix m2(t2,1,1) -> " << m2 << endl;
    Matrix m3(t3, 2, 3);
    cout << "Matrix m3(t3,2,3) -> " << m3 << endl;
    Matrix m4(t4[0], 2, 3);
    cout << "Matrix m4(t4[0],2,3) -> " << m4 << endl;
    Matrix m5(t5[0], 3, 3);
    cout << "Matrix m5(t5[0],3,3) -> " << m5 << endl;
    Matrix m6(t6[0], 3, 2);
    cout << "Matrix m6(t6[0],3,2) -> " << m6 << endl;
    Matrix m3bis(m3);
    cout << "Matrix m3bis(m3) -> " << m3bis << endl;
    try {
        Matrix m(2, 0);
        cerr << "Erreur : Exception non lancée pour Matrix m(2, 0)" << endl;
    } catch (Matrix::BadSize const& e) {
        cout << "Exception lancée pour Matrix m(2,0) -> " << e.what() << endl;
    }
    Matrix m7 = Matrix::Zero(1, 3);
    cout << "Matrix m7 = Matrix::ZERO(1,3) ->" << m7 << endl;
    Matrix m8 = Matrix::One(3);
    cout << "Matrix m8 = Matrix.One(3) ->" << m8 << endl;

    cout << "m1 ->" << endl << m1.ToTabularString();
    cout << "m2 ->" << endl << m2.ToTabularString();
    cout << "m3 ->" << endl << m3.ToTabularString();
    cout << "m4 ->" << endl << m4.ToTabularString();
    cout << "m5 ->" << endl << m5.ToTabularString();
    cout << "m6 ->" << endl << m6.ToTabularString();
    cout << "m7 ->" << endl << m7.ToTabularString();
    cout << "m8 ->" << endl << m8.ToTabularString();

    m7 = m3 + m4;
    cout << "m7 = m3+m4 ->" << endl << m7.ToTabularString();
    try {
        m3 + m5;
        cerr << "Erreur : Exception non lancée pour m3+m5" << endl;
    } catch (Matrix::IncompatibleSizes const& e) {
        cout << "Exception lancée pour m3+m5 -> " << e.what() << endl;
    }
    m3bis += m4;
    cout << "m3bis+=m4 ->" << endl << m3bis.ToTabularString();
    try {
        m3 += m5;
        cerr << "Erreur : Exception non lancée pour m3+=m5" << endl;
    } catch (Matrix::IncompatibleSizes const& e) {
        cout << "Exception lancée pour m3+=m5 -> " << e.what() << endl;
    }
    cout << "m3 -> " << endl << m3.ToTabularString();

    m7 = m5 * m8;
    cout << "m7 = m5 * m8 ->" << endl << m7.ToTabularString();
    m7 = m8 * m5;
    cout << "m7 = m8 * m5 ->" << endl << m7.ToTabularString();
    m7 = m3 * m6;
    cout << "m7 = m3 * m6 ->" << endl << m7.ToTabularString();
    m7 = m5 * m5;
    cout << "m7 = m5 * m5 ->" << endl << m7.ToTabularString();
    cout << "m3*m5 ->" << endl << (m3 * m5).ToTabularString();
    try {
        m5 * m4;
        cerr << "Erreur : Exception non lancée pour m5*m4" << endl;
    } catch (Matrix::IncompatibleSizes const& e) {
        cout << "Exception lancée pour m5*m4 -> " << e.what() << endl;
    }

    m5 *= m8;
    cout << "m5*=m8 -> " << endl << m5.ToTabularString();
    m3 *= m5;
    cout << "m3*=m5 -> " << endl << m3.ToTabularString();
    m5 *= m5;
    cout << "m5*=m5 -> " << endl << m5.ToTabularString();
    try {
        m3 *= m6;
        cerr << "Erreur : Exception non lancée pour m3*=m6" << endl;
    } catch (Matrix::IncompatibleSizes const& e) {
        cout << "Exception lancée pour m3*=m6 -> " << e.what() << endl;
    }

    cout << "m1.GetNbrRows() -> " << m1.GetNbrRows() << endl;
    cout << "m1.GetNbrColumns() -> " << m1.GetNbrColumns() << endl;

    m1[1][2] = 11.1;
    cout << "m1[1][2] = 11.1; m1[1][2] -> " << m1[1][2] << endl;
    cout << "m6==m6 -> " << (m6 == m6) << endl;
    cout << "m3==m4 -> " << (m3 == m4) << endl;
    cout << "m1==m2 -> " << (m1 == m2) << endl;
    cout << "m7==m5 -> " << (m7 == m5) << endl;
    cout << "m4.Norm() -> " << m4.Norm() << endl;
    cout << "m6.Norm() -> " << m6.Norm() << endl;
    try {
        cout << "m3.DetRec() -> " << m3.DetRec() << endl;
        cout << "m4.DetRec() -> " << m4.DetRec() << endl;
        cerr << "Erreur : Exception non lancée pour DetRec() sur matrice non carrée" << endl;
    } catch (Matrix::BadSize const& e) {
        cout << "Exception lancée pour DetRec() sur matrice non carrée -> " << e.what() << endl;
    }
    cout << "m5.DetRec() -> " << m5.DetRec() << endl;

    return 0;
}
//---------------------------------------------------------------------------
