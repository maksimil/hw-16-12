#include "poly.hpp"
#include <gtest/gtest.h>

TEST(Mul, Degree2_2int) {
  poly::Polynomial<int> a = poly::create<int>(2);

  a.coeficients[0] = 1;
  a.coeficients[1] = 0;
  a.coeficients[2] = -1;

  poly::Polynomial<int> b = poly::create<int>(2);

  b.coeficients[0] = -2;
  b.coeficients[1] = 0;
  b.coeficients[2] = 10;

  poly::Polynomial<int> p = poly::mul(a, b);

  ASSERT_EQ(p.degree, 4);
  ASSERT_EQ(p.coeficients[0], -2);
  ASSERT_EQ(p.coeficients[1], 0);
  ASSERT_EQ(p.coeficients[2], 12);
  ASSERT_EQ(p.coeficients[3], 0);
  ASSERT_EQ(p.coeficients[4], -10);

  poly::destroy(a);
  poly::destroy(b);
  poly::destroy(p);
}

TEST(Mul, Degree2_2double) {
  poly::Polynomial<double> a = poly::create<double>(2);

  a.coeficients[0] = 1.5;
  a.coeficients[1] = 2.1;
  a.coeficients[2] = -1.2;

  poly::Polynomial<double> b = poly::create<double>(2);

  b.coeficients[0] = -2.0;
  b.coeficients[1] = -1.1;
  b.coeficients[2] = 10.0;

  poly::Polynomial<double> p = poly::mul(a, b);

  ASSERT_EQ(p.degree, 4);
  ASSERT_DOUBLE_EQ(p.coeficients[0], -3.0);
  ASSERT_DOUBLE_EQ(p.coeficients[1], -5.85);
  ASSERT_DOUBLE_EQ(p.coeficients[2], 15.09);
  ASSERT_DOUBLE_EQ(p.coeficients[3], 22.32);
  ASSERT_DOUBLE_EQ(p.coeficients[4], -12.0);

  poly::destroy(a);
  poly::destroy(b);
  poly::destroy(p);
}

TEST(Mul, Degree2_1int) {
  poly::Polynomial<int> a = poly::create<int>(2);

  a.coeficients[0] = 1;
  a.coeficients[1] = 0;
  a.coeficients[2] = -1;

  poly::Polynomial<int> b = poly::create<int>(1);

  b.coeficients[0] = -2;
  b.coeficients[1] = 1;

  poly::Polynomial<int> p = poly::mul(a, b);

  ASSERT_EQ(p.degree, 3);
  ASSERT_EQ(p.coeficients[0], -2);
  ASSERT_EQ(p.coeficients[1], 1);
  ASSERT_EQ(p.coeficients[2], 2);
  ASSERT_EQ(p.coeficients[3], -1);

  poly::destroy(a);
  poly::destroy(b);
  poly::destroy(p);
}

TEST(Mul, Degree1_2double) {
  poly::Polynomial<double> a = poly::create<double>(1);

  a.coeficients[0] = 1.5;
  a.coeficients[1] = 2.1;

  poly::Polynomial<double> b = poly::create<double>(2);

  b.coeficients[0] = -2.0;
  b.coeficients[1] = -1.1;
  b.coeficients[2] = 10.0;

  poly::Polynomial<double> p = poly::mul(a, b);

  ASSERT_EQ(p.degree, 3);
  ASSERT_DOUBLE_EQ(p.coeficients[0], -3.0);
  ASSERT_DOUBLE_EQ(p.coeficients[1], -5.85);
  ASSERT_DOUBLE_EQ(p.coeficients[2], 12.69);
  ASSERT_DOUBLE_EQ(p.coeficients[3], 21.0);

  poly::destroy(a);
  poly::destroy(b);
  poly::destroy(p);
}
