#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstdlib>

namespace poly {

template <typename T> struct Polynomial {
  T *coeficients;
  size_t degree;
};

template <typename T> Polynomial<T> create(const size_t &degree) {
  Polynomial<T> poly;
  poly.degree = degree;
  poly.coeficients = (T *)malloc(sizeof(T) * (degree + 1));
  return poly;
}

template <typename T> void destroy(Polynomial<T> &poly) {
  free(poly.coeficients);
}

template <typename T> void change_degree(Polynomial<T> &poly, size_t degree) {
  poly.degree = degree;
  poly.coeficients = (T *)realloc(poly.coeficients, sizeof(T) * (degree + 1));
}

template <typename T> void add(Polynomial<T> &a, const Polynomial<T> &b) {
  size_t new_degree = std::max(a.degree, b.degree);

  if (a.degree < b.degree) {
    change_degree(a, new_degree);
  }

  for (size_t i = 0; i <= a.degree; i++) {
    if (i <= b.degree) {
      a.coeficients[i] += b.coeficients[i];
    }
  }
}

template <typename T> void diff(Polynomial<T> &a, const Polynomial<T> &b) {
  size_t new_degree = std::max(a.degree, b.degree);

  if (a.degree < b.degree) {
    change_degree(a, new_degree);
  }

  for (size_t i = 0; i <= a.degree; i++) {
    if (i <= b.degree) {
      a.coeficients[i] -= b.coeficients[i];
    }
  }
}

template <typename T> void mul(Polynomial<T> &a, T lambda) {
  for (size_t i = 0; i <= a.degree; i++) {
    a.coeficients[i] *= lambda;
  }
}

template <typename T>
Polynomial<T> mul(const Polynomial<T> &a, const Polynomial<T> &b) {
  Polynomial<T> new_poly = create<T>(a.degree + b.degree);

  for (size_t n = 0; n <= new_poly.degree; n++) {
    size_t i_start = 0;
    if (n > b.degree)
      i_start = n - b.degree;

    new_poly.coeficients[n] = 0;
    for (size_t i = i_start; i <= std::min(n, a.degree); i++) {
      size_t j = n - i;
      new_poly.coeficients[n] += a.coeficients[i] * b.coeficients[j];
    }
  }

  return new_poly;
}

} // namespace poly
