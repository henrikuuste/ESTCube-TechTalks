#include <array>
#include <array>
#include <cstdint>
#include <iostream>

constexpr char my_fun(size_t i) { return 'a' + i; }

//**Implementation********************************************************************************
/*!\name Implementation */
//@{
template <int N, int... Rest> struct CompileArray { // Generic
  static constexpr auto &value = CompileArray<N - 1, N, Rest...>::value;
};

template <int... Rest> struct CompileArray<0, Rest...> { // Stop condition
  static constexpr std::array<char, sizeof...(Rest) + 1> value = {
      my_fun(0), my_fun(Rest)...};
};

template <int... Rest> // Definition
constexpr std::array<char, sizeof...(Rest) + 1> CompileArray<0, Rest...>::value;
//@}
//**********************************************************************************************

constexpr auto MY_COUNT = 10;
constexpr auto &my_data = CompileArray<MY_COUNT>::value;

int main() {
  for (auto &e : my_data) {
    std::cout << e << ", ";
  }
}