#include <iostream>
#include <limits>
#include <type_traits>
#include <typeinfo>

template <class L, class R> concept bool Comprable = requires(L a, R b) {
  { a < b }
  ->bool;
};

template <typename Left, typename Right>
requires Comprable<Left, Right>
    Left custom_max(const Left &lhs, const Right &rhs) {
  return (lhs < rhs ? rhs : lhs);
}

template <class T> void TD(const T &v) {
  std::cout << __PRETTY_FUNCTION__ << " = " << v << "\n";
}

int main() {
  int int_val = 500;
  long long long_val = std::numeric_limits<long long>::max();
  unsigned long ulong_val = 2000;

  auto c1 = custom_max(int_val, long_val);
  TD(c1);

  auto c2 = custom_max(int_val, ulong_val);
  TD(c2);
}