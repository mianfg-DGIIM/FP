#include <iostream>

using namespace std;

int main() {
	int entrada = 0, suma = 0;
	do {
		suma += entrada;
		cout << "Introduzca un numero entero positivo: ";
		cin >> entrada;
	} while ( entrada > 0 );
	cout << "La suma de todos los numeros insertados es: " << suma;
}
