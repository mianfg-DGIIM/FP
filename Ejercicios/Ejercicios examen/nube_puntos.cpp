#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Punto {
	double x;
    double y;
};

/*
void leerPunto ( Punto & a ) {
    double x, y;
    cout << "Inserte las coordenadas del punto: ";
    cin >> x >> y;
    a.x = x;
    a.y = y;
}
*/
// hacer paso por referencia !!!
Punto leerPunto ( Punto & a ) {
    cin >> a.x >> a.y;
    return a;
}

void leerPositivo ( double & a ) {
    double x = -1; 
    while ( x < 0 ) {
        cin >> x;
    }
    a = x;
}

double distancia ( Punto a, Punto b ) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

class Circulo {
    Punto c;
    double r;
    
    public:
    	Circulo () {
    		c.x = 0;
    		c.y = 0;
    		r = 1;
		}
        Circulo ( Punto centro, double radio ) {
            c= centro ;
            r= radio ;
        }
        Punto centro() const {
            return c;
        }
        double radio() const {
            return r;
        }
        bool interior ( Punto p ) const {
            return (distancia(p, c) <= r);
        }
};


void leerCirculo ( Circulo & circ ) {
    Punto centro;
    double radio;
    cout << "Inserte las coordenadas del centro: ";
    leerPunto(centro);
    cout << "Inserte el radio: ";
    leerPositivo(radio);
    Circulo circ2(centro, radio);
    circ = circ2;
}

void escribirPunto ( Punto a ) {
    cout << "(" << a.x << "," << a.y << ")";
}

void escribirCirculo ( Circulo circ ) {
    cout << "{" << circ.radio() << ",";
	escribirPunto(circ.centro());
	cout << "}";
}


//

void leerPuntos ( vector<Punto> & puntos ) {
    int num_puntos;
    Punto p;
    cout << "Inserte el numero de puntos: ";
    cin >> num_puntos;
    
    for ( int i = 1; i <= num_puntos; i++ ) {
    	cout << "   Inserte las coordenadas del punto " << i << ": ";
        leerPunto(p);
        puntos.push_back(p);
    }
}

void separar( const Circulo & circ, const vector<Punto> & puntos, vector<Punto> & interior, vector<Punto> & exterior ) {
    for ( int i = 0; i < puntos.size(); i++ ) {
        if (circ.interior(puntos[i])) {
        	cout << (circ.interior(puntos[i]));
    	    interior.push_back( puntos[i] );
        } else {
        	cout << (circ.interior(puntos[i]));
            exterior.push_back( puntos[i] );
    }
     }
}

void escribir ( const vector<Punto> & v ) {
    for ( int i = 0; i < v.size(); i++ ) {
    	cout << "  ";
    	escribirPunto(v[i]);
        cout << endl;
	}
}

int main() {
    Circulo circ;
    leerCirculo(circ);
    vector<Punto> puntos;
    vector<Punto> interior;
    vector<Punto> exterior;
    leerPuntos(puntos);
    separar( circ, puntos, interior, exterior );
    cout << "Los puntos que se encuentran en el circulo ";
		escribirCirculo(circ);
		cout << " son: " << endl;
    escribir(interior);
    cout << "Los puntos que se encuentran fuera del circulo ";
		escribirCirculo(circ);
		cout << " son: " << endl;
    escribir(exterior);
}
