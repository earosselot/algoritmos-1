#include "../puntaje.h"
#include "gtest/gtest.h"

// Escribir tests aca:
TEST(puntajeTest, menor10Divisible3)  {
  //setup
  int b = 3;
  // exercise
  int result = puntaje(b);
  // check
  EXPECT_EQ(result, 16);
}

TEST(puntajeTest, menor10NoDivisible3) {
  //setup
  int b = 1;
  // exercise
  int result = puntaje(b);
  // check
  EXPECT_EQ(result, -8);
}

TEST(puntajeTest, mayor10Divisible3) {
  //setup
  int b = 12;
  // exercise
  int result = puntaje(b);
  // check
  EXPECT_EQ(result, 22);
}

TEST(puntajeTest, mayor10NoDivisible3) {
  //setup
  int b = 16;
  // exercise
  int result = puntaje(b);
  // check
  EXPECT_EQ(result, 6);
}
