#include <iostream>
#include <cmath>

using namespace std;

int main() {
	char letter;
	cout << "Inserte un caracter y se lo convertiremos a mayuscula (si es posible): ";
	cin >> letter;
	letter -= (letter >= 97) && (letter <= 122) ? 32 : 0;
	cout << "Convertido: " << letter;
}
