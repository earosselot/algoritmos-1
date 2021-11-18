#include <vector>

using namespace std;

int minimo(const vector<int> &v) {
    int minimo = v[0];

    for (int i = 1; i < v.size(); i++) {
        if (v[i] < minimo) {
            minimo = v[i];
        }
    }
    return minimo;
}

int maximo(const vector<int> &v) {
    int maximo = v[0];

    for (int i = 1; i < v.size(); i++) {
        if (v[i] > maximo) {
            maximo = v[i];
        }
    }
    return maximo;
}

void llenarContador(int min, vector<int> &v, vector<int> &contador) {
    for (int i = 0; i < v.size(); i++) {
        contador[v[i] - min] = contador[v[i] - min] + 1;
    }
}

void ordenarVector(vector<int> &v, int min, vector<int> &contador) {
    int k = 0;
    for (int j = (int)contador.size() - 1; j >= 0; j--) {
        while (contador[j] > 0) {
            v[k] = j + min;
            k++;
            contador[j] = contador[j] - 1;
        }
    }
}

void ordenaLineal(vector<int> &v) {
    if (v.size() > 0) {
        int min = minimo(v);
        int max = maximo(v);
        vector<int> contador(max-min+1, 0);
        llenarContador(min, v, contador);
        ordenarVector(v, min, contador);
    }
}





