#include <iostream>
#include <string>

using namespace std;
int main() { 
	string s; 
	cout << "Introduzca una cadena " 
			"de caracteres y pulse \"Intro\":" << endl;
	getline(cin,s); 
	for (int i=0; i< s.size();++i) 
		if (s.at(i)==' ') 
			s.at(i)= '-';
	cout << "Separaciones: " << s << endl;
} 
