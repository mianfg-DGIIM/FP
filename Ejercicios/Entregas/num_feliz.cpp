/* 
 * FUNCI�N SIMPLE - Fundamentos de Programaci�n (Pr�cticas) - 1� DGIIM
 * (N�MERO FELIZ)
 * Alumnos: Miguel �ngel Fern�ndez Guti�rrez
 *			Marta G�mez S�nchez
 * Fecha: 21 noviembre, 2017
 */

#include <iostream>

using namespace std;

// calcula el cuadrado de los d�gitos de x
int cuadradosDigitos ( int x ) {
	int suma = 0;
	while ( x != 0 ) {
		int resto = x % 10;
		x = (x-resto)/10;
		suma += resto*resto;
	}
	return suma;
}

// comprueba si num es un n�mero feliz
bool esFeliz ( int num ) {
	while ( num > 9 ) {
		num = cuadradosDigitos(num);
	}
	if ( num == 1 || num == 7 ) return true;
	else return false;
}

int main() {
	int max, min;
	int contador = 0;
	
	cout << "Rango de valores: ";
	cin >> min >> max;
	
	while ( ( min<0 ) || ( max<0 ) ) {
		cout << "Valores err�neos, los n�meros deben ser positivos" << endl << "Nuevo rango de valores: ";
		cin >> min >> max;
	}
	
	while ( min > max ) {
		cout << "Numeros desordenados, intercambiando..." << endl;
		int aux;
		aux = min;
		min = max;
		max = aux;
		cout << "Valores minimo y maximo: " << min << " " << max << endl;
	}
	
	for (int i = min; i <= max; i++ ) {
		if (esFeliz(i)) {
			cout << i << " ";
			contador++;
		}
	}
	cout << endl << "Total: " << contador << " numeros";
}

