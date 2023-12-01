#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double tabA2[] = { 1.0,1.0 };
double tabA3[] = { 5.0 / 9.0, 8.0 / 9.0, 5.0 / 9.0 };
double tabA4[] = { 1.0 / 36. * (18. - sqrt(30.)),
					   1. / 36. * (18. + sqrt(30.)),
					   1. / 36. * (18. + sqrt(30.)),
					   1. / 36. * (18. - sqrt(30.)) };

double tabx2[] = { -sqrt(3.) / 3., sqrt(3.) / 3. };
double tabx3[] = { -sqrt(3. / 5.), 0., sqrt(3. / 5.) };
double tabx4[] = { -1. / 35. * (sqrt(525. + 70. * sqrt(30.))),
				-1. / 35. * (sqrt(525. - 70. * sqrt(30.))),
				1. / 35. * (sqrt(525. - 70. * sqrt(30.))),
				1. / 35. * (sqrt(525. + 70. * sqrt(30.))) };


void metoda_prostokatow(double a, double b, double n, double (*f)(double)) {
	double s = (b - a) / n;
	double wynik = 0.0;
	fstream plik;
	plik.open("plik.txt", ios_base::out);
	for (int i = 0; i < n; i++) {
		wynik += f(a + i * s + 0.5 * s);
	}
	wynik *= s;
	cout << "Wynik metody prostokatow: " << wynik << endl;
	plik << wynik;
	plik.close();
}

void metoda_trapezow(double a, double b, double n, double (*f)(double)) {
	double s = (b - a) / n;
	double wynik = 0.0;
	fstream plik;
	plik.open("plik.txt", ios_base::out);
	for (int i = 0; i < n; i++) {
		wynik += ((a + s * (i + 1) - (a + s * i)) / 2) * (f(a + s * (i)) + f(a + s * (i + 1)));
	}
	cout << "Wynik metody trapezow: " << wynik << endl;
	plik << wynik;
	plik.close();
}

void metoda_simpsona(double a, double b, double n, double (*f)(double)) {
	double s = (b - a) / n;
	double wynik = 0.0;
	fstream plik;
	plik.open("plik.txt", ios_base::out);
	plik << n;
	for (int i = 0; i < n; i++) {
		wynik += (((a + s * (i + 1) - (a + s * i)) / 6) * (f(a + s * i) + 4 * f((a + s * (i + 1) + a + s * i) / 2) + f(a + s * (i + 1))));
	}
	cout << "Wynik metody simpsona: " << wynik << endl;
	plik << wynik;
	plik.close();
}

void Gauss(double a, double b, int size, double (*f)(double)) {
	double wynik = (b - a) / 2.0;
	double temp = 0.0;
	double t = 0.0;
	if (size == 2) {
		for (int i = 0; i < size; i++) {
			t = (a + b) / 2. + (b - a) / 2. * tabx2[i];
			temp += tabA2[i] * f(t);
		}
	}
	else if (size == 3) {
		for (int i = 0; i < size; i++) {
			t = (a + b) / 2. + (b - a) / 2. * tabx3[i];
			temp += tabA3[i] * f(t);
		}
	}
	else if (size == 4) {
		for (int i = 0; i < size; i++) {
			t = (a + b) / 2. + (b - a) / 2. * tabx4[i];
			temp += tabA4[i] * f(t);

		}
	}
	wynik *= temp;
	cout << "Metoda Gaussa: " << wynik << endl;
}

double wielomian(double x) {
	return pow(x, 2) + 2 * x + 5;
}

int main() {
	double a = 0.5, b = 2.5, n = 4.0;
	cout << "Wzor calkowanej funkcji: sinx" << endl;
	cout << "przedzial calkowania: <" << a << ", " << b << ">" << endl;
	cout << "Liczba przedzialow: " << n << endl;
	metoda_prostokatow(0.5, 2.5, 4, sin);
	metoda_trapezow(0.5, 2.5, 4, sin);
	metoda_simpsona(0.5, 2.5, 4, sin);
	Gauss(0.5, 2.5, 4, sin);
	Gauss(0.5, 2.5, 3, sin);
	Gauss(0.5, 2.5, 2, sin);
	cout << endl;

	cout << "Wzor calkowanej funkcji: x^2 + 2x + 5" << endl;
	cout << "przedzial calkowania: <" << 0.5 << ", " << 5 << ">" << endl;
	cout << "Liczba przedzialow: " << n << endl;
	metoda_prostokatow(0.5, 5, 4, wielomian);
	metoda_trapezow(0.5, 5, 4, wielomian);
	metoda_simpsona(0.5, 5, 4, wielomian);
	Gauss(0.5, 5., 4, wielomian);
	Gauss(0.5, 5., 3, wielomian);
	Gauss(0.5, 5., 2, wielomian);
	cout << endl;

	cout << "Wzor calkowanej funkcji: exp(x)" << endl;
	cout << "przedzial calkowania: <" << 0.5 << ", " << 5 << ">" << endl;
	cout << "Liczba przedzialow: " << 4 << endl;
	metoda_prostokatow(0.5, 5, 4, exp);
	metoda_trapezow(0.5, 5, 4, exp);
	metoda_simpsona(0.5, 5, 4, exp);
	Gauss(0.5, 5., 4, exp);
	Gauss(0.5, 5., 3, exp);
	Gauss(0.5, 5., 2, exp);

	//double a = 0.5, b = 2.5, n = 4.0;
	//cout << "Wzor calkowanej funkcji: sinx" << endl;
	//cout << "przedzial calkowania: <" << a << ", " << b << ">" << endl;
	//cout << "Liczba przedzialow: " << n << endl;
	//metoda_prostokatow(0.5, 2.5, 4, sin);
	//metoda_trapezow(0.5, 2.5, 4, sin);
	//metoda_simpsona(0.5, 2.5, 4, sin);
	//cout << endl;

	//cout << "Wzor calkowanej funkcji: x^2 + 2x + 5" << endl;
	//cout << "przedzial calkowania: <" << 0.5 << ", " << 5 << ">" << endl;
	//cout << "Liczba przedzialow: " << n << endl;
	//metoda_prostokatow(0.5, 5, 4, wielomian);
	//metoda_trapezow(0.5, 5, 4, wielomian);
	//metoda_simpsona(0.5, 5, 4, wielomian);
	//cout << endl;

	//cout << "Wzor calkowanej funkcji: exp(x)" << endl;
	//cout << "przedzial calkowania: <" << 0.5 << ", " << 5 << ">" << endl;
	//cout << "Liczba przedzialow: " << 4 << endl;
	//metoda_prostokatow(0.5, 5, 4, exp);
	//metoda_trapezow(0.5, 5, 4, exp);
	//metoda_simpsona(0.5, 5, 4, exp);
}




