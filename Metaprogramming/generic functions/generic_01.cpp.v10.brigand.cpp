#define BRIGAND_NO_BOOST_SUPPORT
#include "../libs/brigand/standalone/brigand.hpp"

#include "../generic classes/mymatrix.v1.hpp"
#include "../helpers/meta_base.hpp"
#include <cstdint>
#include <iomanip>
#include <iostream>

using namespace std;

template <typename T> auto func(T val) {
  using allowed_types = brigand::set<int, float, double, MyMatrix>;
  static_assert(brigand::contains<allowed_types, T>::value, "Type not allowed");
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