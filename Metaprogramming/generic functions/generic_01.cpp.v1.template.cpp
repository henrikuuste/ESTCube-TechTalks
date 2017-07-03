#include <cstdint>
#include <cstdio>

template <typename T> T func(T val) { return val + 10; }

int main() {
  int i = 10;
  printf("func(%i) = %i\n", i, func<int>(i));
  float f = 5.5;
  printf("func(%.1f) = %.1f\n", f, func<float>(f));
  double d = 1.25;
  printf("func(%.3e) = %.3e\n", d, func<double>(d));

  void *bad_stuff = &i;
  printf("func(0x%016lx) = 0x%016lx\n", (uint64_t)bad_stuff,
         (uint64_t)func<void *>(bad_stuff));
}