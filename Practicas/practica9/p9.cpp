#import <vector>

// Ejercicio 1 -----------------------------------------------

// n = filas de m
vector<int> buscarEnMatriz(vector<vector<int>> &m, int x) {
  vector<int> res;                                // 1
  res.push_back(-1).push_back(-1);                // 2

  for (int i = 0; i < m.size(); i++)              // 3, n veces
  {
    for (int j = 0; j < m[0].size(); j++) {       // 3, n veces
      if (m[i][j] == x) {                         // 1
        res[0] = i;                               // 1
        res[1] = j;                               // 1  
      }   
    }                                             // t(n) = 6n
  }                                               // t(n) = n*(3 + 6n) = 3n + 6n^2
  return res;                               
}                                                 // t(n) = 3 + 3n + 6n^2 -> O(n^2)


// Ejercicio 2 -----------------------------------------------


int encontrarFaltante(vector<int> &v) {
  int desde = 0;
  int hasta = v.size() - 1;
  int medio;
  
  if (v[0] == 1)
    hasta = 0;
  else if (v[v.size() - 1] != v.size())
    hasta = v.size();
  else {
    while (desde +1 < hasta)
    {
      medio = (hasta + desde) / 2;
      if (v[medio] == medio)   // el que falta esta a la derecha
        desde = medio;
      else 
        hasta = medio;
    } 
  }
  return hasta;
}
