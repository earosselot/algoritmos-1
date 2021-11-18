#include <vector>

using namespace std;

// 6a Contar la cantidad de veces que aparece un numero e en v.
// Complejidad O(n) // n == v.size()
int contarE(vector<int> v, int e) {
    int cantidad = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == e) {
            cantidad++;
        }
    }
    return cantidad;
}

// 6b Encontrar la diferencia entre max(v) y min(v).
// Complejidad O(n) // n == v.size()
int maximaDiferencia(vector<int> v) {
    if (!v.empty()) {
        int min = v[0];
        int max = v[0];
        for (int i = 1; i < v.size(); i++) {
            if (v[i] > max) {
                max = v[i];
            }
            if (v[i] < min) {
                min = v[i];
            }
        }
        return max - min;
    }
    return 0;
}

// 6c Encontrar el numero que mas veces aparece en la secuencia.
// Complejidad O(n^2)

int cantidadApariciones(vector<int> v, int elem) {
    int apariciones = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == elem)
            apariciones++;
    }
    return apariciones;
}

int maximasApariciones(vector<int> v) {
    int numeroQueMasAparece = 0;
    int maximaCantidadDeApariciones = 0;
    if (!v.empty()) {
        for (int i = 0; i < v.size(); i++) {
            int aparicionesVi = cantidadApariciones(v, v[i]);
            if (maximaCantidadDeApariciones < aparicionesVi) {
                maximaCantidadDeApariciones = aparicionesVi;
                numeroQueMasAparece = v[i];
            }
        }
    }
    return numeroQueMasAparece;
}

// 6d Igual que el 6c pero con un rango acotado [r1, r2]
// Complejidad O(|v|)

int maximasAparicionesLineal(vector<int> v, int r1, int r2) {
    int numeroQueMasAparece = 0;
    int maximaCantidadDeApariciones = 0;
    vector<int> contador(r2-r1+1, 0);

    for (int i = 0; i < v.size(); i++) {

        contador[v[i] - r1] += 1;

        if (contador[v[i] - r1] > maximaCantidadDeApariciones) {
            maximaCantidadDeApariciones = contador[v[i] - r1];
            numeroQueMasAparece = v[i];
        }
    }
    return numeroQueMasAparece;
}


// 6e

// 6f

// v = {3, 1, −2, 0, 2, −2, −2, −2, 3, 10, 0, 4};
// sin ordenar:
//    6a: O(n)
//    6b: O(n)
//    6c: O(n) porque tiene rango acotado + buscar max y min (6b)

// ordenado:
//    6a:  O(log(n))
//    6b:  O(1)
//    6c:  O(n)
//    ord: O(n^2)