#include <iostream>
using namespace std;

int main() {
	char team;
	int puntos_A_tiempo1 = 0, puntos_B_tiempo1 = 0, puntos_A = 0,
	puntos_B = 0, triples_A = 0, triples = 0, minuto, puntos;
	while (true) {
		cin >> team;
		if ( team == 'S' ) {
			break;
		} else {
			cin >> puntos;
			cin >> minuto;
			if ( team == 'A' ) {
				if ( puntos == 3 ) {
					triples++;
				}
				if ( minuto >= 0 && minuto <= 19 ) {
					puntos_A_tiempo1 += puntos;
					puntos_A += puntos;
				} else {
					puntos_A += puntos;
				}
			} else if ( team == 'B' ) {
				if ( puntos == 3 ) {
					triples++;
				}
				if ( minuto >= 0 && minuto <= 19 ) {
					puntos_B_tiempo1 += puntos;
					puntos_B += puntos;
				} else {
					puntos_B += puntos;
				]
			}
		}
	}
	
	char winner_1st, winner;
	// equipo ganador de la primera mitad
	if ( puntos_A_tiempo1 > puntos_B_tiempo1 ) {
		winner_1st = 'A';
	} else if ( puntos_A_tiempo1 < puntos_B_tiempo1 ) {
		winner_1st = 'B';
	} else {
		winner_1st = '0';
	}
	// equipo ganador del partido
	if ( puntos_A > puntos_B ) {
		winner = 'A';
	} else if ( puntos_A < puntos_B ) {
		winner = 'B';
	} else {
		winner = '0';
	}
	
	// dar resultados
	cout << "Ganador de la primera parte : ";
	if ( winner_1st == '0' ) cout << "empate"; else cout << winner_1st;
	cout << endl;
	cout << "Ganador del partido : ";
	if ( winner == '0' ) cout << "empate"; else cout << winner;
	cout << endl;
	cout << "Resultado final : " << puntos_A << "-" << puntos_B << endl;
	cout << "Numero de triples : " << triples;
	
}
