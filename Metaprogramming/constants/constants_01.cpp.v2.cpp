#include "exp_math.hpp"
#include <cstdint>
#include <iostream>

// [complex function call]
template <typename T> constexpr T ex = smath::exp(4.0f);

// [function objects]
template <typename T, size_t N> struct Factorial {
  static constexpr T value = N * Factorial<T, N - 1>::value;
};

template <typename T> struct Factorial<T, 0> { static constexpr T value = 1; };

template <size_t N> constexpr long fac = Factorial<long, N>::value; 
// [function objects]

int main() {
  std::cout << ex<float> << std::endl;
  std::cout << Factorial<int, 5>::value << std::endl;
  std::cout << fac<5> << std::endl;
}