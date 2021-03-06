#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace std;

pair<eph_h, eph_i> encuesta_prueba(vector<pair<int, int>> pos);


TEST(histogramaDeAnillosConcentricosTEST, primeroYUltimo) {
    vector<int> distancias = {10, 20, 50, 100};

    pair<int, int> centro = {0, 0};

    pair<eph_h, eph_i> p = encuesta_prueba({
                                                   {1,   1},     // 1.41
                                                   {3,   5},     // 5.83
                                                   {53,  5},    // 52.24
                                                   {101, 21},  // 103.16
                                           });

    vector<int> res = {2, 0, 0, 1};

    EXPECT_EQ(res, histogramaDeAnillosConcentricos(p.first, p.second, centro, distancias));
}

TEST(histogramaDeAnillosConcentricosTEST, cuatroCuadrantes) {

    vector<int> distancias = {10, 20, 50, 100};

    pair<int, int> centro = {0, 0};

    pair<eph_h, eph_i> p = encuesta_prueba({
                                                   {11,  11},
                                                   {-11, -11},
                                                   {-11, 11},
                                                   {11,  -11}
                                           });

    vector<int> res = {0, 4, 0, 0};

    EXPECT_EQ(res, histogramaDeAnillosConcentricos(p.first, p.second, centro, distancias));
}


pair<eph_h, eph_i> encuesta_prueba(vector<pair<int, int>> pos) {
    eph_h th = {{22114, 2020, 3, 319611, 629088, 3, 41, 0, 1, 3, 1, 2},
                {31117, 2020, 3, 332870, 642475, 3, 40, 0, 1, 6, 6, 2},
                {22866, 2020, 3, 317157, 627217, 2, 42, 1, 1, 2, 2, 2},
                {20957, 2020, 3, 313965, 623297, 1, 43, 0, 1, 3, 1, 2}};

    eph_i ti = {{20957, 2020, 1,  1, 3, 1, 88, 0, 0, 90000, 10},
                {20957, 2020, 2,  1, 3, 2, 82, 0, 0, 25000, 10},
                {31117, 2020, 1,  0, 3, 1, 58, 1, 3, 22000, 1},
                {31117, 2020, 2,  0, 3, 2, 54, 1, 1, -1,    1},
                {31117, 2020, 3,  0, 3, 2, 46, 1, 3, 17000, 1},
                {31117, 2020, 4,  0, 3, 1, 20, 1, 3, 5000,  1},
                {31117, 2020, 5,  0, 3, 2, 15, 0, 0, 5000,  10},
                {31117, 2020, 6,  0, 3, 1, 7,  0, 0, 0,     10},
                {31117, 2020, 8,  0, 3, 2, 11, 0, 0, 0,     10},
                {31117, 2020, 9,  0, 3, 1, 50, 0, 2, 0,     10},
                {31117, 2020, 10, 0, 3, 1, 28, 1, 3, 5000,  1},
                {22866, 2020, 1,  0, 3, 1, 31, 1, 3, 59000, 10},
                {22866, 2020, 2,  1, 3, 2, 28, 1, 3, 0,     6},
                {22114, 2020, 1,  0, 3, 1, 18, 0, 0, 20000, 10}};

    for (int i = 0; i < pos.size(); i++) {
        th[i][HOGLATITUD] = pos[i].first;
        th[i][HOGLONGITUD] = pos[i].second;
    }

    return make_pair(th, ti);
}

