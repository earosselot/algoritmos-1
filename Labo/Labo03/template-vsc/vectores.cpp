#include "vectores.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

// Función para probar en main.cpp si este módulo fue cargado correctamente
void holaModuloVectores()
{
  cout << "El módulo vectores fue cargado correctamente" << endl;
}

//Ejercicio
bool divide(vector<int> v, int a)
{
  // Dados un vector v y un int a, decide si a divide a todos los numeros de v.
  bool res = true;
  int i = 0;
  while (i < v.size() && res)
  {
    if (v[i] % a != 0)
    {
      res = false;
    }
    i++;
  }
  return res;
}

//Ejercicio
int mayor(vector<int> v)
{
  // Dado un vector v, devuelve el valor maximo encontrado.
  int maximo;
  if (v.size() > 0)
  {
    maximo = v[0];
    for (int i = 1; i < v.size(); i++)
    {
      if (maximo < v[i])
      {
        maximo = v[i];
      }
    }
  }
  if (maximo)
  {
    return maximo;
  }
  else
  {
    return -1232214;
  }
}

//Ejercicio
vector<int> reverso(vector<int> v)
{
  // Dado un vector v, devuelve el reverso.
  vector<int> res(v.size());
  for (int i = v.size() - 1; i >= 0; i--)
  {
    res[v.size() - 1 - i] = v[i];
  }
  return res;
}

//Ejercicio
vector<int> rotar(vector<int> v, int k)
{
  // Dado un vector v y un entero k, rotar k posiciones los elementos de v.
  // [1,2,3,4,5,6] rotado 2, deberia dar [3,4,5,6,1,2].
  vector<int> res(v.size());
  int size = v.size();

  // normalizo k, para que este en el rango [0, v.size()]
  if (size < k)
  {
    k = k % size;
  }
  if (k < 0)
  {
    k = abs(abs(k % size) - size);
  }

  // algoritmo que rota si k esta en el rango [0, v.size()]
  for (int i = 0; i < size; i++)
  {
    if (i + k < size)
    {
      res[i + k] = v[i];
    }
    else
    {
      res[i + k - size] = v[i];
    }
  }

  return res;
}

bool esCreciente(vector<int> v)
{
  bool creciente = true;
  int i = 0;
  while (i < v.size() - 1 && creciente)
  {
    if (!(v[i] <= v[i + 1]))
    {
      creciente = false;
    }
    i++;
  }
  return creciente;
}

bool esDecreciente(vector<int> v)
{
  bool decreciente = true;
  int i = 0;
  while (i < v.size() - 1 && decreciente)
  {
    if (!(v[i] >= v[i + 1]))
    {
      decreciente = false;
    }
    i++;
  }
  return decreciente;
}

//Ejercicio
bool estaOrdenado(vector<int> v)
{
  // Dado un vector v de enteros no repetidos, devuelve verdadero si el mismo
  // esta ordenado (creciente o decrecientemente).
  bool res = true;
  if (v.size() > 2)
  {
    res = esCreciente(v) || esDecreciente(v);
  }
  return res;
}

bool esPrimo(int n)
{
  int i = 2;
  bool esPrimo = true;
  while (esPrimo && i < n)
  {
    if (n % i == 0)
    {
      esPrimo = false;
    }
    i = i + 1;
  }
  return esPrimo;
}

//Ejercicio
vector<int> factoresPrimos(int n)
{
  //que dado un entero devuelve un vector con los factores primos del mismo

  vector<int> factoresPrimos;
  int i = 2;

  while (n > 1)
  {
    if (esPrimo(i) && n % i == 0)
    {
      n = n / i;
      factoresPrimos.push_back(i);
    }
    else
    {
      i = i + 1;
    }
  }
  return factoresPrimos;
}

/* 
15%2 = 0 ? no
15%3 = 0 ? si 15/3=5
5%3 = 0 ? no
4 es primo ? no
5%5 = 0 ? si 5/5=1 
*/

//Ejercicio 7
//que dado un vector de enteros muestra por la salida estándar, el vector
// Ejemplo: si el vector es <1, 2, 5, 65> se debe mostrar en pantalla [1, 2, 5, 65]
void mostrarVector(vector<int> v)
{
  cout << "[";
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i];
    if (i != v.size() - 1)
    {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}

// Ejercicio 8
// Dado un archivo que contiene una secuencia de numeros enteros separados por espacio
// leerlo y devolver un vector von los numeros en el mismo orden.
vector<int> leerVector(string nombreArchivo)
{
  vector<int> data;
  int number;
  ifstream archivoIn;
  string path = "../archivos/" + nombreArchivo;

  archivoIn.open(path, ios::in);
  if (archivoIn.fail())
  {
    cout << "Error al abrir el archivo: " << path << endl;
  }
  else
  {
    cout << "Exito al abrir el archivo: " << path << endl;
  }

  while (!archivoIn.eof())
  {
    archivoIn >> number;
    data.push_back(number);
  }

  archivoIn.close();
  return data;
}

