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

// a.

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

// b.

vector<int> encontrarFaltantes(vector<int> &v) {
  int cantidadFaltantes = v[v.size() - 1] - v.size() + 1;
  vector<int> res;
  int i = 1;
  int elemento = v[0] + 1;

  while (cantidadFaltantes > 0) {
    if (v[i] == elemento) {
      i++;
      elemento++;
    } else {
      res.push_back(elemento);
      elemento++;
      cantidadFaltantes--;
    }
  }

  return res;
}

// El tiempo de ejecucion es O(n), donde n es v[v.size() - 1] - v[0];

// c.
v = [ 1, 3, 5, 7] k = 3
int encontrarFaltanteK(vector<int> &v, int k) {
  int faltantesAcum = 0;
  int i = 1;
  int elemento = v[0] + 1;          // 2

  while (i < v.size() && faltantesAcum < k) { 
    if (v[i] == elemento) {         // 
      i++;                          // 2 3
    } else {
      faltantesAcum++;              // 1 2
    }
    elemento++;
  }

  if (i == v.size()) {
    return -1;
  }
  return elemento - 1;
}

// El tiempo de ejecucion es O(n), donde n es v[v.size() - 1] - v[0];

// d.

vector<int> encontrarFaltantesLog(vector<int> &v) {
  int cantidadFaltantes = v[v.size() - 1] - v.size() + 1;
  vector<int> faltantes;
  
  while (cantidadFaltantes > 0) {
    int desde = 0;
    int hasta = v.size() - 1;
    int medio;
    
    while (desde +1 < hasta)
    {
      medio = (hasta + desde) / 2;
      if (v[medio] == medio)   // el que falta esta a la derecha
        desde = medio;
      else 
        hasta = medio;
    } 
    
    faltantes.push_back(v[desde] + 1);
    auto pos = v.begin() + desde + 1;
    v.insert(pos, desde + 1);
    cantidadFaltantes = cantidadFaltantes - 1;
  }
  return faltantes;
}



// Ejercicio 3 -----------------------------------------------

int raizRaiz(int n) {
  int i = 1;
  while (i * i <= n) {
    i++;
  }
  return i - 1;
}

int raizLogN(int n) {
  int inicio = 1;
  int fin = n;
  while (inicio + 1 < fin) {
    int medio = (inicio + fin) / 2;
    if (medio * medio == n) {
      return medio;
    } else if (medio * medio > n) {
      fin = medio;
    } else {
      inicio = medio;
    }
  }
  return inicio;
}


// Ejercicio 4 -----------------------------------------------

int sumarCerosUnos(vector<int> vectorBinario) {
  int suma = 0;
  for (int i = 0; i < vectorBinario.size(); i++)
  {
    suma += vectorBinario[i];
  }
  return suma;
}


int sumarCerosUnosLogN(vector<int> vectorBinario) {
  int inicio = 0;
  int fin = (int)vectorBinario.size();
  int medio;
  while (inicio + 1 < fin) {
    medio = (inicio + fin) / 2;

    if (vectorBinario[medio] == 0 && vectorBinario[medio + 1] == 1) {
      return vectorBinario.size() - medio - 1;
    }
    else 
    if (vectorBinario[medio] == 1)
    {
      fin = medio;
    }
    else if (vectorBinario[medio] == 0)
    {
      inicio = medio;
    }
  }
  return vectorBinario.size() - (medio + 1);
}


int sumarNumerosLogN(vector<int> vectorBinario) {
  int inicio = 0;
  int fin = (int)vectorBinario.size();
  int medio;
  while (inicio + 1 < fin) {
    medio = (inicio + fin) / 2;

    if (vectorBinario[medio] == 15 && vectorBinario[medio + 1] == 22) {
      int suma15s = ((int)vectorBinario.size() - medio + 1) * 15;
      int suma22s = ((int)vectorBinario.size() - medio - 1) * 22;
      return suma15s + suma22s;
    }
    else if (vectorBinario[medio] == 15)
    {
      fin = medio;
    }
    else if (vectorBinario[medio] == 22)
    {
      inicio = medio;
    }
  }
  return vectorBinario.size() - (medio + 1);
}

