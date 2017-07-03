#include <iostream>
#include <type_traits>

void foo(unsigned i) { std::cout << "unsigned " << i << "\n"; }

template <typename T>
std::enable_if_t<std::is_floating_point<T>::value, void> foo(T t) {
  std::cout << "template " << t << "\n";
}

int main() { foo(42); }