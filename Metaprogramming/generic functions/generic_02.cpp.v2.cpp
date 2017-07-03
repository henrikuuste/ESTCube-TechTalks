#include <iostream>
#include <limits>
#include <type_traits>
#include <typeinfo>

template <class L, class R> concept bool Comprable = requires(L a, R b) {
  { a < b }
  ->bool;
};

template <typename Left, typename Right>
requires Comprable<Left, Right> auto
custom_max(const Left &lhs, const Right &rhs) {
  using Type = std::common_type_t<Left, Right>;
  return static_cast<Type>((
      static_cast<const Type>(lhs) < static_cast<const Type>(rhs) ? rhs : lhs));
}

template <class T> void TD(const T &v) {
  std::cout << __PRETTY_FUNCTION__ << " = " << v << "\n";
}

int main() {
  int int_val = 500;

  long long long_val = std::numeric_limits<long long>::max();
  auto c1 = custom_max(int_val, long_val);
  TD(c1);

  unsigned long ulong_val = 2000;
  auto c2 = custom_max(int_val, ulong_val);
  TD(c2);

  long double ld_val = 1.5;
  auto c3 = custom_max(int_val, ld_val);
  TD(c3);
}