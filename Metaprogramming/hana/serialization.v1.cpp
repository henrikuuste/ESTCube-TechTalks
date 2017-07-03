#include <iostream>
#include <string>

struct Foo {
  int int_member;
  float float_member;
  std::string name;
};

std::ostream &operator<<(std::ostream &os, const Foo &rhs) {
  os << "{";
  os << " \"int_member\": " << rhs.int_member << ",";
  os << " \"float_member\": " << rhs.float_member << ",";
  os << " \"name\": \"" << rhs.name << "\"";
  os << "}";
  return os;
}

struct Bar {
  Foo foo_member;
  double double_member;
};

std::ostream &operator<<(std::ostream &os, const Bar &rhs) {
  os << "{";
  os << " \"myFoo\": " << rhs.foo_member << ",";
  os << " \"double_member\": " << rhs.double_member;
  os << "}";
  return os;
}

int main() {
   Bar bar1{{5, 10.5, "FooBar"}, 1e-6};

   std::cout << bar1;
}