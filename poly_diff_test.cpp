#include "poly.hpp"
#include <gtest/gtest.h>

TEST(Diff, Degree3_3int) {
  poly::Polynomial<int> a = poly::create<int>(3);

  a.coeficients[0] = 1;
  a.coeficients[1] = 0;
  a.coeficients[2] = -1;
  a.coeficients[3] = 3;

  poly::Polynomial<int> b = poly::create<int>(3);

  b.coeficients[0] = 2;
  b.coeficients[1] = 2;
  b.coeficients[2] = -10;
  b.coeficients[3] = 10;

  poly::diff(a, b);

  ASSERT_EQ(a.coeficients[0], -1);
  ASSERT_EQ(a.coeficients[1], -2);
  ASSERT_EQ(a.coeficients[2], 9);
  ASSERT_EQ(a.coeficients[3], -7);

  poly::destroy(a);
  poly::destroy(b);
}

TEST(Diff, Degree3_3double) {
  poly::Polynomial<double> a = poly::create<double>(3);

  a.coeficients[0] = 1.0;
  a.coeficients[1] = 0.2;
  a.coeficients[2] = -1.4;
  a.coeficients[3] = 3.34;

  poly::Polynomial<double> b = poly::create<double>(3);

  b.coeficients[0] = 2.4;
  b.coeficients[1] = 2.2;
  b.coeficients[2] = -10.2;
  b.coeficients[3] = 10.1;

  poly::diff(a, b);

  ASSERT_DOUBLE_EQ(a.coeficients[0], -1.4);
  ASSERT_DOUBLE_EQ(a.coeficients[1], -2.0);
  ASSERT_DOUBLE_EQ(a.coeficients[2], 8.8);
  ASSERT_DOUBLE_EQ(a.coeficients[3], -6.76);

  poly::destroy(a);
  poly::destroy(b);
}

TEST(Diff, Degree3_1int) {
  poly::Polynomial<int> a = poly::create<int>(3);

  a.coeficients[0] = 1;
  a.coeficients[1] = 0;
  a.coeficients[2] = -1;
  a.coeficients[3] = 3;

  poly::Polynomial<int> b = poly::create<int>(1);

  b.coeficients[0] = 2;
  b.coeficients[1] = 2;

  poly::diff(a, b);

  ASSERT_EQ(a.coeficients[0], -1);
  ASSERT_EQ(a.coeficients[1], -2);
  ASSERT_EQ(a.coeficients[2], -1);
  ASSERT_EQ(a.coeficients[3], 3);

  poly::destroy(a);
  poly::destroy(b);
}

TEST(Diff, Degree3_1double) {
  poly::Polynomial<double> a = poly::create<double>(3);

  a.coeficients[0] = 1.0;
  a.coeficients[1] = 0.2;
  a.coeficients[2] = -1.4;
  a.coeficients[3] = 3.34;

  poly::Polynomial<double> b = poly::create<double>(1);

  b.coeficients[0] = 2.4;
  b.coeficients[1] = 2.2;

  poly::diff(a, b);

  ASSERT_DOUBLE_EQ(a.coeficients[0], -1.4);
  ASSERT_DOUBLE_EQ(a.coeficients[1], -2.0);
  ASSERT_DOUBLE_EQ(a.coeficients[2], -1.4);
  ASSERT_DOUBLE_EQ(a.coeficients[3], 3.34);

  poly::destroy(a);
  poly::destroy(b);
}

TEST(Diff, Degree1_3int) {
  poly::Polynomial<int> a = poly::create<int>(1);

  a.coeficients[0] = 1;
  a.coeficients[1] = 0;

  poly::Polynomial<int> b = poly::create<int>(3);

  b.coeficients[0] = 2;
  b.coeficients[1] = 2;
  b.coeficients[2] = -10;
  b.coeficients[3] = 10;

  poly::diff(a, b);

  ASSERT_EQ(a.coeficients[0], -1);
  ASSERT_EQ(a.coeficients[1], -2);
  ASSERT_EQ(a.coeficients[2], 10);
  ASSERT_EQ(a.coeficients[3], -10);

  poly::destroy(a);
  poly::destroy(b);
}

TEST(Diff, Degree1_3double) {
  poly::Polynomial<double> a = poly::create<double>(1);

  a.coeficients[0] = 1.0;
  a.coeficients[1] = 0.2;

  poly::Polynomial<double> b = poly::create<double>(3);

  b.coeficients[0] = 2.4;
  b.coeficients[1] = 2.2;
  b.coeficients[2] = -10.2;
  b.coeficients[3] = 10.1;

  poly::diff(a, b);

  ASSERT_DOUBLE_EQ(a.coeficients[0], -1.4);
  ASSERT_DOUBLE_EQ(a.coeficients[1], -2.0);
  ASSERT_DOUBLE_EQ(a.coeficients[2], 10.2);
  ASSERT_DOUBLE_EQ(a.coeficients[3], -10.1);

  poly::destroy(a);
  poly::destroy(b);
}
