#include "gtest/gtest.h"
#include <vector>
#include <string>
#include "../auxiliares/ej10.h"

using namespace std;


TEST(Ejercicio10, happyPathImpares) {

    vector<int> v = {6,7,5,3,4,1,2};

    vector<int> esperado = {1,2,3,4,5,6,7};

    coctailSort(v);

    EXPECT_EQ(esperado, v);
}

TEST(Ejercicio10, happyPathPares) {

    vector<int> v = {6,7,5,8,3,4,1,2};

    vector<int> esperado = {1,2,3,4,5,6,7,8};

    coctailSort(v);

    EXPECT_EQ(esperado, v);
}

TEST(Ejercicio10, todosIguales) {

    vector<int> v = {12,12,12,12};

    vector<int> esperado = {12,12,12,12};

    coctailSort(v);

    EXPECT_EQ(esperado, v);
}

TEST(Ejercicio10, noConsecutivos) {

    vector<int> v = {15,23,54,32,213,3123123};

    vector<int> esperado = {15,23,32,54,213,3123123};

    coctailSort(v);

    EXPECT_EQ(esperado, v);
}

TEST(Ejercicio10, alReves) {

    vector<int> v = {8,7,6,5,4,3,2,1};

    vector<int> esperado = {1,2,3,4,5,6,7,8};

    coctailSort(v);

    EXPECT_EQ(esperado, v);
}