// Ejercicio 9
// Dado un vector de enteros, grabar sus elementos en un archivo cuyo nombre viene como
// parametro de entrada.
// Ejemplo:si el vector es<1, 2, 5, 65>el archivo contiene[1, 2, 5, 65].

void guardarVector(vector<int> v, string nombreArchivo)
{
  string path = "../archivos/" + nombreArchivo;
  ofstream fout;
  fout.open(path);
  fout << "[";
  for (int i = 0; i < v.size(); i++)
  {
    fout << v[i];
    if (i != v.size() - 1)
    {
      fout << ", ";
    }
  }
  fout << "]";
  fout.close();
}

// Ejercicio 10
// Dado un vector de enteros encontrar el primer elemento de izquierda a derecha tal que los elementos a su
//  izquierda suman mas que los que estan a su derecha.
//  Ejemplo:<1, 2, 3, 4> el resultado es 3 porque (1+2)<3 + 4 y (1 + 2 +3)>4.
//  El vector de entrada debe ser leido desde un archivo y el resultado debe ser mostrado por pantalla.
//  Utilizar el archivo elementoMedio.in para probar la funcion.

int sumarVector(vector<int> v)
{
  int sumaTotal = 0;
  for (int i = 0; i < v.size(); i++)
  {
    sumaTotal += v[i];
  }
  return sumaTotal;
}

int elementoMedio(vector<int> v)
{
  int sumaDerecha = sumarVector(v);
  int sumaIzquierda = 0;
  int i = 0;
  while (sumaIzquierda < sumaDerecha && i < v.size())
  {
    sumaIzquierda += v[i];
    sumaDerecha -= v[i];
    i++;
  }
  return v[i - 1];
}

// Ejercicio 11
// Dado un archivo que contiene una lista de numeros, contar la cantidad de apariciones
// de cada uno y crear en un archivo en el directorio archivos/out con el mismo nombre
// del archivo de entrada, de manera de tener una linea por cada numero encontrado, un
// espacio y su cantidad de apariciones.
// Por ejemplo, si el vector es <1, 2, 2, 1, 1, 4> el archivo de salida tiene que ser:
//   linea 1: 1 3
//   linea 2: 2 2
//   linea 3: 4 1
// Utilizar los archivos 10000NumerosEntre1y50.in y cantidadApariciones.in.

bool estaEnVector(int n, vector<int> v)
{
  bool esta = false;
  int i = 0;
  while (!esta && i < v.size())
  {
    if (v[i] == n)
    {
      esta = true;
    }
    i++;
  }
  return esta;
}

void cantApariciones(string nombreArchivo)
{
  vector<int> v = leerVector(nombreArchivo);
  string path = "../archivos/out/" + nombreArchivo;
  ofstream fout;
  fout.open(path);
  int numero;
  int apariciones = 0;
  vector<int> contados;
  int i = 0;
  while (i < v.size())
  {
    if (!estaEnVector(v[i], contados))
    {
      apariciones = 0;
      for (int j = i; j < v.size(); j++)
      {
        if (v[i] == v[j])
        {
          apariciones++;
        }
      }
      contados.push_back(v[i]);
      fout << v[i] << " " << apariciones << endl;
    }
    i++;
  }
  fout.close();
}

// Ejercicio 12
// Ingresar por consola una palabra a buscar y el nombre de un archivo de texto y devolver la cantidad de
// apariciones de la palabra en el archivo. Mostrar el resultado por pantalla. Para testear el ejercicio
// pueden usar el archivo cantidadAparicionesDePalabra.in.

string trim(string palabra)
{
  string caracteres = ",.():[]{}";
  for (int i = 0; i < caracteres.length(); i++)
  {
    palabra.erase(remove(palabra.begin(), palabra.end(), caracteres[i]), palabra.end());
  }
  return palabra;
}

vector<string> leerArchivoTexto(string nombreArchivo)
{
  vector<string> data;
  string palabra;
  ifstream archivoIn;
  string path = "../archivos/" + nombreArchivo;

  archivoIn.open(path, ios::in);
  if (archivoIn.fail())
  {
    cout << "Error al abrir el archivo: " << path << endl;
  }
  else
  {
    cout << "Exito al abrir el archivo: " << path << endl;
  }

  while (!archivoIn.eof())
  {
    archivoIn >> palabra;
    data.push_back(trim(palabra));
  }

  archivoIn.close();
  return data;
}

void mostrarVectorStrings(vector<string> v)
{
  cout << "[";
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i];
    if (i != v.size() - 1)
    {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}

int contarApariciones(vector<string> palabras, string palabra)
{
  int apariciones = 0;
  for (int i = 0; i < palabras.size(); i++)
  {
    if (palabras[i] == palabra)
    {
      apariciones++;
    }
  }
  return apariciones;
}

