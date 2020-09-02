#include <iostream>
#include <string>

using namespace std;

int main() {
	string palindromo, palindromo2;
	
	cout << "Introduzca la palabra: ";
	cin >> palindromo;
	
	for (int i=0; i < palindromo.size() ; i++ ){
		palindromo2.push_back(palindromo[palindromo.size()-i-1]);
	}
	
	cout << "Palabra invertida: " << palindromo2 << endl;
	if (palindromo2 == palindromo) 
		cout << "Son palindromos";
	else cout << "No son palindromos";
}

