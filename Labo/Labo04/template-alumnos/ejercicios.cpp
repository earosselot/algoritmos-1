#include <iostream>
#include "ejercicios.h"
#include <math.h>

using namespace std;

/************* Ejercicio 1 *************/

// Decidir si un vector esta ordenado tanto ascendente como descendentemente
bool estaOrdenadoAsc(vector<int> v)
{
  int i = 0;
  int longitud = v.size();
  bool esMenor = true;
  while (i <= longitud - 2 && esMenor)
  {
    esMenor = (v[i] <= v[i + 1]);
    i++;
  }
  return esMenor;
}

bool estaOrdenadoDesc(vector<int> v)
{
  int longitud = v.size();
  int i = 0;
  bool esMayor = true;
  while (i <= longitud - 2 && esMayor)
  {
    esMayor = (v[i] >= v[i + 1]);
    i++;
  }
  return esMayor;
}

bool estaOrdenado(vector<int> v)
{
  int longitud = v.size();
  if (longitud == 0 || longitud == 1)
  {
    return true;
  }
  else
  {
    return estaOrdenadoDesc(v) || estaOrdenadoAsc(v);
  }
}

/************* Ejercicio 2 *************/

// Decidir si un numero es primo.
bool esPrimo(int numero)
{
  if (numero > 2)
  {
    int i = 2;
    bool divide = false;
    while (i < numero && !divide)
    {
      divide = numero % i == 0;
      i++;
    }
    return !divide;
  }
  else if (numero == 2)
    return true;
  else
    return false;
}

/************* Ejercicio 3 *************/

// Decidir si un elemento dado pertenece al vector.
bool pertenece(int elemento, vector<int> v)
{
  int longitud = v.size();
  if (longitud == 0)
  {
    return false;
  }
  else
  {
    int i = 0;
    bool sigo = true;
    while (i < longitud && sigo)
    {
      sigo = v[i] != elemento;
      i++;
    }
    return !sigo;
  }
}

/************* Ejercicio 4 *************/

// Encontrar el desvio estandar de un vector de floats.
float promedio(vector<float> v)
{
  int longitud = v.size();
  float suma = 0;
  for (int i = 0; i < longitud; i++)
  {
    suma += v[i];
  }
  return suma / longitud;
}

float sumaDeCuadrados(vector<float> v)
{
  float sumadecuadrados = 0;
  float media = promedio(v);
  // unsigned int i;
  for (int i = 0; i < v.size(); i++)
  {
    sumadecuadrados += pow((v[i] - media), 2);
  }
  return sumadecuadrados;
}

float desvioEstandar(vector<float> v)
{
  return sqrt(sumaDeCuadrados(v) / v.size());
}

/************* Ejercicio 5 *************/

// Calcular el k-esimo numero de fibonacci
long fibonacci(int k)
{
  if (k == 0)
    return 0;
  else
  {
    if (k == 1)
    {
      return 1;
    }
    else
    {
      long preAnterior = 0;
      long anterior = 1;
      long actual;
      int nesimo;
      for (nesimo == 1; nesimo <= k; nesimo++)
      {
        preAnterior = anterior;
        anterior = actual;
        actual = anterior + preAnterior;
      }
      return actual;
    }
  }
}

/************* Ejercicio 6 *************/

// Encontrar el maximo comun divisor de dos numeros
int maximo(int x, int y)
{
  if (x < 0)
    x = -x;
  if (y < 0)
    y = -y;
  if (x > y)
    return x;
  else
    return y;
}

int minimo(int x, int y)
{
  if (x < 0)
    x = -x;
  if (y < 0)
    y = -y;
  if (x < y)
    return x;
  else
    return y;
}

int maximoComunDivisor(int x, int y)
{
  int mayor = maximo(x, y); // 100
  int menor = minimo(x, y); // 0
  int resto = 1;
  while (resto != 0 && menor != 0)
  {
    resto = mayor % menor;
    mayor = menor;
    menor = resto;
  }
  if (resto == 0)
    return mayor;
  else
    return 1;
}

/************* Ejercicio 7 *************/

// Para un vector de enteros, calcular la sumatoria del doble de los elementos positivos y pares.
int sumaDoble(vector<int> v)
{
  int suma = 0;
  for (unsigned int i = 0; i < v.size(); i++)
  {
    if (v[i] % 2 == 0 && v[i] >= 0)
    {
      suma += v[i] * 2;
    }
  }
  return suma;
}

/************* Ejercicio 8 *************/

// Contar la cantidad de palabras que hay en un archivo de texto.
int cantPalabras(string filename)
{
  ifstream miArchivo;
  string palabra;
  int cont = 0;

  miArchivo.open(filename.c_str(), ifstream::in);
  if (miArchivo.is_open())
  {
    while (!miArchivo.eof())
    {
      miArchivo >> palabra;
      cont++;
    }
  }
  miArchivo.close();
  return cont;
}

/************* Ejercicio 9 *************/

/* El archivo SensadoRemoto.txt contiene una lista de valores reales provenientes de una estacion
* de medicion de una variable fisica dada, cuyos valores son positivos menores a 1.
* Escribir un programa que calcule el promedio de los valores tomados durante un periodo de tiempo.
* Verificar el resultado obtenido.
*/
float valorMedio()
{
  ifstream miArchivo;
  float val;
  float acum = 0;
  int cont = 0;

  miArchivo.open("datos/SensadoRemoto.txt", ios::in);
  if (miArchivo.is_open())
  {
    while (!miArchivo.eof())
    {
      miArchivo >> val;
      if (val > 1)
      {
        cout << val << " " << cont << endl;
      }
      acum += val;
      cont++;
    }
  }
  miArchivo.close();

  return acum / cont;
}

// Devolver en res la fraccion (entre 0 y 1) de numeros mayores a 0.
void fraccion(vector<int> v, float &res)
{
  int longitud = v.size();
  if (longitud == 0)
  {
    res = 0;
  }
  else
  {
    int count = 0;
    for (int i = 0; i < longitud; i++)
    {
      if (v[i] > 0)
      {
        count++;
      }
    }
    res = (float)count / (float)v.size();
  }
}

// v.size() devuelve un unsigned int -> solo positivos