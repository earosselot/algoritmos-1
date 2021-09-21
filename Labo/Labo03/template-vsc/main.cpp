#include "generador.h"
#include "vectores.h"
using namespace std;

int main()
{
    // funcion para generar automaticamente los archivos numericos
    // generarDatosLaboratorio();
    // descomentar para crear automaticamente
    // los archivos necesarios en la parte de entrada-salida.
    // Una vez creados, se puede volver a comentar

    // holaModuloVectores(); // función definida en vectores.cpp

    vector<int> numeros(10);
    for (int i = 0; i < numeros.size(); i++)
    {
        numeros[i] = i + 1;
    }

    // numeros.push_back(1);
    // numeros.push_back(1);
    // numeros.push_back(2);
    // numeros.push_back(1);

    // vector<int> resultado = rotar(numeros, 343242342);

    // cout << "numeros: " << endl;
    // for (int i = 0; i<numeros.size(); i++) {
    //   cout << i << ": " << numeros[i] << endl;
    // }

    // cout << "resultado: " << endl;
    // for (int i = 0; i<resultado.size(); i++) {
    //   cout << i << ": " << resultado[i] << endl;
    // }

    // cout << abs(-5) % 6 << endl;

    // vector<int> resultado = leerVector("elementoMedio.in");
    // mostrarVector(resultado);
    // int res = elementoMedio(resultado);
    // cout << res << endl;

    // cantApariciones("10000NumerosEntre1y50.in");
    // int n = cantidadDeAparicionesPalabra("cantidadAparicionesDePalabra.in", "tiempo");
    // cout << n << endl;

    // promedio("promedio1.in", "promedio2.in", "promediosOut.in");

    // En archivos/ se encuentra ordenarSecuencia1.in y ordenarSecuencia2.in. Cada archivo contiene 5000 numeros
    // ordenados entre 1 y 1000.
    // El primer archivo contiene los numeros pares en el rango y el segundo los impares.

    // ordenarSecuencias("ordenarSecuencia1.in", "ordenarSecuencia2.in", "ordenarSecuenciaOut.in");
    // cout << "resultado: " << endl;
    // for (int i = 0; i<resultado.size(); i++) {
    //   cout << i << ": " << resultado[i] << endl;
    // }
    // guardarVector(numeros, "archivo_nuevo.in");

    vector<int> v = interseccion();
    mostrarVector(v);

    // mostrarVector(resultado);
    return 0;
}
