#include "exp_math.hpp"
#include <algorithm>
#include <array>
#include <iostream>

template <typename Value, size_t Size>
constexpr Value &stdarray_at(const std::array<Value, Size> &a, size_t index) {
  return const_cast<Value &>(a[index]);
}

template <size_t NUM> constexpr std::array<float, NUM> make_lut(double step) {
  std::array<float, NUM> a = {};
  for (size_t i = 0; i < a.size(); i++) {
    stdarray_at(a, i) = smath::exp(static_cast<double>(i)*step);
  }
  return a;
}

constexpr size_t COUNT = 20;
constexpr double STEP_SIZE = 0.5;
constexpr static auto lut = make_lut<COUNT>(STEP_SIZE);

int main() {
  for (auto &v : lut) {
    std::cout << v << " ";
  }
}
