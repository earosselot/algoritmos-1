#include <vector>

using namespace std;

// Determinar si la secuencia es de cuentas


int maximo(vector<int> &v) {
    int max = 0;
    if (v.size() > 0) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i] > max)
                max = v[i];
        }
    }
    return max;
}

bool esDeCuentas(vector<int> &v) {
    int max = maximo(v);
    vector<int> contador(max + 1, 0);
    // contador cuenta las apariciones del numero i:
    //   -1: el numero esta i veces
    //   -2: el numero esta mas de i veces
    //    0: el numero esta 0 veces
    //    x: el numero esta x veces

    for (int i = 0; i < v.size(); i++) {
        if (contador[v[i]] == -1) {
            contador[v[i]] = -2;
        }

        if (contador[v[i]] >= 0) {
            contador[v[i]] = contador[v[i]] + 1;
            if (contador[v[i]] == v[i]) {
                contador[v[i]] = -1;
            }
        }
    }
    int j = 0;
    while (contador[j] == -1 || contador[j] == 0) {
        j++;
    }
    return j == contador.size();
}


