#include "gtest/gtest.h"
#include <vector>
#include <string>
#include "../auxiliares/ej7.h"

using namespace std;

// 7.

TEST(Ejercicio7, happyPath) {

    vector<int> v = {4, 1, 4, 4, 5, 5, 5, 4, 5, 5};

    EXPECT_TRUE(esDeCuentas(v));
}

TEST(Ejercicio7, unoDeMas) {

    vector<int> v = {4, 1, 4, 4, 5, 5, 1, 5, 4, 5, 5};

    EXPECT_FALSE(esDeCuentas(v));
}

TEST(Ejercicio7, unoDeMenos) {

    vector<int> v = {4, 1, 4, 4, 5, 5, 2, 5, 4, 5, 5};

    EXPECT_FALSE(esDeCuentas(v));
}

TEST(Ejercicio7, elDobleDeNumeros) {

    vector<int> v = {4, 1, 4, 4, 5, 5, 2, 5, 4, 5, 5, 4, 4, 4, 4};

    EXPECT_FALSE(esDeCuentas(v));
}

TEST(Ejercicio7, arregloVacio) {

    vector<int> v = {};

    EXPECT_TRUE(esDeCuentas(v));
}