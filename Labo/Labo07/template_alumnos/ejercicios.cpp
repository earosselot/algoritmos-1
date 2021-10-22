#include "ejercicios.h"

vector<vector<int>> productoVectorial(vector<int> u, vector<int> v){
  int filas = u.size();
  int columnas = v.size();
	vector<vector<int>> res(filas, vector<int>(columnas));

  for(int i = 0; i < filas; i++) {
    for(int j = 0; j < columnas; j++) {
      res[i][j] = u[i] * v[j];
    }
  }

	return res;
}

void swap(int& a, int& b){
    a = b + a;
    b = a - b;
    a = a - b;
}

void trasponer(vector<vector<int>> &m) {
	for (int i = 0; i < m.size(); i ++) 
		for (int j = i + 1; j < m.size(); j ++) 
			swap(m[i][j], m[j][i]);
}

vector<vector<int>> multiplicar(vector<vector<int>> m1, vector<vector<int>> m2){

	vector<vector<int>> res(m1.size(), vector<int>(m2[0].size()));
  int prod;
  for (int i = 0; i < m1.size(); i++) {
    for (int j = 0; j < m2[0].size(); j++) {
      prod = 0;
      for (int k = 0; k < m2.size(); k++) {
        prod += m1[i][k] * m2[k][j];
      }
      res[i][j] = prod;
    }
  }

	return res;
}

bool enRango(vector<vector<int>> m, int i, int j) {
  return 0 <= i && i < m.size() && 0 <= j && j < m[0].size();
}

int promedioVecinos(vector<vector<int>> m, int iCentro, int jCentro) {
  int suma = 0;
  int vecinos = 0;
  for (int i = iCentro-1; i <= iCentro+1; i++) {
    for (int j = jCentro-1; j <= jCentro+1; j++) {
      if (enRango(m, i, j)) {
        suma += m[i][j];
        vecinos += 1;
      }
    }
  }
  return suma / vecinos;
}

vector<vector<int>> promediar(vector<vector<int>> m){
	vector<vector<int>> res(m.size(), vector<int>(m[0].size()));

  for (int i = 0; i < m.size(); i++) {
    for (int j = 0; j < m[0].size(); j++) {
      res[i][j] = promedioVecinos(m, i, j);
    }
  }

	return res;
}

bool esPico(vector<vector<int>> m, int iCentro, int jCentro) {

  bool res = true;
  for (int i = iCentro-1; i <= iCentro+1; i++) {
    for (int j = jCentro-1; j <= jCentro+1; j++) {
      if (enRango(m, i, j) && (i != iCentro || j != jCentro))
        res = res && m[iCentro][jCentro] > m[i][j];
    }
  }
  return res;
}

int contarPicos(vector<vector<int>> m){

  vector<vector<int>> res(m.size(), vector<int>(m[0].size()));
  int picos = 0;

  for (int i = 0; i < m.size(); i++) {
    for (int j = 0; j < m[0].size(); j++) {
      if (esPico(m, i, j)) {
        picos += 1;
      }
    }
  }

	return picos;
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

vector<vector<int>> buscarUnos(vector<vector<int>> m) {
  vector<vector<int>> coordenadasUnos;
  vector<int> coordenada = {};
  for (int i = 0; i < m.size(); i++) {
    for (int j = 0; j < m[0].size(); j ++) {
      if (m[i][j] == 1) {
        coordenada = {i, j};
        coordenadasUnos.push_back(coordenada);
      }
    }
  }
  return coordenadasUnos;
}

bool seAmenazan(vector<vector<int>> m, vector<int> reina1, vector<int> reina2) {
  bool mismaFila = reina1[0] == reina2[0];
  bool mismaColumna = reina1[1] == reina2[1];
  bool mismaDiagonal = abs(reina1[0] - reina2[0]) == abs(reina1[1] - reina2[1]);
  return mismaFila || mismaColumna || mismaDiagonal;
}

bool hayAmenaza(vector<vector<int> > m){
  vector<vector<int>> coordenadasReinas = buscarUnos(m);
  bool res = false;
  for(int k = 0; k < coordenadasReinas.size() - 1; k++) {
    for (int t = k+1; t < coordenadasReinas.size(); t++) {
      res = res || seAmenazan(m, coordenadasReinas[k], coordenadasReinas[t]);
    }
  }
	return res;
}

int diferenciaDiagonales(vector<vector<int>> m) {
    int sumaDiagonal1 = 0;
    int sumaDiagonal2 = 0;
    for (int i = 0; i < m.size(); i++) {
      sumaDiagonal1 += m[i][i];
      sumaDiagonal2 += m[i][m.size() - 1 - i];
    }
    return abs(sumaDiagonal1 - sumaDiagonal2);
}
