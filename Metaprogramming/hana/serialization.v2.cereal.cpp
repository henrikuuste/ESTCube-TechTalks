#include "cereal/cereal.hpp"
#include "cereal/archives/binary.hpp"
#include "cereal/archives/json.hpp"
#include "cereal/archives/xml.hpp"
#include "cereal/types/string.hpp"
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>

struct Foo {
  int int_member;
  float float_member;
  std::string name;

  template <class Archive> void serialize(Archive &archive) {
    archive(CEREAL_NVP(int_member), CEREAL_NVP(float_member), CEREAL_NVP(name));
  }
};

struct Bar {
  Foo foo_member;
  double double_member;

  template <class Archive> void serialize(Archive &archive) {
    archive(cereal::make_nvp("myFoo", foo_member), CEREAL_NVP(double_member));
  }
};

using namespace std;

int main() {
  Bar bar1{{5, 10.5, "FooBar"}, 1e-6};

  ostringstream json_out;
  ostringstream bin_out;
  ostringstream xml_out;

  {
    cereal::JSONOutputArchive jsonArchive(json_out);
    cereal::BinaryOutputArchive binArchive(bin_out);
    cereal::XMLOutputArchive xmlArchive(xml_out);
  
    xmlArchive(CEREAL_NVP(bar1));
    jsonArchive(CEREAL_NVP(bar1));
    binArchive(CEREAL_NVP(bar1));
  }

  cout << xml_out.str();
  cout << json_out.str();
  cout << bin_out.str();

  {
    std::stringstream in_data;
    in_data << bin_out.str();

    cereal::BinaryInputArchive binArchive(in_data);

    Bar bar_test;
    binArchive(bar_test);
    cout << "\nGot name: " << bar_test.foo_member.name;
  }
}