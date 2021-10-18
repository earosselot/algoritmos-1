#include <vector>

using namespace std;

//-----------------------------------------------------------------//
//-----------------------------------------------------------------//
//--------------------------Ejercicio 1----------------------------//
//-----------------------------------------------------------------//
//-----------------------------------------------------------------//

vector<int> copiarSecuencia(vector<int> s) 
{
  vector<int> r;
  int i = 0;
  while(i<s.size()) 
  {
    r.push_back(s[i]);
    i = i + 1;
  }
  return r;
}


//-----------------------------------------------------------------//
//-----------------------------------------------------------------//
//--------------------------Ejercicio 2----------------------------//
//-----------------------------------------------------------------//
//-----------------------------------------------------------------//

// Hecho en la clase



//-----------------------------------------------------------------//
//-----------------------------------------------------------------//
//--------------------------Ejercicio 3----------------------------//
//-----------------------------------------------------------------//
//-----------------------------------------------------------------//

int cantApariciones(vector<int> s, int e) 
{
  int r = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == e)
      r++;
  }
  return r;
}


//-----------------------------------------------------------------//
//-----------------------------------------------------------------//
//--------------------------Ejercicio 4----------------------------//
//-----------------------------------------------------------------//
//-----------------------------------------------------------------//

// Pc === i = -1 ^ s = S0
// Qc === |s| = |S0| ^L (Vz: Z)(0 <= z < |s| ->L s[z] = S0[z] ** 2)

//  I === (|s| = |S0| ^ -1 <= i <= |s| ^L (Vj: Z)(0 <= j < i ->L s[j] = S0[j] ** 2)) 
//            ^ (Vj: Z)( i < j < |s| ->L s[j] = S0[j])

int i = -1;
void alCuadrado(vector<int> &s)
{
  for (i = 0; i < s.size(); i++) 
  {
    s[i] = s[i] * s[i];
  }
}

int i = -1;
void alCuadrado2(vector<int> &s)
{
  while (s.size() + i > 0 ) 
  {
    s[- i - 1] = s[- i - 1] * s[- i - 1];
    i = i - 1;
  }
}

// s = [1,2,3]

// i = -1
// - i - 1 = 0
// s.size() + i = 2

// i = -2
// - i - 1 = 1
// s.size() + i = 1

// i = -3
// - i - 1 = 2
// s.size() + i = 0


//-----------------------------------------------------------------//
//-----------------------------------------------------------------//
//--------------------------Ejercicio 5----------------------------//
//-----------------------------------------------------------------//
//-----------------------------------------------------------------//


// I === (|s| = |S0| ^ 0 <= i <= |s|/2) ^L
//       subseq(s, 0, |s| - 2*i) = subseq(S0, 0, |S0| - 2*i) ^ 
//       (Vk: Z)(|s| - 2*i <= k < |s| ->L s[k] = 2 * S0[k])

void duplicarElementos(vector<int> &s) 
{
  int i = 0;
  while (i < s.size() / 2) 
  {
    s[2 * i] = 2 * s[2 * i];
    s[(2 * i) + 1] = 2 * s[(2 * i) + 1];
    i = i + 1;
  }
}

// s0 = [1,2,3,4]
// s.size() / 2 = 2

// i = 0
// i < 2 === false
// s = [2, 4, 3, 4]

// i = 1
// i < 2 === false
// s = [2, 4, 6, 8]

// i = 2
// i < 2 === true


//-----------------------------------------------------------------//
//-----------------------------------------------------------------//
//--------------------------Ejercicio 6----------------------------//
//-----------------------------------------------------------------//
//-----------------------------------------------------------------//

// Resuelto en video de Youtube

// TODO: 
// en el ultimo del invariante no deberia ser |s| - i - 1 <= k < |s| ?? ahora ya no
// me acuerdo como lo habia pensado. Ver video de nuevo.


//-----------------------------------------------------------------//
//-----------------------------------------------------------------//
//--------------------------Ejercicio 7----------------------------//
//-----------------------------------------------------------------//
//-----------------------------------------------------------------//

