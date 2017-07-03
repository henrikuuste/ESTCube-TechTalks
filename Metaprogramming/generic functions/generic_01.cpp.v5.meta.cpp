#include <cstdint>
#include <iomanip>
#include <iostream>
#include "../helpers/meta_base.hpp"
#include "../generic classes/mymatrix.v1.hpp"

using namespace std;

template <class T, class = void> struct is_usable_in_func : false_type {};
template <class T>
struct is_usable_in_func<
    T, void_t<decltype(std::declval<T>() + std::declval<int>())>> // NOTE: This is all we REALLY wanted to know
    : std::true_type {};

template <typename T> T func(T val) {
  static_assert(is_usable_in_func<T>::value,
                "func() used with A VERY BAD type");
  return val + 10;
}

int main() {
  int i = 10;
  cout << "func(" << i << ") = " << func(i) << "\n";
  float f = 5.5;
  cout << "func(" << f << ") = " << func(f) << "\n";
  double d = 1.25;
  streamsize ss = cout.precision();
  cout << scientific << setprecision(3);
  cout << "func(" << d << ") = " << func(d) << "\n";
  cout << defaultfloat << setprecision(ss);

  // void* bad_stuff = &i;
  // cout << hex << "func(" << bad_stuff << ") = " << func(bad_stuff) << "\n";

  MyMatrix cool_stuff{{{1, 5.5}, {-5.5, 1}}};
  cout << "func(" << cool_stuff << ") =" << func(cool_stuff) << "\n";
}