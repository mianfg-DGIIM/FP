#include <iostream>
using namespace std;

int main() {
	// comprobar si es un n�mero perfecto
	int numero_tope;
	int suma = 0;
	int mayor_perfecto = 0;
	cout << "Inserte un entero: "; cin >> numero_tope;
	for ( int numero = 1 ; numero <= numero_tope ; numero++ ) {
		suma = 0;
		for ( int i = numero; i >= 1; i-- ) {
			if ( numero % i == 0 && numero != i ) {
				// cout << "Divisor de " << numero << ": " << i << endl;
				suma += i;
			}
		}
		// cout << suma << endl;
		if ( suma == numero ) {
			// se trata de un n�mero perfecto
			mayor_perfecto = numero;
		}
	}
	
	if ( mayor_perfecto != 0 ) {
		cout << "El mayor numero perfecto hasta " << numero_tope << " es " << mayor_perfecto;
	} else {
		cout << "No hay ningun numero perfecto menor o igual que " << numero_tope;
	}
}
