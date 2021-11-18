#include "gtest/gtest.h"
#include <vector>
#include <string>
#include "../auxiliares/ej16.h"

using namespace std;


TEST(Ejercicio16, happyPath) {

    vector<int> v = { 1, 3, 4, 5, 2, 6, 7 };
    //                1  2  3  4  5

    vector<int> esperado = { 1, 2, 3, 4, 5, 6, 7 };

    dosMitades(v);

    EXPECT_EQ(esperado, v);
}

TEST(Ejercicio16, segundaMitadVacia) {

    vector<int> v = { 1, 2, 3, 4, 5, 6, 7 };

    vector<int> esperado = { 1, 2, 3, 4, 5, 6, 7 };

    dosMitades(v);

    EXPECT_EQ(esperado, v);
}

TEST(Ejercicio16, primeraMitadUnElemento) {

    vector<int> v = { 6, 1, 2, 3, 4, 5, 7 };

    vector<int> esperado = { 1, 2, 3, 4, 5, 6, 7 };

    dosMitades(v);

    EXPECT_EQ(esperado, v);
}

TEST(Ejercicio16, primeraMitadUnElemento2) {

    vector<int> v = { 7, 1, 2, 3, 4, 5, 6 };

    vector<int> esperado = { 1, 2, 3, 4, 5, 6, 7 };

    dosMitades(v);

    EXPECT_EQ(esperado, v);
}

TEST(Ejercicio16, segundaMitadUnElemento) {

    vector<int> v = { 1, 3, 4, 5, 6, 2 };

    vector<int> esperado = { 1, 2, 3, 4, 5, 6 };

    dosMitades(v);

    EXPECT_EQ(esperado, v);
}

TEST(Ejercicio16, segundaMitadUnElemento2) {

    vector<int> v = { 2, 3, 4, 5, 6, 1 };

    vector<int> esperado = { 1, 2, 3, 4, 5, 6 };

    dosMitades(v);

    EXPECT_EQ(esperado, v);
}

TEST(Ejercicio16, segundaMitadUnElemento3) {

    vector<int> v = { 2, 3, 4, 5, 6, 1 };

    vector<int> esperado = { 1, 2, 3, 4, 5, 6 };

    dosMitades(v);

    EXPECT_EQ(esperado, v);
}