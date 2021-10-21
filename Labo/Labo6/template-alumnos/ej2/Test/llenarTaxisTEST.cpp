#include "../llenarTaxis.h"
#include "gtest/gtest.h"

// llenarTaxis 1

TEST(llenarTaxis1, todasMismoValor) {
  int a = 4;
  int b = 4;
  int c = 4;

  int result = llenarTaxis1(a, b, c);

  EXPECT_EQ(result, 6);
}

TEST(llenarTaxis1, solosJuntos) {
  int a = 6; // 1 (1p+1p)
  int b = 4; // 2 (2p+2p)
  int c = 4; // 4 (3p+1p)

  int result = llenarTaxis1(a, b, c);

  EXPECT_EQ(result, 7);
}

TEST(llenarTaxis1, masSolosJuntos) {
  int a = 2; // -
  int b = 6; // 3 (2p+2p)
  int c = 5; // 2 (3p+1p) 3(3p)

  int result = llenarTaxis1(a, b, c);

  EXPECT_EQ(result, 8);
}

// TEST(llenarTaxis1, nombre) {
//   int a = numero;
//   int b = numero;
//   int c = numero;

//   int result = llenarTaxis1(a, b, c);

//   EXPECT_EQ(result, reslutadoEsperado);
// }

//--------------------------------------
//--------------------------------------
//--------------------------------------
//           LLENAR TAXIS 2

// ----------- Dominio 1 ---------------

TEST(llenarTaxis2, todasMismoValor2) {
  int a = 4;
  int b = 4;
  int c = 4;

  int result = llenarTaxis2(a, b, c);

  EXPECT_EQ(result, 6);
}

TEST(llenarTaxis2, todasMismoValorImpar) {
  int a = 7;
  int b = 7;
  int c = 7;

  int result = llenarTaxis2(a, b, c);

  EXPECT_EQ(result, 6);
}

TEST(llenarTaxis2, solosJuntos2) {
  int a = 6;
  int b = 4;
  int c = 4;

  int result = llenarTaxis2(a, b, c);

  EXPECT_EQ(result, 7);
}

TEST(llenarTaxis2, masSolosJuntos2) {
  int a = 2;
  int b = 6;
  int c = 5;

  int result = llenarTaxis2(a, b, c);

  EXPECT_EQ(result, 8);
}

// TEST(llenarTaxis2, nombre) {
//   int a = numero;
//   int b = numero;
//   int c = numero;

//   int result = llenarTaxis2(a, b, c);

//   EXPECT_EQ(result, reslutadoEsperado);
// }

//--------------------------------------
//--------------------------------------
//--------------------------------------
// llenarTaxis 3

TEST(llenarTaxis3, todasMismoValor2) {
  int a = 4;
  int b = 4;
  int c = 4;

  int result = llenarTaxis3(a, b, c);

  EXPECT_EQ(result, 6);
}

TEST(llenarTaxis3, solosJuntos3) {
  int a = 6; // 1 (1p+1p)
  int b = 4; // 2 (2p+2p)
  int c = 4; // 4 (3p+1p)

  int result = llenarTaxis3(a, b, c);

  EXPECT_EQ(result, 7);
}

TEST(llenarTaxis3, masSolosJuntos3) {
  int a = 2;
  int b = 6;
  int c = 5;

  int result = llenarTaxis3(a, b, c);

  EXPECT_EQ(result, 8);
}
