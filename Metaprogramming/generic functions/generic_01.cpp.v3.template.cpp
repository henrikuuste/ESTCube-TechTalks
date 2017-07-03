#include <cstdint>
#include <iomanip>
#include <iostream>
#include <type_traits>

#include "../generic classes/mymatrix.v1.hpp"

using namespace std;

template <typename T> T func(T val) {
  static_assert(is_arithmetic<T>::value,
                "func() used with non-arithmetic type");
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

  // void *bad_stuff = &i;
  // cout << hex << "func(" << bad_stuff << ") = " << func(bad_stuff) << "\n";

  // MyMatrix cool_stuff{{{1, 5.5}, {-5.5, 1}}};
  // cout << "func(" << cool_stuff << ") = " << "???" << "\n";
  // cout << "func(" << cool_stuff << ") = " << func(cool_stuff) << "\n";
}