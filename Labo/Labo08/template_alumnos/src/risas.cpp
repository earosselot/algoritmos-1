#include <string>
#include <vector>
#include "risas.h"
#include <iostream>
#include <fstream>

using namespace std;

/* Utiles */
vector<char> leerDatos(const string& nombreArchivo) {
  vector<char> data;
  char letra;
  ifstream archivoIn;
  archivoIn.open(nombreArchivo, ios::in);

  while (!archivoIn.eof())
  {
    archivoIn >> letra;
    data.push_back(letra);
  }

  archivoIn.close();
  return data;
}

int leerLargoReal(string nombreArchivo) {
  int largoReal;
  ifstream  archivoIn;

  archivoIn.open(nombreArchivo, ios::in);
  archivoIn >> largoReal;

  archivoIn.close();
  return largoReal;
}
/* Utiles */

bool esRisa(char x, char y) {
  return (x == 'h' && y == 'a') || (x == 'a' && y == 'h');
}

int risaMasLarga(vector<char> s) {
  int risaMax = 0;
  int risa = 0;
  int i = 0;
  while (i < s.size()) {
    int j = i+1;
    if (s[i] == 'h' || s[i] == 'a') {
      risa = 1;
      while (esRisa(s[j-1], s[j])) {
        risa += 1;
        j++;
      }

      if (risa > risaMax) {
        risaMax = risa;
//        risa = 0;
      }
    }
    i = j;
  }
  return risaMax;
}
