#include <cmath>
#include "CKomplex.h"
using namespace std;

//Betrags Methode
double CKomplex::abs()
{
    return sqrt(pow(this->real, 2) + pow(this->imag, 2));
}

//Überladene Operatoren
CKomplex CKomplex::operator+(const CKomplex b)
{
    CKomplex result(this->real + b.re(), this->imag + b.im());
    return result;
}

CKomplex CKomplex::operator*(const CKomplex b)
{
    CKomplex result(this->real*b.re() - this->imag*b.im(), this->real*b.im() + this->imag*b.re());
    return result;
}

CKomplex CKomplex::operator-(const CKomplex b)
{
    CKomplex result(this->real - b.re(), this->imag - b.im());
    return result;
}


CKomplex operator*(const double a, const CKomplex b)
{
    CKomplex result(a*b.re(),a*b.im());
    return result;
}