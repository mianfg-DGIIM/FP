#include<iostream>
#include<vector>

using namespace std;

int main(){
	int num;
	cout << "Introduzca numero"; cin >> num;
	vector <bool> criba(num);
	
	for (int i = 0 ; i < criba.size() ; i++ ){
		criba[i] = true;
	}
	
	for ( int j=2 ; j < criba.size() ; j++ ){
		for (int k=2 ; j*k < criba.size() ; k++ ){
			criba[k*j] = false;
		}
	}

	for (int l=1 ; l < criba.size() ; l++)
		if (criba[l]) cout << l << endl;	
}
