#include "ejercicios.h"

/* Para compilar */ 

using namespace std;

vector<string> split(string s, char delim){
	vector<string> v;
	return v;
}

string darVueltaPalabra(string s){
	string res;
	return res;
}

// Decidir si s1 es substring o subsecuencia de s2
bool subsecuencia(string s1, string s2) {
	int i = 0;
	int j = 0;
	while (i < s2.size() && j < s1.size()) 
	{
		if (s1[j] == s2[i]) {
			j = j + 1;
		}
		i = i + 1;
	}
	return j == s1.size();
}

// Mismo orden relativo de conjunto de anagramas y dentro de cada vector y con repetidos
vector<vector<string> > agruparAnagramas(vector<string> v){
	vector<vector<string> > res;
	return res;
}

bool esPalindromo(string s){
	bool cumple = true;
	return cumple;
}

bool tieneRepetidos(string s){
	bool distinto = true;
	return !distinto;
}

string rotar(string s, int v){
	int size = s.size();
	string rotada;
	int indice;
	for (int i = 0; i < s.size(); i++)
	{
		indice = (size - (v % size) + i) % size;
		rotada.push_back(s[indice]);
	}
	return rotada;
}

// no se puede usar substring
string darVueltaK(string s, int k){
	string res(s);
	return res;
}

string abueloLaino(string s){
    string res;
    return res;
}

int cantidadDeFelicitaciones(vector<string> v){
    int res;
    return res;
}

int middleOut(string s, string t){

    return 0;
}
