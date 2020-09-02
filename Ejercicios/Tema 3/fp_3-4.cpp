/*
 *  EJERCICIO 3-4 v2
 */

#include <iostream>

using namespace std;

int main() {
	int numero = 0;
	while (numero <= 0) {
		cout << "Introduzca un numero entero positivo: ";
		cin >> numero;
	}
	cout << numero << " es un numero entero positivo" << endl;
	
	int digitos = 0;
	while (numero > 0) {
		numero /= 10;
		digitos++;
	}
	cout << "Ademas, el numero tiene " << digitos << " digitos";
}
