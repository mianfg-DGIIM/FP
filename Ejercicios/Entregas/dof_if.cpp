/*
 *   EJERCICIO DE CONDICIONALES: Profundidad de campo
 *	  Fundamentos de Programación - 1º DGIIM
 *
 *	  Alumnos: Miguel Ángel Fernández Gutiérrez
 *			 	  Marta Gómez Sánchez
 *   Fecha:   25 octubre, 2017
 *
 */

#include <iostream>

using namespace std;

int main(){
	double circ_conf, long_focal, dist_enfoque, num_f;
	double hiperfocal, d_min, d_max, profundidad;
	
	// Constantes para definir limites de las variables de entrada
	const double circ_conf_min = 0.001;
	const double circ_conf_max = 1;
	const double long_focal_min = 5;
	const double long_focal_max = 2000;
	const double dist_enfoque_min = 1;
	const double num_f_min = 0.5;
	const double num_f_max = 64;
	
	// Variable para comprobar que no hay error
	bool error = false;
	
	
	// Comprobaremos que los valores de entrada son posibles para cada parámetro
	
	if ( error == false ) {
		cout << "No olvide que distancias y longitudes estan en milimetros..." << endl
			<< "Introduzca circulo de confusion " << circ_conf_min << " a " << circ_conf_max << ": ";
		cin >> circ_conf;
		if ( circ_conf < circ_conf_min || circ_conf > circ_conf_max ) {
		    error = true;
		    cout << "Error: El circulo debe estar en [" << circ_conf_min << " , " << circ_conf_max << "]" << endl;
		}
	}
	
	if ( error == false ) {
		cout << "Introduzca el numero f " << num_f_min << " a " << num_f_max << ": ";
		cin >> num_f;
		if ( num_f < num_f_min || num_f > num_f_max ) {
	    	error = true;
	    	cout << "Error: El numero f debe estar en [" << num_f_min << " , " << num_f_max << "]" << endl;
		}
	}
	
	if ( error == false ) {
		cout << "Introduzca la longitud focal [" << num_f_min << " , " << num_f_max << "] y la distancia de enfoque (desde " << dist_enfoque_min << "): ";
		cin >> long_focal >> dist_enfoque;
		if ( long_focal > dist_enfoque ){
	   	double aux;
	   	aux = long_focal;
	   	long_focal = dist_enfoque;
	   	dist_enfoque = aux;
	   	cout << "    Valores imposibles: suponemos invertidos" << endl;
		}
		if ( long_focal < long_focal_min || long_focal > long_focal_max ) {
	   	error = true;
	   	cout << "Error: La longitud focal debe estar en [" << long_focal_min << " , " << long_focal_max << "]" << endl;
		}
		if ( dist_enfoque < dist_enfoque_min){
	   	error = true;
	   	cout << "Error: La distancia de enfoque tiene que ser mayor que " << dist_enfoque_min << endl;
		}
	}
	
	
	if (error == false) {
		hiperfocal = ( long_focal * long_focal / ( num_f * circ_conf ) ) + long_focal;
	   d_min = dist_enfoque * ( hiperfocal - long_focal ) / ( hiperfocal + dist_enfoque - 2 * long_focal );
	   d_max = dist_enfoque * ( hiperfocal - long_focal ) / ( hiperfocal - dist_enfoque );
	   profundidad = d_max - d_min;
	   
		cout << "Hiperfocal obtenida: " << hiperfocal << endl;
	   cout << "Distancia de nitidez aceptable: desde " << d_min;
	   
	   if (d_max < 0)
	      cout << " a infinito" << endl;
	   else 
	   	cout << " a " << d_max << endl;
	   
	   if (profundidad < 0)
	   	cout << "Profundidad de campo: infinito";
	   else 
	   	cout << "Profundidad de campo: " << profundidad << endl;
	} else 
		cout << "Vuelve a introducir los valores" << endl;
}
