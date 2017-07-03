#include <cstdint>
#include <cstdio>

constexpr double MY_PI = 3.14;
constexpr size_t MY_COUNT = 10;

char my_data[MY_COUNT] = {'a'};

int main() {
  printf("Some stuff %f %c", MY_PI, my_data[0]);
}