TEST(histogramaDeAnillosConcentricosTEST, prueba) {

    vector<int> distancias = {10, 20, 50, 100};

    pair<int, int> centro = {0, 0};
    eph_h th = {{22114, 2020, 3, 1,   1,  3, 41, 0, 1, 3, 1, 2},  // 1.4
                {31117, 2020, 3, 3,   5,  3, 40, 0, 1, 6, 6, 2},  // 5.8
                {22866, 2020, 3, 53,  5,  2, 42, 1, 1, 2, 2, 2},  // 53.23
                {20957, 2020, 3, 101, 21, 1, 43, 0, 1, 3, 1, 2}}; // 103.16

    eph_i ti = {{20957, 2020, 1,  1, 3, 1, 88, 0, 0, 90000, 10},
                {20957, 2020, 2,  1, 3, 2, 82, 0, 0, 25000, 10},
                {31117, 2020, 1,  0, 3, 1, 58, 1, 3, 22000, 1},
                {31117, 2020, 2,  0, 3, 2, 54, 1, 1, -1,    1},
                {31117, 2020, 3,  0, 3, 2, 46, 1, 3, 17000, 1},
                {31117, 2020, 4,  0, 3, 1, 20, 1, 3, 5000,  1},
                {31117, 2020, 5,  0, 3, 2, 15, 0, 0, 5000,  10},
                {31117, 2020, 6,  0, 3, 1, 7,  0, 0, 0,     10},
                {31117, 2020, 8,  0, 3, 2, 11, 0, 0, 0,     10},
                {31117, 2020, 9,  0, 3, 1, 50, 0, 2, 0,     10},
                {31117, 2020, 10, 0, 3, 1, 28, 1, 3, 5000,  1},
                {22866, 2020, 1,  0, 3, 1, 31, 1, 3, 59000, 10},
                {22866, 2020, 2,  1, 3, 2, 28, 1, 3, 0,     6},
                {22114, 2020, 1,  0, 3, 1, 18, 0, 0, 20000, 10}};

    vector<int> res = {2, 0, 0, 1};

    EXPECT_EQ(res, histogramaDeAnillosConcentricos(th, ti, centro, distancias));
}

TEST(histogramaDeAnillosConcentricosTEST, noHayAdentro) {

    vector<int> distancias = {10, 20, 50, 100};

    pair<int, int> centro = {0, 0};
    eph_h th = {{22114, 2020, 3, 52,  207, 3, 41, 0, 1, 3, 1, 2},  // 1.4
                {31117, 2020, 3, 99,  101, 3, 40, 0, 1, 6, 6, 2},  // 5.8
                {22866, 2020, 3, 53,  100, 2, 42, 1, 1, 2, 2, 2},  // 53.23
                {20957, 2020, 3, 101, 21,  1, 43, 0, 1, 3, 1, 2}}; // 103.16

    eph_i ti = {{20957, 2020, 1,  1, 3, 1, 88, 0, 0, 90000, 10},
                {20957, 2020, 2,  1, 3, 2, 82, 0, 0, 25000, 10},
                {31117, 2020, 1,  0, 3, 1, 58, 1, 3, 22000, 1},
                {31117, 2020, 2,  0, 3, 2, 54, 1, 1, -1,    1},
                {31117, 2020, 3,  0, 3, 2, 46, 1, 3, 17000, 1},
                {31117, 2020, 4,  0, 3, 1, 20, 1, 3, 5000,  1},
                {31117, 2020, 5,  0, 3, 2, 15, 0, 0, 5000,  10},
                {31117, 2020, 6,  0, 3, 1, 7,  0, 0, 0,     10},
                {31117, 2020, 8,  0, 3, 2, 11, 0, 0, 0,     10},
                {31117, 2020, 9,  0, 3, 1, 50, 0, 2, 0,     10},
                {31117, 2020, 10, 0, 3, 1, 28, 1, 3, 5000,  1},
                {22866, 2020, 1,  0, 3, 1, 31, 1, 3, 59000, 10},
                {22866, 2020, 2,  1, 3, 2, 28, 1, 3, 0,     6},
                {22114, 2020, 1,  0, 3, 1, 18, 0, 0, 20000, 10}};

    vector<int> res = {0, 0, 0, 0};

    EXPECT_EQ(res, histogramaDeAnillosConcentricos(th, ti, centro, distancias));
}

