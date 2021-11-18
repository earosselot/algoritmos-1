#include "gtest/gtest.h"
#include <vector>
#include <string>
#include "../auxiliares/ej9.h"

using namespace std;

TEST(Ejercicio9, happyPath) {

    vector<int> v = {1,2,3,4,5,6,7};
    int e = 4;
    int k = 3;

    vector<int> esperado = {4,3,5};

    EXPECT_EQ(esperado, enterosCercanos(v, e, k));
}

TEST(Ejercicio9, dosConIgualDiferencia) {

    vector<int> v = {1,2,3,4,5,6,7};
    int e = 4;
    int k = 4;

    vector<int> esperado = {4,3,5,2};

    EXPECT_EQ(esperado, enterosCercanos(v, e, k));
}


TEST(Ejercicio9, numerosNoConsecutivos) {
    //   diferencias                     5       9   5  1
    vector<int> v = {34, 33, 32, 51, 67, 4, 64, 18, 14, 8, 56, 64};
    int e = 9;
    int k = 4;

    vector<int> esperado = {8, 4, 14, 18};

    EXPECT_EQ(esperado, enterosCercanos(v, e, k));
}

TEST(Ejercicio9, masDeKIgualesAe) {
    //   diferencias                     5       9   5  1
    vector<int> v = {34, 9, 33, 32, 51, 67, 9, 9, 4, 64, 18, 14, 9, 9, 8, 56, 64};
    int e = 9;
    int k = 4;

    vector<int> esperado = {9, 9, 9, 9};

    EXPECT_EQ(esperado, enterosCercanos(v, e, k));
}

TEST(Ejercicio9, kIgualesAe) {
    //   diferencias                     5       9   5  1
    vector<int> v = {34, 9, 33, 32, 51, 67, 9, 9, 4, 64, 18, 14, 9, 9, 8, 56, 64};
    int e = 9;
    int k = 5;

    vector<int> esperado = {9, 9, 9, 9, 9};

    EXPECT_EQ(esperado, enterosCercanos(v, e, k));
}