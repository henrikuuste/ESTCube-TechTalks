#include "boost/hana.hpp"

#include <cstdint>
#include <iostream>
#include <string>
#include <type_traits>
#include <utility>
namespace hana = boost::hana;

//! [cross-cutting logging]
template <class T> concept bool WithLogString = requires (T a) { a.logString(); };

void log(const WithLogString &d) {
  std::cout << "STATUS: " << d.logString() << "\n";
}
//! [cross-cutting logging]

//! [user data structures]
// log to stdout
struct MyData1 {
  int x;
  std::string logString() const { return "MyData1[" + std::to_string(x) + "]"; }
};

// log to stdout
struct MyData2 {
  std::string y;
  std::string logString() const { return "MyData3[" + y + "]"; }
};

// log to stderr
struct MyData3 {
  double z;
  std::string logString() const { return "MyData3[" + std::to_string(z) + "]"; }
};
//! [user data structures]

//! [logging override]
template<> void log(const MyData3& d) {
  std::cerr << "ERROR: " << d.logString() << "\n";
}
//! [logging override]

//! [user code]
int main() {
  MyData1 d1{10};
  MyData2 d2{"Foo"};
  MyData3 d3{1e-6};

  log(d1);
  log(d2);
  log(d3);
}
//! [user code]