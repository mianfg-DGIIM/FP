#include <iostream>
using namespace std;

// ejercicio 1
int DivisoresP ( int num ) {
	int divisores = 0;
	for ( int i = 1; i < num; i++ ) {
		if ( num % i == 0 ) divisores++;
	}
	return divisores;
}

// ejercicio 2
char Minuscula ( char letra ) {
	if ( letra >= 'A' && letra <= 'Z' ) {
		letra += 32;
	}
	return letra;
}

// ejercicio 3
int mcd ( int a, int b ) {
	int resto = a % b;
	while ( resto != 0 ) {
		a = b;
		b = resto;
		resto = a % b;
	}
	return b;
}

int mcm ( int a, int b ) {
	int c = a / mcd(a,b) * b;  // para evitar que se vaya de rango
	return c;
}

// ejercicio 4
int potencia ( int a, int b ) {
	int resultado = a;
	for ( int i = 1; i < b; i++ ) {
		resultado *= a;
	}
	return resultado;
}

// ejercicio 5
double Evaluar ( double a, double b, double c, double d, double x ) {
	x = a * potencia ( x , 3 ) + b * potencia ( x , 2 ) + c * x + d;
}

int main () {
	/*
	// ejercicio 1
	int numero;
	cout << "Inserte el numero ";
	cin >> numero;
	cout << "Tiene " << DivisoresP(numero) << " divisores";
	
	// ejercicio 2
	char letra;
	cout << "Inserte la letra y la convertiremos a minuscula: ";
	cin >> letra;
	cout << "En minuscula es " << Minuscula(letra);
	*/
	// ejercicio 3
	int num1 = 0, num2 = 0;
	cout << "Inserte los numeros: ";
	cin >> num1 >> num2;
	cout << "  - Maximo comun divisor : " << mcd(num1, num2) << endl;
	cout << "  - Minimo comun multiplo : " << mcm(num1, num2) << endl;
	/*
	// ejercicio 4
	int a, b;
	cout << "Inserte a b : ";
	cin >> a >> b;
	cout << a << "^" << b << " = " << potencia(a, b);
	
	// ejercicio 5
	double a, b, c, d, x;
	cout << "Inserte a b c d x : ";
	cin >> a >> b >> c >> d >> x;
	cout << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << " = " << Evaluar(a, b, c, d, x);
	*/	
}
