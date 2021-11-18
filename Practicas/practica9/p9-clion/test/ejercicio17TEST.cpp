#include "gtest/gtest.h"
#include <vector>
#include "../auxiliares/ej17.h"

using namespace std;


TEST(Ejercicio17, happyPath) {
    vector<int> v = { 1, 0, 3, 0 };

    vector<int> esperado = { 0, 2, 2, 2 };

    EXPECT_EQ(esperado, reconstruye(v));
}

TEST(Ejercicio17, happyPath1) {
    vector<int> v = { 2, 0, 1, 0, 3, 0 };

    vector<int> esperado = { 0, 0, 2, 4, 4, 4 };

    EXPECT_EQ(esperado, reconstruye(v));
}

TEST(Ejercicio17, vectorVacio) {
    vector<int> v = {};

    vector<int> esperado = {};

    EXPECT_EQ(esperado, reconstruye(v));
}

