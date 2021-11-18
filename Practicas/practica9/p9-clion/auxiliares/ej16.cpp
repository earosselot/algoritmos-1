#include <vector>
#include <tuple>

using namespace std;

int buscarI(vector<int> &v) {
    int i = 1;
    while (i < v.size() && v[i-1] < v[i]) {
        i++;
    }
    return i;
}

void dosMitades(vector<int> &v) {
    // i es el primero de la segunda mitad
    int medio = buscarI(v);
    vector<int> res(v.size());

    int j = 0;
    int i = medio;
    int length = (int)v.size();
    while (j < medio && i < length) {
        if (v[i] < v[j]) {
            res[i + j - medio] = v[i];
            i++;
        } else {
            res[i + j - medio] = v[j];
            j++;
        }
    }

    if (j == medio) {
        while (i < length) {
            res[i + j - medio] = v[i];
            i++;
        }
    } else {
        while (j < medio) {
            res[i + j - medio] = v[j];
            j++;
        }
    }
    v = res;
}


// { 1, 3, 4, 5, 3, 4, 7 }
