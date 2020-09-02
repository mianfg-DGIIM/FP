#include <iostream>

using namespace std;

int main() {
	int numero;
	do {
		cout << "Introduzca un numero entero positivo: ";
		cin >> numero;
	} while ( numero < 0 );
		cout << numero << " es un numero entero positivo" << endl;
}
