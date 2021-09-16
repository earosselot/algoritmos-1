#include <iostream>
#include <vector>

using namespace std;

bool esCreciente(vector<int> v) {
    bool creciente = true;
    int i = 0;
    while (i < v.size() - 1 && creciente) {
        if (!(v[i] <= v[i+1])) {
        creciente = false;
        }
        i++;
    }
    return creciente;
}

bool esDecreciente(vector<int> v) {
    bool decreciente = true;
    int i = 0;
    while (i < v.size() - 1 && decreciente) {
        if (!(v[i] >= v[i+1])) {
        decreciente = false;
        }
        i++;
    }
    return decreciente;
}

bool estaOrdenado(vector<int> v){
    // Dado un vector v de enteros no repetidos, devuelve verdadero si el mismo
    // esta ordenado (creciente o decrecientemente).
    bool res = true;
    if (v.size() > 2) {
        res = esCreciente(v) || esDecreciente(v);
    }
    return res;
}
    
int main() {
    /* No hace falta modificar el main */
    // Leo las entradas
    int n; 
    cin >> n;
    int i = 0;
    int x;
    vector<int> v;// En v leo el vector
    while (i<n){
        cin >> x;
        v.push_back(x);
        i++;
    }
    
    // Evaluo si el vector v esta ordenado
    bool res = estaOrdenado(v);
    
    // Imprimo la salida
    cout << (res?"True":"False");
    
    return 0;
}
