#include "../electores.h"
#include "gtest/gtest.h"

// -- TEST Suite Caja Negra

TEST(validarVotante, fechaInvalida) {
  int d = 23;
  int m = 10;
  int a = 2021;

  int res = validarVotante(a, m, d);

  EXPECT_EQ(res, 4);
}

TEST(validarVotante, fechaInvalida1) {
  int d = 1;
  int m = 1;
  int a = 2030;

  int res = validarVotante(a, m, d);

  EXPECT_EQ(res, 4);
}

TEST(validarVotante, recienNacido) {
  int d = 22;
  int m = 10;
  int a = 2021;

  int res = validarVotante(a, m, d);

  EXPECT_EQ(res, 0);
}

TEST(validarVotante, cumple16alDiaSiguente) {
  int d = 23;
  int m = 10;
  int a = 2005;

  int res = validarVotante(a, m, d);

  EXPECT_EQ(res, 0);
}

TEST(validarVotante, cumple16elMismoDia) {
  int d = 22;
  int m = 10;
  int a = 2005;

  int res = validarVotante(a, m, d);

  EXPECT_EQ(res, 1);
}

TEST(validarVotante, cumple18alDiaSiguente) {
  int d = 23;
  int m = 10;
  int a = 2003;

  int res = validarVotante(a, m, d);

  EXPECT_EQ(res, 1);
}

TEST(validarVotante, cumple18elMismoDia) {
  int d = 22;
  int m = 10;
  int a = 2003;

  int res = validarVotante(a, m, d);

  EXPECT_EQ(res, 2);
}

TEST(validarVotante, mayorDeEdad) {
  int d = 9;
  int m = 4;
  int a = 1990;

  int res = validarVotante(a, m, d);

  EXPECT_EQ(res, 2);
}

TEST(validarVotante, cumple70ElMismoDia) {
  int d = 22;
  int m = 10;
  int a = 1951;

  int res = validarVotante(a, m, d);

  EXPECT_EQ(res, 3);
}

TEST(validarVotante, cumple70AlDiaSiguiente) {
  int d = 23;
  int m = 10;
  int a = 1951;

  int res = validarVotante(a, m, d);

  EXPECT_EQ(res, 2);
}

TEST(validarVotante, mayorDe70) {
  int d = 12;
  int m = 31;
  int a = 1940;

  int res = validarVotante(a, m, d);

  EXPECT_EQ(res, 3);
}
