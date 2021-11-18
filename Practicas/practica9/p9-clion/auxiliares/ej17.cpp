#include <vector>
#include <tuple>

using namespace std;

vector<int> reconstruye(vector<int> v) {
    // el largo de la entrada es igual a la suma de los elementos.

    // el largo de la salida es igual al de la entrada
    // la salida esta ordenada
    // V elemento de la salida esta entre 0 y |a|
    // V indice de la entrada, el elemento en ese indice, es igual a la cantidad de apariciones de el indice en b.

    //  i -  0  1  2  3
    // a = { 1, 0, 3, 0 }
    // b = { 0, 2, 2, 2 }

    //  i -  0  1  2  3  4  5
    // a = { 2, 0, 1, 0, 3, 0 }
    // b = { 0, 0, 2, 4, 4, 4 }

    vector<int> res(v.size());
    int j = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int k = 0; k < v[i]; k++) {
            res[j] = i;
            j++;
        }
    }
    return res;
}
