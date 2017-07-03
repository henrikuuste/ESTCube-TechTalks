#include <iostream>

template <typename T, typename V> auto accum(T &accu, V &val) {
  return accu += val;
}

struct pass {
  template <typename... T> pass(T...) {}
};

template <typename... Args> double adder(Args... args) {
  double accu = 0;
  pass{accum(accu, args)...};
  return accu;
}

int main() {
  int i1 = -20;
  double d1 = 1e2;
  unsigned u1 = 10;
  float sum = adder(0.1, 2, 4.1, 5.5, i1, d1, u1);
  std::cout << sum << "\n";
}