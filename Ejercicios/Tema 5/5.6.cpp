#include <iostream>
#include <string>
using namespace std;

int main() {
	string nombre1, nombre2;
	
	cout << "Introduzca el nombre de la primera persona: ";
	cin >> nombre1;
	cout << "Introduzca el nombre de la segunda persona: ";
	cin >> nombre2;
	
	if (nombre1 < nombre2)
		cout << nombre1 << endl << nombre2;
	else
		cout << nombre2 << endl << nombre1;
}

