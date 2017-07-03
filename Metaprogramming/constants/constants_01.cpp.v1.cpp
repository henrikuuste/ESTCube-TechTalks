#include <cstdint>
#include <cstdio>
#include "../helpers/algo_helper.hpp"
#include <array>
#include <iostream>
#include <iterator>
#include <utility>

template<typename T>
constexpr T MY_PI = 3.14;

template<>
constexpr int MY_PI<int> = 3;

int main() {
  std::cout << MY_PI<float> << " " << MY_PI<int> << std::endl;
}