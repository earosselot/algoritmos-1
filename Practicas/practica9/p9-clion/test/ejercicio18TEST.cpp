#include "gtest/gtest.h"
#include <vector>
#include "../auxiliares/ej18.h"

using namespace std;


TEST(Ejercicio18, happyPath) {
    vector<int> v = { 1, 4, 2, 5, 7, 3 };
    ordenaLineal(v);

    vector<int> esperado = { 7, 5, 4, 3, 2, 1 };

    EXPECT_EQ(esperado, v);
}

TEST(Ejercicio18, odenadoAsc) {
    vector<int> v = { 1, 3, 5, 8, 12 };
    ordenaLineal(v);

    vector<int> esperado = { 12, 8, 5, 3, 1 };

    EXPECT_EQ(esperado, v);
}

TEST(Ejercicio18, repetidos) {
    vector<int> v = { 4, 3, 2, 45, 42, 3, 5, 2, 1 };
    ordenaLineal(v);

    vector<int> esperado = {45, 42, 5, 4, 3, 3, 2, 2, 1 };

    EXPECT_EQ(esperado, v);
}

TEST(Ejercicio18, repetidosOrdenadoAsc) {
    vector<int> v = { 1, 3, 5, 5, 5, 8, 8, 12 };
    ordenaLineal(v);

    vector<int> esperado = { 12, 8, 8, 5, 5, 5, 3, 1 };

    EXPECT_EQ(esperado, v);
}

TEST(Ejercicio18, todosIguales) {
    vector<int> v = { 4, 4, 4, 4 };
    ordenaLineal(v);

    vector<int> esperado = { 4, 4, 4, 4 };

    EXPECT_EQ(esperado, v);
}

TEST(Ejercicio18, vectorVacio) {
    vector<int> v = {};
    ordenaLineal(v);

    vector<int> esperado = {};

    EXPECT_EQ(esperado, v);
}