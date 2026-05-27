 #include <iostream>
#include <fstream>   
#include <vector>
#include <cmath>
#include "CKomplex.h"
using namespace std;

const double pi = 2*acos(0.0);

vector<CKomplex> werte_einlesen(const std::string dateiname)
{
	int i, N, idx;
	double re, im;
	vector<CKomplex> werte;
		// File oeffnen
	ifstream fp;
	fp.open(dateiname);
		// Dimension einlesen
	fp >> N;
		// Werte-Vektor anlegen
	werte.resize(N);
	CKomplex null(0,0);
	for (i = 0; i<N; i++)
		werte[i] = null;
		// Eintraege einlesen und im Werte-Vektor ablegen
	while (!fp.eof())
	{
		fp >> idx >> re >> im;
		CKomplex a(re,im);
		werte[idx] = a;
	}
		// File schliessen
	fp.close();

	return werte;
}

void werte_ausgeben(const std::string dateiname, vector<CKomplex> werte, double epsilon = -1.0)
{
	int i;
	int N = werte.size();
		// File oeffnen
	ofstream fp;
	fp.open(dateiname);
		// Dimension in das File schreiben
	fp << N << endl;
		// Eintraege in das File schreiben
	fp.precision(10);
	for (i = 0; i < N; i++)
		if (werte[i].abs() > epsilon)
			fp << i << "\t" << werte[i].re() << "\t" << werte[i].im() << endl;
		// File schliessen
	fp.close();
}

vector<CKomplex> fourier_transformationen(vector<CKomplex> werte, bool hin)
{
	double N = werte.size();
    vector<CKomplex> trans(N);		//Ergebnisvektor
	double vorFaktor = 1/sqrt(N);	//Vorfaktor 1/sqrt(N)

    //Cn = vorFaktor * summe(werte[b] * e^((-2 * pi * k * n)/N)
    for(int n = 0; n < N; n++)
    {
        CKomplex result;
		for(int k = 0; k < N; k++)
    	{
			if(hin)
			{
				result = result + werte[k] * CKomplex((-2*pi*k*n)/N);
			}
			else
			{
				result = result + werte[k] * CKomplex((2*pi*k*n)/N);
			}
    	}

		result = vorFaktor * result;		//Multiplizieren mit dem Vorfaktor
		trans[n] = result;
    }
	return trans;
}

void abweichungen(vector<CKomplex> a, vector<CKomplex> b)
{
	double max_ab = 0.0;
	CKomplex abweichung;
	for(size_t n = 0; n < a.size(); n++)
	{
		abweichung = a[n] - b[n];
		max_ab = max(max_ab, abweichung.abs());
	}
	cout << max_ab;
}