TEST(histogramaDeAnillosConcentricosTEST, todosAlPrimero) {

    vector<int> distancias = {10, 20, 50, 100};

    pair<int, int> centro = {0, 0};
    eph_h th = {{22114, 2020, 3, 1, 1, 3, 41, 0, 1, 3, 1, 2},  // 1.4
                {31117, 2020, 3, 1, 1, 3, 40, 0, 1, 6, 6, 2},  // 5.8
                {22866, 2020, 3, 1, 1, 2, 42, 1, 1, 2, 2, 2},  // 53.23
                {20957, 2020, 3, 1, 1, 1, 43, 0, 1, 3, 1, 2}}; // 103.16

    eph_i ti = {{20957, 2020, 1,  1, 3, 1, 88, 0, 0, 90000, 10},
                {20957, 2020, 2,  1, 3, 2, 82, 0, 0, 25000, 10},
                {31117, 2020, 1,  0, 3, 1, 58, 1, 3, 22000, 1},
                {31117, 2020, 2,  0, 3, 2, 54, 1, 1, -1,    1},
                {31117, 2020, 3,  0, 3, 2, 46, 1, 3, 17000, 1},
                {31117, 2020, 4,  0, 3, 1, 20, 1, 3, 5000,  1},
                {31117, 2020, 5,  0, 3, 2, 15, 0, 0, 5000,  10},
                {31117, 2020, 6,  0, 3, 1, 7,  0, 0, 0,     10},
                {31117, 2020, 8,  0, 3, 2, 11, 0, 0, 0,     10},
                {31117, 2020, 9,  0, 3, 1, 50, 0, 2, 0,     10},
                {31117, 2020, 10, 0, 3, 1, 28, 1, 3, 5000,  1},
                {22866, 2020, 1,  0, 3, 1, 31, 1, 3, 59000, 10},
                {22866, 2020, 2,  1, 3, 2, 28, 1, 3, 0,     6},
                {22114, 2020, 1,  0, 3, 1, 18, 0, 0, 20000, 10}};

    vector<int> res = {4, 0, 0, 0};

    EXPECT_EQ(res, histogramaDeAnillosConcentricos(th, ti, centro, distancias));
}

TEST(histogramaDeAnillosConcentricosTEST, borde) {

    vector<int> distancias = {10, 20, 50, 100};

    pair<int, int> centro = {0, 0};
    eph_h th = {{22114, 2020, 3, 100, 1, 3, 41, 0, 1, 3, 1, 2},  // 1.4
                {31117, 2020, 3, 100, 1, 3, 40, 0, 1, 6, 6, 2},  // 5.8
                {22866, 2020, 3, 100, 1, 2, 42, 1, 1, 2, 2, 2},  // 53.23
                {20957, 2020, 3, 100, 1, 1, 43, 0, 1, 3, 1, 2}}; // 103.16

    eph_i ti = {{20957, 2020, 1,  1, 3, 1, 88, 0, 0, 90000, 10},
                {20957, 2020, 2,  1, 3, 2, 82, 0, 0, 25000, 10},
                {31117, 2020, 1,  0, 3, 1, 58, 1, 3, 22000, 1},
                {31117, 2020, 2,  0, 3, 2, 54, 1, 1, -1,    1},
                {31117, 2020, 3,  0, 3, 2, 46, 1, 3, 17000, 1},
                {31117, 2020, 4,  0, 3, 1, 20, 1, 3, 5000,  1},
                {31117, 2020, 5,  0, 3, 2, 15, 0, 0, 5000,  10},
                {31117, 2020, 6,  0, 3, 1, 7,  0, 0, 0,     10},
                {31117, 2020, 8,  0, 3, 2, 11, 0, 0, 0,     10},
                {31117, 2020, 9,  0, 3, 1, 50, 0, 2, 0,     10},
                {31117, 2020, 10, 0, 3, 1, 28, 1, 3, 5000,  1},
                {22866, 2020, 1,  0, 3, 1, 31, 1, 3, 59000, 10},
                {22866, 2020, 2,  1, 3, 2, 28, 1, 3, 0,     6},
                {22114, 2020, 1,  0, 3, 1, 18, 0, 0, 20000, 10}};

    vector<int> res = {0, 0, 0, 0};

    EXPECT_EQ(res, histogramaDeAnillosConcentricos(th, ti, centro, distancias));
}

