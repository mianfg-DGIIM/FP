#include <iostream>

using namespace std;

main () {
	int dia, mes, anio;
	char c;
	
	cout << "Introduce la fecha (d/m/a)";
	cin >> dia >> c >> mes >> c >> anio;
		
	if (anio > 0 && mes > 0 && mes <= 12){
		if ( mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes ==12 )
			if (dia <=31)
				cout << "La fecha es correcta";
			else 
				cout << "La fecha no es correcta, el mes introducido tiene menos de 31 dias";
				
		else if ( mes == 2 )
			if ( dia <= 28 )
				cout << "La fecha es correcta";
			else 
				cout << "La fecha es incorrecta, el mes introducido tiene menos de 28 dias";
				
		else 
			if (dia <=30)
				cout << "La fecha es correcta";
			else 
				cout << "La fecha no es correcta, el mes introducido tiene menos de 30 dias";
	}
	else
		cout << "La fecha no es correcta, el mes o el año no tienen un valor correcto";
			
}
