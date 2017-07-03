#include <cstdint>
#include <iostream>

constexpr uint32_t factorial_fun(uint32_t n) {
  return (n == 0) ? 1 : (n * factorial_fun(n - 1));
}

template <unsigned int n> struct factorial {
  enum { value = n * factorial<n - 1>::value };
};

template <> struct factorial<0> {
  enum { value = 1 };
};


constexpr uint32_t f4 = factorial_fun(4);

int main() {
  std::cout << f4 << "\n";
  std::cout << factorial<4>::value;
}