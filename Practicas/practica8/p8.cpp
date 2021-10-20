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

