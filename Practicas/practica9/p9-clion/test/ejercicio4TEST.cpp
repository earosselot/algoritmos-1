#include "gtest/gtest.h"
#include <vector>
#include <string>
#include "../auxiliares/ej4.h"

using namespace std;

TEST(Ejercicio4a, happyPath) {

   vector<int> v = {0, 1, 0, 1, 1, 0, 1, 1};

   EXPECT_EQ(sumarCerosUnos(v), 5);
}

TEST(Ejercicio4a, todos0s) {

    vector<int> v = {0, 0, 0, 0, 0, 0, 0};

    EXPECT_EQ(sumarCerosUnos(v), 0);
}


TEST(Ejercicio4a, todos1s) {

    vector<int> v = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    EXPECT_EQ(sumarCerosUnos(v), 10);
}

TEST(Ejercicio4b, happyPath) {

    vector<int> v = {0, 0, 0, 1, 1, 1, 1};

    EXPECT_EQ(sumarCerosUnosLogN(v), 4);
}

TEST(Ejercicio4b, todos0s) {

    vector<int> v = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    EXPECT_EQ(sumarCerosUnosLogN(v), 0);
}


TEST(Ejercicio4b, todos1s) {

    vector<int> v = {1, 1, 1, 1, 1, 1, 1, 1};

    EXPECT_EQ(sumarCerosUnosLogN(v), 8);
}

TEST(Ejercicio4b, un0) {

    vector<int> v = {0, 1, 1, 1, 1, 1, 1, 1};

    EXPECT_EQ(sumarCerosUnosLogN(v), 7);
}

TEST(Ejercicio4b, un1) {

    vector<int> v = {0, 0, 0, 0, 0, 0, 0, 0, 1};

    EXPECT_EQ(sumarCerosUnosLogN(v), 1);
}

TEST(Ejercicio4c, happyPath) {

    vector<int> v = {15, 15, 15, 15, 22, 22, 22, 22, 22};

    EXPECT_EQ(sumarNumerosLogN(v), 170);
}

TEST(Ejercicio4c, todos15s) {

    vector<int> v = {15, 15, 15, 15, 15, 15, 15, 15};

    EXPECT_EQ(sumarNumerosLogN(v), 120);
}


TEST(Ejercicio4c, todos22s) {

    vector<int> v = {22, 22, 22, 22, 22, 22};

    EXPECT_EQ(sumarNumerosLogN(v), 132);
}

TEST(Ejercicio4c, un15) {

    vector<int> v = {15, 22, 22, 22};

    EXPECT_EQ(sumarNumerosLogN(v), 81);
}

TEST(Ejercicio4c, un22) {

    vector<int> v = {15, 15, 15, 22};

    EXPECT_EQ(sumarNumerosLogN(v), 67);
}