#include <cmath>
using namespace std;

class CKomplex
{
    private:
    double real;
    double imag;

    public:
    //Konstruktoren
    CKomplex(){real = 0; imag = 0;}
    CKomplex(double r, double i) : real{r}, imag{i} {}
    CKomplex(double phi) : real{cos(phi)}, imag{sin(phi)} {}

    //Getter
    double re() const {return real;}
    double im() const {return imag;}

    //Funktion zur Errechnung und Rückgabe des Betrags der komplexen Zahl
    double abs();


    //Überladene Operatoren
    CKomplex operator+(const CKomplex b);
    CKomplex operator*(const CKomplex b);
    CKomplex operator-(const CKomplex b);
};

    CKomplex operator*(const double a, const CKomplex b);