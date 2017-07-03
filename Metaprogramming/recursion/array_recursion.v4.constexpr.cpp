#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <utility>

//**Implementation********************************************************************************
/*!\name Implementation */
//@{
template <typename Value, size_t Size>
constexpr Value &stdarray_at(const std::array<Value, Size> &a, size_t index) {
  return const_cast<Value &>(a[index]);
}

template <size_t N, class Function> constexpr auto make_array(Function f) {
  using ValueType = std::result_of_t<Function(size_t)>;
  std::array<ValueType, N> a = {};
  for (size_t i = 0; i < N; i++) {
    const_cast<ValueType &>(static_cast<std::array<ValueType, N> const &>(a)[i]) = f(i);
    // stdarray_at(a, i) = f(i);
  }
  return a;
}
//@}
//**********************************************************************************************

using namespace std;

constexpr char fun(size_t i) { return 'a' + i; }
constexpr auto MY_COUNT = 10;
constexpr auto my_data = make_array<MY_COUNT>(fun);

constexpr double square(double x) { return x * x; }
constexpr auto my_squared = make_array<MY_COUNT>(square);

int main() {
  for (auto &e : my_data) {
    cout << e << ", ";
  }
  cout << "\n";
  for (auto &e : my_squared) {
    cout << e << ", ";
  }
}