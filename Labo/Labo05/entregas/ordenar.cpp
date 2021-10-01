#include <vector>
#include <iostream>

using namespace std;

int indiceMinSubsec(vector<int> v, int l, int r)
{
    int i = r;
    int res = r;
    while (i >= l)
    {
        if (v[i] < v[res])
        {
            res = i;
        }
        i--;
    }
    return res;
}

void ordenar1(vector<int> &v)
{
    int indiceMinimo;
    for (int i = 0; i < v.size(); i++)
    {
        indiceMinimo = indiceMinSubsec(v, i, v.size() - 1);
        swap(v[i], v[indiceMinimo]);
    }
    return;
}

int main()
{
    /* No hace falta modificar el main */

    // Leo las entradas
    int n; //Longitud del vector
    cin >> n;
    int i = 0;
    int x;
    vector<int> v; // En v leo el vector
    while (i < n)
    {
        cin >> x;
        v.push_back(x);
        i++;
    }

    // Hago el ordenamiento
    ordenar1(v);

    // Imprimo el vector resultado
    i = 0;
    while (i < v.size())
    {
        cout << v[i] << " ";
        i++;
    }

    return 0;
}
