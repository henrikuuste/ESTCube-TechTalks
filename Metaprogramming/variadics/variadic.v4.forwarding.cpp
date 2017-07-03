#include <iostream>
#include <map>
#include <string>
#include <typeinfo>

namespace helpers {
  struct Data {
    Data() { std::cout << "::: ctor\n"; };
    Data(Data const &) { std::cout << "::: copy\n"; };
    Data(Data &&) { std::cout << "::: move\n"; };
    ~Data() { std::cout << "::: dtor\n"; }
  };

  std::ostream &operator<<(std::ostream &out, const Data &d) {
    return out << "Data object " << &d;
  }

  std::map<ptrdiff_t, std::string> lookup;
  struct pass {
    template <typename... T> pass(T...) {}
  };

  template <typename T> void print_arg(size_t N, size_t &i, const T &arg) {
    std::cout << arg << (++i < N ? ", " : "");
  }
}

using namespace helpers;
//! [cross-cutting logger]
template <typename Function, typename... Args>
auto log_wrapper(Function f, Args &&... args) {
  std::cout << "Calling " << lookup[(ptrdiff_t)f] << "(";
  auto nargs = sizeof...(args);
  size_t i = 0;
  pass{(print_arg(nargs, i, args), 1)...};
  std::cout << ")\n";
  return f(std::forward<Args>(args)...);
}
//! [cross-cutting logger]

//! [user code]
void foo(int i, int y) { std::cout << "foo [" << i << ", " << y << "]\n"; }
double bar(double d) { return d * d; }
std::string baz(std::string s) { return "Doing " + s; }
void foobar(const Data &d) {
  std::cout << "This data[" << &d << "] is foobar\n";
}

int main() {
  lookup[(ptrdiff_t)&foo] = "foo";
  lookup[(ptrdiff_t)&bar] = "bar";
  lookup[(ptrdiff_t)&baz] = "baz";
  lookup[(ptrdiff_t)&foobar] = "foobar";

  log_wrapper(foo, 2, 10);
  std::cout << "bar " << log_wrapper(bar, 5.2f) << "\n";
  std::cout << "baz " << log_wrapper(baz, "metaprogramming") << "\n";
  log_wrapper(foobar, Data());
}
//! [user code]