int cantidadDeAparicionesPalabra(string nombreArchivo, string palabra)
{
  vector<string> palabras = leerArchivoTexto(nombreArchivo);
  int apariciones = contarApariciones(palabras, palabra);
  // string s = trim(palabra);
  return apariciones;
}

// Ejercicio 13
// Dados dos archivos en los que cada uno contiene una secuencia de enteros de la misma longitud,
// guardar el promedio decada par de numeros que se encuentran en la misma “posicion” en el archivo
// de salida.
// Ejemplo: si tenemos dos secuencias <1, 2, 3, 4> y <1, 25, 3, 12> el resultado debe ser [1, 13.5, 3, 8].
// En archivos/ se encuentra promedio1.in y promedio2.in. Cada archivo contiene 100 numeros random entre 1 y 10.

void guardarVectorFloat(vector<float> v, string nombreArchivo)
{
  string path = "../archivos/" + nombreArchivo;
  ofstream fout;
  fout.open(path);
  fout << "[";
  for (int i = 0; i < v.size(); i++)
  {
    fout << v[i];
    if (i != v.size() - 1)
    {
      fout << ", ";
    }
  }
  fout << "]";
  fout.close();
}

void promedio(string nombreArchivo1, string nombreArchivo2, string nombreArchivoOut)
{
  vector<int> valores1 = leerVector(nombreArchivo1);
  vector<int> valores2 = leerVector(nombreArchivo2);
  vector<float> promedio(valores1.size());
  for (int i = 0; i < valores1.size(); i++)
  {
    promedio[i] = ((float)valores1[i] + (float)valores2[i]) / 2.0;
  }
  guardarVectorFloat(promedio, nombreArchivoOut);
}

// Ejercicio 14
// Dados dos archivos en los que cada uno contiene una secuencia de enteros ordenada, ordenarlos
// y guardar el resultado en el archivo de salida.
// Ejemplo: si tenemos dos secuencias <1, 4, 8, 19> y <3, 25, 31> el resultado debe ser [1,3, 4, 8, 25, 31].
// En archivos/ se encuentraordenarSecuencia1.in y ordenarSecuencia2.in. Cada archivo contiene 5000 numeros
// ordenados entre 1 y 1000.
// El primer archivo contiene los numeros pares en el rango y el segundo los impares.

void ordenarSecuencias(string nombreArchivoIn1, string nombreArchivoIn2, string nombreArchivoOut)
{
  vector<int> secuenciaOrdenada1 = leerVector(nombreArchivoIn1);
  vector<int> secuenciaOrdenada2 = leerVector(nombreArchivoIn2);
  vector<int> secuenciaUnida(secuenciaOrdenada1.size() + secuenciaOrdenada2.size());
  int i = 0;
  int j = 0;
  // intercalo los valores en orden.
  while (i < secuenciaOrdenada1.size() && j < secuenciaOrdenada2.size())
  {
    if (secuenciaOrdenada1[i] < secuenciaOrdenada2[j])
    {
      secuenciaUnida[i + j] = secuenciaOrdenada1[i];
      i++;
    }
    else
    {
      secuenciaUnida[i + j] = secuenciaOrdenada2[j];
      j++;
    }
  }
  // agrego la cola de la secuencia a la que le sobraron elementos.
  if (i < secuenciaOrdenada1.size())
  {
    while (i < secuenciaOrdenada1.size())
    {
      secuenciaUnida[i + j] = secuenciaOrdenada1[i];
      i++;
    }
  }
  else
  {
    while (j < secuenciaOrdenada2.size())
    {
      secuenciaUnida[i + j] = secuenciaOrdenada2[j];
      j++;
    }
  }
  guardarVector(secuenciaUnida, nombreArchivoOut);
}

// Ejercicio 15
// Funcion que pide al usuario que se ingrese por teclado dos nombres de archivos que
// contengan solo numeros enteros, luego  calcule  la  interseccioon  (los  elementos
// comunes  a  ambos  archivos),  que  debe  mostrar  por  pantalla,  ademas
// dedevolverla como vector.

vector<int> calcularInterseccion(vector<int> v1, vector<int> v2)
{
  vector<int> interseccion;
  for (int i = 0; i < v1.size(); i++)
  {
    for (int j = 0; j < v2.size(); j++)
    {
      if (v1[i] == v2[j])
      {
        interseccion.push_back(v1[i]);
      }
    }
  }
  return interseccion;
}

vector<int> interseccion()
{
  string nombreArchivo1, nombreArchivo2;
  cout << "Programa que calcula la interseccion" << endl;
  cout << "Igrese el nombre del primer archivo: ";
  cin >> nombreArchivo1;
  cout << endl;
  cout << "Igrese el nombre del segundo archivo: ";
  cin >> nombreArchivo2;
  cout << endl;
  vector<int> vector1 = leerVector(nombreArchivo1);
  vector<int> vector2 = leerVector(nombreArchivo2);
  vector<int> interseccion = calcularInterseccion(vector1, vector2);
  mostrarVector(interseccion);
  return interseccion;
}