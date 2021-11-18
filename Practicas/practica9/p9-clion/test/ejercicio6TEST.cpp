#include "gtest/gtest.h"
#include <vector>
#include <string>
#include "../auxiliares/ej6.h"

using namespace std;

// 6a Contar la cantidad de veces que aparece un numero e en v.

TEST(Ejercicio6a, happyPath) {

vector<int> v = {1, 32, 34, 54, 3, 2, 4, 5};

EXPECT_EQ(contarE(v, 34), 1);
}

TEST(Ejercicio6a, noEsta) {

vector<int> v = {1, 32, 34, 54, 3, 2, 4, 5};

EXPECT_EQ(contarE(v, 22), 0);
}

TEST(Ejercicio6a, vectorVacio) {

vector<int> v = {};

EXPECT_EQ(contarE(v, 22), 0);
EXPECT_EQ(contarE(v, 123), 0);
}

TEST(Ejercicio6a, estaUltimo) {

    vector<int> v = {1, 32, 34, 54, 3, 2, 4, 5};

    EXPECT_EQ(contarE(v, 5), 1);
}

TEST(Ejercicio6a, estaPrimero) {

    vector<int> v = {12, 32, 34, 54, 3, 2, 4, 5};

    EXPECT_EQ(contarE(v, 12), 1);
}


// 6b Encontrar la diferencia entre max(v) y min(v).

TEST(Ejercicio6b, happyPath) {
    vector<int> v = {12, 32, 34, 54, 3, 2, 4, 5};
    EXPECT_EQ(maximaDiferencia(v), 52);
}

TEST(Ejercicio6b, vectorVacio) {
    vector<int> v = {};
    EXPECT_EQ(maximaDiferencia(v), 0);
}

TEST(Ejercicio6b, todosIguales) {
    vector<int> v = {3, 3, 3, 3, 3};
    EXPECT_EQ(maximaDiferencia(v), 0);
}

TEST(Ejercicio6b, todosIgualesUnoDistinto) {
    vector<int> v = {3, 3, 3, 3, 4};
    EXPECT_EQ(maximaDiferencia(v), 1);
}

// 6c Encontrar el numero que mas veces aparece en la secuencia.

TEST(Ejercicio6c, happyPath) {
    vector<int> v = {3, 3, 3, 3, 4};
    EXPECT_EQ(maximasApariciones(v), 3);
}

TEST(Ejercicio6c, todosIgaules) {
    vector<int> v = {6, 6, 6, 6};
    EXPECT_EQ(maximasApariciones(v), 6);
}

TEST(Ejercicio6c, todosDistintos) {
    vector<int> v = {6, 4, 2, 1};
    bool res = maximasApariciones(v) == 6 ||
            maximasApariciones(v) == 4 ||
            maximasApariciones(v) == 2 ||
            maximasApariciones(v) == 1;

    ASSERT_TRUE(res);
}

TEST(Ejercicio6c, happyPath2) {
    vector<int> v = {5, 4, 0, 0, 1};
    EXPECT_EQ(maximasApariciones(v), 0);
}

// 6d Encontrar el numero que mas veces aparece en la secuencia, con rango acotado y complejidad lineal.

TEST(Ejercicio6d, happyPath) {
    vector<int> v = {3, 3, 3, 3, 4};
    EXPECT_EQ(maximasAparicionesLineal(v, 3, 4), 3);
}

TEST(Ejercicio6d, todosIgaules) {
    vector<int> v = {6, 6, 6, 6};
    EXPECT_EQ(maximasAparicionesLineal(v, 6, 6), 6);
}

TEST(Ejercicio6d, todosDistintos) {
    vector<int> v = {6, 4, 2, 1};
    bool res = maximasAparicionesLineal(v, 1, 6) == 6 ||
            maximasAparicionesLineal(v, 1, 6) == 4 ||
            maximasAparicionesLineal(v, 1, 6) == 2 ||
            maximasAparicionesLineal(v, 1, 6) == 1;

    ASSERT_TRUE(res);
}

TEST(Ejercicio6d, happyPath2) {
    vector<int> v = {5, 4, 0, 0, 1};
    EXPECT_EQ(maximasAparicionesLineal(v, 0, 5), 0);
}