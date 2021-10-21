#include "../baldosasDelPiso.h"
#include "gtest/gtest.h"

// Escribir tests aca:

TEST(baldosasDelPiso, MyNdivisiblesB) {
  int M = 12;  // 4
  int N = 18;  // 6
  int B = 3;

  int baldosas = baldosasDelPiso(M, N, B);

  EXPECT_EQ(baldosas, 24);
}

TEST(baldosasDelPiso, soloMdivisibleB) {
  int M = 20;  // 4
  int N = 33;  // 7
  int B = 5;

  int baldosas = baldosasDelPiso(M, N, B);

  EXPECT_EQ(baldosas, 28);
}

TEST(baldosasDelPiso, soloNdivisibleB) {
  int M = 76;   // 7
  int N = 132;  // 11
  int B = 12;

  int baldosas = baldosasDelPiso(M, N, B);

  EXPECT_EQ(baldosas, 77);
}

TEST(baldosasDelPiso, NyMindivisiblesB) {
  int M = 76;   // 6
  int N = 132;  // 9
  int B = 15;

  int baldosas = baldosasDelPiso(M, N, B);

  EXPECT_EQ(baldosas, 54);
}