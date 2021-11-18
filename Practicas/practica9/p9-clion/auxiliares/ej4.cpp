#include <vector>

using namespace std;

int sumarCerosUnos(vector<int> vectorBinario) {
    int suma = 0;
    for (int i = 0; i < vectorBinario.size(); i++)
    {
        suma += vectorBinario[i];
    }
    return suma;
}

int sumarCerosUnosLogN(vector<int> vectorBinario) {
    if (vectorBinario[0] == 1) {
        return (int)vectorBinario.size();
    }

    int inicio = 0;
    int fin = (int)vectorBinario.size();
    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;

        if (vectorBinario[medio] == 1 && vectorBinario[medio - 1] == 0) {
            return (int)vectorBinario.size() - medio;
        }
        else
        if (vectorBinario[medio] == 1)
        {
            fin = medio - 1;
        }
        else if (vectorBinario[medio] == 0)
        {
            inicio = medio + 1;
        }
    }
    return 0;
}


int sumarNumerosLogN(vector<int> vectorBinario) {
    if (vectorBinario[0] == 22) {
        return (int)vectorBinario.size() * 22;
    }

    int inicio = 0;
    int fin = (int)vectorBinario.size();
    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;
        if (vectorBinario[medio] == 22 && vectorBinario[medio - 1] == 15) {
            int suma22s = ((int)vectorBinario.size() - medio) * 22;
            int suma15s = medio * 15;
            return suma22s + suma15s;
        }
        else
        if (vectorBinario[medio] == 22)
        {
            fin = medio - 1;
        }
        else if (vectorBinario[medio] == 15)
        {
            inicio = medio + 1;
        }
    }
    return (int)vectorBinario.size() * 15;
}
