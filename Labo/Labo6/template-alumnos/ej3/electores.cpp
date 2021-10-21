#include "electores.h"

int calcularEdad(int a, int m, int d, int aEleccion, int mEleccion, int dEleccion) {
//  int resultado;
//  if (a > aEleccion || (a == aEleccion && m > mEleccion) || (a == aEleccion && m == mEleccion && d > dEleccion) )) {
//    resultado = -1;
//  } else {
//
//  }
  int correccion = 0;
  if ((m == mEleccion && d > dEleccion) || (m > mEleccion)) {
    correccion = - 1;
  }
  return aEleccion - a + correccion;
}

int validarVotante(int a, int m, int d) {

  int aEleccion = 2021;
  int mEleccion = 10;
  int dEleccion = 22;

  int edad = calcularEdad(a, m, d, aEleccion, mEleccion, dEleccion);
  int resultado;
  if (edad < 0) {
    resultado = 4;
  } else if (edad < 16) {
    resultado = 0;
  } else if (edad < 18) {
    resultado = 1;
  } else if (edad < 70) {
    resultado = 2;
  } else {
    resultado = 3;
  }
	return resultado;
}
