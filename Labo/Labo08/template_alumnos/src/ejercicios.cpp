#include "ejercicios.h"
#include <string>

using namespace std;

vector<string> split(string s, char delim){
  vector<string> res;
  string subres = "";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == delim && subres.size() != 0) {
      res.push_back(subres);
      subres = "";
    }
    if (s[i] != delim) {
      subres.push_back(s[i]);
    }
  }
  if (subres.size() > 0) {
    res.push_back(subres);
  }
	return res;
}

string join(vector<string> v, char delim) {
  string res;
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      res.push_back(v[i][j]);
    }
    if (i != v.size() - 1) {
      res.push_back(delim);
    }
  }
  return res;
}

string darVueltaPalabra(string s){
  vector<string> v = split(s, ' ');
  vector<string> dadoVuelta;

  for (int i = v.size() - 1; i >= 0; i--) {
    dadoVuelta.push_back(v[i]);
  }

  return join(dadoVuelta, ' ');
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

int cantApariciones(string s1, char c) {
  int apariciones = 0;
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] == c) {
      apariciones++;
    }
  }
  return apariciones;
}

bool esAnagrama(string s1, string s2) {
  bool res = true;
  if (s1.size() == s2.size()) {
    for (int i = 0; i < s1.size(); i++) {
      res = res && cantApariciones(s1, s1[i]) == cantApariciones(s2, s1[i]);
    }
  } else {
    res = !res;
  }
  return res;
}

// Mismo orden relativo de conjunto de anagramas y dentro de cada vector y con repetidos
vector<vector<string> > agruparAnagramas(vector<string> v){
  vector<vector<string>> res = {};
  if (v.size() > 0) {
    vector<string> subres = {};

    int i = 0;
    while (i < v.size()) {

      int j = 0;
      while (j < res.size() && res[j].size() > 0 && !esAnagrama(v[i], res[j][0])) {
        j++;
      }
      if (j == res.size()) {
        // no habia ningun anagrama
        subres = {v[i]};
        res.push_back(subres);
      } else {
        res[j].push_back(v[i]);
      }
      i++;
    }
  }
	return res;
}

bool esPalindromo(string s){
	bool cumple = true;
  for (int i = 0; i < s.size()/2; i++) {
    cumple = cumple && s[i] == s[s.size() - 1 - i];
  }
	return cumple;
}

bool tieneRepetidos(string s){
	bool distinto = true;
  for (int i = 0; i < s.size(); i++) {
    for (int j = i+1; j < s.size(); j++) {
      distinto &= s[i] != s[j];
    }
  }
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
	string res;
  for (int i = 0; i < s.size(); i = i + k) {
    for (int j = k-1; j >= 0; j--) {
      if (i+j < s.size())
        res.push_back(s[i+j]);
    }
  }
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
