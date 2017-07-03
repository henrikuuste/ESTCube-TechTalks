#include <iostream>

void foo(unsigned i) {
  std::cout << "unsigned " << i << "\n";
}

template <typename T>
typename T::value_type foo(const T& t) {
  std::cout << "template " << t << "\n";
  return t();
}

int main() {
  foo(42);
}