#include "ejercicios.h"

vector<vector<int> > productoVectorial(vector<int> u, vector<int> v){
	//COMPLETAR
	vector<vector<int> > res;
	return res;
}

void swap(int& a, int& b){
    a = b + a;
    b = a - b;
    a = a - b;
}

void f5(vector<int> &v1, vector<int> &v2){vector<int> res(v1.size()+v2.size(),0);


void trasponer(vector<vector<int>> &m) {
	for (int i = 0; i < m.size(); i ++) 
		for (int j = i + 1; j < m.size(); j ++) 
			swap(m[i][j], m[j][i]);
	return;
}

vector<vector<int> > multiplicar(vector<vector<int> > m1, vector<vector<int> > m2){
	//COMPLETAR
	vector<vector<int> > res;
	return res;
}

vector<vector<int> > promediar(vector<vector<int> > m){
	//COMPLETAR
	vector<vector<int> > res;
	return res;
}

int contarPicos(vector<vector<int> > m){
	//COMPLETAR
	return true;
}

bool esTriangularInferior(vector<vector<int>> m){
	bool res = true;
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m[i].size(); j++) {
			if(i < j && m[i][j] != 0) {
				res = false;
				break;
			}
		}
	}
	return res;
}

bool esTriangularSuperior(vector<vector<int>> m){
	bool res = true;
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m[i].size(); j++) {
			if(i > j && m[i][j] != 0) {
				res = false;
				break;
			}
		}
	}
	return res;
}

bool esTriangular(vector<vector<int> > m){
	return esTriangularSuperior(m) || esTriangularInferior(m) ;
}


bool hayAmenaza(vector<vector<int> > m){
	//COMPLETAR
	return true;
}

int diferenciaDiagonales(vector<vector<int> > m) {
    //COMPLETAR
    return 0;
}