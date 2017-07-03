#include "exp_math.hpp"
#include <algorithm>
#include <array>
#include <iostream>

constexpr auto make_lut(size_t NUM, double step) {
  float a[NUM] = {};
  for (size_t i = 0; i < NUM; i++) {
    a[i] = smath::exp(static_cast<double>(i)*step);
  }
  return a;
}

constexpr size_t COUNT = 20;
constexpr double STEP_SIZE = 0.5;
constexpr static float lut[COUNT] = make_lut(COUNT, STEP_SIZE);

int main() {
  for (auto i = 0; i < COUNT; i++) {
    std::cout << lut[i] << " ";
  }
}
