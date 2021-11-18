#include <vector>
#include <tuple>

using namespace std;

pair<int, int> buscarMinMaxPos(vector<int> &v, int inicio, int fin) {
    int min = v[inicio];
    int max = v[inicio];
    int minPos = inicio;
    int maxPos = inicio;
    int i = inicio + 1;
    while (i < fin) {
        if (v[i] < min) {
            min = v[i];
            minPos = i;
        } else if (v[i] > max) {
            max = v[i];
            maxPos = i;
        }
        i++;
    }
    return make_pair(minPos, maxPos);
}

void swap(vector<int> &v, int pos1, int pos2) {
    int cache = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = cache;
}

void coctailSwap(vector<int> &v, pair<int, int> minMaxPos, int inicio, int fin) {
    if(minMaxPos.second == inicio && minMaxPos.first == fin) {
        swap(v,inicio, fin);
    } else if (minMaxPos.second == inicio) {
        swap(v, fin, minMaxPos.second);
        swap(v, inicio, minMaxPos.first);
    } else  {
        swap(v, inicio, minMaxPos.first);
        swap(v, fin, minMaxPos.second);
    }
}

void coctailSort(vector<int> &v) {
    for (int i = 0; i < v.size()/2; i++) {
        pair<int, int> minMaxPos = buscarMinMaxPos(v, i, v.size() - i);
        coctailSwap(v, minMaxPos, i, v.size() - 1 - i);
    }
}
