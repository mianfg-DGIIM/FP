#include <iostream>

using namespace std;

int main(){
	int anio;
	int A, B, C, D, E, N;
	
	cout << "Introduce el año del que quieres saber la fecha de pascua" << endl;
	cin >> anio;
	
	if ( 1900 < anio && anio < 2100) {
		A = anio % 19;
		B = anio % 4;
		C = anio % 7;
		D = ( 19 * A + 24 ) % 30;
		E = ( 2 * B + 4 * C + 6 * D +5) % 7;
		N = ( 22 + D + E );
	
		if (N <= 31) {
			cout << "El dia de Pascua es el " << N << " de Marzo";
		}
		else { //(N > 31)
			if ( N != 57 && N!=56 ){
				cout << "El dia de Pascua es el " << N - 31 << " de Abril";
			}
			if ( N == 57 ) {
				cout << "El dia de Pascua es el 19 de Abril";
			}
			if ( N == 56 ) {
				if ( D==28 && E==6 && A>10)
					cout << "El dia de Pascua es el 18 de Abril";
				else 
					cout << " El dia de Pascua es el 25 de Abril";
			}
		}
	}
	else 
		cout << "El año introducido tiene que estar entre 1900 y 2100";
}

