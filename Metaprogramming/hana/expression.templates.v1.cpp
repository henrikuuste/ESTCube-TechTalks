#include <iostream>
#include <string>
#include <type_traits>
#include <typeinfo>
#include <utility>
#include <vector>

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

//! [Eval with access function]
namespace ops {
  template <typename F> auto eval_f(const valueop &o, F fun) {
    return fun(o.value);
  }

  template <class LT, class RT, typename F>
  auto eval_f(const addop<LT, RT> &o, F fun) {
    return eval_f(o.lv, fun) + eval_f(o.rv, fun);
  }
}
//! [Eval with access function]
using namespace ops;

int main(void) {
  Data a{1, 2};
  Data b{2, 4};

  std::cout << "a: " << std::string(a) << "\n";
  std::cout << "b: " << std::string(b) << "\n";

  auto ab = a + b;
  std::cout << "eval(ab): " << eval(ab) << "\n";
  std::cout << "eval_f(ab): " << eval_f(ab, [&](const Data &d) { return d.x; })
            << "\n";

  Data c{3, 9};
  std::cout << "c: " << std::string(c) << "\n";
  auto abc = a + b + c;
  std::cout << "eval(abc): " << eval(abc) << "\n";
  std::cout << "eval_f(abc): "
            << eval_f(abc, [&](const Data &d) { return d.x; }) << "\n";
}