#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double x, y, z, avg, dvn;
	// Introducci�n de valores
	cout << "Introduzca tres valores separados con espacios: ";
	cin >> x >> y >> z;
	// C�lculo de la media, avg, y de la desviaci�n t�pica, dvn
	avg = (x+y+z)/3;
	dvn = sqrt((pow(x-avg, 2)+pow(y-avg, 2)+pow(z-avg, 2))/3);
	cout << "La media de los tres valores: " << avg << endl << "Su desviacion tipica: " << dvn;
}
