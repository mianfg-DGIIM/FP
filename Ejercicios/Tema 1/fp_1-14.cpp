#include <iostream>
#include <cmath>

using namespace std;

int main() {
	const double pi = 3.14159265358979323846;
	double desviacion, media, x, gaussiana;
	cout << "Inserte los valores desviacion media x: ";
	cin >> desviacion >> media >> x;
	gaussiana = 1/(desviacion * sqrt(2 * pi)) * exp(-(1/2.0) * pow((x - media) / desviacion , 2));
	cout << "Gaussiana de x: " << gaussiana;
}
