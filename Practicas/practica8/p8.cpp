#include <vector>
// Ejercicio 1

  //  ultimo1 - 3 operaciones elementales
  //  ultimo2 - 4 operaciones elementales
  //  ultimo3 - 6 operaciones elementales

// Ejercicio 2

void f1(vector<int> &vec)             // n = |vec|
{
  i = vec.size() / 2;                 // 3
  while( i >= 0)                      // 2, n/2 iteraciones
  {
    vec[vec.size() / 2 - i] = i;      // 6 = 1 asig + 3acc + 2op
    vec[vec.size() / 2 + i] = i;      // 6
    i--;                              // 3
  }                                   // t(n) = 2 + 17*(n/2)
}                                     // t(n) = 5 + 17*(n/2) -> O(n)

// pre: |vec| > 20000
void f2(vector<int> &vec)             // n = |vec|
{
  i = 0;                              // 1
  while(i < 10000)                    // 2, 10000 iteraciones
  {
    vec[vec.size() / 2 - i] = i;      // 6
    vec[vec.size() / 2 + i] = i;      // 6
    i++;                              // 3
  }                                   // t(n) = 2 + 10000 * 17
}                                     // t(n) = 3 + 170000 -> O(1)

// pre: e pertenece a v1
int f3(vector<int> &v1, int e)        // n = |v1|
{       
  int i = 0;                          // 1
  while (v1[i] != e)                  // 4,  n-1 iteraciones
  {
    i++;                              // 3
  }                                   // t(n) = 4 + 7*(n-1)
  return i;                           // 1
}                                     // t(n) = 6 + 7*(n-1) -> O(n)
    
void f4(vector<int> &vec)             // n = |vec|
{
  int rec = 0;                        // 1
  int max_iter = 1000;                // 1
  if max_iter > vec.size()            // 3
  {
    max_iter = vec.size();            // 2
  }

  for (int i=0; i < max_iter; i++)    // 1, 3, 3, 1000 iteraciones
  {
    for(int j=0; j < max_iter; j++)   // 1, 3, 3, 1000 iteraciones
    {
      res += vec[i] * vec[j];         // 6
    }                                 // t(n) = 4 + 12*1000
  }                                   // t(n) = 4 + (6+(4 + 12000)) * 1000
}                                     // t(n) = 12010000 -> O(1)

void f5(vector<int> &v1, vector<int> &v2)  // n = |v1|, m = |v2|
{
  vector<int> res(v1.size()+v2.size(),0);  // 1 
  // inicializa vector en O(|a|+|b|)
  for(int i=0; i < v1.size(); i++)         // 1, 3, 3, n iteraciones
  {
    res[i]=v1[i]; // O(1)                  // 3
  }                                        // t(n) = 4 + 3n
  for(int i=0; i < v2.size(); i++)         // 1, 3, 3, m iteraciones
  {
    res[v1.size()+i]=v2[i];// O(1)         // 3
  }                                        // t(m) = 4 + 3m
  return; 
}                                          // t(n,m) = 9 + 3n + 3m -> O(n+m)


// Ejercicio 3

  // a) Verdadero.
  // b) Falso. Un programa puede tener un tiempo 10000n y el otro n, ambos son O(n), pero el primero tardaria mas.
  // c) Verdadero.
  // d) Verdadero.
  // e) Falso. Depende de el rango de iteracion del ciclo.

// Ejercicio 4

  int mesetaMasLarga(vector<int> &v)          // n = |v|
  {
    int i = 0;                                // 1
    int maxMeseta = 0;                        // 1
    int meseta;                               // 1
    while (i < v.size())                      // 1
    {
      int j = i + 1;                          // 2
      while (j < v.size() && v[i] == v[j])    // 2, n - (i + 1)
      {
        j++;                                  //
      }
      meseta = j - i;
      i = j;
      if (meseta > maxMeseta) 
      {
        maxMeseta = meseta;
      }
    }
    return maxMeseta;
  }
  
  // a) Devuelve maxima cantidad de elementos repetidos contiguos en un vector.

  // b) 

  // c)

    int mesetaMasLarga2(vector<int> &v)
    {
      maxMeseta = 0;
      meseta = 1;
      for (int i = 0; i < v.size() - 1; i++)
      {
        if (v[i] == v[i+1])
          meseta += 1;
        else
          meseta = 1;
        if (meseta > maxMeseta)
          maxMeseta = meseta;
      }
      return maxMeseta;
    }