/*
pred esPiramide(l: seq<Z>, v: Z) {
  (Vj: Z)(0 <= j < |l|/2 ->L l[j] = v + j) ^
  (Vj: Z)(|l|/2 <= j < |l| ->L l[j] = v + |l| - j - 1)
}

l = [3,4,5,4,3]
|l|/2 = 2
esPiramide(l, 3) === true

l = [3,4,4,3]
|l|/2 = 2
esPiramide(l, 3) === true

Invariante A
I === |l| = |L0| ^ |l|/2 <= i <= |l| ^L
      (Ep: seq<Z>)(esPiramide(p, v) ^ |p| = |l| ^L 
                   subseq(p, |l| - i, i) = subseq(l, |l| - i, i))

Invariante B
I === |l| = |L0| ^ 0 <= i <= |l| ^L piramideHastaI(l, i, v)

pred piramideHastaI(l: seq<Z>, i: Z, v: Z) {
  (Ep: seq<Z>)(esPiramide(p, v) ^ |p| = |l| ^L 
               subseq(p, 0, i) = subseq(l, 0, i))
}
*/

void armarPiramide(int v, vector<int> &l) 
{
  int i = l.size() / 2;
  while (i < l.size()) 
  {
    l[l.size() - i - 1] = v + (l.size() - i - 1); // centro izquierdo
    l[i] = v + l.size() - i - 1;                  // centro derecho
    i = i + 1;
  }
}


/* 
caso |l| par

  i = |l| / 2
  subseq(p, |l| - |l| / 2, |l| / 2) = subseq(l, |l| - |l| / 2, |l| / 2)
  === subseq(p, |l| / 2, |l| / 2) = subseq(l, |l| / 2, |l| / 2)
  === [] = [] === true

  i = |l|/2 + 1
  subseq(p, |l| - |l| / 2 - 1, |l| / 2 + 1) = subseq(l, |l| - |l| / 2 - 1, |l| / 2 + 1)
  subseq(p, |l| / 2 - 1, |l| / 2 + 1) = subseq(l, |l| / 2 - 1, |l| / 2 + 1)
  miro las 2 posiciones centrales

  i = |l|/2 + 2
  subseq(p, |l| - |l| / 2 - 2, |l| / 2 + 2) = subseq(l, |l| - |l| / 2 - 2, |l| / 2 + 2)
  subseq(p, |l| / 2 - 2, |l| / 2 + 2) = subseq(l, |l| / 2 - 2, |l| / 2 + 2)
  miro las 2 posiciones centrales y las dos contiguas hacia cada lado

caso |l| impar

  i = |l| / 2
  subseq(p, |l| - |l| / 2, |l| / 2) = subseq(l, |l| - |l| / 2, |l| / 2)
  === subseq(p, |l| / 2 + 1, |l| / 2) = subseq(l, |l| / 2 + 1, |l| / 2)
  === [] = [] === true

  i = |l|/2 + 1
  subseq(p, |l| - |l| / 2 - 1, |l| / 2 + 1) = subseq(l, |l| - |l| / 2 - 1, |l| / 2 + 1)
  subseq(p, |l| / 2 + 1 - 1, |l| / 2 + 1) = subseq(l, |l| / 2 + 1 - 1, |l| / 2 + 1)
  subseq(p, |l| / 2, |l| / 2 + 1) = subseq(l, |l| / 2, |l| / 2 + 1)
  miro la posicion central

  i = |l|/2 + 2
  subseq(p, |l| - |l| / 2 - 2, |l| / 2 + 2) = subseq(l, |l| - |l| / 2 - 2, |l| / 2 + 2)
  subseq(p, |l| / 2 - 1, |l| / 2 + 2) = subseq(l, |l| / 2 - 1, |l| / 2 + 2)
  miro la posicion central y las congiuas hacia los lados
*/

void armarPiramide2(int v, vector<int> &l) 
{
  int i = 0;
  while(i < l.size()) 
  {
    if(i < l.size() / 2) 
      l[i] = v + l[i];
    else
      l[i] = v + l.size() - i - 1;
    i = i + 1;
  }
}


//-----------------------------------------------------------------//
//-----------------------------------------------------------------//
//--------------------------Ejercicio 8----------------------------//
//-----------------------------------------------------------------//
//-----------------------------------------------------------------//

