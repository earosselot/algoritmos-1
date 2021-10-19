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