TEST(histogramaDeAnillosConcentricosTEST, centro) {

    vector<int> distancias = {10, 20, 50, 100};

    pair<int, int> centro = {0, 0};
    eph_h th = {{22114, 2020, 3, 0, 0, 3, 41, 0, 1, 3, 1, 2},  // 1.4
                {31117, 2020, 3, 0, 0, 3, 40, 0, 1, 6, 6, 2},  // 5.8
                {22866, 2020, 3, 0, 0, 2, 42, 1, 1, 2, 2, 2},  // 53.23
                {20957, 2020, 3, 0, 0, 1, 43, 0, 1, 3, 1, 2}}; // 103.16

    eph_i ti = {{20957, 2020, 1,  1, 3, 1, 88, 0, 0, 90000, 10},
                {20957, 2020, 2,  1, 3, 2, 82, 0, 0, 25000, 10},
                {31117, 2020, 1,  0, 3, 1, 58, 1, 3, 22000, 1},
                {31117, 2020, 2,  0, 3, 2, 54, 1, 1, -1,    1},
                {31117, 2020, 3,  0, 3, 2, 46, 1, 3, 17000, 1},
                {31117, 2020, 4,  0, 3, 1, 20, 1, 3, 5000,  1},
                {31117, 2020, 5,  0, 3, 2, 15, 0, 0, 5000,  10},
                {31117, 2020, 6,  0, 3, 1, 7,  0, 0, 0,     10},
                {31117, 2020, 8,  0, 3, 2, 11, 0, 0, 0,     10},
                {31117, 2020, 9,  0, 3, 1, 50, 0, 2, 0,     10},
                {31117, 2020, 10, 0, 3, 1, 28, 1, 3, 5000,  1},
                {22866, 2020, 1,  0, 3, 1, 31, 1, 3, 59000, 10},
                {22866, 2020, 2,  1, 3, 2, 28, 1, 3, 0,     6},
                {22114, 2020, 1,  0, 3, 1, 18, 0, 0, 20000, 10}};

    vector<int> res = {0, 0, 0, 0};

    EXPECT_EQ(res, histogramaDeAnillosConcentricos(th, ti, centro, distancias));
}

TEST(histogramaDeAnillosConcentricosTEST, bordes) {

    vector<int> distancias = {10, 20, 50, 100};

    pair<int, int> centro = {0, 0};
    eph_h th = {{22114, 2020, 3, 0, 0,   3, 41, 0, 1, 3, 1, 2},  // 1.4
                {31117, 2020, 3, 1, 1,   3, 40, 0, 1, 6, 6, 2},  // 5.8
                {22866, 2020, 3, 0, 25,  2, 42, 1, 1, 2, 2, 2},  // 53.23
                {20957, 2020, 3, 0, 100, 1, 43, 0, 1, 3, 1, 2},
                {20958, 2020, 3, 1, 100, 1, 43, 0, 1, 3, 1, 2}}; // 103.16

    eph_i ti = {{20957, 2020, 1,  1, 3, 1, 88, 0, 0, 90000, 10},
                {20957, 2020, 2,  1, 3, 2, 82, 0, 0, 25000, 10},
                {31117, 2020, 1,  0, 3, 1, 58, 1, 3, 22000, 1},
                {31117, 2020, 2,  0, 3, 2, 54, 1, 1, -1,    1},
                {31117, 2020, 3,  0, 3, 2, 46, 1, 3, 17000, 1},
                {31117, 2020, 4,  0, 3, 1, 20, 1, 3, 5000,  1},
                {31117, 2020, 5,  0, 3, 2, 15, 0, 0, 5000,  10},
                {31117, 2020, 6,  0, 3, 1, 7,  0, 0, 0,     10},
                {31117, 2020, 8,  0, 3, 2, 11, 0, 0, 0,     10},
                {31117, 2020, 9,  0, 3, 1, 50, 0, 2, 0,     10},
                {31117, 2020, 10, 0, 3, 1, 28, 1, 3, 5000,  1},
                {22866, 2020, 1,  0, 3, 1, 31, 1, 3, 59000, 10},
                {22866, 2020, 2,  1, 3, 2, 28, 1, 3, 0,     6},
                {22114, 2020, 1,  0, 3, 1, 18, 0, 0, 20000, 10}};

    vector<int> res = {1, 0, 1, 1};

    EXPECT_EQ(res, histogramaDeAnillosConcentricos(th, ti, centro, distancias));
}

