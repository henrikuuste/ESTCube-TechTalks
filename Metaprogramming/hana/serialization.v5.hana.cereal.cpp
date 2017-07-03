#include "cereal/archives/binary.hpp"
#include "cereal/archives/json.hpp"
#include "cereal/archives/xml.hpp"
#include "cereal/cereal.hpp"
#include "cereal/types/string.hpp"

#include <boost/hana.hpp>

#include <cstdint>
#include <iostream>
#include <string>
#include <type_traits>
#include <utility>
namespace hana = boost::hana;
using namespace std::literals;

template <class T> concept bool HanaStruct = hana::Struct<T>::value;

//! [cereal + hana]
namespace cereal {
constexpr auto &member_name = hana::first;
constexpr auto &member_val = hana::second;
template <typename Member> constexpr auto member_name_str(Member m) {
  return hana::to<char const *>(member_name(m));
}

template <typename Archive> void save(Archive &archive, const HanaStruct &src) {
  hana::for_each(src, [&archive](const auto &m) {
    archive(make_nvp(member_name_str(m), member_val(m)));
  });
}

template <typename Archive> void load(Archive &archive, HanaStruct &src) {
  hana::for_each(src, [&archive, &src](auto &&m) {
    archive(make_nvp(member_name_str(m), member_val(m)));
    hana::at_key(src, member_name(m)) = member_val(m);
  });
}
}
//! [cereal + hana]

//! [user code]
struct Foo {
  int int_member;
  float float_member;
  std::string name;
};
BOOST_HANA_ADAPT_STRUCT(Foo, int_member, float_member, name);

struct Bar {
  Foo foo_member;
  double double_member;
};
BOOST_HANA_ADAPT_STRUCT(Bar, foo_member, double_member);

struct Baz : public Bar {
  std::string baz_name;
};
BOOST_HANA_ADAPT_STRUCT(Baz, foo_member, double_member, baz_name);

int main() {
  Baz baz1;
  baz1.foo_member = {5, 10.5, "FooBar"};
  baz1.double_member = 1e-6;
  baz1.baz_name = "Not sure";

  std::ostringstream json_out;
  { //! [serialization]
    cereal::JSONOutputArchive jsonArchive(json_out);
    jsonArchive(CEREAL_NVP(baz1));
  } //! [serialization]

  std::cout << json_out.str();
}
//! [user code]