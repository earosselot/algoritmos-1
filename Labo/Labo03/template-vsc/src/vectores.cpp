#include "vectores.h"

// Función para probar en main.cpp si este módulo fue cargado correctamente
void holaModuloVectores(){
    cout << "El módulo vectores fue cargado correctamente" << endl;
}


//Ejercicio
bool divide(vector<int> v, int a){
  // Dados un vector v y un int a, decide si a divide a todos los numeros de v.
  bool res = true;
  int i = 0;
  while (i < v.size() && res) {
    if (v[i] % a != 0) {
      res = false;
    }
    i++;
  }
  return res;
}

//Ejercicio
int mayor(vector<int> v){
	// Dado un vector v, devuelve el valor maximo encontrado.
	int maximo;
	if (v.size() > 0) {
	  maximo = v[0];
	  for (int i = 1; i < v.size(); i++) {
	    if (maximo < v[i]) {
	      maximo = v[i];
	    }
	  }
	}
	if (maximo) {
	  return maximo;
	} else {
	  return -1232214;
	}
}

//Ejercicio
vector<int> reverso(vector<int> v){
  // Dado un vector v, devuelve el reverso.
  vector<int> res(v.size());
  for (int i = v.size()-1; i >= 0; i--) {
    res[v.size()-1-i] = v[i];
  }
  return res;
}

//Ejercicio
vector<int> rotar(vector<int> v, int k){
	// Dado un vector v y un entero k, rotar k posiciones los elementos de v.
	// [1,2,3,4,5,6] rotado 2, deberia dar [3,4,5,6,1,2].
	vector<int> res(v.size());
	int size = v.size();

  // normalizo k, para que este en el rango [0, v.size()]
  if (size < k) {
    k = k % size;
  }
  if (k < 0) {
    k = abs(abs(k % size) - size);
  }
	
	// algoritmo que rota si k esta en el rango [0, v.size()]
	for (int i = 0; i < size; i++) {
	  if (i+k < size) {
	    res[i+k] = v[i]; 
	  } else {
	    res[i+k-size] = v[i];
	  }
	}
	
	return res;
}

bool esCreciente(vector<int> v) {
  bool creciente = true;
  int i = 0;
  while (i < v.size() - 1 && creciente) {
    if (!(v[i] <= v[i+1])) {
      creciente = false;
    }
    i++;
  }
  return creciente;
}

bool esDecreciente(vector<int> v) {
  bool decreciente = true;
  int i = 0;
  while (i < v.size() - 1 && decreciente) {
    if (!(v[i] >= v[i+1])) {
      decreciente = false;
    }
    i++;
  }
  return decreciente;
}

//Ejercicio
bool estaOrdenado(vector<int> v) {
  // Dado un vector v de enteros no repetidos, devuelve verdadero si el mismo
  // esta ordenado (creciente o decrecientemente).
  bool res = true;
  if (v.size() > 2) {
    res = esCreciente(v) || esDecreciente(v);
  }
  return res;
}

//Ejercicio
vector<int> factoresPrimos(int n){
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
void mostrarVector(vector<int> v){
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
  //que dado un vector de enteros muestra por la salida estándar, el vector
	// Ejemplo: si el vector es <1, 2, 5, 65> se debe mostrar en pantalla [1, 2, 5, 65]
}
