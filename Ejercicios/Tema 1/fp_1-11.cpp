#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double grados_input, segundos;
	int grados, minutos;
	// Introducci�n de valores
	cout << "Introduzca los grados con decimales: ";
	cin >> grados_input;
	// C�lculo de los grados, minutos y segundos
	grados = grados_input;
	minutos = (grados_input - grados)*60;
	segundos = ((grados_input - grados)*60 - minutos)*60;
	// Salida
	cout << "Conversion: " << grados << "o " << minutos << "\' " << segundos << "\"";
}
