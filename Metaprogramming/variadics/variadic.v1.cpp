#include <iostream>

template <typename T> T adder(T v) { return v; }

template <typename T, typename... Args> T adder(T first, Args... args) {
  return first + adder(args...);
}

int main() {
  int i1 = -20;
  double d1 = 1e2;
  unsigned u1 = 10;
  float sum = adder(0.1, 2, 4.1, 5.5, i1, d1, u1);
  std::cout << sum << "\n";
}