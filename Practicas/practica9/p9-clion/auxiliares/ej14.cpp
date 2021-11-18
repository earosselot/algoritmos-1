#include <vector>
#include <tuple>
#include "./ej10.h"

using namespace std;

vector<int> buscarMinimos(vector<int> &v, int inicio, int fin) {
    int minimo = v[inicio];
    vector<int> minPos = {inicio};
    for (int i = inicio + 1; i < fin; i++) {
        if (v[i] < minimo) {
            minimo = v[i];
            minPos = {i};
        } else if (v[i] == minimo) {
            minPos.push_back(i);
        }
    }
    return minPos;
}

// selection sort con todos los iguales a la vez
void bingoSort(vector<int> &v) {
    int i = 0;
    vector<int> minPos;
    while (i < v.size()) {
        minPos = buscarMinimos(v, i, v.size());
        for (int j = 0; j < minPos.size(); j++) {
            swap(v, i+j, minPos[j]);
        }
        i = i + (int)minPos.size();
    }
}