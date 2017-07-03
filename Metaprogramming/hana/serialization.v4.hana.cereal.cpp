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

//! [cereal + hana]
namespace cereal {
template <typename Archive, typename T,
          typename std::enable_if<hana::Struct<T>::value>::type * = nullptr>
void save(Archive &archive, T const &src) {
  hana::for_each(src, [&archive](const auto &x) {
    archive(cereal::make_nvp(hana::to<char const *>(hana::first(x)),
                             hana::second(x)));
  });
}

template <typename Archive, typename T,
          typename std::enable_if<hana::Struct<T>::value>::type * = nullptr>
void load(Archive &archive, T &src) {
  hana::for_each(src, [&archive, &src](auto &&x) {
    archive(cereal::make_nvp(hana::to<char const *>(hana::first(x)),
                             hana::second(x)));
    hana::at_key(src, hana::first(x)) = hana::second(x);
  });
}
}
//! [cereal + hana]

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
  BOOST_HANA_DEFINE_STRUCT(   //
      Bar,                    //
      (Foo, foo_member),      //
      (double, double_member) //
      );
};

int main() {
  Bar bar1{{5, 10.5, "FooBar"}, 1e-6};

  std::ostringstream json_out;
  { //! [serialization]
    cereal::JSONOutputArchive jsonArchive(json_out);
    jsonArchive(CEREAL_NVP(bar1));
  } //! [serialization]

  std::cout << json_out.str();

  { //! [deserialization]
    std::stringstream in_data;
    in_data << json_out.str();

    cereal::JSONInputArchive jsonArchive(in_data);

    Bar bar_test;
    jsonArchive(bar_test);
    std::cout << "\nGot name: " << bar_test.foo_member.name;
  } //! [deserialization]
}
//! [user code]