int main() 
{
    /* Test fÃ¼r einlesen und ausgeben
    vector<CKomplex> test;
    test = werte_einlesen("Daten_original1.txt");
    werte_ausgeben("Daten_o1_test.txt", test);
    */

   	//Aufgabe 4 Test
   	vector<CKomplex> original1;
	vector<CKomplex> original2;
   	vector<CKomplex> umwandlung;
	original1 = werte_einlesen("Daten_original1.txt");
	original2 = werte_einlesen("Daten_original2.txt");
	
	//Fouriertransformationen (hin)
	//Original 1 hintransformation
	umwandlung = fourier_transformationen(original1, true);
	werte_ausgeben("Daten_original1_-1.txt", umwandlung);
	werte_ausgeben("Daten_original1_0,001.txt", umwandlung, 0.001);
	werte_ausgeben("Daten_original1_0,01.txt", umwandlung, 0.01);
	werte_ausgeben("Daten_original1_0,1.txt", umwandlung, 0.1);
	werte_ausgeben("Daten_original1_1.txt", umwandlung, 1);
	//Original 1 hintransformation
	umwandlung = fourier_transformationen(original2, false);
	werte_ausgeben("Daten_original2_-1.txt", umwandlung);
	werte_ausgeben("Daten_original2_0,001.txt", umwandlung, 0.001);
	werte_ausgeben("Daten_original2_0,01.txt", umwandlung, 0.01);
	werte_ausgeben("Daten_original2_0,1.txt", umwandlung, 0.1);
	werte_ausgeben("Daten_original2_1.txt", umwandlung, 1);

  /*
	//Aufgabe 5 Test
  vector<CKomplex> original;
  vector<CKomplex> original_umwandlung;
  vector<CKomplex> epsilon_umwandlung;
  vector<CKomplex> umwandlung1;

  
  //Bild mit Auflösung 64
  original = werte_einlesen("Testbild_original_64.txt");
  original_umwandlung = fourier_transformationen(original, true);

  werte_ausgeben("Testbild_trans_64_10.txt", original_umwandlung, 10);
  epsilon_umwandlung = werte_einlesen("Testbild_trans_64_10.txt");
  umwandlung = fourier_transformationen(epsilon_umwandlung, false);
  werte_ausgeben("Testbild_rueck_trans_64_10.txt", umwandlung);

  werte_ausgeben("Testbild_trans_64_30.txt", original_umwandlung, 30);
  epsilon_umwandlung = werte_einlesen("Testbild_trans_64_30.txt");
  umwandlung = fourier_transformationen(epsilon_umwandlung, false);
  werte_ausgeben("Testbild_rueck_trans_64_30.txt", umwandlung);

  werte_ausgeben("Testbild_trans_64_100.txt", original_umwandlung, 100);
  epsilon_umwandlung = werte_einlesen("Testbild_trans_64_100.txt");
  umwandlung = fourier_transformationen(epsilon_umwandlung, false);
  werte_ausgeben("Testbild_rueck_trans_64_100.txt", umwandlung);

  werte_ausgeben("Testbild_trans_64_300.txt", original_umwandlung, 300);
  epsilon_umwandlung = werte_einlesen("Testbild_trans_64_300.txt");
  umwandlung = fourier_transformationen(epsilon_umwandlung, false);
  werte_ausgeben("Testbild_rueck_trans_64_300.txt", original_umwandlung);

  werte_ausgeben("Testbild_trans_64_1000.txt", original_umwandlung, 1000);
  epsilon_umwandlung = werte_einlesen("Testbild_trans_64_1000.txt");
  umwandlung = fourier_transformationen(epsilon_umwandlung, false);
  werte_ausgeben("Testbild_rueck_trans_64_1000.txt", umwandlung);
  
*/
  

	
	//RÃ¼cktransformationen und Abweichung
	vector<CKomplex> hin;

	//Bei Daten_original1
	cout << "Bei Daten_original1.txt" << endl;

	hin = werte_einlesen("Daten_original1_-1.txt");
	umwandlung = fourier_transformationen(hin, false);
	werte_ausgeben("Daten_original1_hinrueck_-1.txt",umwandlung);
	cout << "Maximale Abweichung bei Standard-Epsilon: ca. ";
	abweichungen(original1, umwandlung); cout << endl;

	hin = werte_einlesen("Daten_original1_0,001.txt");
	umwandlung = fourier_transformationen(hin, false);
	werte_ausgeben("Daten_original1_hinrueck_0,001.txt",umwandlung,0.001);
	cout << "Maximale Abweichung bei epsilon=0.001: ";
	abweichungen(original1, umwandlung); cout << endl;

	hin = werte_einlesen("Daten_original1_0,01.txt");
	umwandlung = fourier_transformationen(hin, false);
	werte_ausgeben("Daten_original1_hinrueck_0,01.txt",umwandlung,0.01);
	cout << "Maximale Abweichung bei epsilon=0.01: ";
	abweichungen(original1, umwandlung); cout << endl;

	hin = werte_einlesen("Daten_original1_0,1.txt");
	umwandlung = fourier_transformationen(hin, false);
	werte_ausgeben("Daten_original1_hinrueck_0,1.txt",umwandlung,0.1);
	cout << "Maximale Abweichung bei epsilon=0.1: ";
	abweichungen(original1, umwandlung); cout << endl;

	hin = werte_einlesen("Daten_original1_1.txt");
	umwandlung = fourier_transformationen(hin, false);
	werte_ausgeben("Daten_original1_hinrueck_1.txt",umwandlung,1);
	cout << "Maximale Abweichung bei epsilon=1: ";
	abweichungen(original1, umwandlung); cout << endl;

	//Bei Daten_original2
	cout << "Bei Daten_original2.txt" << endl;

	hin = werte_einlesen("Daten_original2_-1.txt");
	umwandlung = fourier_transformationen(hin, true);
	werte_ausgeben("Daten_original2_hinrueck_-1.txt",umwandlung);
	cout << "Maximale Abweichung bei Standard-Epsilon: ca. ";
	abweichungen(original2, umwandlung); cout << endl;

	hin = werte_einlesen("Daten_original2_0,001.txt");
	umwandlung = fourier_transformationen(hin, true);
	werte_ausgeben("Daten_original2_hinrueck_0,001.txt",umwandlung,0.001);
	cout << "Maximale Abweichung bei epsilon=0.001: ";
	abweichungen(original2, umwandlung); cout << endl;

	hin = werte_einlesen("Daten_original2_0,01.txt");
	umwandlung = fourier_transformationen(hin, true);
	werte_ausgeben("Daten_original2_hinrueck_0,01.txt",umwandlung,0.01);
	cout << "Maximale Abweichung bei epsilon=0.01: ";
	abweichungen(original2, umwandlung); cout << endl;

	hin = werte_einlesen("Daten_original2_0,1.txt");
	umwandlung = fourier_transformationen(hin, true);
	werte_ausgeben("Daten_original2_hinrueck_0,1.txt",umwandlung,0.1);
	cout << "Maximale Abweichung bei epsilon=0.1: ";
	abweichungen(original2, umwandlung); cout << endl;

	hin = werte_einlesen("Daten_original2_1.txt");
	umwandlung = fourier_transformationen(hin, true);
	werte_ausgeben("Daten_original2_hinrueck_1.txt",umwandlung,1);
	cout << "Maximale Abweichung bei epsilon=1: ";
	abweichungen(original2, umwandlung); cout << endl;
	

	


    system("pause");
}