#include "boost/hana.hpp"

#include <cstdint>
#include <iostream>
#include <string>
#include <type_traits>
#include <utility>
namespace hana = boost::hana;

//! [cross-cutting logging]
template <class T> concept bool WithLogString = requires(T a) { a.logString(); };
struct info_data;
struct error_data;

namespace detail {
template <typename Tag> struct log_impl {
  static void apply(const WithLogString &d) {
    std::cout << "STATUS: " << d.logString() << "\n";
  }
};

template <> struct log_impl<error_data> {
  static void apply(const WithLogString &d) {
    std::cerr << "ERROR: " << d.logString() << "\n";
  }
};
}

void log(const WithLogString &d) {
  using Tag = typename hana::tag_of<decltype(d)>::type;
  detail::log_impl<Tag>::apply(d);
}

//! [cross-cutting logging]

//! [user data structures]
struct MyData1 {
  using hana_tag = info_data;
  int x;
  std::string logString() const { return "MyData1[" + std::to_string(x) + "]"; }
};

struct MyData2 {
  using hana_tag = info_data;
  std::string y;
  std::string logString() const { return "MyData3[" + y + "]"; }
};

struct MyData3 {
  using hana_tag = error_data;
  double z;
  std::string logString() const { return "MyData3[" + std::to_string(z) + "]"; }
};

struct MyException {
  using hana_tag = error_data;
  uint32_t code;
  std::string logString() const { return "Exception[" + std::to_string(code) + "]"; }
};
//! [user data structures]

//! [user code]
int main() {
  MyData1 d1{10};
  MyData2 d2{"Foo"};
  MyData3 d3{1e-6};

  log(d1);
  log(d2);
  log(d3);

  MyException e{101};
  log(e);
}
//! [user code]