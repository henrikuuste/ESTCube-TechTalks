#include "boost/hana.hpp"

#include <iostream>
#include <string>
#include <type_traits>
#include <utility>
#include <typeinfo>
namespace hana = boost::hana;

template <class T> concept bool HanaStruct = hana::Struct<T>::value;

void view(const HanaStruct &x) {
  std::cout << typeid(x).name() << "\n";
  hana::for_each(hana::keys(x), [&](auto name) {
    std::cout << "  " << hana::to<char const *>(name) << " : "
              << hana::at_key(x, name) << "\n";
  });
}

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
  char char_member;
  bool bool_member;
};
BOOST_HANA_ADAPT_STRUCT(Bar, char_member, bool_member);

int main() {
  std::cout << std::boolalpha;

  Foo foo1{5, 10.5, "FooBar"};
  view(foo1);
  view(Bar{'a', true});
}
//! [user code]