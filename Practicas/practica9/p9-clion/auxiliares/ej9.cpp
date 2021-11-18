#include <vector>
#include <tuple>

using namespace std;

// Escribir un programa que, dado una secuencia de enteros v y dos enteros e y k (con k ≤ |v|),
// devuelva los k numeros mas cercanos a e.
// En caso de empates, considerar el de menor valor. Calcular el tiempo de ejecucion de peor caso.

// Complejidad:

/*
v = {2,3,4,5,63,3,4,5};

e = 4;
k = 3;
res = {4,4,3};

  v = {9,5,4,6,2,1,12,15,20};
dif = {3,7,...};

e = 12;
k = 2;
res = {12,9};
*/

//

int modulo(int n){  // O(1)
    if (n >= 0)
        return n;
    else
        return -n;
}

bool esMenor(pair<int, int> p1, pair<int, int> p2) {  // O(1)
    bool res = false;
    if (p1.first < p2.first) {
        res = true;
    } else if (p1.first == p2.first && p1.second < p2.second ) {
        res = true;
    }
    return res;

}

int buscarMinimo(const vector<pair<int, int>> &v, int inicio, int fin) {  // O(|v|)
    pair<int, int> minimo = v[inicio];
    int minPos = inicio;
    for (int i = inicio + 1; i < fin; i++) {
        if (esMenor(v[i], minimo)) {
            minimo = v[i];
            minPos = i;
        }
    }
    return minPos;
}

void swap(vector<pair<int, int>> &v, int pos1, int pos2) {  // O(1)
    pair<int, int> cache = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = cache;
}

vector<int> convertirVector(vector<pair<int, int>> v, int k) {  // O(k)
    vector<int> res;
    for (int i = 0; i < k; i++) {
        res.push_back(v[i].second);
    }
    return res;
}

vector<int> enterosCercanos(vector<int> &v, int e, int k) {
    int length = (int)v.size();
    vector<pair<int, int>> diferencias(length);


    for (int i = 0; i < length; i++) {                              // O(|v|)
        diferencias[i] = make_pair(modulo(e - v[i]), v[i]);
    }

    int j = 0;
    while (j < k) {                                                  // O(k) * O(|v|)
        int minPos = buscarMinimo(diferencias, j, length);
        swap(diferencias, j, minPos);
        j++;
    }
    vector<int> res = convertirVector(diferencias, k);            // O(k)
    return res;
}                                                                    // O(|v| * k)
