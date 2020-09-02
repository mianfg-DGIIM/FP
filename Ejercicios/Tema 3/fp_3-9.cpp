#include <iostream>
using namespace std;

int main() {
	double a, b, epsilon;
	double c = 0;
	int iteracion = 0;
	cout << "Buscaremos las soluciones de 2x^3 + 8x^2 - 5 = 0 a partir de un intervalo" << endl;
	cout << "Inserte el intervalo [a,b] : ";
	cin >> a >> b;
	cout << "Inserte el epsilon : ";
	cin >> epsilon;
	while ( ( b - a ) > epsilon ) {
		iteracion += 1;
		c = ( a + b ) / 2;
		if ( ( 2*a*a*a + 8*a*a - 5 ) * ( 2*c*c*c + 8*c*c - 5 ) <= 0 ) {
			b = c;
		} else if ( ( 2*b*b*b + 8*b*b - 5 ) * ( 2*c*c*c + 8*c*c - 5 ) <= 0 ) {
			a = c;
		}
		cout << "x_" << iteracion << " = " << c << endl;
	}
	cout << "Tras " << iteracion << " iteraciones, x = " << c;
}
