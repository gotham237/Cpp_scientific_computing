#include <iostream>
#include <fstream>

using namespace std;

void interpolacja(double x, int size, double tabx[], double tabf[]) {
	double* tabl = new double[size];
	for (int i = 0; i < size; i++) {
		tabl[i] = 1;
		for (int j = 0; j < size; j++) {
			if (i == j) continue;
			tabl[i] *= ((x - tabx[j]) / (tabx[i] - tabx[j]));
		}
	}
	double wynik = 0.0;
	for (int i = 0; i < size; i++) {
		wynik += tabf[i] * tabl[i];
	}
	cout << "Wynik: " << wynik << endl;
	delete[] tabl;
}

void zad2() {
	const int size = 4;
	double tabx[] = { 27, 64, 128, 216 };
	double tabf[size];
	for (int i = 0; i < size; i++) {
		tabf[i] = pow(tabx[i], 1.0/3.0);
	}
	double punkt = 50.0;
	cout << "zad2: ";
	//cout << punkt << endl;
	interpolacja(punkt, size, tabx, tabf);
}

int main() {

	ifstream plik;
	plik.open("plik.txt", ios_base::in);
	int size;
	plik >> size;
	double* tabx = new double[size];
	double* tabf = new double[size];
	
	for (int i = 0; i < size; i++) {
		plik >> tabx[i] >> tabf[i];
		//cout << tabx[i] << "  " << tabf[i] << endl;
	}
	plik.close();


	cout << "Liczba wezlow: " << size << endl;
	cout << "dane: " << endl;
	for (int i = 0; i < size; i++) {
		cout << tabx[i] << "  " << tabf[i] << endl;
	}
	double x = 0;
	cout << "Podaj punkt: ";
	cin >> x;
	interpolacja(x, size, tabx, tabf);

	zad2();

	delete[] tabx;
	delete[] tabf;
}
