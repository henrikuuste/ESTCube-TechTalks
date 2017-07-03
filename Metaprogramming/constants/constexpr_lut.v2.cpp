#include "exp_math.hpp"
#include <algorithm>
#include <array>
#include <iostream>

template <size_t NUM> constexpr std::array<float, NUM> make_lut(double step) {
  std::array<float, NUM> a = {};
  size_t i = 0;
  for (float &entry : a) {
    entry = smath::exp(static_cast<double>(i++) * step);
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
