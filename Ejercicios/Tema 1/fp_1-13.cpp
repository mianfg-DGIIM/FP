#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double a, b, c, e, p, theta, arctan;
	cout << "Inserte los valores, separados por espacios, a b c e p theta: ";
	cin >> a >> b >> c >> e >> p >> theta;
	arctan = atan2( (c + pow(e, 2) * b * pow(sin(theta) , 3)) , (p - pow(e, 2) * a * pow(pow(cos(theta) , 3) , 1/5.0)) );
	cout << "El valor del arcotangente es: " << arctan;
}
