#include "poly.hpp"
#include <iostream>
#include <string>

typedef poly::Polynomial<double> Polynomial;

void print_poly(const Polynomial &poly) {
  for (int n = poly.degree; n >= 0; n--) {
    std::cout << poly.coeficients[n] << " ";
  }
}

void operation_add(Polynomial &a, Polynomial &b) {
  poly::add(a, b);
  print_poly(a);
}

void operation_diff(Polynomial &a, Polynomial &b) {
  poly::diff(a, b);
  print_poly(a);
}

void operation_mul(Polynomial &a, Polynomial &b) {
  Polynomial poly = poly::mul(a, b);
  print_poly(poly);
  poly::destroy(poly);
}

Polynomial enter_poly(const char *name) {
  size_t degree;
  std::cout << "Degree " << name << ": ";
  std::cin >> degree;

  poly::Polynomial<double> poly = poly::create<double>(degree);

  std::cout << "Coefficients (from x^n to 1): ";
  for (int n = poly.degree; n >= 0; n--) {
    std::cin >> poly.coeficients[n];
  }

  return poly;
}

int main(int arc, const char *argv[]) {
  Polynomial a = enter_poly("A");
  Polynomial b = enter_poly("B");

  int operation;
  std::cout << "Operation (1 - add, 2 - diff, 3 - mul): ";
  std::cin >> operation;

  switch (operation) {
  case 1:
    operation_add(a, b);
    break;
  case 2:
    operation_diff(a, b);
    break;
  case 3:
    operation_mul(a, b);
    break;
  }

  poly::destroy(a);
  poly::destroy(b);
  return 0;
}
