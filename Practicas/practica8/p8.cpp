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

// a. Pre { |m1|[0] = |m2| }

// b. 

vector<vector<int>> multiplicar(vector<vector<int>> &m1, vector<vector<int>> &m2) {
  vector<vector<int>> res(m1.size(), m2[0].size());
  for (int i = 0; i < m1.size(); i++)
  {
    for (int j = 0; j < m2[0].size(); j++) {
      for (int k = 0; k < m2.size(); k++) {
        res[i][j] = m1[i][k] * m2[k][j];
      }
    }
  }
}

// c. tiempo de ejecucion
//    a. Es n^3 pero variando alguna constante.
//    b. La complejidad es O(n^3)



// Ejercicio 10 ----------------------------------------------


// 1, O(n^4)

// 2. 
void sumasAcumuladas(vector<vector<int>> &mat, int N) {
  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; i < mat[0].size(); j++) {
      if (i > 0 && j == 0) {
        mat[i][j] = mat[i][j] + mat[i - 1][N - 1];
      } else if (j > 0) {
        mat[i][j] = mat[i][j] + mat[i][j-1]
      }
    }
  }
}



// Ejercicio 11 ----------------------------------------------


int imparesConsecutivos(vector<int> &s) {
  int consecutivos = 0;
  int maxConsecutivos = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] % 2 == 1) {
      consecutivos++;
    } else {
      consecutivos = 0;
    }
    if (consecutivos > maxConsecutivos) {
      maxConsecutivos = consecutivos;
    }
  }
  return maxConsecutivos;
}



// Ejercicio 12 ----------------------------------------------


vector<int> restarAcumulado(vector<int> &s, int x) {
  vector<int> res(s.size());
  vector<int> acum(s.size());
  
  acum[0] = s[0];
  for (int i = 1; i < acum.size(); i++)
  {
    acum[i] = s[i] + acum[i - 1];
  }

  for (int i = 0; i < res.size(); i++) {
    res[i] = x - acum[i];
  }

  return res;
}




// Ejercicio 13 ----------------------------------------------


// 2 4 5
// 3 5 6
// 2 1 3

// 11 13 14
// 9 9 9
// 6 4 3 

int calcularMenorCosto(vector<vector<int>> &mat) {
  vector<vector<int>> costos(mat.size(), mat[0].size());
  costos[mat.size() - 1][mat[0].size() - 1] = mat[mat.size() - 1][mat[0].size() - 1];
  for (int i = mat.size() - 1; i >= 0; i--)
  {
    for (int j = mat[0].size() - 1; j >= 0; j--) {
      if (i < mat.size() - 1 && j < mat[0].size() - 1) {
        costos[i][j] = mat[i][j] + min(costos[i][j+1], costos[i+1][j])
      } else if (i == mat.size() - 1 && j < mat[0].size() - 1) {
        costos[i][j] = mat[i][j] + costos[i][j + 1];
      } else if (i < mat.size() && j == mat[0].size() - 1) {
        costos[i][j] = mat[i][j] + costos[i + 1][j];
      }
    }
  }
  return costos[0][0]
}



// Ejercicio 14 ----------------------------------------------

// a.

vector<vector<int>> potenciaMatrices(<vector<vector<int>> &m, int pot) {
  vector<vector<int>> res = m;
  for (int k = 1; k < pot; k++) {
    res = multiplicar(res, m);     // O(n^3)
  }
  return res;
}

// La complejidad sigue siendo O(n^3)

// b.
vector<vector<int>> potenciaMatrices2(<vector<vector<int>> &m, int pot) {
  vector<vector<int>> res = m;
  float times = log2(pot);

  for (int k = 1; k <= times; k++) {
    res = multiplicar(res, res);     // O(n^3)
  }
  return res;
}

// Los dos tienen complejidad O(n^3)


// Ejercicio 15 ----------------------------------------------

// Dada una matriz de booleanos de n filas y m columnas con n impar.  
//  Se sabe que hay exactamente una fila que no esta repetida, y el resto
//  se encuentra exactamente dos veces en la matriz.

// a. Escribir un programa que devuelva un vector con los valores de la fila que no se repite. 
//      ¿Cual es su tiempo de ejecucion de peor caso descripto ?

vector<int> buscarFilaUnica(vector<vector<int>> &m) {     // n filas   m columnas
  vector<int> filasBinarias;                              // 1
  for (int i = 0; i < m.size(); i++) {                    // 3, n veces
    int filaBinaria = 0;                                    // 1
    for (int j = 0; j < m[0].size(); j++)                     // 3, m veces
    {
      if (m[i][j])                                            // 1
        filaBinaria += 1 * pow(10, j);                        // 1
    }                                                         // t(m) = 5m
    filasBinarias.push_back(filaBinaria);                   // 1
  }                                                       // t(m, n) = 5n * 5m   

  int filaUnica = 0;                                      // 1
  for (int i = 0; i < filasBinarias.size(); i++)          // 3, n veces 
  {
    bool unica = true;                                      // 1
    for (int j = i + 1; j < filasBinarias.size(); j++) {    // 3, n veces
      unica = unica && !(filasBinarias[i] - filasBinarias[j] == 0)  // 1
    }                                                       // t(n) = 3n
    if (unica)                                            // 1
      filaUnica = i;                                      // 1
  }                                                       // t(n) = 3n * 3n
  return filaUnica;
}                                                         // t(n, n) = 9(n^2) + 5(nm)

// La complejidad es O(n^2) considerando la cantidad de elementos