TEST(histogramaDeAnillosConcentricosTEST, limites) {

    vector<int> distancias = {10, 20, 50, 100};

    pair<int, int> centro = {0, 0};
    eph_h th = {{22114, 2020, 3, 0, 0,   3, 41, 0, 1, 3, 1, 2},  // 1.4
                {31117, 2020, 3, 1, 10,  3, 40, 0, 1, 6, 6, 2},
                {31157, 2020, 3, 0, 10,  3, 40, 0, 1, 6, 6, 2},  // 5.8
                {22866, 2020, 3, 1, 20,  2, 42, 1, 1, 2, 2, 2},  // 53.23
                {20957, 2020, 3, 1, 100, 1, 43, 0, 1, 3, 1, 2},
                {20157, 2020, 3, 0, 100, 1, 43, 0, 1, 3, 1, 2}}; // 103.16

    eph_i ti = {{20957, 2020, 1,  1, 3, 1, 88, 0, 0, 90000, 10},
                {20957, 2020, 2,  1, 3, 2, 82, 0, 0, 25000, 10},
                {31117, 2020, 1,  0, 3, 1, 58, 1, 3, 22000, 1},
                {31117, 2020, 2,  0, 3, 2, 54, 1, 1, -1,    1},
                {31117, 2020, 3,  0, 3, 2, 46, 1, 3, 17000, 1},
                {31117, 2020, 4,  0, 3, 1, 20, 1, 3, 5000,  1},
                {31117, 2020, 5,  0, 3, 2, 15, 0, 0, 5000,  10},
                {31117, 2020, 6,  0, 3, 1, 7,  0, 0, 0,     10},
                {31117, 2020, 8,  0, 3, 2, 11, 0, 0, 0,     10},
                {31117, 2020, 9,  0, 3, 1, 50, 0, 2, 0,     10},
                {31117, 2020, 10, 0, 3, 1, 28, 1, 3, 5000,  1},
                {22866, 2020, 1,  0, 3, 1, 31, 1, 3, 59000, 10},
                {22866, 2020, 2,  1, 3, 2, 28, 1, 3, 0,     6},
                {22114, 2020, 1,  0, 3, 1, 18, 0, 0, 20000, 10}};

    vector<int> res = {1, 1, 1, 1};

    EXPECT_EQ(res, histogramaDeAnillosConcentricos(th, ti, centro, distancias));
}

TEST(histogramaDeAnillosConcentricosTEST, centroDistintoDe0) {

    vector<int> distancias = {10, 20, 50, 100};

    pair<int, int> centro = {-2, 3};
    eph_h th = {
            {22114, 2020, 3, -2, 3,  3, 41, 0, 1, 3, 1, 2},  // 0
            {31117, 2020, 3, 0,  0,  3, 40, 0, 1, 6, 6, 2},  // 3,5
            {31157, 2020, 3, 1,  1,  3, 40, 0, 1, 6, 6, 2},  // 3,5
            {20167, 2020, 3, 18, 3,  1, 43, 0, 1, 3, 1, 2},  // 20
            {20867, 2020, 3, 18, 4,  1, 43, 0, 1, 3, 1, 2}, //20.4
            {27867, 2020, 3, -2, -7, 1, 43, 0, 1, 3, 1, 2}, //10
            {20767, 2020, 3, -1, -7, 1, 43, 0, 1, 3, 1, 2}}; //10.5

    eph_i ti = {{20957, 2020, 1,  1, 3, 1, 88, 0, 0, 90000, 10},
                {20957, 2020, 2,  1, 3, 2, 82, 0, 0, 25000, 10},
                {31117, 2020, 1,  0, 3, 1, 58, 1, 3, 22000, 1},
                {31117, 2020, 2,  0, 3, 2, 54, 1, 1, -1,    1},
                {31117, 2020, 3,  0, 3, 2, 46, 1, 3, 17000, 1},
                {31117, 2020, 4,  0, 3, 1, 20, 1, 3, 5000,  1},
                {31117, 2020, 5,  0, 3, 2, 15, 0, 0, 5000,  10},
                {31117, 2020, 6,  0, 3, 1, 7,  0, 0, 0,     10},
                {31117, 2020, 8,  0, 3, 2, 11, 0, 0, 0,     10},
                {31117, 2020, 9,  0, 3, 1, 50, 0, 2, 0,     10},
                {31117, 2020, 10, 0, 3, 1, 28, 1, 3, 5000,  1},
                {22866, 2020, 1,  0, 3, 1, 31, 1, 3, 59000, 10},
                {22866, 2020, 2,  1, 3, 2, 28, 1, 3, 0,     6},
                {22114, 2020, 1,  0, 3, 1, 18, 0, 0, 20000, 10}};

    vector<int> res = {3, 2, 1, 0};

    EXPECT_EQ(res, histogramaDeAnillosConcentricos(th, ti, centro, distancias));
}