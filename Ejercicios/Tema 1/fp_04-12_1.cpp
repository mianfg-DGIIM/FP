#include <iostream>

using namespace std;

int main() {
	double x, y, z;
	cout << "Introduzca dos valores separados con espacios del tipo x y: ";
	cin >> x >> y;
	cout << "Inicialmente tenemos que: x = " << x << "; y = " << y << endl;
	z = x;
	x = y;
	y = z;
	cout << "Tras intercambiar los valores: x = " << x << "; y = " << y;
}
