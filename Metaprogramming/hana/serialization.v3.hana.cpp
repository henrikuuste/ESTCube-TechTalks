#include <boost/hana.hpp>

#include <cstdint>
#include <iostream>
#include <string>
#include <type_traits>
#include <utility>
namespace hana = boost::hana;
using namespace std::literals;

//! [utilities]
template <typename Xs>
std::string join(Xs&& xs, std::string sep) {
  return hana::fold(hana::intersperse(std::forward<Xs>(xs), sep), "", hana::_ + hana::_);
}

std::string quote(std::string s) { return "\"" + s + "\""; }

template <typename T>
auto to_json(T const& x) -> decltype(std::to_string(x)) {
  return std::to_string(x);
}

std::string to_json(char c) { return quote({c}); }
std::string to_json(std::string s) { return quote(s); }
//! [utilities]

//! [Struct]
template <typename T>
  std::enable_if_t<hana::Struct<T>::value,
std::string> to_json(T const& x) {
  auto json = hana::transform(hana::keys(x), [&](auto name) {
    auto const& member = hana::at_key(x, name);
    return quote(hana::to<char const*>(name)) + " : " + to_json(member);
  });

  return "{" + join(std::move(json), ", ") + "}";
}
//! [Struct]

//! [Sequence]
template <typename Xs>
  std::enable_if_t<hana::Sequence<Xs>::value,
std::string> to_json(Xs const& xs) {
  auto json = hana::transform(xs, [](auto const& x) {
    return to_json(x);
  });

  return "[" + join(std::move(json), ", ") + "]";
}
//! [Sequence]

//! [user code]
struct Foo {
  BOOST_HANA_DEFINE_STRUCT(  //
      Foo,                   //
      (int, int_member),     //
      (float, float_member), //
      (std::string, name)    //
  );
};

struct Bar {
  BOOST_HANA_DEFINE_STRUCT( //
    Bar, //
    (Foo, foo_member), //
    (double, double_member) //
  );
};


int main() {
  Bar bar1{{5, 10.5, "FooBar"}, 1e-6};

  std::cout << to_json(bar1);
}
//! [user code]