// Ejercicio 5

vector<int> hacerALgo(vector<int> &v) {           // n = |v|
  vector<int> res;
  for (int i = 0; i < 100; i++) {                 // t(n) = 100
    res.push_back(contarApariciones(v, i + 1));
  }
  return res;
};

int contarApariciones(vector<int> &v, int elem) {  
  int cantAp = 0;
  for (int i = 0; i < v.size(); i++) {            // t(n) = n
    if (v[i] == elem) {
      cantAp++;
    }
  }
  return cantAp;
};

// la complejidad es O(n)

// Ejercicio 6

bool f(vector<float> s) {
  float p;
  float res = 0;
  for (int i = 0; i < s.size(); i++) {
    p = productoriaDelVector(h(s, i));
    if(p > res) {
      res = p;
    }
  }
  return res;
}

float productoriaDelVector(vector<float> v) {
  float prod = 1;
  for (int i = 0; i < v.size(); i++) {
    prod = prod * v[i];
  }
  return prod;
}

// Devuelve los primeros n elementos no negativos o los primeros elementos no negativos
vector<float> h(vector<float> w, int n) {
  vector<float> res;
  int i = 0;
  while (i < n && w[i] > 0) {
    res.push_back(w[i]);
    i++;
  }
  return res;
}

// 1. Devuelve la mayor de las productorias de numeros positivos arrancando desde el
//      principio del vector.

// 2. O(n) en el peor caso que es que w[i] > 0 siempre se cumpla y que n = |w|.

// 3. Peor caso #1: w = [1, 2, 3, 34, 4, 5, 3, 2, 0.5], n = 9. Este caso cumple 
//      con la guarda la mayor cantidad de veces posible sin indefinirse.
//    Mejor caso #1: w = [-1, 2, 3, 4, 5], n = 5. En este caso la guarda no se cumple nunca.
//    Mejor caso #2: w = [1, 2, 3, 4, 5], n = 0. En este caso la gaurda tampoco se cumple nunca.

// 4. g tiene complejidad O(n). recorre todos los elementos de un vector.
//    h tiene complijidad O(n) tambien. 
//    f hace n iteraciones de 2 funciones O(n), es decir n * (2 O(n)) = O(n**2)
//      tiene complejidad O(n**2)



// Ejercicio 7 -----------------------------------------------

// a. tiene tiempo de ejecucion log(n)

// b. no

// c. hay una formula, pero no lo entendi.



// Ejercicio 8 -----------------------------------------------

int determinanteTriangular(vector<vector<int>> &m) {
  int res = 1;
  for (int i = 0; i < m.size(); i++) {
    res = res * m[i][i];
  }
  return res;
}

bool esTriangSup(vector<vector<int>> &m) {
  bool res = true;
  for (int i = 0; i < m.size() - 1; i++)
  {
    for (int j = i + 1; j < m.size(); j++) 
    {
      res = res && m[i][j] == 0;
    }
  }
  return res;
}

bool esTriangInf(vector<vector<int>> &m) {
  bool res = true;
  for (int i = 1; i < m.size(); i++)
  {
    for (int j = 0; j < i; j++) 
    {
      res = res && m[i][j] == 0;
    }
  }
  return res;
}

bool esTriangular(vector<vector<int>> &m) {
  return esTriangSup(m) || esTriangInf(m);
}

// c. a. En funcion de la cantidad de elementos de la matriz (n):
//          - determinanteTriangular se ejecuta 1 vez por cada fila, m es de NxN elementos
//            la complejidad es O(sqrt(n));
//          - esTriangular tiene ciclos que recorren una vez cada elemento, excepto los de la
//              diagonal. Tiene complejidad O(n).
//    b. En funcion de la cantidad de filas de la matriz.
//          - determinanteTriangular se ejecuta 1 vez por cada fila.
//            la complejidad es O(n).
//          - esTriangular tiene ciclos que recorren una vez cada elemento. A medida que la
//              matriz aumenta la cantidad de filas tambien aumenta la cantidad de columnas
//              porque es cuadrada. Este aumento es cuadratico con respecto a la cantidad de
//              filas. La complejidad es O(n^2).




// Ejercicio 9 -----------------------------------------------


