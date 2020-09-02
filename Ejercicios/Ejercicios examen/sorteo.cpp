#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

int generar(int hasta) {
	int aleatorio;
	
	aleatorio = rand() % hasta;
	return aleatorio;
}

void random( vector<int> & toca, int size ) {
	int valor;
	bool iterar;
	for ( int i = 0; i < size; i++ ) {
		do {
			iterar = false;
			valor = generar(size);
			for ( int j = 0; j < i; j++ ) {
				if ( toca[j] == valor ) {
					iterar = true;
				}
			}
			if ( valor == i )
				iterar = true;
		} while ( iterar );
		toca.push_back(valor);
	}
}

void limpiar_pantalla() {
	for ( int i = 0; i < 100; i++ )
		cout << endl;
}

int main() {
	srand (time(NULL));
	vector<int> toca;
	
	vector<string> nombres;
	cout << "SORTEO" << endl << "______________________" << endl << endl;
	string nombre_insertar = "null";
	while ( nombre_insertar != "0" ) {
		cout << "Inserte el nombre. Inserte 0 para terminar input: ";
		cin >> nombre_insertar;
		if ( nombre_insertar != "0" )
			nombres.push_back(nombre_insertar);
	}
	cout << "______________________" << endl << endl;
	char validacion = 'X';
	while ( validacion != 'Y' ) {
		cout << "Vamos a realizar el sorteo. Pulse Y para comenzar. El primero sera " << nombres[0] << ": ";
		cin >> validacion;
	}
	random(toca, nombres.size());
	for ( int i = 0; i < nombres.size(); i++ ) {
		limpiar_pantalla();
		cout << "A " << nombres[i] << " le ha tocado " << nombres[toca[i]] << endl;
		validacion = 'X';
		if ( i != nombres.size() - 1 ) {
		while ( validacion != 'B' ) {
			cout << "Inserte B para borrar la pantalla: ";
			cin >> validacion;
		}
		limpiar_pantalla();
		validacion = 'X';
		while ( validacion != 'N' ) {
			cout << "Inserte N para mostrar el siguiente, que correspondera a " << nombres[i+1] << ": ";
			cin >> validacion;
		}
		}
	}
	cout << "Listo!";
}