/*
proc multiplicar(inout s: seq<R>) {
  Pre { s = S0 ^ |s| mod 4 = 0}
  Post { |s| = |S0| ^L (Vi: Z)( 0 <= i < |s| ->L s[i] = 10 * S0[i]) }
}

I === (|s| = |S0| ^ |s|/2 <= i <= |s|) ^L esPar(i) ^
      subseq(s, i, |s|) = subseq(S0, i, |S0|) ^
      subseq(s, 0, |s| - i) = subseq(S0, 0, |S0| - i) ^
      (Vk: Z)( |s|/2 <= k < i ->L s[k] = 10 * S0[k]) ^
      (Vk: Z)( |s| - i <= k < |s|/2 ->L s[k] = 10 * S0[k])
*/

void multiplicar(vector<float> &s) 
{
  int i = s.size() / 2;
  while (i < s.size()) 
  { 
    s[i - 1] = 10 * s[i - 1];     // centro izquiero
    s[i - 2] = 10 * s[i - 2];     // izquierdo
    s[i] = 10 * s[i];             // centro derecho
    s[i + 1] = 10 * s[i + 1];     // derecho
    i = i + 2;
  }
}


//-----------------------------------------------------------------//
//-----------------------------------------------------------------//
//--------------------------Ejercicio 9----------------------------//
//-----------------------------------------------------------------//
//-----------------------------------------------------------------//

/*
proc crearYsumar(inout s: seq<Z>, inout suma: Z) {
  Pre { s = S0 ^ |s| mod 8 = 0 }
  Post { |s| = |S0| ^L (
         (Vi: Z)(enRango(i, s) ->L s[i] = 0) ^ 
         suma = sum(i=0, |s| - 1)(S0[i])) }
}
Pone todos los elementos de s en 0 y
suma contiene la suma de los elementos de S0

I === (|s| = |S0| ^ 0 <= i <= |s|/4) ^L (
      subseq(s, 2*i, |s| - 2*i) = subseq(S0, 2*i, |S0| - 2*i) ^
      (Vk: Z)(0 <= k < 2*i ->L s[k] = 0) ^
      (Vk: Z)(|s| - 2*i <= k < |s| ->L s[k] = 0) ^
      suma = sum(j=0, 2*i - 1)(S0[j]) + sum(j = |s| - 2*i, |s| - 1)(S0[j])
      )

s = [1,2,3,4,5,6,7,8]

i = 0
  subseq(s, 0, |s|) = subseq(S0, 0, |S0|) === true 

i = 1 (= |s|/4 - 1)
  subseq(s, 2, |s| - 2) = subseq(S0, 2, |S0| - 2) // las 4 posiciones centrales siguen igual
  (Vk: Z)(0 <= k < 2 ->L s[k] = 0)                // las 2 posiciones del ppio son 0
  (Vk: Z)(|s| - 2 <= k < |s| ->L s[k] = 0)        // las 2 posiciones finales son 0
  suma = sum(j=0, 1)(S0[j])                       // suma las posiciones 0 y 1
        + sum(j = |s| - 2, |s| - 1)(S0[j])        // suma las 2 ultimas posiciones

  s = [0,0,3,4,5,6,0,0]
  suma = 18


i = 2 (= |s|/4)
  subseq(s, 4, |s| - 4) = subseq(S0, 4, |S0| - 4) // rango vacio
  (Vk: Z)(0 <= k < 4 ->L s[k] = 0) ^              // las primeras 4 pos son 0
  (Vk: Z)(|s| - 4 <= k < |s| ->L s[k] = 0)        // las ultimas 4 pos son 0
  suma = sum(j=0, 3)(S0[j]) + 
          sum(j = |s| - 4, |s| - 1)(S0[j])
  
  s = [0,0,0,0,0,0,0,0]
  suma = 36
*/

int crearYsumar(vector<int> &s)
{
  int i = 0;
  int l = s.size();
  int suma = 0;
  while (i < l / 4)
  {
    suma = s[2 * i] + s[(2 * i) + 1] + s[l - (2 * i) - 1] + s[l - (2 * i) - 2];
    s[2 * i] = 0;
    s[(2 * i) + 1] = 0;
    s[l - (2 * i)] = 0;
    s[l - (2 * i) - 1] = 0;
  }
  return suma;
}
