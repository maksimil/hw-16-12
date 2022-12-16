#include "poly.hpp"
#include <gtest/gtest.h>

TEST(MulConst, Degree3int) {
  poly::Polynomial<int> p = poly::create<int>(3);

  p.coeficients[0] = 1;
  p.coeficients[1] = 0;
  p.coeficients[2] = -1;
  p.coeficients[3] = 3;

  int c = 2;

  poly::mul(p, c);

  ASSERT_EQ(p.coeficients[0], 2);
  ASSERT_EQ(p.coeficients[1], 0);
  ASSERT_EQ(p.coeficients[2], -2);
  ASSERT_EQ(p.coeficients[3], 6);

  poly::destroy(p);
}

TEST(MulConst, Degree3double) {
  poly::Polynomial<double> p = poly::create<double>(3);

  p.coeficients[0] = 1.0;
  p.coeficients[1] = 0.0;
  p.coeficients[2] = -0.1;
  p.coeficients[3] = 0.0;

  double c = 2.5;

  poly::mul(p, c);

  ASSERT_DOUBLE_EQ(p.coeficients[0], 2.5);
  ASSERT_DOUBLE_EQ(p.coeficients[1], 0.0);
  ASSERT_DOUBLE_EQ(p.coeficients[2], -0.25);
  ASSERT_DOUBLE_EQ(p.coeficients[3], 0.0);

  poly::destroy(p);
}

TEST(MulConst, Degree1int) {
  poly::Polynomial<int> p = poly::create<int>(1);

  p.coeficients[0] = 1;
  p.coeficients[1] = -1;

  int c = -2;

  poly::mul(p, c);

  ASSERT_EQ(p.coeficients[0], -2);
  ASSERT_EQ(p.coeficients[1], 2);

  poly::destroy(p);
}

TEST(MulConst, Degree1double) {
  poly::Polynomial<double> p = poly::create<double>(1);

  p.coeficients[0] = 1.0;
  p.coeficients[1] = -1000.0001;

  ASSERT_DOUBLE_EQ(p.coeficients[0], 1.0);
  ASSERT_DOUBLE_EQ(p.coeficients[1], -1000.0001);

  double c = 0;

  poly::mul(p, c);

  ASSERT_DOUBLE_EQ(p.coeficients[0], 0.0);
  ASSERT_DOUBLE_EQ(p.coeficients[1], 0.0);

  poly::destroy(p);
}

TEST(MulConst, Degree0int) {
  poly::Polynomial<int> p = poly::create<int>(0);

  p.coeficients[0] = 1;

  int c = 1;

  poly::mul(p, c);

  ASSERT_EQ(p.coeficients[0], 1);

  poly::destroy(p);
}

TEST(MulConst, Degree0double) {
  poly::Polynomial<double> p = poly::create<double>(0);

  p.coeficients[0] = 1.0;

  double c = 1;

  poly::mul(p, c);

  ASSERT_DOUBLE_EQ(p.coeficients[0], 1.0);

  poly::destroy(p);
}
