#include "ejercicios.h"

using namespace std;

void tiempoHayDuplicados(int desde, int hasta, int paso, string nombreArchivoSalida) {
  ofstream fout;
  string path = "../" + nombreArchivoSalida;
  fout.open(path);
  fout << "n\t tiempo" << endl;
  for (int n = desde; n < hasta; n += paso) {
    fout << n << "\t";
    vector<int> v = construir_vector(n, "asc");
    double t0 = clock();
    v.pop_back();
    double t1 = clock();
    double tiempo = (double(t1 - t0)) / CLOCKS_PER_SEC;
    fout << tiempo << endl;
  }
  fout.close();
}

void tiempoPushBack(int desde, int hasta, string nombreArchivoSalida) {
  ofstream fout;
  string path = "../" + nombreArchivoSalida;
  fout.open(path);
  fout << "n\t tiempo" << endl;

  vector<int> v = construir_vector(desde, "asc");
  for (int n = desde; v.size() < hasta; n++) {
    fout << n << "\t";

    double t0 = clock();
    v.push_back(n);
    double t1 = clock();

    double tiempo = (double(t1 - t0)) / CLOCKS_PER_SEC;
    fout << tiempo << endl;
  }
  fout.close();
}


void tiempoPopBack(int desde, int hasta, string nombreArchivoSalida) {
  ofstream fout;
  string path = "../" + nombreArchivoSalida;
  fout.open(path);
  fout << "n\t tiempo" << endl;

  vector<int> v = construir_vector(hasta, "asc");
  for (int n = desde; v.size() > desde; n++) {
    fout << n << "\t";

    double t0 = clock();
    v.pop_back();
    double t1 = clock();

    double tiempo = (double(t1 - t0)) / CLOCKS_PER_SEC;
    fout << tiempo << endl;
  }
  fout.close();
}

int main() {

//  tiempoHayDuplicados(1, 10000, 500, "datos_ej5_vPopBack.csv");
//  tiempoPushBack(500, 1000, "datos_ej5_vPushBack2.csv");
  tiempoPopBack(500, 1000, "datos_ej5_vPopBack2.csv");

  return 0;
}

// double t0 = clock()
// funcion()
// double t1 = clock()
// double tiempo = (double(t1 - t0)) / CLOCKS_PER_SEC
// CLOCK_PER_SEC