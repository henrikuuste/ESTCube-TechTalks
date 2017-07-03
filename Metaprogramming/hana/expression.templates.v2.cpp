#include <iostream>
#include <string>
#include <type_traits>
#include <typeinfo>
#include <utility>
#include <vector>

#include <boost/hana.hpp>
namespace hana = boost::hana;
using namespace std::literals;

//! [Data type]
struct Data {
  int x;
  double y;

  operator std::string() const {
    return "{" + std::to_string(x) + ", " + std::to_string(y) + "}";
  };
};
//! [Data type]

//! [Basic expression templates]
namespace ops {
  //! [Operator types]
  struct valueop {
    const Data &value;
  };

  template <class LT, class RT> struct addop {
    const LT lv;
    const RT rv;

    addop(const LT &left, const RT &right) : lv(left), rv(right){};
  };
  //! [Operator types]

  //! [Standard operator overloads]
  template <class LT, class RT>
  auto operator+(const LT &left, const RT &right) {
    return addop<LT, RT>(left, right);
  }

  auto operator+(const Data &left, const Data &right) {
    return addop<valueop, valueop>({left}, {right});
  }

  template <class LT> auto operator+(const LT &left, const Data &right) {
    return addop<LT, valueop>(left, {right});
  }

  template <class RT> auto operator+(const Data &left, const RT &right) {
    return addop<valueop, RT>({left}, right);
  }
  //! [Standard operator overloads]

  //! [Eval string]
  std::string eval(const valueop &o) { return std::string(o.value); }

  template <class LT, class RT> std::string eval(const addop<LT, RT> &o) {
    return eval(o.lv) + " + " + eval(o.rv);
  }

  //! [Eval string]
}
//! [Basic expression templates]

//! [Some tricks]
namespace ops {
  //! @overload
  template <>
  std::string
  eval([[gnu::unused]] const addop<addop<valueop, valueop>, valueop> &o) {
    return "BINGO!";
  }

  //! [Merge]
  constexpr auto getValues(const valueop &o) {
    return hana::make_tuple(&o.value);
  }

  template <class LT, class RT>
  constexpr auto getValues(const addop<LT, RT> &o) {
    return hana::concat(getValues(o.lv), getValues(o.rv));
  }

  template <class LT, class RT> void eval_serial(const addop<LT, RT> &o) {
    auto v_o = getValues(o);
    hana::for_each(v_o, [&](auto x) { std::cout << std::string(*x) << ", "; });
  }
  //! [Merge]
}
//! [Some tricks]

using namespace ops;
int main(void) {
  Data a{1, 2};
  Data b{2, 4};

  std::cout << "a: " << std::string(a) << "\n";
  std::cout << "b: " << std::string(b) << "\n";

  auto ab = a + b;
  std::cout << "eval(ab): " << eval(ab) << "\n";

  Data c{3, 9};
  std::cout << "c: " << std::string(c) << "\n";
  auto abc = a + b + c + a;
  std::cout << "eval(abc): " << eval(abc) << "\n";

  eval_serial(abc);
}