/* 
 * DISE�O DE FUNCIONES - Fundamentos de Programaci�n (Pr�cticas) - 1� DGIIM
 * Alumnos: Miguel �ngel Fern�ndez Guti�rrez
 *				Marta G�mez S�nchez
 * Fecha: 22 noviembre, 2017		
 */

#include <iostream>

using namespace std;

/**
  @brief Determina si el a�o introducido es bisiesto
  @param anno : a�o a analizar
  @return Si el a�o es bisiesto
 */

bool Bisiesto ( int anno ) {
	return  ( anno % 400 == 0 ) || ( anno % 4 == 0 && anno % 100 != 0 ) ;
		
}

/**
  @brief Determina el n�mero juliano de la fecha introducida
  @param dia : d�a a analizar
  @param mes : mes a analizar
  @param anno : a�o a analizar
  @return Valor del n�mero juliano 
 */

int Juliano ( int dia , int mes , int anno ) {
	int juliano;
	juliano = ( 1461 * ( anno + 4800 + ( mes - 14 ) / 12 ) ) / 4 +
				 ( 367 * ( mes - 2 - 12 * ( ( mes - 14 ) / 12 ) ) ) / 12 -
				 ( 3 * ( ( anno + 4900 + ( mes - 14 ) / 12 ) / 100 ) ) / 4 + dia - 32075; 
	return juliano;
}

/**
  @brief Determina el d�a de la semana 
  @param dia : d�a a analizar
  @param mes : mes a analizar
  @param anno : a�o a analizar
  @return Asigna una letra al dia de la semana correspondiente a la fecha
 */

char DiaSemana ( int dia , int mes , int anno ) {
	char dias[7] = {'L', 'M', 'X', 'J', 'V', 'S', 'D'};
	int diasemana = Juliano(dia,mes,anno) % 7; 
	return dias [diasemana];
}

/**
  @brief Determina si la fecha es v�lida
  @param dia : d�a a analizar
  @param mes : mes a analizar
  @param anno : a�o a analizar
  @return Si el d�a es v�lido
 */

bool EsValida ( int dia , int mes , int anno ) {
	bool valido;
	if ( mes >= 1 && mes <= 12 ) {
		int dias[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if ( Bisiesto(anno) ) dias[2] = 29;
		valido = dia >= 1 && dia <= dias[mes];
	} else
		valido = false;
	return valido;
} 

/**
  @brief Escribe en el formato especificado la fecha introducida
  @param dia : d�a a analizar
  @param mes : mes a analizar
  @param anno : a�o a analizar
 */

void Escribir ( int dia, int mes, int anno ) {
	string dia_semana, mes_escrito;
	switch ( DiaSemana( dia, mes, anno ) ) {
		case 'L' :
			dia_semana = "Lunes";
			break;
		case 'M' :
			dia_semana = "Martes";
			break;
		case 'X' :
			dia_semana = "Miercoles";
			break;
		case 'J' :
			dia_semana = "Jueves";
			break;
		case 'V' :
			dia_semana = "Viernes";
			break;
		case 'S' :
			dia_semana = "Sabado";
			break;
		case 'D' :
			dia_semana = "Domingo";
			break;
		default :
			break;
	}
	switch ( mes ) {
		case 1:
			mes_escrito = "Enero";
			break;
		case 2:
			mes_escrito = "Febrero";
			break;
		case 3:
			mes_escrito = "Marzo";
			break;
		case 4:
			mes_escrito = "Abril";
			break;
		case 5:
			mes_escrito = "Mayo";
			break;
		case 6:
			mes_escrito = "Junio";
			break;
		case 7:
			mes_escrito = "Julio";
			break;
		case 8:
			mes_escrito = "Agosto";
			break;
		case 9:
			mes_escrito = "Septiembre";
			break;
		case 10:
			mes_escrito = "Octubre";
			break;
		case 11:
			mes_escrito = "Noviembre";
			break;
		case 12:
			mes_escrito = "Diciembre";
			break;
		default:
			break;
	}
	cout << "La fecha es: " << dia_semana << ", " << dia << " de " << mes_escrito << " de " << anno;
	if ( Bisiesto (anno) ) cout << " (Bisiesto)";
	cout << endl;
}

/**
  @brief Lee una fecha y la devuelve mediante par�metros por referencia mientras sea v�lida
  @param dia : d�a a analizar
  @param mes : mes a analizar
  @param anno : a�o a analizar
 */

void Leer ( int & dia, int & mes, int & anno ) {
	bool esValida = false;
	while (!esValida) {
		cout << "Introduzca una fecha (dia, mes, anio): ";
		cin >> dia >> mes >> anno;
		if (EsValida(dia, mes, anno))
			esValida = true;
		else
			cout << "La fecha no es valida. Introduzcala de nuevo" << endl;
	}
}

int main (){
	int dia, mes, anno;
	Leer (dia, mes, anno);
	Escribir (dia, mes, anno);
}
