#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <utility>

//**Implementation********************************************************************************
/*!\name Implementation */
//@{
template <class Function, std::size_t... Indices>
constexpr auto make_array_helper(Function f, std::index_sequence<Indices...>)
    -> std::array<typename std::result_of<Function(std::size_t)>::type,
                  sizeof...(Indices)> {
  return {{f(Indices)...}};
}

template <int N, class Function> constexpr auto make_array(Function f) {
  return make_array_helper(f, std::make_index_sequence<N>{});
}
//@}
//**********************************************************************************************

using namespace std;

constexpr char fun(size_t i) { return 'a' + i; }
constexpr auto MY_COUNT = 10;
constexpr auto my_data = make_array<MY_COUNT>(fun);

constexpr double square(double x) { return x*x; }
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